#include<EEPROM.h>

int in1 = PA4;
int in2 = PB0;
int in3 = PB9;
int in4 = PB5;
int in5 = PB11;
int in6 = PA15;
int in7 = PA11;
int in8 = PA8;
int in9 = PB12;

String incomingByte;
char *strings[10];
char *ptr = NULL;
String w,x,y,v,u;

int state1 = HIGH; 
int state2 = HIGH; 
int state3 = HIGH;
int state4 = HIGH;
int state5 = HIGH;
int state6 = HIGH;
int state7 = HIGH;
int state8 = HIGH;
int state9 = HIGH;
  

int r1;
int r2;
int r3;
int r4;
int r5;
int r6;
int r7;
int r8;
int r9;
   
        
int p1 = LOW;
int p2 = LOW;
int p3 = LOW;
int p4 = LOW;
int p5 = LOW;
int p6 = LOW;
int p7 = LOW;
int p8 = LOW;
int p9 = LOW;


int ledState1 = HIGH; 
int ledState2 = HIGH; 
int ledState3 = HIGH; 
int ledState4 = HIGH; 
int ledState5; 
   
void setup()
{
  Serial.begin(9600);
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(in3, INPUT);
  pinMode(in4, INPUT);
  pinMode(in5, INPUT);
  pinMode(in6, INPUT);
  pinMode(in7, INPUT);
  pinMode(in8, INPUT);
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

  LS(ledState1, ledState2, ledState3, ledState4, ledState5);
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
    u = strings[0];
    v = strings[1];
    w = strings[2];
    x = strings[3]; 
    y = strings[4];

    LS(u.toInt(), v.toInt(), w.toInt(), x.toInt(), y.toInt());
  
  }

  r1 = digitalRead(in1);                               //first sensor input data 
  if (r1 == HIGH && p1 == LOW) {                       //if first sensor data is HIGH and p1 is LOW then Enter IF condition
    
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
  p1 = r1;                                            // first loop p1 value will change LOW to HIGH


  
  r2 = digitalRead(in2);                                //second sensor input data
  if (r2 == HIGH && p2 == LOW) {                        //if second sensor data is HIGH and p2 is LOW then relay will turn on and also led will turn on
    
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
  p2 = r2;                                              // first loop p2 value will change LOW to HIGH


  r3 = digitalRead(in3);                           //third sensor input data                            
  if (r3 == HIGH && p3 == LOW) {                   //if third sensor data is HIGH and p3 is low then relay will turn on and also led will turn on
    
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
  p3 = r3;                                         // first loop p3 value will change LOW to HIGH



  r4 = digitalRead(in4);                           //third sensor input data                            
  if (r4 == HIGH && p4 == LOW) {                   //if third sensor data is HIGH and p3 is low then relay will turn on and also led will turn on
    
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
  p4 = r4;


 r5 = digitalRead(in5);                           //third sensor input data                            
  if (r5 == HIGH && p5 == LOW) {                   //if third sensor data is HIGH and p3 is low then relay will turn on and also led will turn on
    
    if (state5 == HIGH){                           //if state3 is high then relay and led will turn on
      state5 = LOW;
      digitalWrite(PC13, HIGH);
      digitalWrite(PB8, HIGH);
      EEPROM.write(4, 0);
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
      EEPROM.write(4, 9);
      delay(10);
    }    
  } 
  p5 = r5;



  r6 = digitalRead(in6);                           //third sensor input data                            
  if (r6 == HIGH && p6 == LOW) {                   //if third sensor data is HIGH and p3 is low then relay will turn on and also led will turn on
    
    if (state6 == HIGH && state5 == LOW){                           //if state3 is high then relay and led will turn on
      state6 = LOW;
      digitalWrite(PC13, HIGH);
      digitalWrite(PB8, HIGH);
      digitalWrite(PA12, HIGH);
      digitalWrite(PA6, HIGH);
      digitalWrite(PA7, LOW);
      digitalWrite(PB6, LOW);
      EEPROM.write(4, 1);
      delay(10);
    }
      
    else{                                          //if state3 is low then relay and led will turn off
      state6 = HIGH; 
      digitalWrite(PB13, LOW);
      digitalWrite(PB14, LOW);
      digitalWrite(PB15, LOW);
      digitalWrite(PA12, LOW);
      digitalWrite(PA6, LOW);
      digitalWrite(PA7, LOW);
      digitalWrite(PB6, LOW);
      EEPROM.write(4, 8);
      delay(10);
    }    
  } 
  p6 = r6;




  r7 = digitalRead(in7);                           //third sensor input data                            
  if (r7 == HIGH && p7 == LOW) {                   //if third sensor data is HIGH and p3 is low then relay will turn on and also led will turn on
    
    if (state7 == HIGH && state5 == LOW){                           //if state3 is high then relay and led will turn on
      state7 = LOW;
      digitalWrite(PC13, HIGH);
      digitalWrite(PB8, HIGH);
      digitalWrite(PA12, HIGH);
      digitalWrite(PB15, HIGH);
      digitalWrite(PA6, LOW);
      digitalWrite(PA7, HIGH);
      digitalWrite(PB6, LOW);
      EEPROM.write(4, 2);
      delay(10);
    }
      
    else{                                          //if state3 is low then relay and led will turn off
      state7 = HIGH; 
      digitalWrite(PB13, LOW);
      digitalWrite(PB14, LOW);
      digitalWrite(PB15, LOW);
      digitalWrite(PA6, HIGH);
      digitalWrite(PA7, LOW);
      digitalWrite(PB6, LOW);
      EEPROM.write(4, 7);
      delay(10);
    }    
  } 
  p7 = r7;




  r8 = digitalRead(in8);                           //third sensor input data                            
  if (r8 == HIGH && p8 == LOW) {                   //if third sensor data is HIGH and p3 is low then relay will turn on and also led will turn on
    
    if (state8 == HIGH && state5 == LOW){                           //if state3 is high then relay and led will turn on
      state8 = LOW;
      digitalWrite(PC13, HIGH);
      digitalWrite(PB8, HIGH);
      digitalWrite(PA12, HIGH);
      digitalWrite(PB15, HIGH);
      digitalWrite(PB14, HIGH);
      digitalWrite(PA6, HIGH);
      digitalWrite(PA7, HIGH);
      digitalWrite(PB6, LOW);
      EEPROM.write(4, 3);
      delay(10);
    }
      
    else{                                          //if state3 is low then relay and led will turn off
      state8 = HIGH; 
      digitalWrite(PB13, LOW);
      digitalWrite(PB14, LOW);
      digitalWrite(PA6, LOW);
      digitalWrite(PA7, HIGH);
      digitalWrite(PB6, LOW);
      EEPROM.write(4, 6);
      delay(10);
    }
  } 
  p8 = r8;




  r9 = digitalRead(in9);                           //third sensor input data                            
  if (r9 == HIGH && p9 == LOW) {                   //if third sensor data is HIGH and p3 is low then relay will turn on and also led will turn on
    
    if (state9 == HIGH && state5 == LOW){                           //if state3 is high then relay and led will turn on
      state9 = LOW;
      digitalWrite(PC13, HIGH);
      digitalWrite(PB8, HIGH);
      digitalWrite(PA12, HIGH);
      digitalWrite(PB15, HIGH);
      digitalWrite(PB14, HIGH);
      digitalWrite(PB13, HIGH);
      digitalWrite(PA6, LOW);
      digitalWrite(PA7, LOW);
      digitalWrite(PB6, HIGH);
      EEPROM.write(4, 4);
      delay(10);
    }
      
    else{                                          //if state3 is low then relay and led will turn off
      state9 = HIGH; 
      digitalWrite(PB13, LOW);
      digitalWrite(PA6, HIGH);
      digitalWrite(PA7, HIGH);
      digitalWrite(PB6, LOW);
      EEPROM.write(4, 5);
      delay(10);
    }
  } 
  p9 = r9;

}





void LS(int a, int b, int c, int d, int e){
 
 if (a == 1){                  
    digitalWrite(PB1, HIGH);
    digitalWrite(PA0, HIGH);
    EEPROM.write(0, 1);
    delay(10);
  }
  else
  {
    digitalWrite(PB1, LOW);
    digitalWrite(PA0, LOW);
    EEPROM.write(0, 0);
    delay(10);
  }

  
  if (b == 1){                  //if second sensor data from eeprom is low relay will turn on and also led will turn on
    digitalWrite(PB10, HIGH);
    digitalWrite(PA1, HIGH);
    EEPROM.write(1, 1);
    delay(10);
  }
  else                                     //if second sensor data from eeprom is High relay will turn off and also led will turn off( Littel brightness)
  {
    digitalWrite(PB10, LOW);
    digitalWrite(PA1, LOW);
    EEPROM.write(1, 0); 
    delay(10);
  }


  if (c == 1){                   //if third sensor data from eeprom is low relay will turn on and also led will turn on
    digitalWrite(PC15, HIGH);
    digitalWrite(PB7, HIGH);
    EEPROM.write(2, 1);
    delay(10);
  }
  else                                    //if third sensor data from eeprom is High relay will turn off and also led will turn off( Littel brightness)
  {
    digitalWrite(PC15, LOW);
    digitalWrite(PB7, LOW);
    EEPROM.write(2, 0);
    delay(10);
  }


  if (d == 1){                   //if third sensor data from eeprom is low relay will turn on and also led will turn on
    digitalWrite(PC14, HIGH);
    digitalWrite(PA5, HIGH);
    EEPROM.write(3, 1);
    delay(10);
  }
  else                                    //if third sensor data from eeprom is High relay will turn off and also led will turn off( Littel brightness)
  {
    digitalWrite(PC14, LOW);
    digitalWrite(PA5, LOW);
    EEPROM.write(3, 0);
    delay(10);
  }

   switch(e){
   case 0: digitalWrite(PC13, HIGH);
             digitalWrite(PB8, HIGH);
             digitalWrite(PA12, LOW);
             digitalWrite(PB15, LOW);
             digitalWrite(PB14, LOW);
             digitalWrite(PB13, LOW);
             digitalWrite(PA6, LOW);
             digitalWrite(PA7, LOW);
             digitalWrite(PB6, LOW);
             EEPROM.write(4, 0);
             delay(10);
   break;
   case 1: digitalWrite(PC13, HIGH);
             digitalWrite(PB8, HIGH);
             digitalWrite(PA12, HIGH);
             digitalWrite(PB15, LOW);
             digitalWrite(PB14, LOW);
             digitalWrite(PB13, LOW);
             digitalWrite(PA6, HIGH);
             digitalWrite(PA7, LOW);
             digitalWrite(PB6, LOW);
             EEPROM.write(4, 1);
             delay(10);
   break;
   case 2: digitalWrite(PC13, HIGH);
             digitalWrite(PB8, HIGH);
             digitalWrite(PA12, HIGH);
             digitalWrite(PB15, HIGH);
             digitalWrite(PB14, LOW);
             digitalWrite(PB13, LOW);
             digitalWrite(PA6, LOW);
             digitalWrite(PA7, HIGH);
             digitalWrite(PB6, LOW);
             EEPROM.write(4, 2);
             delay(10);
   break;
   case 3: digitalWrite(PC13, HIGH);
             digitalWrite(PB8, HIGH);
             digitalWrite(PA12, HIGH);
             digitalWrite(PB15, HIGH);
             digitalWrite(PB14, HIGH);
             digitalWrite(PB13, LOW);
             digitalWrite(PA6, HIGH);
             digitalWrite(PA7, HIGH);
             digitalWrite(PB6, LOW);
             EEPROM.write(4, 3);
             delay(10);
   break;
   case 4: digitalWrite(PC13, HIGH);
             digitalWrite(PB8, HIGH);
             digitalWrite(PA12, HIGH);
             digitalWrite(PB15, HIGH);
             digitalWrite(PB14, HIGH);
             digitalWrite(PB13, HIGH);
             digitalWrite(PA6, LOW);
             digitalWrite(PA7, LOW);
             digitalWrite(PB6, HIGH);
             EEPROM.write(4, 4);
             delay(10);
   break;
   case 5: digitalWrite(PC13, HIGH);
             digitalWrite(PB8, HIGH);
             digitalWrite(PA12, HIGH);
             digitalWrite(PB15, HIGH);
             digitalWrite(PB14, HIGH);
             digitalWrite(PB13, LOW);
             digitalWrite(PA6, HIGH);
             digitalWrite(PA7, HIGH);
             digitalWrite(PB6, LOW);
             EEPROM.write(4, 5);
             delay(10);
   break;
   case 6: digitalWrite(PC13, HIGH);
             digitalWrite(PB8, HIGH);
             digitalWrite(PA12, HIGH);
             digitalWrite(PB15, HIGH);
             digitalWrite(PB14, LOW);
             digitalWrite(PB13, LOW);
             digitalWrite(PA6, LOW);
             digitalWrite(PA7, HIGH);
             digitalWrite(PB6, LOW);
             EEPROM.write(4, 6);
             delay(10);
   break;
   case 7: digitalWrite(PC13, HIGH);
             digitalWrite(PB8, HIGH);
             digitalWrite(PA12, HIGH);
             digitalWrite(PB15, LOW);
             digitalWrite(PB14, LOW);
             digitalWrite(PB13, LOW);
             digitalWrite(PA6, HIGH);
             digitalWrite(PA7, LOW);
             digitalWrite(PB6, LOW);
             EEPROM.write(4, 7);
             delay(10);
   break;
   case 8: digitalWrite(PC13, HIGH);
             digitalWrite(PB8, HIGH);
             digitalWrite(PA12, LOW);
             digitalWrite(PB15, LOW);
             digitalWrite(PB14, LOW);
             digitalWrite(PB13, LOW);
             digitalWrite(PA6, LOW);
             digitalWrite(PA7, LOW);
             digitalWrite(PB6, LOW);
             EEPROM.write(4, 8);
             delay(10);
   break;
   case 9: digitalWrite(PC13, LOW);
             digitalWrite(PB8, LOW);
             digitalWrite(PA12, LOW);
             digitalWrite(PB15, LOW);
             digitalWrite(PB14, LOW);
             digitalWrite(PB13, LOW);
             digitalWrite(PA6, LOW);
             digitalWrite(PA7, LOW);
             digitalWrite(PB6, LOW);
             EEPROM.write(4, 9);
             delay(10);
   break;
   default: Serial.println("none"); 
  } 
}
