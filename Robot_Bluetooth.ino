
#include <VarSpeedServo.h>



#include <SoftwareSerial.h>

String Data;

VarSpeedServo S1;


//MOTORES

const int fl1 = 22;
const int fl2 = 24;
const int bl1 = 23;
const int bl2 = 25;
const int fr1 = 26;
const int fr2 = 28;
const int br1 = 27;
const int br2 = 29;

//LEDS

const int ledB1 = 52;
const int ledB2 = 53;
const int ledR1 = 50;
const int ledR2 = 51;
const int ledA1 = 48;
const int ledA2 = 49;
const int ledV1 = 46;
const int ledV2 = 47;

//BUZZER

const int BUZZER = 11;

//ULTRASONIDO

const int TRIGGER = 9;
const int ECHO = 8;
unsigned int tiempo, distancia;

void setup() {


Serial.begin(9600);

S1.attach(12);

pinMode(fl1, OUTPUT);
pinMode(fl2, OUTPUT);
pinMode(bl1, OUTPUT);
pinMode(bl2, OUTPUT);
pinMode(fr1, OUTPUT);
pinMode(fr2, OUTPUT);
pinMode(br1, OUTPUT);
pinMode(br2, OUTPUT);
pinMode(ledB1, OUTPUT);
pinMode(ledB2, OUTPUT);
pinMode(ledR1, OUTPUT);
pinMode(ledR2, OUTPUT);
pinMode(ledA1, OUTPUT);
pinMode(ledA2, OUTPUT);
pinMode(ledV1, OUTPUT);
pinMode(ledV2, OUTPUT);
pinMode(BUZZER, OUTPUT);
pinMode(TRIGGER, OUTPUT);
pinMode(ECHO, INPUT);

digitalWrite(TRIGGER, LOW);

digitalWrite(fl1, LOW);
digitalWrite(fl2, LOW);
digitalWrite(bl1, LOW);
digitalWrite(bl2, LOW);
digitalWrite(fr1, LOW);
digitalWrite(fr2, LOW);
digitalWrite(br1, LOW);
digitalWrite(br2, LOW);

S1.write(90, 20);
}

void loop() {

if (Serial.available()){
  
Data = Serial.read();

if(Data == "1"){
  
 adelante();
  
  }
  
  if(Data == "2"){
  
 izq();
  
  }
  
  if(Data == "3"){
  
 parar();
  
  }
  
  if(Data == "4"){
  
 der();
  
  }
  
  if(Data == "5"){
  
 atras();
  
  }
  
  if(Data == "6"){
  
 digitalWrite(ledB1, HIGH);
 digitalWrite(ledB2, HIGH);

  }

  if(Data == "7"){

    tone(BUZZER, 472);
    delay(100);
    noTone(BUZZER);
    
    }
  
  if(Data == "8"){
  
 digitalWrite(ledB1, LOW);
 digitalWrite(ledB2, LOW);
  
  }
  
  if(Data == "9"){
  
 digitalWrite(ledR1, HIGH);
 digitalWrite(ledR2, HIGH);
 delay(100);
 
 digitalWrite(ledR1, LOW);
 digitalWrite(ledR2, LOW);
 digitalWrite(ledA1, HIGH);
 digitalWrite(ledA2, HIGH);
 delay(100);
 
 digitalWrite(ledA1, LOW);
 digitalWrite(ledA2, LOW);
 digitalWrite(ledV1, HIGH);
 digitalWrite(ledV2, HIGH);
 delay(100);

 digitalWrite(ledV1, LOW);
 digitalWrite(ledV2, LOW);
  
  }

  if(Data == "10"){
    
    digitalWrite(ledR1,HIGH);
    digitalWrite(ledR2,HIGH);
    digitalWrite(ledA1,HIGH);
    digitalWrite(ledA2,HIGH);
    digitalWrite(ledV1,HIGH);
    digitalWrite(ledV2,HIGH);
    delay(100);
    
    digitalWrite(ledR1,LOW);
    digitalWrite(ledR2,LOW);
    digitalWrite(ledA1,LOW);
    digitalWrite(ledA2,LOW);
    digitalWrite(ledV1,LOW);
    digitalWrite(ledV2,LOW);
    delay(100);
    
    digitalWrite(ledR1,HIGH);
    digitalWrite(ledR2,HIGH);
    digitalWrite(ledA1,HIGH);
    digitalWrite(ledA2,HIGH);
    digitalWrite(ledV1,HIGH);
    digitalWrite(ledV2,HIGH);
    delay(100);
    
    digitalWrite(ledR1,LOW);
    digitalWrite(ledR2,LOW);
    digitalWrite(ledA1,LOW);
    digitalWrite(ledA2,LOW);
    digitalWrite(ledV1,LOW);
    digitalWrite(ledV2,LOW);
    delay(100);
    
    digitalWrite(ledR1,HIGH);
    digitalWrite(ledR2,HIGH);
    digitalWrite(ledA1,HIGH);
    digitalWrite(ledA2,HIGH);
    digitalWrite(ledV1,HIGH);
    digitalWrite(ledV2,HIGH);
    delay(100);
    
    digitalWrite(ledR1,LOW);
    digitalWrite(ledR2,LOW);
    digitalWrite(ledA1,LOW);
    digitalWrite(ledA2,LOW);
    digitalWrite(ledV1,LOW);
    digitalWrite(ledV2,LOW);
    
    
    }

    if(Data == "30"){
      
      S1.write(30, 20);
      
      }

    if(Data == "45"){
      
      S1.write(45, 20);
      
      }

    if(Data == "60"){
      
      S1.write(60, 20);
      
      }

    if(Data == "75"){
      
      S1.write(75, 20);
      
      }

    if(Data == "90"){
      
      S1.write(90, 20);
      
      }

    if(Data == "105"){
      
      S1.write(105, 20);
      
      }

    if(Data == "120"){
      
      S1.write(120, 20);
      
      }

    if(Data == "135"){
      
      S1.write(135, 20);
      
      }

    if(Data == "150"){
      
      S1.write(150, 20);
      
      }
    
    }

    digitalWrite(TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER, LOW);

    tiempo = pulseIn(ECHO, HIGH);
    distancia = tiempo/58;

if(distancia <= 10){
  
    tone(BUZZER, 2);
  
  } else {
    
    noTone(BUZZER);
    
    }

}

void adelante()
{
  
  digitalWrite(fl1, HIGH);
  digitalWrite(fl2, LOW);
  digitalWrite(bl1, HIGH);
  digitalWrite(bl2, LOW);
  digitalWrite(fr1, HIGH);
  digitalWrite(fr2, LOW);
  digitalWrite(br1, HIGH);
  digitalWrite(br2, LOW);

  }

void atras()
{
  
  digitalWrite(fl1, LOW);
  digitalWrite(fl2, HIGH);
  digitalWrite(bl1, LOW);
  digitalWrite(bl2, HIGH);
  digitalWrite(fr1, LOW);
  digitalWrite(fr2, HIGH);
  digitalWrite(br1, LOW);
  digitalWrite(br2, HIGH);

  }

void izq()
{
  
  digitalWrite(fl1, LOW);
  digitalWrite(fl2, HIGH);
  digitalWrite(bl1, LOW);
  digitalWrite(bl2, HIGH);
  digitalWrite(fr1, HIGH);
  digitalWrite(fr2, LOW);
  digitalWrite(br1, HIGH);
  digitalWrite(br2, LOW);

  }

void der()
{
  
  digitalWrite(fl1, HIGH);
  digitalWrite(fl2, LOW);
  digitalWrite(bl1, HIGH);
  digitalWrite(bl2, LOW);
  digitalWrite(fr1, LOW);
  digitalWrite(fr2, HIGH);
  digitalWrite(br1, LOW);
  digitalWrite(br2, HIGH);
  }

void parar()
{
  
  digitalWrite(fl1, LOW);
  digitalWrite(fl2, LOW);
  digitalWrite(bl1, LOW);
  digitalWrite(bl2, LOW);
  digitalWrite(fr1, LOW);
  digitalWrite(fr2, LOW);
  digitalWrite(br1, LOW);
  digitalWrite(br2, LOW);

  }
