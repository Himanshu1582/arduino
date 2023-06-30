#define trigPin 2
#define echoPin 3

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

long start_time = 0, seconds = 0;
String stopwatch = "stop";

int IR1 = 11;


int Ok = 9;
int volumeup = 8;
int volumedown = 10;


 

long duration; 
int distance;

int LEDState=0;
int LEDPin=13;

int normalMode=4;
int normalNew;
int normalOld=1;

int overflowMode=5;
int overNew;
int overOld=1;

int VolumeMode=6;
int VolumeNew;
int VolumeOld=1;

int TimerMode=7;
int timerNew;
int timerOld=1;



int r = 14;

int dt=9;

 
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
pinMode(volumeup,INPUT);
pinMode(volumedown,INPUT);
pinMode(Ok,INPUT);
pinMode(IR1,INPUT);



  lcd.init();                      
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("ADVANCE-TAPS");
  lcd.setCursor(2,1);
  lcd.print("PRESS BUTTON");
 
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
  lcd.print("TAP  ON");
    LEDState=1;
  }
  else{
    digitalWrite(LEDPin, LOW);
      lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("NORMAL MODE");
  lcd.setCursor(0,1);
  lcd.print("TAP  OFF");
    LEDState=0;
  }
}
normalOld=normalNew;


overNew=digitalRead(overflowMode);
if(overOld==0 && overNew==1){
  if (LEDState==0)
  { 
    lcd.clear();
    digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  Serial.print(distance);
  Serial.print('\n'); 

  
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
      
  lcd.setCursor(0,0);
  lcd.print("OVERFLOW MODE");
  lcd.setCursor(0,1);
  lcd.print("ON");
  delay(100);

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

VolumeNew=digitalRead(VolumeMode);
if(VolumeOld==0 && VolumeNew==1){
  if (LEDState==0)
  {
    lcd.clear();
    while(digitalRead(Ok) == false)
      {
lcd.setCursor(0,0);
lcd.print("SET VOLUME");
lcd.setCursor(12,0);
lcd.print(dt);
lcd.setCursor(0,1);
lcd.print("Press OK");
        
         if (digitalRead(volumeup) == HIGH  )
   { 
      if(dt <=  50){
        dt = dt + 1;  
        delay(200);
      }}
    
  if (digitalRead(volumedown) == HIGH  )
  { 
    if(dt>=5 )
    {
    dt = dt - 1;
    delay(100);
   }}
        }
      


    
       lcd.clear();
    digitalWrite(LEDPin,HIGH);
    digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  
    while(seconds <= dt-1 && r <= distance )
   {
      if (stopwatch == "run") 
      {
    seconds = (millis() - start_time) / 1000;
    long  centisecond = ((millis() - start_time) / 10) % 100;
  }
  if ( stopwatch == "stop") {
    //Start stopwatch
    start_time = millis();
    stopwatch = "run";
      
 }
   
  lcd.setCursor(0,0);
  lcd.print("VOLUME MODE");
  lcd.setCursor(12,0);
  lcd.print(dt);
  lcd.setCursor(0,1);
  lcd.print(seconds);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  
   if (digitalRead(volumeup) == HIGH  )
   { 
      if(dt <=  50){
        dt = dt + 1;  
        delay(200);
      }}
    
  if (digitalRead(volumedown) == HIGH  )
  { 
    if(dt>=5 )
    {
    dt = dt - 1;
    delay(100);
   }}

  
  delay(100);
 
 
 }
  }
{
    digitalWrite(LEDPin, LOW);
      lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press RESET");
    LEDState=0;
  }
}
VolumeOld=VolumeNew;

timerNew=digitalRead(TimerMode);
if(timerOld==0 && timerNew==1){
  if (LEDState==0)
  {
    lcd.clear();
    while(digitalRead(Ok) == false)
      {
lcd.setCursor(0,0);
lcd.print("set timer");
lcd.setCursor(12,0);
lcd.print(dt);
lcd.setCursor(0,1);
lcd.print("Press OK");
        
         if (digitalRead(volumeup) == HIGH  )
   { 
      if(dt <=  50){
        dt = dt + 1;  
        delay(200);
      }}
    
  if (digitalRead(volumedown) == HIGH  )
  { 
    if(dt>=5 )
    {
    dt = dt - 1;
    delay(100);
   }}
        }
      


    
       lcd.clear();
    digitalWrite(LEDPin,HIGH);
    digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  
    while(seconds <= dt-1 && r <= distance )
   {
      if (stopwatch == "run") 
      {
    seconds = (millis() - start_time) / 1000;
    long  centisecond = ((millis() - start_time) / 10) % 100;
  }
  if ( stopwatch == "stop") {
    //Start stopwatch
    start_time = millis();
    stopwatch = "run";
      
 }
   
  lcd.setCursor(0,0);
  lcd.print("timermode");
  lcd.setCursor(12,0);
  lcd.print(dt);
  lcd.setCursor(0,1);
  lcd.print(seconds);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  
   if (digitalRead(volumeup) == HIGH  )
   { 
      if(dt <=  50){
        dt = dt + 1;  
        delay(200);
      }}
    
  if (digitalRead(volumedown) == HIGH  )
  { 
    if(dt>=5 )
    {
    dt = dt - 1;
    delay(100);
   }}

  
  delay(100);
 
 
 }
  }
{
    digitalWrite(LEDPin, LOW);
      lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press RESET");
    LEDState=0;
  }
}
timerOld=timerNew;




delay(100);
}
