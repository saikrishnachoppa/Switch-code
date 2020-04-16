#include <EEPROM.h>                    //library for EEPROM
int SensorPin1 = PA1;
int SensorPin2 = PA2;
int SensorPin3 = PA4;
int SensorPin4 = PA7;
int SensorPin5 = PB11;
int SensorPin6 = PA15;
int SensorPin7 = PA11;
int SensorPin8 = PB15;
int SensorPin9 = PB13;

String incomingByte;
char *strings[10];
char *ptr = NULL;
String AppData0,AppData1,AppData2,AppData3,AppData4,AppData5,AppData6,AppData7,AppData8;  

int state1 = HIGH; 
int state2 = HIGH; 
int state3 = HIGH;
int state4 = HIGH;
int state5 = HIGH;
int state6 = HIGH;
int state7 = HIGH;
int state8 = HIGH;
int state9 = HIGH;
  

int SensorData1;
int SensorData2;
int SensorData3;
int SensorData4;
int SensorData5;
int SensorData6;
int SensorData7;
int SensorData8;
int SensorData9;
   
        
int SensorState1 = LOW;
int SensorState2 = LOW;
int SensorState3 = LOW;
int SensorState4 = LOW;
int SensorState5 = LOW;
int SensorState6 = LOW;
int SensorState7 = LOW;
int SensorState8 = LOW;
int SensorState9 = LOW;


int EepromData1 = HIGH; 
int EepromData2 = HIGH; 
int EepromData3 = HIGH; 
int EepromData4 = HIGH; 
int EepromData5 = HIGH; 
int EepromData6 = HIGH; 
int EepromData7 = HIGH; 
int EepromData8 = HIGH; 
int EepromData9 = HIGH;  
   
void setup()
{
  Serial.begin(9600);
  pinMode(SensorPin1, INPUT);
  pinMode(SensorPin2, INPUT);
  pinMode(SensorPin3, INPUT);
  pinMode(SensorPin4, INPUT);
  pinMode(SensorPin5, INPUT);
  pinMode(SensorPin6, INPUT);
  pinMode(SensorPin7, INPUT);
  pinMode(SensorPin8, INPUT);
  pinMode(SensorPin9, INPUT);
  

  
  pinMode(PA3, PWM);
  pinMode(PA6, PWM);
  pinMode(PB0, PWM);
  pinMode(PB1, PWM);
  pinMode(PA0, PWM);
  pinMode(PB9, PWM);
  pinMode(PB7, PWM);
  pinMode(PB8, PWM);
  pinMode(PB6, PWM);
  pinMode(PA8, PWM);
  
  
  pinMode(PB12, OUTPUT);
  pinMode(PB10, OUTPUT);
  pinMode(PA5, OUTPUT);
  pinMode(PC13, OUTPUT);
  pinMode(PB14, OUTPUT);
  pinMode(PB5, OUTPUT);
  pinMode(PA12, OUTPUT);



  EepromData1 = EEPROM.read(0);             //reading the first sensor data from eeprom in Byte 0 
  delay(10);
  EepromData2 = EEPROM.read(1);             //reading the second sensor data from eeprom in Byte 1
  delay(10);
  EepromData3 = EEPROM.read(2);             //reading the third sensor data from eeprom in Byte 2
  delay(10);
  EepromData4 = EEPROM.read(3);             //reading the fourth sensor data from eeprom in Byte 3             
  delay(10);
  EepromData5 = EEPROM.read(4);             //reading the fifth sensor data from eeprom in Byte 4             
  delay(10);
  EepromData6 = EEPROM.read(5);             //reading the sixth sensor data from eeprom in Byte 5            
  delay(10);
  EepromData7 = EEPROM.read(6);             //reading the seventh sensor data from eeprom in Byte 6            
  delay(10);
  EepromData8 = EEPROM.read(7);             //reading the eighth sensor data from eeprom in Byte 7          
  delay(10);
  EepromData9 = EEPROM.read(8);             //reading the ninth sensor data from eeprom in Byte 8            
  delay(10);
  
  LS(EepromData1, EepromData2, EepromData3, EepromData4, EepromData5, EepromData6, EepromData7, EepromData8, lEepromData9);                  //LightState function for relay and led turn on and turn off.


void loop()
{
    if(Serial.available() > 0)
  {
    incomingByte = Serial.readStringUntil('\n');               //Get the Data From Esp32 
    Serial.println(incomingByte);
    int str_len = incomingByte.length() + 1;
    char char_array[str_len];
    incomingByte.toCharArray(char_array, str_len);
    byte index = 0;
    ptr = strtok(char_array, ",");
    while (ptr != NULL)                                        //this loop while divide the string and store in Strings array.
    {
      strings[index] = ptr;
      index++;
      ptr = strtok(NULL, ",");
    }
    AppData0 = strings[0];                                    //first Switch Data From App
    AppData1 = strings[1];                                    //Second Switch Data From App
    AppData2 = strings[2];                                    //third Switch Data From App 
    AppData3 = strings[3];                                    //fourth Switch Data From App
    AppData4 = strings[4];                                    //fifth Switch Data From App
    AppData5 = strings[5];                                    //sixth Switch Data From App
    AppData6 = strings[6];                                    //seventh Switch Data From App
    AppData7 = strings[7];                                    //eighth Switch Data From App
    AppData8 = strings[8];                                    //ninth Switch Data From App
    

    LS(AppData0.toInt(), AppData1.toInt(), AppData2.toInt(), AppData3.toInt(), AppData4.toInt(), AppData5.toInt(), AppData6.toInt(), AppData7.toInt(), AppData8.toInt());
  
  }

  SensorData1 = digitalRead(SensorPin1);                           //first sensor input data 
  SensorData2 = digitalRead(SensorPin2);                           //second sensor input data
  SensorData3 = digitalRead(SensorPin3);                           //third sensor input data
  SensorData4 = digitalRead(SensorPin4);                           //fourth sensor input data 
  SensorData5 = digitalRead(SensorPin5);                           //fifth sensor input data
  SensorData6 = digitalRead(SensorPin6);                           //sixth sensor input data
  SensorData7 = digitalRead(SensorPin7);                           //seventh sensor input data 
  SensorData8 = digitalRead(SensorPin8);                           //eighth sensor input data
  SensorData9 = digitalRead(SensorPin9);                           //ninth sensor input data    


  LS(SensorData1,SensorData2,SensorData3,SensorData4,SensorData5,SensorData6,SensorData7,SensorData8,SensorData9);                   //LightState function for relay and led turn on and turn off.

}


// depends on input data relays will turn on and turn off
void LS(int input1, int input2, int input3, int input4, int input5, int input6, int input7, int input8, int input9){
  
  if (input1 == HIGH && SensorState1 == LOW) {                       //if first sensor data is HIGH and SensorState1 is LOW then Enter If condition
    
    if (state1 == HIGH){                                             //if state1 is high then relay and led will turn on
      state1 = LOW;
      pwmWrite(PA3, 65535);                                          //LED will Turn on with HIGH Brightness
      digitalWrite(PB12, HIGH);                                      //Relay will Turn on
      EEPROM.write(0, 1);                                            //Store 0 Byte in 1 value to EEPROM
      delay(10);                                                     //delay 10 ms
    }
      
    else{                                                            //if state1 is low then relay and led will turn off
      state1 = HIGH;
      pwmWrite(PA3, 3840);                                           //LED will Turn on with LOW Brightness
      digitalWrite(PB12, LOW);                                       //Relay will Turn off
      EEPROM.write(0, 0);                                            //Store 0 Byte in 0 value to EEPROM
      delay(10);                                                     //delay 10 ms
    }    
  }
  SensorState1 = input1;                                            // first loop sensorState1 value will change LOW to HIGH


  if (input2 == HIGH && SensorState2 == LOW) {                        
    
    if (state2 == HIGH){                                
      state2 = LOW;
      pwmWrite(PA6, 65535);
      digitalWrite(PB10, HIGH);
      EEPROM.write(1, 1);
      delay(10);
    }
      
    else{                                              
      state2 = HIGH; 
      pwmWrite(PA6, 3840);
      digitalWrite(PB10, LOW);
      EEPROM.write(1, 0);
      delay(10); 
    }    
  }
  SensorState2 = input2;                                              

                             
  if (input3 == HIGH && SensorState3 == LOW) {                   
    
    if (state3 == HIGH){                           
      state3 = LOW;
      pwmWrite(PB0, 65535);
      digitalWrite(PA5, HIGH);
      EEPROM.write(2, 1);
      delay(10);
    }
      
    else{                                          
      state3 = HIGH; 
      pwmWrite(PB0, 3840);
      digitalWrite(PA5, LOW);
      EEPROM.write(2, 0); 
      delay(10);
    }    
  } 
  SensorState3 = input3;                                         


                                                      
  if (input4 == HIGH && SensorState4 == LOW) {                   
    
    if (state4 == HIGH){                           
      state4 = LOW;
      pwmWrite(PB1, 65535);
      digitalWrite(PC13, HIGH);
      EEPROM.write(3, 1);
      delay(10);
    }
      
    else{                                          
      state4 = HIGH; 
      pwmWrite(PB1, 3840);
      digitalWrite(PC13, LOW);
      EEPROM.write(3, 0); 
      delay(10);
    }    
  } 
  SensorState4 = input4;

                                                      
  if (input5 == HIGH && SensorState5 == LOW) {                   
    
    if (state5 == HIGH){                           
      state5 = LOW;
      pwmWrite(PA0, 65535);
      pwmWrite(PB9, 65535);
      EEPROM.write(4, 1);
      delay(10);
    }
      
    else{
      state5 = HIGH; 
      pwmWrite(PA8, 3840);
      pwmWrite(PB6, 3840);
      pwmWrite(PB8, 3840);
      pwmWrite(PB7, 3840);
      pwmWrite(PB9, 3840);
      pwmWrite(PA0, 3840);
      digitalWrite(PB14, LOW);
      digitalWrite(PB5, LOW);
      digitalWrite(PA12, LOW);
      EEPROM.write(4, 0); 
      delay(10);
    }    
  } 
 SensorState5 = input5;


                                                      
  if (input6 == HIGH && SensorState6 == LOW) {                   
    
    if (state6 == HIGH && state5 == LOW){                           
      state6 = LOW;
      pwmWrite(PA0, 65535);
      pwmWrite(PB9, 65535);
      pwmWrite(PB7, 65535);
      digitalWrite(PB14, HIGH);
      digitalWrite(PB5, LOW);
      digitalWrite(PA12, LOW);
      EEPROM.write(5, 1);
      delay(10);
    }
      
    else{                                          
      state6 = HIGH; 
      pwmWrite(PA8, 3840);
      pwmWrite(PB6, 3840);
      pwmWrite(PB8, 3840);
      pwmWrite(PB7, 3840);
      digitalWrite(PB14, HIGH);
      digitalWrite(PB5, LOW);
      digitalWrite(PA12, LOW);
      EEPROM.write(5, 0); 
      delay(10);
    }    
  } 
  SensorState6 = input6;



                                                      
  if (input7 == HIGH && SensorState7 == LOW) {                   
    
    if (state7 == HIGH && state5 == LOW){                           
      state7 = LOW;
      pwmWrite(PA0, 65535);
      pwmWrite(PB9, 65535);
      pwmWrite(PB7, 65535);
      pwmWrite(PB8, 65535);
      digitalWrite(PB14, LOW);
      digitalWrite(PB5, HIGH);
      digitalWrite(PA12, LOW);
      EEPROM.write(6, 1);
      delay(10);
    }
      
    else{                                          
      state7 = HIGH; 
      pwmWrite(PA8, 3840);
      pwmWrite(PB6, 3840);
      pwmWrite(PB8, 3840);
      digitalWrite(PB14, LOW);
      digitalWrite(PB5, HIGH);
      digitalWrite(PA12, LOW);
      EEPROM.write(6,0); 
      delay(10);
    }    
  } 
  SensorState7 = input7;



                                                    
  if (input8 == HIGH && SensorState8 == LOW) {                   
    
    if (state8 == HIGH && state5 == LOW){
      state8 = LOW;
      pwmWrite(PA0, 65535);
      pwmWrite(PB9, 65535);
      pwmWrite(PB7, 65535);
      pwmWrite(PB8, 65535);
      pwmWrite(PB6, 65535);
      digitalWrite(PB14, HIGH);
      digitalWrite(PB5, HIGH);
      digitalWrite(PA12, LOW);
      EEPROM.write(7, 1);
      delay(10);
    }
      
    else{                                          
      state8 = HIGH; 
      pwmWrite(PA8, 3840);
      pwmWrite(PB6, 3840);
      digitalWrite(PB14, HIGH);
      digitalWrite(PB5, HIGH);
      digitalWrite(PA12, LOW);
      EEPROM.write(7,0); 
      delay(10);
    }    
  } 
  SensorState8 = input8;




                                                      
  if (input9 == HIGH && SensorState9 == LOW) {                   
    
    if (state9 == HIGH && state5 == LOW){                           
      state9 = LOW;
      pwmWrite(PA0, 65535);
      pwmWrite(PB9, 65535);
      pwmWrite(PB7, 65535);
      pwmWrite(PB8, 65535);
      pwmWrite(PB6, 65535);
      pwmWrite(PA8, 65535);
      digitalWrite(PB14, LOW);
      digitalWrite(PB5, LOW);
      digitalWrite(PA12, HIGH);
      EEPROM.write(8, 1);
      delay(10);
    }
      
    else{                                          
      state9 = HIGH; 
      pwmWrite(PA8, 3840);
      digitalWrite(PB14, LOW);
      digitalWrite(PB5, LOW);
      digitalWrite(PA12, HIGH);
      EEPROM.write(8,0); 
      delay(10);
    }    
  } 
  SensorState9 = input9;
}
