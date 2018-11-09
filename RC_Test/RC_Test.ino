const int ch1 = 35;
const int ch2 = 37;
const int ch3 = 29;
const int ch4 = 27;
const int ch5 = 25;
const int ch6 = 23;

void setup() {
  pinMode(ch1,INPUT);
  pinMode(ch2,INPUT);
  pinMode(ch3,INPUT);
  pinMode(ch4,INPUT);
  pinMode(ch5,INPUT);
  pinMode(ch6,INPUT);

  Serial.begin(9600);
}

void loop() {
  int CH1 = pulseIn(ch1,HIGH);
  int CH2 = pulseIn(ch2,HIGH);
  int CH3 = pulseIn(ch3,HIGH);
  int CH4 = pulseIn(ch4,HIGH);
  int CH5 = pulseIn(ch5,HIGH);
  int CH6 = pulseIn(ch6,HIGH);

  Serial.println("RC Control Mode");

  Serial.print("Channel 1 = ");
  Serial.println(CH1);
  
  Serial.print("Channel 2 = ");
  Serial.println(CH2);
  
  Serial.print("Channel 3 = ");
  Serial.println(CH3);
 
  Serial.print("Channel 4 = ");
  Serial.println(CH4);
  
  Serial.print("Channel 5 = ");
  Serial.println(CH5);

  Serial.print("Channel 6 = ");
  Serial.println(CH6);

  Serial.println(" ");
  delay(3000);

}
