int xValue = 0 ;
int yValue = 0 ; 
int bValue = 0 ;

void setup()  
{ 
  Serial.begin(9600) ;
  pinMode(9,INPUT); 
  digitalWrite(9,HIGH); 
} 

void loop() 
{ 
  xValue = analogRead(A0);  
  yValue = analogRead(A1);  
  bValue = digitalRead(9);  
  Serial.print(xValue);
  Serial.print(",");
  Serial.print(yValue);
  Serial.print(",");
  Serial.print(!bValue);
  Serial.print("\n");
  delay(10);  
}
