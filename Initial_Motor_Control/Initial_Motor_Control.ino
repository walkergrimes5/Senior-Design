
// SPEED CONTROL PINS

  // Front
  const int pwm_L_frnt = 2 ;  // Initializing pin 2 as pwm
  const int pwm_R_frnt = 3 ;  // Initializing pin 3 as pwm
  // Rear
  const int pwm_L_rear = 5 ;  // Initializing pin 4 as pwm
  const int pwm_R_rear = 4 ;  // Initializing pin 5 as pwm
  
// LOGIC PINS
  // Front
  const int L_frnt_1 = 52 ; // Initializing Left Front pin one 
  const int L_frnt_2 = 50 ; // Initializing Left Front pin two 
  const int R_frnt_1 = 48 ; // Initializing Right Front pin one 
  const int R_frnt_2 = 46 ; // Initializing Right Front pin two 
  
  // Rear
  const int L_rear_1 = 44 ; // Initializing Left Rear pin one 
  const int L_rear_2 = 42 ; // Initializing Left Rear pin two 
  const int R_rear_1 = 40 ; // Initializing Right Rear pin one 
  const int R_rear_2 = 38 ; // Initializing Right Rear pin two 

// Power Pins L298N 
  const int pwr_frnt = 11 ; // Front Power
  const int pwr_rear = 13 ; // Rear Power
  
void setup() { 

pinMode(pwm_L_frnt,OUTPUT) ;   // Front logic pins
pinMode(pwm_R_frnt,OUTPUT) ;  

pinMode(pwm_L_rear,OUTPUT) ;   // Rear logic pins
pinMode(pwm_R_rear,OUTPUT) ;   

pinMode(L_frnt_1,OUTPUT) ;    // Set all front logic pins to output
pinMode(L_frnt_2,OUTPUT) ;
pinMode(R_frnt_1,OUTPUT) ;
pinMode(R_frnt_2,OUTPUT) ;

pinMode(L_rear_1,OUTPUT) ;    // Set all rear logic pins to output
pinMode(L_rear_2,OUTPUT) ;
pinMode(R_rear_1,OUTPUT) ;
pinMode(R_rear_2,OUTPUT) ;


pinMode(pwr_frnt,OUTPUT) ;
pinMode(pwr_rear,OUTPUT) ;

}

void frntLeftFWD(){
// Spin the front left wheel forward (ccw viewed from back of wheel)
digitalWrite(L_frnt_1,LOW) ;
digitalWrite(L_frnt_2,HIGH) ;
analogWrite(pwm_L_frnt,150);
}

void frntRightFWD(){
// Spin the front right wheel forward (cw viewed from back of wheel)
digitalWrite(R_frnt_1,LOW) ;
digitalWrite(R_frnt_2,HIGH) ;
analogWrite(pwm_R_frnt,150);
}

void rearLeftFWD(){
// Spin the rear left wheel forward (ccw viewed from back of wheel)
digitalWrite(L_rear_1,LOW) ;
digitalWrite(L_rear_2,HIGH) ;
analogWrite(pwm_L_rear,150);
}

void rearRightFWD(){
// Spin the front right wheel forward (cw viewed from back of wheel)
digitalWrite(R_rear_1,LOW) ;
digitalWrite(R_rear_2,HIGH) ;
analogWrite(pwm_R_rear,150);
}


void loop() {
digitalWrite(pwr_frnt,HIGH) ;
digitalWrite(pwr_rear,HIGH) ;
frntRightFWD();
frntLeftFWD();
rearLeftFWD();
rearRightFWD();
}
