
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
int a=0;
int b=0;
int c=0;
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
Serial.println(PR_LEFT);
 a=(PR_UP)-(PR_DOWN);
 abs(a);
 b=(PR_LEFT)-(PR_RIGHT);
 abs(b);
 //if (a<100){
  //analogWrite(8,0);
  //analogWrite(10, 0); 
  //analogWrite(9,0);
  //analogWrite(11, 0);
 //}
//else if (b<100) {
  //analogWrite(8,0);
  //analogWrite(10, 0); 
  //analogWrite(9,0);
  //analogWrite(11, 0);
//}
 if(PR_UP>PR_DOWN){
//BACKWARDS
   analogWrite (9,150);
  analogWrite(11, 150); 
  analogWrite(8,0);
  analogWrite(10, 0);
}
else if (PR_UP<PR_DOWN&&PR_RIGHT<PR_UP&&PR_LEFT>PR_RIGHT){
  //RIGHT
  analogWrite(8,150);
  analogWrite(10, 00); 
  analogWrite(9,00);
  analogWrite(11, 00);
}
else if (PR_UP<PR_DOWN&&PR_LEFT<PR_UP&&PR_LEFT<PR_RIGHT){
  //LEFT
  analogWrite(8,00);
  analogWrite(10, 150); 
  analogWrite(9,00);
  analogWrite(11, 00); 
}
else if(PR_UP<PR_DOWN&&PR_LEFT>PR_UP&&PR_RIGHT>PR_UP){
   //FORWARD
   analogWrite(9,150);
  analogWrite(11, 150); 
  analogWrite(8,00);
  analogWrite(10,00);
}
}
