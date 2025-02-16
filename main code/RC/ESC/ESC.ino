// Include library section
#include <Wire.h>
#include <Servo.h>

// Define ESC pins for RC (can adjust later)
#define ESC1_PIN 8
#define ESC2_PIN 9

// Define Servo pins (can adjust later)
#define SERVO1_PIN 3
#define SERVO2_PIN 4

// Define Position of the servo
int pos = 0;

// Define motor speeds (constants for clarity)
#define MOTOR_FORWARD_SPEED 255
#define MOTOR_BACKWARD_SPEED -255
#define MOTOR_TURN_SPEED_HIGH 255
#define MOTOR_TURN_SPEED_LOW 128

/*
Define state of the transformation (using an enum for better readability)

0 = RC mode

1 = Drone Mode
*/

enum Mode {
  RC_MODE = 0,
  DRONE_MODE = 1
};

Mode currentMode = RC_MODE; // Start in RC mode

/*==========================================================*/

// Motor control functions

void initializeMotors() {
  pinMode(ESC1_PIN, OUTPUT);
  pinMode(ESC2_PIN, OUTPUT);
}

void setMotorSpeeds(int speed1, int speed2) {
  analogWrite(ESC1_PIN, speed1);
  analogWrite(ESC2_PIN, speed2);
}

void moveForward() {
  setMotorSpeeds(MOTOR_FORWARD_SPEED, MOTOR_FORWARD_SPEED);
}

void moveBackward() {
  setMotorSpeeds(MOTOR_BACKWARD_SPEED, MOTOR_BACKWARD_SPEED);
}

void turnRight() {
  setMotorSpeeds(MOTOR_TURN_SPEED_LOW, MOTOR_TURN_SPEED_HIGH);
}

void turnLeft() {
  setMotorSpeeds(MOTOR_TURN_SPEED_HIGH, MOTOR_TURN_SPEED_LOW);
}

void stopMotors() {
  setMotorSpeeds(0, 0);
}


// Servo control functions

Servo servo1;
Servo servo2;

void initializeServos() {
  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);
}

void setServosPosition(int position) {
  servo1.write(position);
  servo2.write(position);  // Assuming both servos move together
}


// Mode-specific functions

void handleRCMode() {
  //Implement RC control logic here.
  if (pos>=90) {
    SERVO1_PIN.write(0); // Example position
    delay(15);
  }
}

void handleDroneMode() {
  // Implement Drone control logic here.
  if (pos<=0) {
    SERVO2_PIN.write(90);  // Example position
    delay(15);
  }
}


// Setup and Loop functions

void setup() {
  initializeMotors();
  initializeServos();

  // Calibrate ESCs (important!  This is a simplified version; adapt as needed)
  setMotorSpeeds(0, 0);
  delay(3000); // Give time for ESC calibration
}

void loop() {
  switch (currentMode) {
    case RC_MODE:
      handleRCMode();
      break;
    case DRONE_MODE:
      handleDroneMode();
      break;
  }

  // Example of using motor functions:
  // moveForward();
  // delay(1000);
  // stopMotors();
  // delay(500);
  // turnRight();
  // delay(500);
  // stopMotors();

}