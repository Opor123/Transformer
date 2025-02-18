// Include library section
#include <SPI.h>
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
  servo1.attach(SERVO1_PIN); // change the SERVO_PIN to the pin that servo attach too
  servo2.attach(SERVO2_PIN); // change the SERVO_PIN to the pin that servo attach too
}

void setServosPosition(int position) {
  servo1.write(position);
  servo2.write(position);  // Assuming both servos move together
}


// Mode-specific functions

void handleRCMode() {
  //Implement RC control logic here.
  if (pos>=90) {
    servo1.write(0); // Example position
    delay(15);
  }
}

void handleDroneMode() {
  // Implement Drone control logic here.
  if (pos<=0) {
    servo2.write(90);  // Example position
    delay(15);
  }
}

//This will change if communication change
// SPI Send Function
void sendSPICommand(char command) {
  digitalWrite(SPI_SS_PIN, LOW);  // Select drone board
  SPI.transfer(command);          // Send command
  digitalWrite(SPI_SS_PIN, HIGH); // Deselect
}


// Setup and Loop functions

void setup() {
  Serial.begin(115200);
  SPI.begin();           // Initialize SPI
  pinMode(SPI_SS_PIN, OUTPUT);
  
  initializeMotors();
  initializeServos();

  // Calibrate ESCs
  setMotorSpeeds(0, 0);
  delay(3000);
}

void loop() {
  if(currentMode==RC_MODE){
    
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