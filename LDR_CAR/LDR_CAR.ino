
int photocellPin1 = A14;
int photocellPin2 = A15;
int photocellPin3 = A13;
int photocellPin4 = A13;
int PR_UP;
int PR_DOWN; 
int PR_LEFT;
int PR_RIGHT;
int  for_rev=0;
int left_right=0;

void setup() {
   Serial.begin(9600);                     
  //Starting LDR's
  pinMode(photocellPin1,INPUT);
  pinMode(photocellPin2,INPUT);
  pinMode(photocellPin3,INPUT);
  pinMode(photocellPin4,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(13,OUTPUT);

 }

void drive(int left, int right){
}

void loop() {
  PR_UP = analogRead(photocellPin1);
  PR_DOWN = analogRead(photocellPin2);
  PR_LEFT = analogRead(photocellPin3);
  PR_RIGHT = analogRead(photocellPin4);
  for_rev = PR_UP-PR_DOWN;
  left_right = PR_LEFT-PR_RIGHT;
 
  if (abs(for_rev)<20){
   analogWrite(8,0);
  analogWrite(10, 0); 
    analogWrite(9,0);
  analogWrite(11, 0);

}
  else if (for_rev>0) {
  Serial.println("Backward");
  analogWrite(9,100);
  analogWrite(11, 100); 
  analogWrite(8,0);
  analogWrite(10, 0);  
  }
  else if (PR_UP<PR_DOWN) {
    Serial.println("Forward");
   analogWrite(9,00);
  analogWrite(11, 00); 
  analogWrite(8,100);
  analogWrite(10, 100);  
  }
else if (PR_UP<PR_DOWN && PR_LEFT>PR_RIGHT) {
Serial.println("Right");
  analogWrite(8,100);
  analogWrite(10, 00); 
  analogWrite(9,00);
  analogWrite(11, 00);
}
else if (PR_UP<PR_DOWN && PR_LEFT<PR_RIGHT) {
  Serial.println("Left");
  analogWrite(8,00);
  analogWrite(10, 100); 
  analogWrite(9,00);
  analogWrite(11, 00);
}
else {
  analogWrite(8,00);
  analogWrite(10, 00); 
  analogWrite(9,00);
  analogWrite(11, 00);
}

}

