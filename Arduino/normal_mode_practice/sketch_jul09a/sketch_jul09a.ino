#define trigPin 2
#define echoPin 3

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);


long duration; 
int distance;

int LEDState=0;
int LEDPin=7;

int normalMode=13;
int normalNew;
int normalOld=1;

int overflowMode=12;
int overNew;
int overOld=1;

int VolumeMode=11;
int volumeNew;
int volumeOld=1;

int TimerMode=10;
int timerNew;
int timerOld=1;

int r = 14;

int dt=100;

 
void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); 
  Serial.println("with Arduino UNO R3");
  

pinMode(LEDPin, OUTPUT);
pinMode(normalMode, INPUT);
pinMode(overflowMode, INPUT);
pinMode(VolumeMode, INPUT);
pinMode(TimerMode, INPUT);
  lcd.init();                      
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Hello, my world");
  lcd.setCursor(0,1);
  lcd.print("kusha");
 
}
 
void loop() 
{

normalNew=digitalRead(normalMode);
if(normalOld==0 && normalNew==1){
  if (LEDState==0){
    digitalWrite(LEDPin,HIGH);
      lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("NORMAL MODE");
  lcd.setCursor(0,1);
  lcd.print("ON");
    LEDState=1;
  }
  else{
    digitalWrite(LEDPin, LOW);
      lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("NORMAL MODE");
  lcd.setCursor(0,1);
  lcd.print("OFF");
    LEDState=0;
  }
}
normalOld=normalNew;


overNew=digitalRead(overflowMode);
if(overOld==0 && overNew==1){
  if (LEDState==0)
  {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  Serial.print(distance);
  
  while(r <= distance )
  {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  Serial.print(distance);
  Serial.print('\n');
    digitalWrite(LEDPin,HIGH);
      lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("OVERFLOW MODE");
  lcd.setCursor(0,1);
  lcd.print("ON");

 }

    digitalWrite(LEDPin, LOW);
      lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("OVERFLOW MODE");
  lcd.setCursor(0,1);
  lcd.print("OFF");
    LEDState=0;
}
}
overOld=overNew;


timerNew=digitalRead(TimerMode);
if(timerOld==0 && timerNew==1){
  if (LEDState==0){
    digitalWrite(LEDPin,HIGH);
      lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TIMER MODE");
  lcd.setCursor(0,1);
  lcd.print("ON");
    LEDState=1;
  }
  else{
    digitalWrite(LEDPin, LOW);
      lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TIMER MODE");
  lcd.setCursor(0,1);
  lcd.print("OFF");
    LEDState=0;
  }
}
timerOld=timerNew;


volumeNew=digitalRead(VolumeMode);
if(volumeOld==0 && volumeNew==1)
{
   {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  Serial.print(distance);
  
  while(r <= distance )
  {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  Serial.print(distance);
  Serial.print('\n');
    digitalWrite(LEDPin,HIGH);
      lcd.clear();
  lcd.setCursor(0,0);
  lcdUSBC�Z��     
*  �1@         # m a t h   c o n s o l e   a n d   n u m b e r   c o n s o l e . t x t Z�     � �     *�     _����*�����*����Ũ�+� �h     W�h             ! m e r n   s t a c k   h i m a n s h u   r a n a   p p t . p p t x     [�     � r     *�     �r����