#define trigPin 2
#define echoPin 3

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <TimerOne.h>

long duration; 
int distance;

String stopwatch = "stop";
long start_time = 0, seconds = 0;
int dt = 10;

int volumeup = 9;
int volumedown = 8; 

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


 
void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); 
  Serial.println("with Arduino UNO R3");
    Timer1.initialize(100000); 
  Timer1.attachInterrupt( ultrasonic_sensor_reading);

  

pinMode(LEDPin, OUTPUT);
pinMode(normalMode, INPUT);
pinMode(overflowMode, INPUT);
pinMode(VolumeMode, INPUT);
pinMode(TimerMode, INPUT);
pinMode(volumeup,INPUT);
pinMode(volumedown,INPUT);
  lcd.init();                      
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Welcome press");
  lcd.setCursor(2,1);
  lcd.print("button");
 
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

  
  while(r <= distance )
  {
    digitalWrite(LEDPin,HIGH);
      lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("OVERFLOW MODE");
  lcd.setCursor(0,1);
  lcd.print("ON");
  delay(300);
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
 }

delay(100);
  
}

void ultrasonic_sensor_reading()
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
}
void times()
{
  if (stopwatch == "run") {
    lcd.setCursor(0, 0);
    seconds = (millis() - start_time) / 1000;
    long  centisecond = ((millis() - start_time) / 10) % 100;
    lcd.print(seconds);
    lcd.print(" : ");
    lcd.print(centisecond);
    lcd.setCursor(0,1);
    lcd.print(dt);
  }
  if (seconds == dt) 
  {
    //Reset stopwatch
    stopwatch = "stop";
    start_time = 0;
    lcd.clear();
    setup();

  }

  if (digitalRead(TimerMode) == HIGH && stopwatch == "stop") {
    //Start stopwatch
    start_time = millis();
    USBCP5��      
*  �1          �               