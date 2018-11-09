//Pin Definitions

// Define the pins for RC RECEIVER CH 1-6
  const int ch1 = 35;
  const int ch2 = 37;
  const int ch3 = 29;
  const int ch4 = 27;
  const int ch5 = 25;
  const int ch6 = 23;


// Define the pins for MOTOR CONTROL

  // PWM control pins (control throttle)
    // Front Board
    const int pwm_L_frnt = 2 ;  // Initializing pin 2 as pwm
    const int pwm_R_frnt = 3 ;  // Initializing pin 3 as pwm
    
    // Rear Board
    const int pwm_L_rear = 5 ;  // Initializing pin 4 as pwm
    const int pwm_R_rear = 4 ;  // Initializing pin 5 as pwm
    
  // LOGIC PINS
    // Front Board
    const int L_frnt_1 = 52 ; // Initializing Left Front pin one 
    const int L_frnt_2 = 50 ; // Initializing Left Front pin two 
    const int R_frnt_1 = 48 ; // Initializing Right Front pin one 
    const int R_frnt_2 = 46 ; // Initializing Right Front pin two 
    
    // Rear Board
    const int L_rear_1 = 44 ; // Initializing Left Rear pin one 
    const int L_rear_2 = 42 ; // Initializing Left Rear pin two 
    const int R_rear_1 = 40 ; // Initializing Right Rear pin one 
    const int R_rear_2 = 38 ; // Initializing Right Rear pin two 
  
  // Pins to provide VCC (logic power) to L298N boards 
    const int pwr_frnt = 11 ; // Front Board Power
    const int pwr_rear = 13 ; // Rear Board Power

void MotorSetup(){
  // Setup pins for motor control
  
  pinMode(pwm_L_frnt,OUTPUT) ;   // Front logic pins PWM
  pinMode(pwm_R_frnt,OUTPUT) ;  
  
  pinMode(pwm_L_rear,OUTPUT) ;   // Rear logic pins PWM
  pinMode(pwm_R_rear,OUTPUT) ;   
  
  pinMode(L_frnt_1,OUTPUT) ;    // Set all front logic pins to OUTPUT
  pinMode(L_frnt_2,OUTPUT) ;
  pinMode(R_frnt_1,OUTPUT) ;
  pinMode(R_frnt_2,OUTPUT) ;
  
  pinMode(L_rear_1,OUTPUT) ;    // Set all rear logic pins to OUTPUT
  pinMode(L_rear_2,OUTPUT) ;
  pinMode(R_rear_1,OUTPUT) ;
  pinMode(R_rear_2,OUTPUT) ;
  
  
  pinMode(pwr_frnt,OUTPUT) ;  // Set power signals to OUTPUT
  pinMode(pwr_rear,OUTPUT) ;

}  


void RCSetup() {
  // Setup pins for RC control to read in RF signals
  pinMode(ch1,INPUT);//ch1-Right Gimble L/R
  pinMode(ch2,INPUT);//ch2-Right Gimble U/D
  pinMode(ch3,INPUT);//ch3-Left Gimble Throttle
  pinMode(ch4,INPUT);//ch4-Left Gimble L/R
  pinMode(ch5,INPUT);//ch5-Switch A
  pinMode(ch6,INPUT);//ch6-Switch C
}


void setup() {
  // put your setup code here, to run once:

  RCSetup();// setup pins for RC control
  MotorSetup();//setup pins for motor control
  
  Serial.begin(9600);//used for serial display

}


void MoveFwd(int throt){

  if (throt > 1050)
  {
    // Spin the front left wheel forward (ccw viewed from back of wheel)
    digitalWrite(L_frnt_1,LOW) ;
    digitalWrite(L_frnt_2,HIGH) ;
    analogWrite(pwm_L_frnt,150);
  
    // Spin the front right wheel forward (cw viewed from back of wheel)
    digitalWrite(R_frnt_1,LOW) ;
    digitalWrite(R_frnt_2,HIGH) ;
    analogWrite(pwm_R_frnt,150);
  
    // Spin the rear left wheel forward (ccw viewed from back of wheel)
    digitalWrite(L_rear_1,LOW) ;
    digitalWrite(L_rear_2,HIGH) ;
    analogWrite(pwm_L_rear,150);
  
    // Spin the rear right wheel forward (cw viewed from back of wheel)
    digitalWrite(R_rear_1,LOW) ;
    digitalWrite(R_rear_2,HIGH) ;
    analogWrite(pwm_R_rear,150);
  }

  else
  {
    MotorsOff();
  }
}


void MotorsOff(){
// Turn off all motors by writing PWM signals to 0

  analogWrite(pwm_R_frnt,0);
  analogWrite(pwm_L_frnt,0);
  analogWrite(pwm_R_rear,0);
  analogWrite(pwm_L_rear,0);
}

void RCDisp(int c1, int c2, int c3, int c4, int c5, int c6){
// diaplay values being read by receiver

  Serial.print("Channel 1 = ");
  Serial.println(c1);
  
  Serial.print("Channel 2 = ");
  Serial.println(c2);
  
  Serial.print("Channel 3 = ");
  Serial.println(c3);
 
  Serial.print("Channel 4 = ");
  Serial.println(c4);
  
  Serial.print("Channel 5 = ");
  Serial.println(c5);

  Serial.print("Channel 6 = ");
  Serial.println(c6);

  Serial.println(" ");
  //delay(3000);//delay for reading clarity
  
}
void loop() {

  // Power on to logic boards
  digitalWrite(pwr_frnt,HIGH) ;
  digitalWrite(pwr_rear,HIGH) ;
  
  // Read receiver inputs
    //use pulseIn function to find length of time the pulse is high
  int CH1 = pulseIn(ch1,HIGH);
  int CH2 = pulseIn(ch2,HIGH);
  int CH3 = pulseIn(ch3,HIGH);
  int CH4 = pulseIn(ch4,HIGH);
  int CH5 = pulseIn(ch5,HIGH);
  int CH6 = pulseIn(ch6,HIGH);
  
  RCDisp(CH1,CH2,CH3,CH4,CH5,CH6);//display the values coming into the receiver


    MoveFwd(CH3);
  
  

}
