#include <IRremote.h>
#define carspeed 100 // speed for moving forward/back
#define turningcarspeed 150 // speed for moving left/right 
#define ENA 5
#define ENB 6
#define M1 7
#define M2 8
#define M3 9
#define M4 11
#define IR_R !digitalRead(10)
#define IR_M !digitalRead(4)
#define IR_L !digitalRead(2)
int Echo = A4;  
int Trig = A5; 
int middleDistance = 0;

void setup() {

 pinMode(Echo,INPUT);
 pinMode(Trig,OUTPUT);
 pinMode(10,INPUT);
 pinMode(4,INPUT);
 pinMode(2,INPUT);
 pinMode(M1,OUTPUT);
 pinMode(M2,OUTPUT);
 pinMode(M3,OUTPUT);
 pinMode(M4,OUTPUT);
 pinMode(ENA,OUTPUT);
 pinMode(ENB,OUTPUT);
 Serial.begin(9600);
}
int Distance_test() {
  digitalWrite(Trig, LOW);   
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(2);
  digitalWrite(Trig, LOW);   
  float Fdistance = pulseIn(Echo, HIGH);  
  Fdistance= Fdistance / 58;       
  return (int)Fdistance;
}
void foward(){//function for going forwards
 Serial.println("foward");
 analogWrite(ENA,carspeed);
 analogWrite(ENB,carspeed);
 digitalWrite(M1,HIGH);
 digitalWrite(M2,LOW);
 digitalWrite(M3,LOW);
 digitalWrite(M4,HIGH);
}
void back(){//function for going backwards
 Serial.println("back");
 analogWrite(ENA,carspeed);
 analogWrite(ENB,carspeed);
 digitalWrite(M1,LOW);
 digitalWrite(M2,HIGH);
 digitalWrite(M3,HIGH);
 digitalWrite(M4,LOW);
}
void left(){//function for going left
 Serial.println("left");
 analogWrite(ENA,turningcarspeed);
 analogWrite(ENB,turningcarspeed);
 digitalWrite(M1,HIGH);
 digitalWrite(M2,LOW);
 digitalWrite(M3,HIGH);
 digitalWrite(M4,LOW);
}
void right(){//function for going right
 Serial.println("right");
 analogWrite(ENA,turningcarspeed);
 analogWrite(ENB,turningcarspeed);
 digitalWrite(M1,LOW);
 digitalWrite(M2,HIGH);
 digitalWrite(M3,LOW);
 digitalWrite(M4,HIGH);
}
void stop(){//function for stopping 
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  Serial.println("Stop");
}
void loop() {
  // put your main code here, to run repeatedly:
 int pol=analogRead(A0);//pollutuion sensor
 Serial.println(pol);
 if (pol>=275){
  if(IR_M==HIGH&&IR_R==HIGH&&IR_L==HIGH){ //IR Sensor following line 
    foward();
  }
  else if (IR_R==LOW&&IR_L==HIGH&&IR_M==LOW){
    left();
    delay(200);
  }
  else if (IR_R==HIGH&&IR_L==LOW&&IR_M==HIGH){
    right();
    delay(200);
  }
  if (Distance_test<=40){//Ultrasonic sensor detecting objects
    foward();
  
  }
  else{
    stop();
  }
}
}
 
