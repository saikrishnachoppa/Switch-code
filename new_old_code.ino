#include<EEPROM.h>

int in1 = PA4;
int in2 = PB0;
int in3 = PB9;
int in4 = PB5;
int in5 = PB11;
int in6 = PA8;
int in9 = PA15;

String incomingByte;
char *strings[10];
char *ptr = NULL;
String u0,u1,u2,u3,u4,u5,u8;
int FI=0,FD=9;

int state1 = HIGH; 
int state2 = HIGH; 
int state3 = HIGH;
int state4 = HIGH;
int state5 = HIGH;
int state6 = HIGH;
int state9 = HIGH;
  

int r1;
int r2;
int r3;
int r4;
int r5;
int r6;
int r9;
   
        
int p1 = LOW;
int p2 = LOW;
int p3 = LOW;
int p4 = LOW;
int p5 = LOW;
int p6 = LOW;
int p9 = LOW;


int ledState1 = HIGH; 
int ledState2 = HIGH; 
int ledState3 = HIGH; 
int ledState4 = HIGH; 
int ledState5 = HIGH; 
int ledState6 = HIGH;  
int ledState9 = HIGH;  
   
void setup()
{
  Serial.begin(9600);
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(in3, INPUT);
  pinMode(in4, INPUT);
  pinMode(in5, INPUT);
  pinMode(in6, INPUT);
  pinMode(in9, INPUT);
  

  
  pinMode(PB1, OUTPUT);
  pinMode(PB10, OUTPUT);
  pinMode(PC15, OUTPUT);
  pinMode(PC14, OUTPUT);
  pinMode(PC13, OUTPUT);
  pinMode(PB8, OUTPUT);
  pinMode(PA12, OUTPUT);
  pinMode(PB15, OUTPUT);
  pinMode(PB14, OUTPUT);
  pinMode(PB13, OUTPUT);
  
  
  pinMode(PA0, OUTPUT);
  pinMode(PA1, OUTPUT);
  pinMode(PB7, OUTPUT);
  pinMode(PA5, OUTPUT);
  pinMode(PA6, OUTPUT);
  pinMode(PA7, OUTPUT);
  pinMode(PB6, OUTPUT);


  ledState1 = EEPROM.read(0);             //reading the first sensor data from eeprom 
  delay(10);
  ledState2 = EEPROM.read(1);             //reading the second sensor data from eeprom 
  delay(10);
  ledState3 = EEPROM.read(2);             //reading the third sensor data from eeprom 
  delay(10);
  ledState4 = EEPROM.read(3);              
  delay(10);
  ledState5 = EEPROM.read(4);              
  delay(10);
  ledState6 = EEPROM.read(5);             //reading the first sensor data from eeprom 
  delay(10);
  
  LS(ledState1, ledState2, ledState3, ledState4, ledState5, 0, 0);
  FI=ledState6;
  switch(FI){
  case 1:digitalWrite(PC13, HIGH);
         digitalWrite(PB8, HIGH);
         digitalWrite(PA12, HIGH);
         digitalWrite(PA6, HIGH);
         digitalWrite(PA7, LOW);
         digitalWrite(PB6, LOW);
         FD=6;
         delay(10);
         break;
  case 2:digitalWrite(PC13, HIGH);
         digitalWrite(PB8, HIGH);
         digitalWrite(PA12, HIGH);
         digitalWrite(PB15, HIGH);
         digitalWrite(PA6, LOW);
         digitalWrite(PA7, HIGH);
         digitalWrite(PB6, LOW);
         FD=7;
         delay(10);
         break;
  case 3:digitalWrite(PC13, HIGH);
         digitalWrite(PB8, HIGH);
         digitalWrite(PA12, HIGH);
         digitalWrite(PB15, HIGH);
         digitalWrite(PB14, HIGH);
         digitalWrite(PA6, HIGH);
         digitalWrite(PA7, HIGH);
         digitalWrite(PB6, LOW);
         FD=8;
         delay(10);
         break;
  case 4:digitalWrite(PC13, HIGH);
         digitalWrite(PB8, HIGH);
         digitalWrite(PA12, HIGH);
         digitalWrite(PB15, HIGH);
         digitalWrite(PB14, HIGH);
         digitalWrite(PB13, HIGH);
         digitalWrite(PA6, LOW);
         digitalWrite(PA7, LOW);
         digitalWrite(PB6, HIGH);
         FD=9;
         delay(10);
         break;
   case 5:digitalWrite(PB13, LOW);
         digitalWrite(PB14, LOW);
         digitalWrite(PB15, LOW);
         digitalWrite(PA12, LOW);
         digitalWrite(PC13, HIGH);
         digitalWrite(PB8, HIGH);
         digitalWrite(PA6, LOW);
         digitalWrite(PA7, LOW);
         digitalWrite(PB6, LOW);
         FI=0;
         delay(10);
         break;
   case 6:digitalWrite(PB13, LOW);
         digitalWrite(PB14, LOW);
         digitalWrite(PB15, LOW);
         digitalWrite(PC13, HIGH);
         digitalWrite(PB8, HIGH);
         digitalWrite(PA12, HIGH);
         digitalWrite(PA6, HIGH);
         digitalWrite(PA7, LOW);
         digitalWrite(PB6, LOW);
         FI=1;
         delay(10);
         break; 
   case 7:digitalWrite(PB13, LOW);
         digitalWrite(PB14, LOW);
         digitalWrite(PC13, HIGH);
         digitalWrite(PB8, HIGH);
         digitalWrite(PA12, HIGH);
         digitalWrite(PB15, HIGH);
         digitalWrite(PA6, LOW);
         digitalWrite(PA7, HIGH);
         digitalWrite(PB6, LOW);
         FI=2;
         delay(10);
         break;           
   case 8:digitalWrite(PB13, LOW);
          digitalWrite(PC13, HIGH);
          digitalWrite(PB8, HIGH);
          digitalWrite(PA12, HIGH);
          digitalWrite(PB15, HIGH);
          digitalWrite(PB14, HIGH);
          digitalWrite(PA6, HIGH);
          digitalWrite(PA7, HIGH);
          digitalWrite(PB6, LOW);
          FI=3;
          delay(10);
          break;  
  
}
  
}


void loop()
{
  if(Serial.available() > 0)
  {
    incomingByte = Serial.readStringUntil('\n'); 
    Serial.println(incomingByte);
    int str_len = incomingByte.length() + 1;
    char char_array[str_len];
    incomingByte.toCharArray(char_array, str_len);
    byte index = 0;
    ptr = strtok(char_array, ",");
    while (ptr != NULL)
    {
      strings[index] = ptr;
      index++;
      ptr = strtok(NULL, ",");
    }
    u0 = strings[0];
    u1 = strings[1];
    u2 = strings[2];
    u3 = strings[3];
    u4 = strings[4];
    u5 = strings[5];
    u8 = strings[6];
    

    LS(u0.toInt(), u1.toInt(), u2.toInt(), u3.toInt(), u4.toInt(), u5.toInt(), u8.toInt());
  
  }

  r1 = digitalRead(in1);                           //first sensor input data 
  r2 = digitalRead(in2);                           //second sensor input data
  r3 = digitalRead(in3);                           //third sensor input data
  r4 = digitalRead(in4);                           //third sensor input data 
  r5 = digitalRead(in5);                           //third sensor input data
  r6 = digitalRead(in6);                           //third sensor input data
  r9 = digitalRead(in9);                           //third sensor input data    


  LS(r1,r2,r3,r4,r5,r6,r9);
}





void LS(int r11, int r21, int r31, int r41, int r51, int r61, int r91){
 
 if (r11 == HIGH && p1 == LOW) {                       //if first sensor data is HIGH and p1 is LOW then Enter IF condition
    
    if (state1 == HIGH){                               //if state1 is high then relay and led will turn on
      state1 = LOW;
      digitalWrite(PB1, HIGH);
      digitalWrite(PA0, HIGH);
      EEPROM.write(0, 1);
      delay(10);
    }
      
    else{                                              //if state1 is low then relay and led will turn off
      state1 = HIGH;
      digitalWrite(PB1, LOW);
      digitalWrite(PA0, LOW);
      EEPROM.write(0, 0);
      delay(10);
    }    
  }
  p1 = r11;                                            // first loop p1 value will change LOW to HIGH


  
  
  if (r21 == HIGH && p2 == LOW) {                        //if second sensor data is HIGH and p2 is LOW then relay will turn on and also led will turn on
    
    if (state2 == HIGH){                                //if state2 is high then relay and led will turn on
      state2 = LOW;
      digitalWrite(PB10, HIGH);
      digitalWrite(PA1, HIGH);
      EEPROM.write(1, 1);
      delay(10);
    }
      
    else{                                               //if state2 is low then relay and led will turn off
      state2 = HIGH; 
      digitalWrite(PB10, LOW);
      digitalWrite(PA1, LOW);
      EEPROM.write(1, 0);
      delay(10);
    }    
  }
  p2 = r21;                                              // first loop p2 value will change LOW to HIGH


                             
  if (r31 == HIGH && p3 == LOW) {                   //if third sensor data is HIGH and p3 is low then relay will turn on and also led will turn on
    
    if (state3 == HIGH){                           //if state3 is high then relay and led will turn on
      state3 = LOW;
      digitalWrite(PC15, HIGH);
      digitalWrite(PB7, HIGH);
      EEPROM.write(2, 1);
      delay(10);
    }
      
    else{                                          //if state3 is low then relay and led will turn off
      state3 = HIGH; 
      digitalWrite(PC15, LOW);
      digitalWrite(PB7, LOW);
      EEPROM.write(2, 0);
      delay(10);
    }    
  } 
  p3 = r31;                                         // first loop p3 value will change LOW to HIGH



                             
  if (r41 == HIGH && p4 == LOW) {                   //if third sensor data is HIGH and p3 is low then relay will turn on and also led will turn on
    
    if (state4 == HIGH){                           //if state3 is high then relay and led will turn on
      state4 = LOW;
      digitalWrite(PC14, HIGH);
      digitalWrite(PA5, HIGH);
      EEPROM.write(3, 1);
      delay(10);
    }
      
    else{                                          //if state3 is low then relay and led will turn off
      state4 = HIGH; 
      digitalWrite(PC14, LOW);
      digitalWrite(PA5, LOW);
      EEPROM.write(3, 0);
      delay(10);
    }    
  } 
  p4 = r41;


                             
  if (r51 == HIGH && p5 == LOW) {                   //if third sensor data is HIGH and p3 is low then relay will turn on and also led will turn on
    
    if (state5 == HIGH){                           //if state3 is high then relay and led will turn on
      state5 = LOW;
      digitalWrite(PC13, HIGH);
      digitalWrite(PB8, HIGH);
      EEPROM.write(4, 1);
      FI=0;
      delay(10);
    }
      
    else{                                          //if state3 is low then relay and led will turn off
      state5 = HIGH; 
      digitalWrite(PB13, LOW);
      digitalWrite(PB14, LOW);
      digitalWrite(PB15, LOW);
      digitalWrite(PA12, LOW);
      digitalWrite(PB8, LOW);
      digitalWrite(PC13, LOW);
      digitalWrite(PA6, LOW);
      digitalWrite(PA7, LOW);
      digitalWrite(PB6, LOW);
      EEPROM.write(4, 0);
      FI=0;
      delay(10);
    }    
  } 
  p5 = r51;



                            
if (r61 == HIGH && p6 == LOW && state5 == LOW) 
{                                                  //if third sensor data is HIGH and p3 is low then relay will turn on and also led will turn on
    
    if (state6 == HIGH)
    {                                               //if state3 is high then relay and led will turn on
      state6 = LOW;
      FI+=1;
      FD=FI+5;
          if(FI>4)
          {
            FI=4;
            FD=FI+5;
          }
    }
      
    else
    {                                              //if state3 is low then relay and led will turn off
      state6 = HIGH;
      FI+=1;
      FD=FI+5;
            if(FI>4)
            {
               FI=4;
               FD=FI+5;
            }
    }
  switch(FI)
  {
  case 1:digitalWrite(PC13, HIGH);
         digitalWrite(PB8, HIGH);
         digitalWrite(PA12, HIGH);
         digitalWrite(PA6, HIGH);
         digitalWrite(PA7, LOW);
         digitalWrite(PB6, LOW);
         EEPROM.write(5, FI);
         delay(10);
         break;
  case 2:digitalWrite(PC13, HIGH);
         digitalWrite(PB8, HIGH);
         digitalWrite(PA12, HIGH);
         digitalWrite(PB15, HIGH);
         digitalWrite(PA6, LOW);
         digitalWrite(PA7, HIGH);
         digitalWrite(PB6, LOW);
         EEPROM.write(5, FI);
         delay(10);
         break;
  case 3:digitalWrite(PC13, HIGH);
         digitalWrite(PB8, HIGH);
         digitalWrite(PA12, HIGH);
         digitalWrite(PB15, HIGH);
         digitalWrite(PB14, HIGH);
         digitalWrite(PA6, HIGH);
         digitalWrite(PA7, HIGH);
         digitalWrite(PB6, LOW);
         EEPROM.write(5, FI);
         delay(10);
         break;
  case 4:digitalWrite(PC13, HIGH);
         digitalWrite(PB8, HIGH);
         digitalWrite(PA12, HIGH);
         digitalWrite(PB15, HIGH);
         digitalWrite(PB14, HIGH);
         digitalWrite(PB13, HIGH);
         digitalWrite(PA6, LOW);
         digitalWrite(PA7, LOW);
         digitalWrite(PB6, HIGH);
         EEPROM.write(5, FI);
         delay(10);
         break;
   }    
} 
  p6 = r61;

                            
  if (r91 == HIGH && p9 == LOW && state5 == LOW) 
{                                                                    //if third sensor data is HIGH and p3 is low then relay will turn on and also led will turn on
    
    if (state9 == HIGH)
    {                                                                //if state3 is high then relay and led will turn on
      state9 = LOW;
      FD-=1;
      FI=FD-5;
        if(FD<5)
        {
           FD=5;
           FI=FD-5;
         }
    }
      
    else
    {                                          //if state3 is low then relay and led will turn off
      state9 = HIGH; 
      FD-=1;
      FI=FD-5;
         if(FD<5)
         {
           FD=5;
           FI=FD-5;
         }
    }
  switch(FD)
  {
  case 8:digitalWrite(PB13, LOW);
         digitalWrite(PA6, HIGH);
         digitalWrite(PA7, HIGH);
         digitalWrite(PB6, LOW);
         EEPROM.write(5, FD);
         delay(10);
         break;
  case 7:digitalWrite(PB13, LOW);
         digitalWrite(PB14, LOW);
         digitalWrite(PA6, LOW);
         digitalWrite(PA7, HIGH);
         digitalWrite(PB6, LOW);
         EEPROM.write(5, FD);
         delay(10);
         break;
  case 6:digitalWrite(PB13, LOW);
         digitalWrite(PB14, LOW);
         digitalWrite(PB15, LOW);
         digitalWrite(PA6, HIGH);
         digitalWrite(PA7, LOW);
         digitalWrite(PB6, LOW);
         EEPROM.write(5, FD);
         delay(10);
         break;
  case 5:digitalWrite(PB13, LOW);
         digitalWrite(PB14, LOW);
         digitalWrite(PB15, LOW);
         digitalWrite(PA12, LOW);
         digitalWrite(PA6, LOW);
         digitalWrite(PA7, LOW);
         digitalWrite(PB6, LOW);
         EEPROM.write(5, FD);
         delay(10);
         break;
   }
} 
  p9 = r91;

}
