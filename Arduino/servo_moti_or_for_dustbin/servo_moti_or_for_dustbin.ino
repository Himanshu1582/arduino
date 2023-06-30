
#include <Servo.h>
const int trigPin = 2;
const int echoPin = 3;
long duration;
int distanceCm;

Servo myservo; 
 
int pos =0; 
 
void setup()
{
  myservo.attach(9); 
  pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
}
 
void loop()
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
Serial.print(distanceCm);
Serial.print("distanceCm");
delay(300);

if(distanceCm <=50 )
 { 
  for(pos = 180; pos>=0; pos-=1) 
  {
    myservo.write(pos);
    delay(10);
//    Serial.print(pos);

  }
  delay(3000);
  
  for(pos = 0; pos <= 180; pos += 1) 
  { 
    myservo.write(pos); 
    delay(10);
//    Serial.print(pos);
  }
 }


}
