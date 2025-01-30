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

void motor(){
    pinMode(motor1,OUTPUT);
    pinMode(motor2,OUTPUT);
    pinMode(motor3,OUTPUT);
    pinMode(motor4,OUTPUT);
}

void setup(){
    Serial.begin(9600);
    motor();
}