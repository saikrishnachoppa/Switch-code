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
  LS(ledState1, ledState2, ledState3);
}


void loop()
{
  r1 = digitalRead(in1);                           //first sensor input data 
  r2 = digitalRead(in2);                           //second sensor input data
  r3 = digitalRead(in3);                           //third sensor input data
  LS(r1,r2,r3);
}




void LS(int r11, int r21, int r31){
  if (r11 == HIGH && p1 == LOW) {                       //if first sensor data is HIGH and p1 is LOW then Enter IF condition
    
    if (state1 == HIGH){                               //if state1 is high then relay and led will turn on
      state1 = LOW;
      pwmWrite(PB1, 65535);
      digitalWrite(PB12, HIGH);
      EEPROM.write(0, 1);
      delay(10);
    }
      
    else{                                              //if state1 is low then relay and led will turn off
      state1 = HIGH;
      pwmWrite(PB1, 3840);
      digitalWrite(PB12, LOW);
      EEPROM.write(0, 0); 
      delay(10); 
    }    
  }
  p1 = r11;                                            // first loop p1 value will change LOW to HIGH


  if (r21 == HIGH && p2 == LOW) {                        //if second sensor data is HIGH and p2 is LOW then relay will turn on and also led will turn on
    
    if (state2 == HIGH){                                //if state2 is high then relay and led will turn on
      state2 = LOW;
      pwmWrite(PB1, 65535);
      digitalWrite(PB10, HIGH);
      EEPROM.write(1, 1);
      delay(10);
    }
      
    else{                                               //if state2 is low then relay and led will turn off
      state2 = HIGH; 
      pwmWrite(PB1, 3840);
      digitalWrite(PB10, LOW);
      EEPROM.write(1, 0);
      delay(10); 
    }    
  }
  p2 = r21;                                              // first loop p2 value will change LOW to HIGH

                            
  if (r31 == HIGH && p3 == LOW) {                   //if third sensor data is HIGH and p3 is low then relay will turn on and also led will turn on
    
    if (state3 == HIGH){                           //if state3 is high then relay and led will turn on
      state3 = LOW;
      pwmWrite(PB1, 65535);
      digitalWrite(PA5, HIGH);
      EEPROM.write(2, 1);
      delay(10);
    }
      
    else{                                          //if state3 is low then relay and led will turn off
      state3 = HIGH; 
      pwmWrite(PB1, 3840);
      digitalWrite(PA5, LOW);
      EEPROM.write(2, 0); 
      delay(10);
    }    
  } 
  p3 = r31;                                         // first loop p3 value will change LOW to HIGH
}
