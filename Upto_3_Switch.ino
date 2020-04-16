#include <EEPROM.h>                               //library for EEPROM

int SensorPin1 = PA2;
int SensorPin2 = PA4;
int SensorPin3 = PA7;

int state1 = HIGH;                                //state of the touch sensors
int state2 = HIGH; 
int state3 = HIGH;
  
int SensorData1;
int SensorData2;
int SensorData3;
   
int SensorState1 = LOW;
int SensorState2 = LOW;
int SensorState3 = LOW;

int EepromData1 = HIGH; 
int EepromData2 = HIGH; 
int EepromData3 = HIGH; 

void setup()
{
  pinMode(SensorPin1, INPUT);
  pinMode(SensorPin2, INPUT);
  pinMode(SensorPin3, INPUT);
  
  pinMode(PA6, PWM);                         //Led pins using output is PWM
  pinMode(PB0, PWM);
  pinMode(PB1, PWM);
  
  pinMode(PB12, OUTPUT);
  pinMode(PB10, OUTPUT);
  pinMode(PA5, OUTPUT);

  EepromData1 = EEPROM.read(0);             //reading the first sensor data from eeprom in Byte 0 
  delay(10);
  EepromData2 = EEPROM.read(1);             //reading the second sensor data from eeprom in Byte 1
  delay(10);
  EepromData3 = EEPROM.read(2);             //reading the third sensor data from eeprom in Byte 2
  delay(10);
  
  LS(EepromData1, EepromData2, EepromData3);                        //LightState function for relay and led turn on and turn off.
}


void loop()
{
  SensorData1 = digitalRead(SensorPin1);                           //first sensor input data 
  SensorData2 = digitalRead(SensorPin2);                           //second sensor input data
  SensorData3 = digitalRead(SensorPin3);                           //third sensor input data   


  LS(SensorData1,SensorData2,SensorData3);                         //LightState function for relay and led turn on and turn off.
}




// depends on input data relays will turn on and turn off
void LS(int input1, int input2, int input3){
  
  if (input1 == HIGH && SensorState1 == LOW) {                       //if first sensor data is HIGH and SensorState1 is LOW then Enter If condition
    
    if (state1 == HIGH){                                             //if state1 is high then relay and led will turn on
      state1 = LOW;
      pwmWrite(PB1, 65535);                                          //LED will Turn on with HIGH Brightness
      digitalWrite(PB12, HIGH);                                      //Relay will Turn on
      EEPROM.write(0, 1);                                            //Store 0 Byte in 1 value to EEPROM
      delay(10);                                                     //delay 10 ms
    }
      
    else{                                                            //if state1 is low then relay and led will turn off
      state1 = HIGH;
      pwmWrite(PB1, 3840);                                           //LED will Turn on with LOW Brightness
      digitalWrite(PB12, LOW);                                       //Relay will Turn off
      EEPROM.write(0, 0);                                            //Store 0 Byte in 0 value to EEPROM 
      delay(10);                                                     //delay 10 ms
    }    
  }
  SensorState1 = input1;                                             // first loop p1 value will change LOW to HIGH


  if (input2 == HIGH && SensorState2 == LOW) {                         
    
    if (state2 == HIGH){                                
      state2 = LOW;
      pwmWrite(PB1, 65535);
      digitalWrite(PB10, HIGH);
      EEPROM.write(1, 1);
      delay(10);
    }
      
    else{                                               
      state2 = HIGH; 
      pwmWrite(PB1, 3840);
      digitalWrite(PB10, LOW);
      EEPROM.write(1, 0);
      delay(10); 
    }    
  }
   SensorState2 = input2;                                              

                            
  if (input3 == HIGH && SensorState3 == LOW) {                    
    
    if (state3 == HIGH){                           
      state3 = LOW;
      pwmWrite(PB1, 65535);
      digitalWrite(PA5, HIGH);
      EEPROM.write(2, 1);
      delay(10);
    }
      
    else{                                          
      state3 = HIGH; 
      pwmWrite(PB1, 3840);
      digitalWrite(PA5, LOW);
      EEPROM.write(2, 0); 
      delay(10);
    }    
  } 
  SensorState3 = input3;                                         
}
