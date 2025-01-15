#define motor1 A1 //Motor pin
#define motor2 A2 //Motor pin
#define motor3 A3 //Motor pin
#define motor4 A4 //Motor pin
#define TRIG_PIN 6  // Trig pin of ultrasonic sensor also can change pin later if in case
#define ECHO_PIN 7  // Echo pin of ultrasonic sensor also can change pin later if in case


double kp = 1.0, ki = 0.5, kd = 0.1; // Default PID parameters
double error_prior = 0;              // Previous error for derivative calculation
double integral_prior = 0;           // Accumulated error for integral term
unsigned long last = 0;              // Last time calculation

// Function for tuning PID parameters
void tunning(double Kp, double Ki, double Kd) {
  kp = Kp;
  ki = Ki;
  kd = Kd;
}

// Function to compute PID output
double compute(double setPoint, double input) {
  unsigned long current = millis();
  double delta = (current - last) / 1000.0; // Convert to seconds

  if (delta <= 0.0) return 0;

  // Calculate error
  double error = setPoint - input;

  // Proportional term
  double prop = kp * error;

  // Integral term
  integral_prior += error * delta;
  double integral = ki * integral_prior;

  // Derivative term
  double derivative = (error - error_prior) / delta;
  double dev = kd * derivative;

  // Calculate output
  double output = prop + integral + dev;

  // Update for next iteration
  error_prior = error;
  last = current;

  return output;
}

double distance(){
  digitalWrite(TRIG_PIN,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN,HIGH);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN,LOW);

  long duration=pulseIn(ECHO_PIN,HIGH);
  double s=(duration*0.034)/2; // s = distance
  return s;
}

void setup() {
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
	
  //Serial.begin(9600); // Debugging
  tunning(2.0, 0.5, 1.0); // Set initial PID values
}

void loop() {
  // Example: Read the sensor value
  double input = distance();  // Get distance from the function that calculate the input from ultrasonic
  double setPoint = 60;       // Desired distance in CM

  // Compute PID output
  double output = compute(setPoint, input);

  // Apply the PID output to the motors (e.g., motor speed control)
  int motorOutput = constrain(map(output,-50,50,0,255), 0, 255); // Constrain output to PWM range

  analogWrite(motor1, motorOutput);
  analogWrite(motor2, motorOutput);
  analogWrite(motor3, motorOutput);
  analogWrite(motor4, motorOutput);

  // Debugging information
 
}
