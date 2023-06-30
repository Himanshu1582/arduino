#define trigPin 2
#define echoPin 3
#include <TimerOne.h>
String LEDStatus="OFF";
long duration; 
int distance;
int dt = 10000;

int r = 14;

int RedLED=9;
long Starttime;
long actualTime;
 
void setup() 
{
   pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); 
  Serial.println("with Arduino UNO R3");
    
  pinMode(RedLED,OUTPUT);
  
  Timer1.initialize(100000); 
  Timer1.attachInterrupt( ultrasonic_sensor_reading); 
  
}
 
void loop()
{  
 while(r <= distance && dt>=actualTime)
{
  digitalWrite(RedLED,HIGH);
  delay(100);
}
digitalWrite(RedLED,LOW);

}
 
void ultrasonic_sensor_reading()
{
  Starttime = millis();
  actualTime = Starttime - 0 ;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  Serial.print(distance);
  Serial.print('\n');
  Serial.print(actualTime);
  
}
