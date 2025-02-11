/* 
#include<MPU6050.h> // If we have IMU can uncomment it later
MPU6050 IMU;
*/



//Define ESC pins for drone
#define esc1 8
#define esc2 9
#define esc3 10 
#define esc4 11

int motor1Speed=0,motor2Speed=0,motor3Speed=0,motor4Speed=0;



void motor(){
    pinMode(esc1, OUTPUT);
    pinMode(esc2, OUTPUT);
    pinMode(esc3, OUTPUT);
    pinMode(esc4, OUTPUT);
}

// Moving Forward
void forward(){
  motor1Speed=128;
  motor2Speed=128;
  motor3Speed=255;
  motor4Speed=255;

  analogWrite(esc1,motor1Speed);
  analogWrite(esc2,motor2Speed);
  analogWrite(esc3,motor3Speed);
  analogWrite(esc4,motor4Speed);
}

// Turn Right
void turnRight(){
  motor1Speed=128;
  motor2Speed=255;
  motor3Speed=128;
  motor4Speed=255;

  analogWrite(esc1,motor1Speed);
  analogWrite(esc2,motor2Speed);
  analogWrite(esc3,motor3Speed);
  analogWrite(esc4,motor4Speed);
}

// Turn Left
void turnLeft(){
  motor1Speed=255;
  motor2Speed=128;
  motor3Speed=255;
  motor4Speed=128;

  analogWrite(esc1,motor1Speed);
  analogWrite(esc2,motor2Speed);
  analogWrite(esc3,motor3Speed);
  analogWrite(esc4,motor4Speed);
}

// Move Backward
void back(){
  motor1Speed=255;
  motor2Speed=255;
  motor3Speed=128;
  motor4Speed=128;

  analogWrite(esc1,motor1Speed);
  analogWrite(esc2,motor2Speed);
  analogWrite(esc3,motor3Speed);
  analogWrite(esc4,motor4Speed);
}

//Stop
void stop(){
  motor1Speed=128;
  motor2Speed=128;
  motor3Speed=128;
  motor4Speed=128;

  analogWrite(esc1,motor1Speed);
  analogWrite(esc2,motor2Speed);
  analogWrite(esc3,motor3Speed);
  analogWrite(esc4,motor4Speed);
}

void setup(){

    motor();

    analogWrite(esc1,motor1Speed);
    analogWrite(esc2,motor2Speed);
    analogWrite(esc3,motor3Speed);
    analogWrite(esc4,motor4Speed);
    delay(3000);
}

void loop(){

}