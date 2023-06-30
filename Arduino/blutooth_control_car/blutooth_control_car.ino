int motorA1 = 5; // Pin  2 of L293
int motorA2 = 6; // Pin  7 of L293
int motorB1 = 9; // Pin 10 of L293
int motorB2 = 10; // Pin 14 of L293
char state = '0';  // Initialise Motors
#include <IRremote.h>  
 int RECV_PIN = 12;  
 int val ; 
 
int xValue = 0 ;
int yValue = 0 ; 
int bValue = 0 ;

 
 IRrecv irrecv(RECV_PIN);  
 decode_results results;

void setup() 
{ 
Serial.begin(9600); // Initialize serial communication at 9600 bits per second
   // Set pins as outputs
pinMode(motorA1, OUTPUT);
pinMode(motorA2, OUTPUT);
pinMode(motorB1, OUTPUT);
pinMode(motorB2, OUTPUT); 
irrecv.enableIRIn();   
Serial.println("Enabled IRin");
  pinMode(8,INPUT); 
  digitalWrite(8,HIGH);  
} 

void loop() 
{
 

if(Serial.available()>0){ // Reads from bluetooth and stores its value
state = Serial.read();
}
if(state=='F' ){ // Forward
  Serial.println(state);
digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, HIGH); 
digitalWrite(motorB1, LOW); 
digitalWrite(motorB2, HIGH); 

}
if(state=='B'){ // Reverse
    Serial.println(state);
digitalWrite(motorA1, HIGH); 
digitalWrite(motorA2, LOW); 
digitalWrite(motorB1, HIGH); 
digitalWrite(motorB2, LOW); 
}
if(state=='R'){ // Right
    Serial.println(state);
digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, HIGH); 
digitalWrite(motorB1, HIGH); 
digitalWrite(motorB2, LOW);  
}
if(state=='L'){ // Left
    Serial.println(state);
digitalWrite(motorA1, HIGH); 
digitalWrite(motorA2, LOW); 
digitalWrite(motorB1, LOW); 
digitalWrite(motorB2, HIGH); 
} 
if(state=='S'){ // Stop
    Serial.println(state);
digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, LOW); 
digitalWrite(motorB1, LOW); 
digitalWrite(motorB2, LOW); 

}


 if (irrecv.decode(&results))   
  {   
   val = results.value, HEX ;  
   Serial.println(val); // Print the value in serial monitor  
   irrecv.resume();   // Receive the next value  
  }  

  xValue = analogRead(A0);  
  yValue = analogRead(A1);  
  bValue = digitalRead(8);  
//  Serial.print(xValue,DEC);
//  Serial.print(",");
//  Serial.print(yValue,DEC);
//  Serial.print(",");
//  Serial.print(!bValue);
//  Serial.print("\n");
  delay(10); 

if(val == -10201)
{
  while(val !=-20401)
  {
    if (irrecv.decode(&results))   
  {   
   val = results.value, HEX ;  
   Serial.println(val); // Print the value in serial monitor  
   irrecv.resume();   // Receive the next value  
  }
  digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, HIGH); 
digitalWrite(motorB1, LOW); 
digitalWrite(motorB2, HIGH); 
 delay(100);
  }

  }
  if(val == -4081)
{
    while(val !=-20401)
  {
    if (irrecv.decode(&results))   
  {   
   val = results.value, HEX ;  
   Serial.println(val); // Print the value in serial monitor  
   irrecv.resume();   // Receive the next value  
  }
  digitalWrite(motorA1, HIGH); 
digitalWrite(motorA2, LOW); 
digitalWrite(motorB1, HIGH); 
digitalWrite(motorB2, LOW); 
 delay(100);
  }}

  if(val == 12495)
{
    while(val !=-20401)
  {
    if (irrecv.decode(&results))   
  {   
   val = results.value, HEX ;  
   Serial.println(val); // Print the value in serial monitor  
   irrecv.resume();   // Receive the next value  
  }
digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, HIGH); 
digitalWrite(motorB1, HIGH); 
digitalWrite(motorB2, LOW);  
 delay(100);
  }}

    if(val == 28815)
{
    while(val !=-20401)
  {
    if (irrecv.decode(&results))   
  {   
   val = results.value, HEX ;  
   Serial.println(val); // Print the value in serial monitor  
   irrecv.resume();   // Receive the next value  
  }
digitalWrite(motorA1, HIGH); 
digitalWrite(motorA2, LOW); 
digitalWrite(motorB1, LOW); 
digitalWrite(motorB2, HIGH);  
delay(100);
 
  }}
  if (irrecv.decode(&results))   
  {   
   val = results.value, HEX ;  
   Serial.println(val); // Print the value in serial monitor  
   irrecv.resume();   // Receive the next value  
  }
  else if(val == -20401)

digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, LOW); 
digitalWrite(motorB1, LOW); 
digitalWrite(motorB2, LOW); 

if(xValue<=10 && yValue>=500 )
{
digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, HIGH); 
digitalWrite(motorB1, LOW); 
digitalWrite(motorB2, HIGH); 
  }

  if (xValue>=500 && yValue>=1020)
{
digitalWrite(motorA1, HIGH); 
digitalWrite(motorA2, LOW); 
digitalWrite(motorB1, LOW); 
digitalWrite(motorB2, HIGH);
  }

   if (xValue>=0 && yValue<=10) 
{
digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, HIGH); 
digitalWrite(motorB1, HIGH); 
digitalWrite(motorB2, LOW);
  }
  if(xValue>=1020 && yValue>=500)
  {
    digitalWrite(motorA1, HIGH); 
digitalWrite(motorA2, LOW); 
digitalWrite(motorB1, HIGH); 
digitalWrite(motorB2, LOW);
    
    }
    if (!bValue == 1)
    {    digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, LOW); 
digitalWrite(motorB1, LOW); 
digitalWrite(motorB2, LOW);
    }
    
    

}
