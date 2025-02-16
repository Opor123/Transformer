#include<Servo.h>

//Define Servo pin (Can adjust the pin later)
Servo servo1; 
Servo servo2; 

int pos = 0;

void RC(){
    if(pos>=90){
        servo1.write(0);
        servo2.write(0);
        delay(15);
    }
}

void Drone(){
    if(pos<=0){
        servo1.write(0);
        servo2.write(0);
        delay(15);
    }
}

void setup(){
    servo1.attach(3) // If any pin had change just change it
    servo2.attach(4) // If any pin had change just change it
}

void loop(){
    //Add any function into here for testing any further
}