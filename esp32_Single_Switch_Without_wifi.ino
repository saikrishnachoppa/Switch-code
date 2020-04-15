#include <EEPROM.h>
#define EEPROM_SIZE 3
             
int in1 = 18;
int in2 = 16;
int in3 = 22;
   
int state1 = HIGH;
int state2 = HIGH;
int state3 = HIGH;

int ledState1 = HIGH; 
int ledState2 = HIGH; 
int ledState3 = HIGH; 
 
int freq = 5000;

int ledChannel0 = 0;
int ledChannel1 = 1;
int ledChannel2 = 2;

int resolution = 8; 

int r1;
int r2;
int r3;
           
int p1 = LOW;
int p2 = LOW;
int p3 = LOW;
              
void setup()
{
  EEPROM.begin(EEPROM_SIZE);
  
  ledcSetup(ledChannel0, freq, resolution);
  ledcSetup(ledChannel1, freq, resolution);
  ledcSetup(ledChannel2, freq, resolution); 
  
  ledcAttachPin(25, ledChannel0);
  ledcAttachPin(26, ledChannel1);
  ledcAttachPin(27, ledChannel2);
  
  pinMode(19, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(23, OUTPUT);
  
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(in3, INPUT);
  
  ledState1 = EEPROM.read(0);
  ledState2 = EEPROM.read(1);
  ledState3 = EEPROM.read(2);
  
  if (ledState1 == LOW){
    ledcWrite(ledChannel0, 250);
    digitalWrite(19, ledState1);
  }
  else
  {
   ledcWrite(ledChannel0, 50);
   digitalWrite(19, ledState1); 
  }


  if (ledState2 == LOW){
    ledcWrite(ledChannel1, 250);
    digitalWrite(17, ledState2);
  }
  else
  {
   ledcWrite(ledChannel1, 50);
   digitalWrite(17, ledState2); 
  }


  if (ledState3 == LOW){
    ledcWrite(ledChannel2, 250);
    digitalWrite(23, ledState3);
  }
  else
  {
   ledcWrite(ledChannel2, 50);
   digitalWrite(23, ledState3); 
  }
  
}
void loop()
{
  
  r1 = digitalRead(in1);
  if (r1 == HIGH && p1 == LOW) {
    if (state1 == HIGH){
      digitalWrite(19, LOW);
      state1 = LOW;
      ledcWrite(ledChannel0, 250);
      EEPROM.write(0, state1);
      EEPROM.commit();
      delay(10); 
    }
    else {
      digitalWrite(19, HIGH);
      state1 = HIGH;
      ledcWrite(ledChannel0, 50);
      EEPROM.write(0, state1);
      EEPROM.commit();
      delay(10); 
      }    
  }
  p1 = r1;



  r2 = digitalRead(in2);
  if (r2 == HIGH && p2 == LOW) {
    if (state1 == HIGH){
      digitalWrite(17, LOW);
      state2 = LOW;
      ledcWrite(ledChannel1, 250);
      EEPROM.write(1, state2);
      EEPROM.commit();
      delay(10); 
    }
    else {
      digitalWrite(17, HIGH);
      state2 = HIGH;
      ledcWrite(ledChannel1, 50);
      EEPROM.write(1, state2);
      EEPROM.commit();
      delay(10); 
      }    
  }
  p2 = r2;



  r3 = digitalRead(in3);
  if (r3 == HIGH && p3 == LOW) {
    if (state3 == HIGH){
      digitalWrite(23, LOW);
      state3 = LOW;
      ledcWrite(ledChannel2, 250);
      EEPROM.write(2, state3);
      EEPROM.commit();
      delay(10); 
    }
    else {
      digitalWrite(23, HIGH);
      state3 = HIGH;
      ledcWrite(ledChannel2, 50);
      EEPROM.write(2, state3);
      EEPROM.commit();
      delay(10); 
      }    
  }
  p3 = r3;
}
