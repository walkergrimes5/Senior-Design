
// SPEED CONTROL PINS
const int pwmA = 2 ;  // Initializing pin 2 as pwm
const int pwmB = 3 ;  // Initializing pin 3 as pwm

// LOGIC PINS
const int A_1 = 52 ; // Initializing Motor A pin one 
const int A_2 = 50 ; // Initializing Motor A pin two 
const int B_1 = 48 ; // Initializing Motor B pin one 
const int B_2 = 46 ; // Initializing Motor B pin two 

// Power L298N 
const int pwr = 11 ;

void setup() { 
pinMode(pwmA,OUTPUT) ;   // Set PWM1 pin as output
pinMode(pwmB,OUTPUT) ;   // Set PWM2 pin as output

pinMode(A_1,OUTPUT) ;    // Set all logic pins to output
pinMode(A_2,OUTPUT) ;
pinMode(B_1,OUTPUT) ;
pinMode(B_2,OUTPUT) ;

pinMode(pwr,OUTPUT) ;
}

void loop() {
// Spin the front left wheel ccw viewed from back of wheel
digitalWrite(pwr,HIGH) ;
digitalWrite(A_1,HIGH) ;
digitalWrite(A_2,LOW) ;
analogWrite(pwmA,150);
}

/*
void forward(){
digitalWrite(A_1,HIGH) ;
digitalWrite(A_2,LOW) ;

digitalWrite(A_1,HIGH) ;
digitalWrite(A_2,LOW) ;
}
*/
