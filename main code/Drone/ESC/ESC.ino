#include <Wire.h>

// Define ESC pins for drone
#define ESC1_PIN 8
#define ESC2_PIN 9
#define ESC3_PIN 10
#define ESC4_PIN 11

// Define motor speeds (constants for clarity)
#define MOTOR_FORWARD_SPEED 255  // Or adjust as needed
#define MOTOR_BACKWARD_SPEED 255 // Or adjust as needed
#define MOTOR_TURN_SPEED_HIGH 255
#define MOTOR_TURN_SPEED_LOW 128
#define MOTOR_STOP_SPEED 128 // Adjust if needed for your ESCs

// Uncomment if you have an IMU
// #include <MPU6050.h>
// MPU6050 imu;

// Uncomment if you have an ultrasonic sensor
// #define TRIG_PIN 6
// #define ECHO_PIN 7

// Motor control functions

void initializeMotors() {
  pinMode(ESC1_PIN, OUTPUT);
  pinMode(ESC2_PIN, OUTPUT);
  pinMode(ESC3_PIN, OUTPUT);
  pinMode(ESC4_PIN, OUTPUT);
}

void setMotorSpeeds(int speed1, int speed2, int speed3, int speed4) {
  analogWrite(ESC1_PIN, speed1);
  analogWrite(ESC2_PIN, speed2);
  analogWrite(ESC3_PIN, speed3);
  analogWrite(ESC4_PIN, speed4);
}

void moveForward() {
  setMotorSpeeds(MOTOR_TURN_SPEED_LOW, MOTOR_TURN_SPEED_LOW, MOTOR_FORWARD_SPEED, MOTOR_FORWARD_SPEED); // Adjusted for likely motor config
}

void moveBackward() {
  setMotorSpeeds(MOTOR_FORWARD_SPEED, MOTOR_FORWARD_SPEED, MOTOR_TURN_SPEED_LOW, MOTOR_TURN_SPEED_LOW); // Adjusted for likely motor config
}

void turnRight() {
  setMotorSpeeds(MOTOR_TURN_SPEED_LOW, MOTOR_TURN_SPEED_HIGH, MOTOR_TURN_SPEED_LOW, MOTOR_TURN_SPEED_HIGH);
}

void turnLeft() {
  setMotorSpeeds(MOTOR_TURN_SPEED_HIGH, MOTOR_TURN_SPEED_LOW, MOTOR_TURN_SPEED_HIGH, MOTOR_TURN_SPEED_LOW);
}

void stopMotors() {
  setMotorSpeeds(MOTOR_STOP_SPEED, MOTOR_STOP_SPEED, MOTOR_STOP_SPEED, MOTOR_STOP_SPEED); // Use consistent stop speed
}


// Ultrasonic sensor functions (if you have one)

double readUltrasonicDistance() {
#ifdef TRIG_PIN // Only compile this code if TRIG_PIN is defined
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10); // Increased pulse width for some sensors
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH); // Use pulseIn() for more reliable readings
  double distance = (duration * 0.034) / 2; // Speed of sound in cm/us, divided by 2 for one-way distance
  return distance;
#else
  return -1.0; // Return -1.0 if no sensor is defined
#endif
}

// Setup and Loop functions

void setup() {
  initializeMotors();

  // Calibrate ESCs (important! This is a simplified version; adapt as needed)
  setMotorSpeeds(MOTOR_STOP_SPEED, MOTOR_STOP_SPEED, MOTOR_STOP_SPEED, MOTOR_STOP_SPEED); // Start with zero speed for calibration
  delay(3000); // Give time for ESC calibration

  // Initialize ultrasonic sensor (if you have one)
#ifdef TRIG_PIN
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
#endif

  // Initialize IMU (if you have one)
  // if (!imu.begin()) {
  //   Serial.println("Failed to initialize IMU");
  //   while (1);
  // }
}

void loop() {
  // Example of using motor functions:
  moveForward();
  delay(1000);
  stopMotors();
  delay(500);
  turnRight();
  delay(500);
  stopMotors();

  // Example of using the ultrasonic sensor (if you have one)
  double distance = readUltrasonicDistance();
  if (distance != -1.0) {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }


}