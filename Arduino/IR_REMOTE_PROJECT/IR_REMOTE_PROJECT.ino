#include <IRremote.h>
int motorA1 = 5; // Pin  2 of L293
int motorA2 = 6; // Pin  7 of L293
int motorB1 = 9; // Pin 10 of L293
int motorB2 = 10; // Pin 14 of L293  
 int RECV_PIN = 12;  
 int val ; 
 int led = 9; 
 IRrecv irrecv(RECV_PIN);  
 decode_results results;  
 void setup()  
 {  
  pinMode(led,OUTPUT);
  Serial.begin(9600);  
  irrecv.enableIRIn();   
  Serial.println("Enabled IRin");  
  pinMode(motorA1, OUTPUT);
pinMode(motorA2, OUTPUT);
pinMode(motorB1, OUTPUT);
pinMode(motorB2, OUTPUT); 
 }  
 void loop()   
 {  
  if (irrecv.decode(&results))   
  {   
   val = results.value, HEX ;  
   Serial.println(val); // Print the value in serial monitor  
   irrecv.resume();   // Receive the next value  
  }  
  delay(10); 
 
      
        
        
 } 
