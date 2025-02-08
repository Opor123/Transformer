#include<Wire.h>

// Define motors pin(Can adjust later)
// Define 1st motor
#define motor1in1 1
#define motor1in2 2
#define motor1ENA 9

//ESC version

// Define 2nd motor
#define motor2in1 3
#define motor2in2 4
#define motor2ENB 10

// Motor speed
int motorA=0,motorB=0;

void motor(){
    // 1st motor
    pinMode(motor1in1,OUTPUT);
    pinMode(motor1in2,OUTPUT);
    pinMode(motor1ENA,OUTPUT);
    
    //2nd motor
    pinMode(motor2in1,OUTPUT);
    pinMode(motor2in2,OUTPUT);
    pinMode(motor2ENB,OUTPUT);

}

void forward(){

}

void setup(){
    Serial.begin(9600);
    motor();
}

void loop(){

}