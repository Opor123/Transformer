#include<Wire.h>
#include<MPU6050.h>

// Motor pins
#define MOTOR1_PIN A1
#define MOTOR2_PIN A2
#define MOTOR3_PIN A3
#define MOTOR4_PIN A4

// Ultrasonic sensor pins
#define TRIG_PIN 6
#define ECHO_PIN 7

//Define IMU
MPU6050 imu;

void IMU(){
  Wire.begin();
  imu.initialize();
}

void motor(){
  pinMode(MOTOR1_PIN, OUTPUT);
  pinMode(MOTOR2_PIN, OUTPUT);
  pinMode(MOTOR3_PIN, OUTPUT);
  pinMode(MOTOR4_PIN, OUTPUT);
}

// PID parameters
double kp = 1.0, ki = 0.5, kd = 0.1;
double error_prior = 0;
double integral_prior = 0;
unsigned long last = 0;

//altitude
double altitude_kp=1.5, altitude_ki=0.8, altitude_kd=0.3;
double altitude_error=0;
double altitude_integral=0;
unsigned long altitude_last=0;

// Function for tuning PID parameters
void tunePID(double Kp, double Ki, double Kd) {
  kp = Kp;
  ki = Ki;
  kd = Kd;
}

// Function to compute PID output
double computePID(double setPoint, double input, double &error_prior, double &integral_prior, unsigned long &last, double Kp, double Ki, double Kd) {
  unsigned long current = millis();
  double delta = (current - last) / 1000.0; // Convert to seconds

  if (delta <= 0.0) return 0;

  double error = setPoint - input;
  double prop = Kp * error;
  integral_prior += error * delta;
  double integral = Ki * integral_prior;
  double derivative = (error - error_prior) / delta;
  double dev = Kd * derivative;

  double output = prop + integral + dev;

  // Update for next iteration
  error_prior = error;
  last = current;

  return output;
}

// Function for control motor speed
double speed(double altitude,double pitch, double roll){
 int m_speed1=constrain(1500+altitude+pitch+roll,1000,2000);
 int m_speed2=constrain(1500+altitude-pitch+roll,1000,2000);
 int m_speed3=constrain(1500+altitude+pitch-roll,1000,2000);
 int m_speed4=constrain(1500+altitude-pitch-roll,1000,2000);

 analogWrite(motor1,m_speed1);
 analogWrite(motor2,m_speed2);
 analogWrite(motor3,m_speed3);
 analogWrite(motor4,m_speed4);
}

// Function to measure distance using the ultrasonic sensor
double measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  double distance = (duration * 0.034) / 2; // Convert duration to distance
  return distance;
}

void stable(){

  double current_altitude=measureDistance();
  double target=60.0; //Height that we want drone to hover above the ground

  double output=computePID(target,current_altitude,altitude_error,altitude_integral,altitude_last,altitude_kp,altitude_ki,altitude_kd);

  double pitch=imu.getAngleY(); // Get Pitch angle
  double roll=imu.getAngleX();  // Get Roll angle

  double set_pitch=0.0;
  double set_roll=0.0;

  double pitch_out=computePID(set_pitch,pitch,error_prior,integral_prior,last,kp,ki,kd);
  double roll_out=computePID(set_roll,roll,error_prior,integral_prior,last,kp,ki,kd);

  speed(output,roll_out);
}

void setup() {
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Serial.begin(9600); // Uncomment for debugging
  IMU();
  motor();

  // Initialize PID parameters
  tunePID(2.0, 0.5, 1.0);
}

void loop() {
  stable();
  delay(10);
  // Optional: Uncomment for debugging
  // Serial.print("Distance: ");
  // Serial.print(input);
  // Serial.print(" cm, Output: ");
  // Serial.println(motorOutput);
}
