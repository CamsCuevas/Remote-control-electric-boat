#include <SoftwareSerial.h>   
SoftwareSerial BT(10,11);    

#define IN1A 3
#define IN1B 5
#define IN2A 6
#define IN2B 9

char tecla1;
char tecla2;

int fixed_speed = 180;
 
void setup() {
 
  pinMode(IN1A, OUTPUT);
  pinMode(IN1B, OUTPUT);
  pinMode(IN2A, OUTPUT);
  pinMode(IN2B, OUTPUT);

  Serial.begin(9600);
  BT.begin(9600);      
}
 
void loop() {
  if(Serial.available())
  {
    tecla1 = Serial.read();
    tecla2=tecla1;
    Serial.println(tecla1);
  }

  if(BT.available())   
  {
    tecla2 = BT.read();
    tecla1=tecla2;
    Serial.println(tecla2);
  }

  if((tecla1 == 'a')||(tecla2 == 'a')) {
  Serial.println("adelante");
  analogWrite(IN1A, fixed_speed);
  analogWrite(IN2A, 0);
  analogWrite(IN1B, fixed_speed);
  analogWrite(IN2B, 0);
  }

  else if((tecla1 == 'd')||(tecla2 == 'd')){
  Serial.println("derecha");
  analogWrite(IN1A, 0);
  analogWrite(IN2A, 0);
  analogWrite(IN1B, fixed_speed);
  analogWrite(IN2B, 0);
  }
 
  else if((tecla1 == 'i')||(tecla2 == 'i')){
  Serial.println("izquierda");
  analogWrite(IN1A, fixed_speed);
  analogWrite(IN2A, 0);
  analogWrite(IN1B, 0);
  analogWrite(IN2B, 0);
  }

  else if ((tecla1 =='0') || (tecla2 == '0')) {
  Serial.println("stop");
  analogWrite(IN1A, 0);
  analogWrite(IN1B, 0);
  analogWrite(IN2A, 0);
  analogWrite(IN2B, 0);
  }
  else if ((tecla1 =='+') || (tecla2 == '+')) {
  fixed_speed = fixed_speed + 10;
  Serial.println("fixed_speed");
    if (fixed_speed >= 255)
    {
      fixed_speed = 255;
    }
  }
  else if ((tecla1 =='-') || (tecla2 == '-')) {
  fixed_speed = fixed_speed - 10;
  Serial.println("fixed_speed");
    if (fixed_speed <= 0)
    {
      fixed_speed = 0;
    }
  }
}