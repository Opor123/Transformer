//Define ESC pins for RC can adjust later
#define esc1 8
#define esc2 9


int motor1Speed=0,motor2Speed=0,motor3Speed=0,motor4Speed=0;

void motor(){
    pinMode(esc1, OUTPUT);
    pinMode(esc2, OUTPUT);
}

// Moving Forward
void forward(){
  motor1Speed=255;
  motor2Speed=255;

  analogWrite(esc1,motor1Speed);
  analogWrite(esc2,motor2Speed);

}

// Turn Right
void turnRight(){
  motor1Speed=128;
  motor2Speed=255;


  analogWrite(esc1,motor1Speed);
  analogWrite(esc2,motor2Speed);

}

// Turn Left
void turnLeft(){
  motor1Speed=255;
  motor2Speed=128;


  analogWrite(esc1,motor1Speed);
  analogWrite(esc2,motor2Speed);

}

// Move Backward
void back(){
  motor1Speed= -255;
  motor2Speed= -255;


  analogWrite(esc1,motor1Speed);
  analogWrite(esc2,motor2Speed);
}

//Stop
void stop(){
  motor1Speed=0;
  motor2Speed=0;


  analogWrite(esc1,motor1Speed);
  analogWrite(esc2,motor2Speed);
}

void setup(){

    motor();

    analogWrite(esc1,motor1Speed);
    analogWrite(esc2,motor2Speed);
    delay(3000);
}

void loop(){

}