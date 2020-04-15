#include <EEPROM.h>
int in1 = PA1;
int in2 = PA2;
int in3 = PA4;
int in4 = PA7;
int in5 = PB11;
int in6 = PA15;
int in7 = PA11;
int in8 = PB15;
int in9 = PB13;

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


  if (ledState1 == LOW){                  //if first sensor data from eeprom is low relay will turn on and also led will turn on
    pwmWrite(Pa3, 65535);
    digitalWrite(PB12, HIGH);
    delay(10);
  }
  else
  {
    pwmWrite(PA3, 3840);                  //if first sensor data from eeprom is High relay will turn off and also led will turn off( Littel brightness)
    digitalWrite(PB12, LOW); 
    delay(10);
  }

  
  if (ledState2 == LOW){                  //if second sensor data from eeprom is low relay will turn on and also led will turn on
    pwmWrite(PA6, 65535);
    digitalWrite(PB10, HIGH);
    delay(10);
  }
  else                                     //if second sensor data from eeprom is High relay will turn off and also led will turn off( Littel brightness)
  {
    pwmWrite(PA6, 3840);
    digitalWrite(PB10, LOW); 
    delay(10);
  }


  if (ledState3 == LOW){                   //if third sensor data from eeprom is low relay will turn on and also led will turn on
    pwmWrite(PB0, 65535);
    digitalWrite(PA5, HIGH);
    delay(10);
  }
  else                                    //if third sensor data from eeprom is High relay will turn off and also led will turn off( Littel brightness)
  {
    pwmWrite(PB0, 3840);
    digitalWrite(PA5, LOW);
    delay(10);
  }


  if (ledState4 == LOW){                   
    pwmWrite(PB1, 65535);
    digitalWrite(PC13, HIGH);
    delay(10);
  }
  else                                    
  {
    pwmWrite(PB1, 3840);
    digitalWrite(PC13, LOW);
    delay(10);
  }

  switch(ledState5){                             //if 5th sensor data from eeprom is 0 to 9 fan regulator relays and leds will work
   case 0: pwmWrite(PA0, 65535);
             pwmWrite(PB9, 65535);
             pwmWrite(PB7, 3840);
             pwmWrite(PB8, 3840);
             pwmWrite(PB6, 3840);
             pwmWrite(PA8, 3840);
             digitalWrite(PB14, LOW);
             digitalWrite(PB5, LOW);
             digitalWrite(PA12, LOW);
             delay(10);
   break;
   case 1: pwmWrite(PA0, 65535);
             pwmWrite(PB9, 65535);
             pwmWrite(PB7, 65535);
             pwmWrite(PB8, 3840);
             pwmWrite(PB6, 3840);
             pwmWrite(PA8, 3840);
             digitalWrite(PB14, HIGH);
             digitalWrite(PB5, LOW);
             digitalWrite(PA12, LOW);
             delay(10);
   break;
   case 2: pwmWrite(PA0, 65535);
             pwmWrite(PB9, 65535);
             pwmWrite(PB7, 65535);
             pwmWrite(PB8, 65535);
             pwmWrite(PB6, 3840);
             pwmWrite(PA8, 3840);
             digitalWrite(PB14, LOW);
             digitalWrite(PB5, HIGH);
             digitalWrite(PA12, LOW);
             delay(10);
   break;
   case 3: pwmWrite(PA0, 65535);
             pwmWrite(PB9, 65535);
             pwmWrite(PB7, 65535);
             pwmWrite(PB8, 65535);
             pwmWrite(PB6, 65535);
             pwmWrite(PA8, 3840);
             digitalWrite(PB14, HIGH);
             digitalWrite(PB5, HIGH);
             digitalWrite(PA12, LOW);
             delay(10);
   break;
   case 4: pwmWrite(PA0, 65535);
             pwmWrite(PB9, 65535);
             pwmWrite(PB7, 65535);
             pwmWrite(PB8, 65535);
             pwmWrite(PB6, 65535);
             pwmWrite(PA8, 65535);
             digitalWrite(PB14, LOW);
             digitalWrite(PB5, LOW);
             digitalWrite(PA12, HIGH);
             delay(10);
   break;
   case 5: pwmWrite(PA8, 3840);
             pwmWrite(PB6, 3840);
             pwmWrite(PB8, 3840);
             pwmWrite(PB7, 3840);
             pwmWrite(PB9, 3840);
             pwmWrite(PA0, 3840);
             digitalWrite(PB14, LOW);
             digitalWrite(PB5, LOW);
             digitalWrite(PA12, LOW);
             delay(10);
   break;
   case 6: pwmWrite(PA8, 3840);
             pwmWrite(PB6, 3840);
             pwmWrite(PB8, 3840);
             pwmWrite(PB7, 3840);
             pwmWrite(PB9, 65535);
             pwmWrite(PA0, 65535);
             digitalWrite(PB14, HIGH);
             digitalWrite(PB5, LOW);
             digitalWrite(PA12, LOW);
             delay(10);
   break;
   case 7: pwmWrite(PA8, 3840);
             pwmWrite(PB6, 3840);
             pwmWrite(PB8, 3840);
             pwmWrite(PB7, 65535);
             pwmWrite(PB9, 65535);
             pwmWrite(PA0, 65535);
             digitalWrite(PB14, LOW);
             digitalWrite(PB5, HIGH);
             digitalWrite(PA12, LOW);
             delay(10);
   break;
   case 8: pwmWrite(PA8, 3840);
             pwmWrite(PB6, 3840);
             pwmWrite(PB8, 65535);
             pwmWrite(PB7, 65535);
             pwmWrite(PB9, 65535);
             pwmWrite(PA0, 65535);
             digitalWrite(PB14, HIGH);
             digitalWrite(PB5, HIGH);
             digitalWrite(PA12, LOW);
             delay(10);
   break;
   case 9: pwmWrite(PA8, 3840);
             pwmWrite(PB6, 65535);
             pwmWrite(PB8, 65535);
             pwmWrite(PB7, 65535);
             pwmWrite(PB9, 65535);
             pwmWrite(PA0, 65535);
             digitalWrite(PB14, LOW);
             digitalWrite(PB5, LOW);
             digitalWrite(PA12, HIGH);
             delay(10);
   break;
   default: Serial.println("none"); 
  }
}


void loop()
{
  if(Serial.available > 0)
  {
    incomingByte = Serial.readStringUntil('\n');          //reading data form esp32 for switch communication 
    Serial.println(incomingByte);
    int str_len = incomingByte.length() + 1;              // String length
    char char_array[str_len];
    incomingByte.toCharArray(char_array, str_len);         // String converted to char array
    byte index = 0;
    ptr = strtok(char_array, ",");
    while (ptr != NULL)
    {
      strings[index] = ptr;
      index++;
      ptr = strtok(NULL, ",");                          // Split 5 data with comma
    }
    u = strings[0];
    v = strings[1];
    w = strings[2];
    x = strings[3]; 
    y = strings[4];
  if (u.toInt() == 1){                  //if first sensor data from wifi or bluetooth is "1" relay will turn on and also led will turn on
    pwmWrite(Pa3, 65535);
    digitalWrite(PB12, HIGH);
    EEPROM.write(0, LOW);
    delay(10);
  }
  else
  {
    pwmWrite(PA3, 3840);                  //if first sensor data from wifi or bluetooth is "0" relay will turn off and also led will turn off( Littel brightness)
    digitalWrite(PB12, LOW); 
    EEPROM.write(0, HIGH);
    delay(10);
  }

  
  if (v.toInt() == 1){                  //if Second sensor data from wifi or bluetooth is "1" relay will turn on and also led will turn on
    pwmWrite(PA6, 65535);
    digitalWrite(PB10, HIGH);
    EEPROM.write(1, LOW);
    delay(10);
  }
  else                                     //if second sensor data from wifi or bluetooth is "0" relay will turn off and also led will turn off( Littel brightness)
  {
    pwmWrite(PA6, 3840);
    digitalWrite(PB10, LOW); 
    EEPROM.write(1, HIGH);
    delay(10);
  }


  if (w.toInt() == 3){                   
    pwmWrite(PB0, 65535);
    digitalWrite(PA5, HIGH);
    EEPROM.write(2, LOW);
    delay(10);
  }
  else                                    
  {
    pwmWrite(PB0, 3840);
    digitalWrite(PA5, LOW);
    EEPROM.write(2, HIGH);
    delay(10);
  }


  if (x.toInt() == 4){                   
    pwmWrite(PB1, 65535);
    digitalWrite(PC13, HIGH);
    EEPROM.write(3, LOW);
    delay(10);
  }
  else                                    
  {
    pwmWrite(PB1, 3840);
    digitalWrite(PC13, LOW);
    EEPROM.write(0, HIGH);
    delay(10);
  }

  switch(y.toInt()){                                //if 5th sensor data from wifi or bluetooth is 0 to 9 fan regulator relays and leds will work
   case 0: pwmWrite(PA0, 65535);
             pwmWrite(PB9, 65535);
             pwmWrite(PB7, 3840);
             pwmWrite(PB8, 3840);
             pwmWrite(PB6, 3840);
             pwmWrite(PA8, 3840);
             digitalWrite(PB14, LOW);
             digitalWrite(PB5, LOW);
             digitalWrite(PA12, LOW);
             EEPROM.write(4, 0);
             delay(10);
   break;
   case 1: pwmWrite(PA0, 65535);
             pwmWrite(PB9, 65535);
             pwmWrite(PB7, 65535);
             pwmWrite(PB8, 3840);
             pwmWrite(PB6, 3840);
             pwmWrite(PA8, 3840);
             digitalWrite(PB14, HIGH);
             digitalWrite(PB5, LOW);
             digitalWrite(PA12, LOW);
             EEPROM.write(4, 1);
             delay(10);
   break;
   case 2: pwmWrite(PA0, 65535);
             pwmWrite(PB9, 65535);
             pwmWrite(PB7, 65535);
             pwmWrite(PB8, 65535);
             pwmWrite(PB6, 3840);
             pwmWrite(PA8, 3840);
             digitalWrite(PB14, LOW);
             digitalWrite(PB5, HIGH);
             digitalWrite(PA12, LOW);
             EEPROM.write(4, 2);
             delay(10);
   break;
   case 3: pwmWrite(PA0, 65535);
             pwmWrite(PB9, 65535);
             pwmWrite(PB7, 65535);
             pwmWrite(PB8, 65535);
             pwmWrite(PB6, 65535);
             pwmWrite(PA8, 3840);
             digitalWrite(PB14, HIGH);
             digitalWrite(PB5, HIGH);
             digitalWrite(PA12, LOW);
             EEPROM.write(4, 3);
             delay(10);
   break;
   case 4: pwmWrite(PA0, 65535);
             pwmWrite(PB9, 65535);
             pwmWrite(PB7, 65535);
             pwmWrite(PB8, 65535);
             pwmWrite(PB6, 65535);
             pwmWrite(PA8, 65535);
             digitalWrite(PB14, LOW);
             digitalWrite(PB5, LOW);
             digitalWrite(PA12, HIGH);
             EEPROM.write(4, 4);
             delay(10);
   break;
   case 5: pwmWrite(PA8, 3840);
             pwmWrite(PB6, 3840);
             pwmWrite(PB8, 3840);
             pwmWrite(PB7, 3840);
             pwmWrite(PB9, 3840);
             pwmWrite(PA0, 3840);
             digitalWrite(PB14, LOW);
             digitalWrite(PB5, LOW);
             digitalWrite(PA12, LOW);
             EEPROM.write(4, 5);
             delay(10);
   break;
   case 6: pwmWrite(PA8, 3840);
             pwmWrite(PB6, 3840);
             pwmWrite(PB8, 3840);
             pwmWrite(PB7, 3840);
             pwmWrite(PB9, 65535);
             pwmWrite(PA0, 65535);
             digitalWrite(PB14, HIGH);
             digitalWrite(PB5, LOW);
             digitalWrite(PA12, LOW);
             EEPROM.write(4, 6);
             delay(10);
   break;
   case 7: pwmWrite(PA8, 3840);
             pwmWrite(PB6, 3840);
             pwmWrite(PB8, 3840);
             pwmWrite(PB7, 65535);
             pwmWrite(PB9, 65535);
             pwmWrite(PA0, 65535);
             digitalWrite(PB14, LOW);
             digitalWrite(PB5, HIGH);
             digitalWrite(PA12, LOW);
             EEPROM.write(4, 7);
             delay(10);
   break;
   case 8: pwmWrite(PA8, 3840);
             pwmWrite(PB6, 3840);
             pwmWrite(PB8, 65535);
             pwmWrite(PB7, 65535);
             pwmWrite(PB9, 65535);
             pwmWrite(PA0, 65535);
             digitalWrite(PB14, HIGH);
             digitalWrite(PB5, HIGH);
             digitalWrite(PA12, LOW);
             EEPROM.write(4, 8);
             delay(10);
   break;
   case 9: pwmWrite(PA8, 3840);
             pwmWrite(PB6, 65535);
             pwmWrite(PB8, 65535);
             pwmWrite(PB7, 65535);
             pwmWrite(PB9, 65535);
             pwmWrite(PA0, 65535);
             digitalWrite(PB14, LOW);
             digitalWrite(PB5, LOW);
             digitalWrite(PA12, HIGH);
             EEPROM.write(4, 9);
             delay(10);
   break;
   default: Serial.println("none"); 
  }
  }
  r1 = digitalRead(in1);                               //first sensor input data 
  if (r1 == HIGH && p1 == LOW) {                       //if first sensor data is HIGH and p1 is LOW then Enter IF condition
    
    if (state1 == HIGH){                               //if state1 is high then relay and led will turn on
      state1 = LOW;
      pwmWrite(PA3, 65535);
      digitalWrite(PB12, HIGH);
      EEPROM.write(0, state1);
      delay(10);
    }
      
    else{                                              //if state1 is low then relay and led will turn off
      state1 = HIGH;
      pwmWrite(PA3, 3840);
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
      pwmWrite(PA6, 65535);
      digitalWrite(PB10, HIGH);
      EEPROM.write(1, state2);
      delay(10);
    }
      
    else{                                               //if state2 is low then relay and led will turn off
      state2 = HIGH; 
      pwmWrite(PA6, 3840);
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
      pwmWrite(PB0, 65535);
      digitalWrite(PA5, HIGH);
      EEPROM.write(2, state3);
      delay(10);
    }
      
    else{                                          //if state3 is low then relay and led will turn off
      state3 = HIGH; 
      pwmWrite(PB0, 3840);
      digitalWrite(PA5, LOW);
      EEPROM.write(2, state3); 
      delay(10);
    }    
  } 
  p3 = r3;                                         // first loop p3 value will change LOW to HIGH



  r4 = digitalRead(in4);                                                      
  if (r4 == HIGH && p4 == LOW) {                   
    
    if (state4 == HIGH){                           
      state4 = LOW;
      pwmWrite(PB1, 65535);
      digitalWrite(PC13, HIGH);
      EEPROM.write(3, state4);
      delay(10);
    }
      
    else{                                          
      state4 = HIGH; 
      pwmWrite(PB1, 3840);
      digitalWrite(PC13, LOW);
      EEPROM.write(3, state4); 
      delay(10);
    }    
  } 
  p4 = r4;


 r5 = digitalRead(in5);                                                      
  if (r5 == HIGH && p5 == LOW) {                   
    
    if (state5 == HIGH){                           
      state5 = LOW;
      pwmWrite(PA0, 65535);
      pwmWrite(PB9, 65535);
      EEPROM.write(4, 0);
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
      EEPROM.write(4, 5); 
      delay(10);
    }    
  } 
  p5 = r5;



  r6 = digitalRead(in6);                                                      
  if (r6 == HIGH && p6 == LOW) {                   
    
    if (state6 == HIGH && state5 == LOW){                           
      state6 = LOW;
      pwmWrite(PA0, 65535);
      pwmWrite(PB9, 65535);
      pwmWrite(PB7, 65535);
      digitalWrite(PB14, HIGH);
      digitalWrite(PB5, LOW);
      digitalWrite(PA12, LOW);
      EEPROM.write(4, 1);
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
      EEPROM.write(4, 6); 
      delay(10);
    }    
  } 
  p6 = r6;




  r7 = digitalRead(in7);                                                      
  if (r7 == HIGH && p7 == LOW) {                   
    
    if (state7 == HIGH && state5 == LOW){                           
      state7 = LOW;
      pwmWrite(PA0, 65535);
      pwmWrite(PB9, 65535);
      pwmWrite(PB7, 65535);
      pwmWrite(PB8, 65535);
      digitalWrite(PB14, LOW);
      digitalWrite(PB5, HIGH);
      digitalWrite(PA12, LOW);
      EEPROM.write(4, 2);
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
      EEPROM.write(4,7); 
      delay(10);
    }    
  } 
  p7 = r7;




  r8 = digitalRead(in8);                                                     
  if (r8 == HIGH && p8 == LOW) {                   
    
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
      EEPROM.write(4, 3);
      delay(10);
    }
      
    else{                                          
      state8 = HIGH; 
      pwmWrite(PA8, 3840);
      pwmWrite(PB6, 3840);
      digitalWrite(PB14, HIGH);
      digitalWrite(PB5, HIGH);
      digitalWrite(PA12, LOW);
      EEPROM.write(4,8); 
      delay(10);
    }    
  } 
  p8 = r8;




  r9 = digitalRead(in9);                                                      
  if (r9 == HIGH && p9 == LOW) {                   
    
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
      EEPROM.write(4, 4);
      delay(10);
    }
      
    else{                                          
      state9 = HIGH; 
      pwmWrite(PA8, 3840);
      digitalWrite(PB14, LOW);
      digitalWrite(PB5, LOW);
      digitalWrite(PA12, HIGH);
      EEPROM.write(4,9); 
      delay(10);
    }    
  } 
  p9 = r9;

}
