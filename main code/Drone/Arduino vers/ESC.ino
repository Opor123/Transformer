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

void start(){
    analogWrite(esc1,motor1Speed);
    analogWrite(esc2,motor2Speed);
    analogWrite(esc3,motor3Speed);
    analogWrite(esc4,motor4Speed);
    delay(3000);
}

void setup(){
    motor();
    start();
    
}

void loop(){

}