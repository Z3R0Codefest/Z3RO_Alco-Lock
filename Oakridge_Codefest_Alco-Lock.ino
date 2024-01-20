#define carspeed 100
#define ENA 5
#define ENB 6
#define M1 7
#define M2 8
#define M3 9
#define M4 11
#define IR_L !digitalRead(10)
#define IR_M !digitalRead(4)
#define IR_R !digitalRead(2)

void setup() {
  // put your setup code here, to run once:
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

void foward(){
 Serial.println("foward");
 analogWrite(ENA,carspeed);
 analogWrite(ENB,carspeed);
 digitalWrite(M1,LOW);
 digitalWrite(M2,HIGH);
 digitalWrite(M3,HIGH);
 digitalWrite(M4,LOW);
}
void back(){
 Serial.println("back");
 analogWrite(ENA,carspeed);
 analogWrite(ENB,carspeed);
 digitalWrite(M1,HIGH);
 digitalWrite(M2,LOW);
 digitalWrite(M3,LOW);
 digitalWrite(M4,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

}
