int motorA1 = 12; // Pin  2 of L293
int motorA2 = 11; // Pin  7 of L293
int motorB1 = 10; // Pin 10 of L293
int motorB2 = 9; // Pin 14 of L293
int LDR = 2;

void setup() { 
pinMode(motorA1, OUTPUT);
pinMode(motorA2, OUTPUT);
pinMode(motorB1, OUTPUT);
pinMode(motorB2, OUTPUT);
pinMode(LDR,INPUT);
} 

void loop() { 
int LDRV = digitalRead(LDR);

if(LDRV == HIGH){ 
digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, LOW); 
digitalWrite(motorB1, LOW); 
digitalWrite(motorB2, LOW); 

}

else{
digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, HIGH); 
digitalWrite(motorB1, LOW); 
digitalWrite(motorB2, HIGH); 

}


}
