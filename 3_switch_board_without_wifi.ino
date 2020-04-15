#include <EEPROM.h>

int in1 = PA2;                          //touch sensor pins
int in2 = PA4;
int in3 = PA7;

int state1 = HIGH;                       //state of the touch sensors
int state2 = HIGH; 
int state3 = HIGH;
  
int r1;                                  //this are storing the touch sensor output data
int r2;
int r3;
   
int p1 = LOW;
int p2 = LOW;
int p3 = LOW;

int ledState1 = HIGH; 
int ledState2 = HIGH; 
int ledState3 = HIGH; 

void setup()
{
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(in3, INPUT);
  
  pinMode(PA6, PWM);                    //Led pins using output is PWM
  pinMode(PB0, PWM);
  pinMode(PB1, PWM);
  
  pinMode(PB12, OUTPUT);
  pinMode(PB10, OUTPUT);
  pinMode(PA5, OUTPUT);

  ledState1 = EEPROM.read(0);             //reading the first sensor data from eeprom 
  delay(10);
  ledState2 = EEPROM.read(1);             //reading the second sensor data from eeprom 
  delay(10);
  ledState3 = EEPROM.read(2);             //reading the third sensor data from eeprom 
  delay(10);
  
  
  if (ledState1 == LOW){                  //if first sensor data from eeprom is low relay will turn on and also led will turn on
    pwmWrite(PB1, 65535);
    digitalWrite(PB12, HIGH);
    delay(10);
  }
  else
  {
    pwmWrite(PB1, 3840);                  //if first sensor data from eeprom is High relay will turn off and also led will turn off( Littel brightness)
    digitalWrite(PB12, LOW); 
    delay(10);
  }

  
  if (ledState2 == LOW){                  //if second sensor data from eeprom is low relay will turn on and also led will turn on
    pwmWrite(PB1, 65535);
    digitalWrite(PB10, HIGH);
    delay(10);
  }
  else                                     //if second sensor data from eeprom is High relay will turn off and also led will turn off( Littel brightness)
  {
    pwmWrite(PB1, 3840);
    digitalWrite(PB10, LOW); 
    delay(10);
  }


  if (ledState3 == LOW){                   //if third sensor data from eeprom is low relay will turn on and also led will turn on
    pwmWrite(PB1, 65535);
    digitalWrite(PA5, HIGH);
    delay(10);
  }
  else                                    //if third sensor data from eeprom is High relay will turn off and also led will turn off( Littel brightness)
  {
    pwmWrite(PB1, 3840);
    digitalWrite(PA5, LOW);
    delay(10);
  }
}


void loop()
{
  r1 = digitalRead(in1);                               //first sensor input data 
  if (r1 == HIGH && p1 == LOW) {                       //if first sensor data is HIGH and p1 is LOW then Enter IF condition
    
    if (state1 == HIGH){                               //if state1 is high then relay and led will turn on
      state1 = LOW;
      pwmWrite(PB1, 65535);
      digitalWrite(PB12, HIGH);
      EEPROM.write(0, state1);
      delay(10);
    }
      
    else{                                              //if state1 is low then relay and led will turn off
      state1 = HIGH;
      pwmWrite(PB1, 3840);
      digitalWrite(PB12, LOW);
      EEPROM.write(0, state1); 
      delay(10); 
    }    
  }
  p1 = r1;                                            // first loop p1 value will change LOW to HIGH


  
  r2 = digitalRead(in2);                                //second sensor input data
  if (r2 == HIGH && p2 == LOW) {                        //if second sensor data is HIGH and p2 is LOW then relay will turn on and also led will turn on
    
    if (state2 == HIGH){                                //if state2 is high then relay and led will turn on
      state2 = LOW;
      pwmWrite(PB1, 65535);
      digitalWrite(PB10, HIGH);
      EEPROM.write(1, state2);
      delay(10);
    }
      
    else{                                               //if state2 is low then relay and led will turn off
      state2 = HIGH; 
      pwmWrite(PB1, 3840);
      digitalWrite(PB10, LOW);
      EEPROM.write(1, state2);
      delay(10); 
    }    
  }
  p2 = r2;                                              // first loop p2 value will change LOW to HIGH


  r3 = digitalRead(in3);                           //third sensor input data                            
  if (r3 == HIGH && p3 == LOW) {                   //if third sensor data is HIGH and p3 is low then relay will turn on and also led will turn on
    
    if (state3 == HIGH){                           //if state3 is high then relay and led will turn on
      state3 = LOW;
      pwmWrite(PB1, 65535);
      digitalWrite(PA5, HIGH);
      EEPROM.write(2, state3);
      delay(10);
    }
      
    else{                                          //if state3 is low then relay and led will turn off
      state3 = HIGH; 
      pwmWrite(PB1, 3840);
      digitalWrite(PA5, LOW);
      EEPROM.write(2, state3); 
      delay(10);
    }    
  } 
  p3 = r3;                                         // first loop p3 value will change LOW to HIGH
}
