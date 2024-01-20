#include <IRremote.h>
IRrecv IR(12);
#define carspeed 125 // speed for moving forward/back
#define turningcarspeed 150 // speed for moving left/right 
#define stopcarspeed 0
#define ENA 5
#define ENB 6
#define M1 7
#define M2 8
#define M3 9
#define M4 11
#define IR_R !digitalRead(10) //IR right Sensor
#define IR_M !digitalRead(4) //IR middle Sensor
#define IR_L !digitalRead(2) //IR left Sensor
int Echo = A4;  // reciever for Ultrasonic 
int Trig = A5; //trigger for Ultrasonic
long duration, inches; // Used to define & store variables

void setup() {
 IR.enableIRIn();
 pinMode(Echo,INPUT);
 pinMode(Trig,OUTPUT);
 pinMode(10,INPUT);//IR sensor right
 pinMode(4,INPUT);//IR sensor middle
 pinMode(2,INPUT);//IR sensor left
 pinMode(M1,OUTPUT);
 pinMode(M2,OUTPUT);
 pinMode(M3,OUTPUT);
 pinMode(M4,OUTPUT);
 pinMode(ENA,OUTPUT);
 pinMode(ENB,OUTPUT);
 Serial.begin(9600);
}

void foward(){//function for going forwards
 Serial.println("foward");
 analogWrite(ENA,carspeed);
 analogWrite(ENB,carspeed);
 digitalWrite(M1,HIGH);
 digitalWrite(M2,LOW);
 digitalWrite(M3,LOW);
 digitalWrite(M4,HIGH);
 delay(400);
}
void back(){//function for going backwards
 Serial.println("back");
 analogWrite(ENA,carspeed);
 analogWrite(ENB,carspeed);
 digitalWrite(M1,LOW);
 digitalWrite(M2,HIGH);
 digitalWrite(M3,HIGH);
 digitalWrite(M4,LOW);
 delay(200);
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
  digitalWrite(ENA,stopcarspeed);
  digitalWrite(ENB,stopcarspeed);
  digitalWrite(M1,LOW);
  digitalWrite(M2,LOW);
  digitalWrite(M3,LOW);
  digitalWrite(M4,LOW);
  Serial.println("Stop");
  
}
void stpright(){
  digitalWrite(ENA,turningcarspeed);
  digitalWrite(ENB,turningcarspeed);
  digitalWrite(M1,HIGH);
  digitalWrite(M2,LOW);
  digitalWrite(M3,LOW);
  digitalWrite(M4,LOW);
  Serial.println("StpRight");
}
void stpleft(){
  digitalWrite(ENA,turningcarspeed);
  digitalWrite(ENB,turningcarspeed);
  digitalWrite(M1,LOW);
  digitalWrite(M2,LOW);
  digitalWrite(M3,LOW);
  digitalWrite(M4,HIGH);
  Serial.println("Stpleft");
}
void loop() {
  digitalWrite(Trig, LOW);   
  delayMicroseconds(5);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);   
  duration = pulseIn(Echo, HIGH);  //used to read ultrasonic value 
  inches = (duration/2) / 74; 
  Serial.print("inches ");
  Serial. println(inches);
  delay(500);

 int pol=analogRead(A0);//pollutuion sensor
 Serial.print("Pollution ");
 Serial. println(pol);
 delay(100);
 if (pol>=275){
    if(inches<=7){
      stop();
    }
    else{
      foward();
    }

  }
 else if (pol<275){
  if (IR.decode()){
    Serial.println(IR.decodedIRData.decodedRawData, HEX);
    if(IR.decodedIRData.decodedRawData == 0xB649FD02){
      stop();
      delay(50);
    }
    if(IR.decodedIRData.decodedRawData == 0xA25DFD02){
      foward();
      delay(50);
    }
    if(IR.decodedIRData.decodedRawData==0xA659FD02){
      back();
      delay(50);
    }
    if(IR.decodedIRData.decodedRawData == 0xF50AFD02){
      stpleft();
      delay(50);
    }
    if(IR.decodedIRData.decodedRawData == 0xB54AFD02){
      stpright();
      delay(50);
    }
    delay(1500);
    IR.resume();
  }
 }
}