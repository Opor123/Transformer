#include <SPI.h>
#include <Wire.h>

// Define ESC pins for drone motors
#define ESC1_PIN 8
#define ESC2_PIN 9
#define ESC3_PIN 10
#define ESC4_PIN 11

#define MOTOR_STOP_SPEED 128  // Adjust if needed for your ESCs

volatile char receivedCommand = 'R'; // Default to "RC Mode"

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

// Interrupt function when SPI data is received
ISR(SPI_STC_vect) {
  receivedCommand = SPDR; // Read received command
}

void setup() {
  Serial.begin(115200);
  SPI.begin();                // Enable SPI
  SPCR |= _BV(SPE);           // Enable SPI in Slave mode
  pinMode(MISO, OUTPUT);

  initializeMotors();
  setMotorSpeeds(MOTOR_STOP_SPEED, MOTOR_STOP_SPEED, MOTOR_STOP_SPEED, MOTOR_STOP_SPEED); // Stop motors initially
}

void loop() {
  if (receivedCommand == 'D') {
    Serial.println("Drone Mode Activated!");
    setMotorSpeeds(255, 255, 255, 255);  // Start drone motors
  } else {
    Serial.println("RC Mode - Drone Motors Off");
    setMotorSpeeds(MOTOR_STOP_SPEED, MOTOR_STOP_SPEED, MOTOR_STOP_SPEED, MOTOR_STOP_SPEED);  // Stop drone motors
  }

  delay(500);
}
