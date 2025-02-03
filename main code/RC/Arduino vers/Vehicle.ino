#include<Wire.h>

// Define motors pin(Can adjust later)

// Define 1st motor
#define motor1in1 1
#define motor1in2 2
#define motor1ENA 9

// Define 2nd motor
#define motor2in1 3
#define motor2in2 4
#define motor2ENB 10

// Define 3rd motor
#define motor3in1 5
#define motor3in2 6
#define motor3ENA 11

// Define 4th motor
#define motor4in1 7
#define motor4in2 8
#define motor4ENB 12

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

    //3rd motor
    pinMode(motor3in1,OUTPUT);
    pinMode(motor3in2,OUTPUT);
    pinMode(motor3ENA,OUTPUT);

    //4th motor
    pinMode(motor4in1,OUTPUT);
    pinMode(motor4in2,OUTPUT);
    pinMode(motor4ENB,OUTPUT);

}

void setup(){
    Serial.begin(9600);
    motor();
}