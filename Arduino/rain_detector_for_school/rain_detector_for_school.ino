#include <Servo.h>
int rainAnalogPin = A0;
int rainDigitalPin = 2;
Servo myservo; 
 
int pos =0;

void setup(){
   myservo.attach(9); 
  pinMode(rainAnalogPin, INPUT);
  pinMode(rainDigitalPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  int sensorAnalogValue = analogRead(rainAnalogPin);
  Serial.print("Rain sensor analog value: ");
  Serial.println(sensorAnalogValue);


  
if(sensorAnalogValue >=800)

 {
  for(pos=0;pos<=180;pos++){
 
myservo.write(pos);
delay(15);
}
  delay(1000);
  
  for(pos=180;pos>=0;pos--)
  {
myservo.write(pos);
delay(15);
}
  delay(1000);
  

 if(sensorAnalogValue <=800)
 {
  
  
  for(pos=180;pos>=0;pos--)
  {
myservo.write(pos);
delay(15);
}
}


  
  
 }
 }
