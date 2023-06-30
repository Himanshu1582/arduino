#define trigPin 35
#define echoPin 34

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

long start_time = 0, seconds = 0;
String stopwatch = "stop";

int IR1 = 45;
int IR2 = 44;

int Ok = 27;
int volumeup = 26;
int volumedown = 28;


 

long duration; 
int distance;

int LEDState=0;
int LEDPin=42;

int normalMode=22;
int normalNew;
int normalOld=1;

int overflowMode=23;
int overNew;
int overOld=1;

int VolumeMode=25;
int VolumeNew;
int VolumeOld=1;
int volume1= 22 ;
int volumelevel = 0;
int volumelcd = 0;
long int dvt=44;


int TimerMode=24;
int timerNew;
int timerOld=1;
long int dtt=10;
int timerlcd = 0;
int timerlcdm = 0;
int timerlcds = 0;

long int minutes = 0;
long int seconds1 = 0;



int r = 13;




 
void setup() {
  digitalWrite(LEDPin, HIGH);
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
pinMode(IR2,INPUT);


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
    digitalWrite(LEDPin,LOW);
      lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("NORMAL MODE");
  lcd.setCursor(0,1);
  lcd.print("TAP  ON");
    LEDState=1;
  }
  else{
    digitalWrite(LEDPin, HIGH);
      lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("ADVANCE-TAPS");
  lcd.setCursor(2,1);
  lcd.print("PRESS BUTTON");
    LEDState=0;
  }
}
normalOld=normalNew;


overNew=digitalRead(overflowMode);

if(overOld==0 && overNew==1)
{
  if(digitalRead(IR1)== LOW)

{
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

  
  while(r <= distance && digitalRead(IR1)==LOW )
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
    digitalWrite(LEDPin,LOW);
      
  lcd.setCursor(0,0);
  lcd.print("OVERFLOW MODE");
  lcd.setCursor(0,1);
  lcd.print("ON");
  delay(100);

 }

    digitalWrite(LEDPin, HIGH);
      lcd.clear();
lcd.setCursor(2,0);
  lcd.print("ADVANCE-TAPS");
  lcd.setCursor(2,1);
  lcd.print("PRESS BUTTON");
    LEDState=0;
}
}
}

overOld=overNew;

VolumeNew=digitalRead(VolumeMode);
if(VolumeOld==0 && VolumeNew==1)
{ 
if(digitalRead(IR1)== LOW)
{
  if (LEDState==0)
  {
    lcd.clear();
    while(digitalRead(Ok) == false)
      {
lcd.setCursor(0,0);
lcd.print("SET VOLUME");
lcd.setCursor(12,0);
lcd.print(volumelevel);
lcd.setCursor(0,1);
lcd.print("Press OK");
if(dvt == 22)
{
  volumelevel = 1;
}

 if(dvt == 44)
{
  volumelevel = 2;
}

if(dvt == 66)
{
  volumelevel = 3;
}

if(dvt == 88)
{
  volumelevel = 4;
}
   if(dvt == 110)
{
  volumelevel = 5;
}

if(dvt == 132)
{
  volumelevel = 6;
}
if(dvt == 154)
{
  volumelevel = 7;
}
if(dvt == 176)
{
  volumelevel = 8;
}
        if(dvt == 198)
{
  volumelevel = 9;
}
if(dvt == 220)
{
  volumelevel = 10;
}
         if (digitalRead(volumeup) == HIGH  )
   { 
      if(dvt <= 6000){
        dvt = dvt + volume1;  
        delay(200);
      }}
    
  if (digitalRead(volumedown) == HIGH  )
  { 
    if(dvt>=5 )
    {
    dvt = dvt - volume1;
    delay(100);
   }}
   }
   
      


    
       lcd.clear();
    digitalWrite(LEDPin,LOW);
    digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  
    while(seconds <= dvt-1 && r <= distance && digitalRead(IR1)==LOW )
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
if(seconds == 22)
{
  volumelcd = 1;
}
if(seconds == 44)
{
  volumelcd = 2;
}
if(seconds == 66)
{
  volumelcd = 3;
}
if(seconds == 88)
{
  volumelcd = 4;
}
if(seconds == 110)
{
  volumelcd = 5;
}
if(seconds == 132)
{
  volumelcd = 6;
}
if(seconds == 154)
{
  volumelcd = 7;
}
if(seconds == 176)
{
  volumelcd = 8;
}
if(seconds == 198)
{
  volumelcd = 9;
}
if(seconds == 220)
{
  volumelcd = 10;
}
 
if(dvt == 22)
{
  volumelevel = 1;
}

 if(dvt == 44)
{
  volumelevel = 2;
}

if(dvt == 66)
{
  volumelevel = 3;
}

if(dvt == 88)
{
  volumelevel = 4;
}
   if(dvt == 110)
{
  volumelevel = 5;
}

if(dvt == 132)
{
  volumelevel = 6;
}

if(dvt == 154)
{
  volumelevel = 7;
}
if(dvt == 176)
{
  volumelevel = 8;
}
if(dvt == 198)
{
  volumelevel = 9;
}
if(dvt == 220)
{
  volumelevel = 10;
}
  lcd.setCursor(0,0);
  lcd.print("VOLUME MODE");
  lcd.setCursor(12,0);
  lcd.print(volumelevel); 
    lcd.setCursor(0,1);
  lcd.print(volumelcd); 
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  
   if (digitalRead(volumeup) == HIGH  )
   { 
      if(dvt <=  60000){
        dvt = dvt + volume1;  
        delay(200);
      }}
    
  if (digitalRead(volumedown) == HIGH  )
  { 
    if(dvt>=5 )
    {
    dvt = dvt - volume1;
    delay(100);
   }}
delay(100);
 }

  while(seconds > 0)
 {
  start_time = 0;
  stopwatch = "stop";
  seconds =0;
  dvt = 44;
  volumelcd = 0;
  volumelevel = 0;
  
  
 }
   }
}
{
    digitalWrite(LEDPin, HIGH);
      lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("ADVANCE-TAPS");
  lcd.setCursor(2,1);
  lcd.print("PRESS BUTTON");
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
lcd.setCursor(11,0);
lcd.print(timerlcdm);
lcd.setCursor(13,0);
lcd.print(".");
lcd.setCursor(14,0);
lcd.print(timerlcds);
lcd.setCursor(0,1);
lcd.print("Press OK");

  if (digitalRead(volumeup) == HIGH  )
  { 
    if(dtt <= 200000 )
    {
    dtt = dtt +1;
    delay(50);
   }}
      
  
        if(dtt <=60)
        {
          timerlcds = 0;
          timerlcds = dtt;
          timerlcdm = 0 ;
        }
        if(dtt >= 60)
        {
          if(dtt <=120)
          {
            timerlcds = 0;
            timerlcds = dtt-60;
            timerlcdm = 1 ;
            }
        }
        if(dtt >= 120)
        {
          if(dtt <=180)
          {
            timerlcds = 0;
            timerlcds = dtt-120;
            timerlcdm = 2 ;
            }
        }
        if(dtt >= 180)
        {
          if(dtt <=240)
          {
            timerlcds = 0;
            timerlcds = dtt-180;
            timerlcdm = 3 ;
            }
        }
        if(dtt >= 240)
        {
          if(dtt <=300)
          {
            timerlcds = 0;
            timerlcds = dtt-240;
            timerlcdm = 4 ;
            }
        }
        if(dtt >= 300)
        {
          if(dtt <=360)
          {
            timerlcds = 0;
            timerlcds = dtt-300;
            timerlcdm = 5 ;
            }
        }
        if(dtt >= 360)
        {
          if(dtt <=420)
          {
            timerlcds = 0;
            timerlcds = dtt-360;
            timerlcdm = 6 ;
            }
        }
        if(dtt >= 420)
        {
          if(dtt <=480)
          {
            timerlcds = 0;
            timerlcds = dtt-420;
            timerlcdm = 7 ;
            }
        }
        if(dtt >= 480)
        {
          if(dtt <=540)
          {
            timerlcds = 0;
            timerlcds = dtt-480;
            timerlcdm = 8 ;
            }
        }
        if(dtt >= 540)
        {
          if(dtt <=600)
          {
            timerlcds = 0;
            timerlcds = dtt-120;
            timerlcdm = 9 ;
            }
        }

        
      
    
  if (digitalRead(volumedown) == HIGH  )
  { 
    if(dtt>=1 )
    {
    dtt = dtt - 1;
    delay(50);
   }}
        }
      


    
       lcd.clear();
    digitalWrite(LEDPin,LOW);
    digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  
    while(seconds <= dtt-1 && r <= distance )
   {
    Serial.print(seconds);
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

 if(seconds == 61)
 {
  minutes = 1;
 }

 if (seconds == 121)
 {
  minutes =2 ;
 }
  if (seconds == 181)
 {
  minutes =3 ;
 }
  if (seconds == 241)
 {
  minutes =4 ;
 }
  if (seconds == 301)
 {
  minutes =5 ;
 }
  if (seconds == 361)
 {
  minutes =6 ;
 }
  if (seconds == 421)
 {
  minutes =7 ;
 }
  if (seconds == 481)
 {
  minutes =8 ;
 }
  if (seconds == 541)
 {
  minutes =9 ;
 }
 if (seconds == 601)
 {
  minutes =10 ;
 }
 

 if(seconds <=60)
 {
  
  seconds1 =seconds;
 }
 if (seconds <= 120)
 {
  
if(seconds > 60)
 {
  seconds1 = 0;
  seconds1 = seconds-60;
 }}

 
 if (seconds <= 180)
 {
  
if(seconds > 120)
 {
  seconds1 = 0;
  seconds1 = seconds-120;
 }}

  if (seconds <= 240)
 {
  
if(seconds > 180)
 {
  seconds1 = 0;
  seconds1 = seconds-180;
 }}
  if (seconds <= 300)
 {
  
if(seconds > 240)
 {
  seconds1 = 0;
  seconds1 = seconds-240;
 }}

  if (seconds <= 360)
 {
  
if(seconds > 300)
 {
  seconds1 = 0;
  seconds1 = seconds-300;
 }}

  if (seconds <= 420)
 {
  
if(seconds > 360)
 {
  seconds1 = 0;
  seconds1 = seconds-360;
 }}
 if (seconds <= 480)
 {
  
if(seconds > 420)
 {
  seconds1 = 0;
  seconds1 = seconds - 420;
 }}

  if (seconds <= 540)
 {
  
if(seconds > 480)
 {
  seconds1 = 0;
  seconds1 = seconds-480;
 }}

  if (seconds <= 600)
 {
  
if(seconds > 540)
 {
  seconds1 = 0;
  seconds1 = seconds-540;
 }}
   
  lcd.setCursor(0,0);
  lcd.print("timermode");
  lcd.setCursor(11,0);
  lcd.print(timerlcdm);
    lcd.setCursor(13,0);
  lcd.print(".");
    lcd.setCursor(14,0);
  lcd.print(timerlcds);
  
  lcd.setCursor(0,1);
  lcd.print(minutes); 
  lcd.setCursor(2,1);
  lcd.print(seconds1);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
           if (digitalRead(volumeup) == HIGH  )
   { 
      if(dtt <= 2000){  
        if(dtt <=60)
        {
          timerlcds = 0;
          timerlcds = dtt;
          timerlcdm = 0 ;
        }
        dtt = dtt + 1;
        if(dtt >= 60)
        {
          if(dtt <=120)
          {
            timerlcds = 0;
            timerlcds = dtt-60;
            timerlcdm = 1 ;
            }
        }
        if(dtt >= 120)
        {
          if(dtt <=180)
          {
            timerlcds = 0;
            timerlcds = dtt-120;
            timerlcdm = 2 ;
            }
        }
        if(dtt >= 180)
        {
          if(dtt <=240)
          {
            timerlcds = 0;
            timerlcds = dtt-180;
            timerlcdm = 3 ;
            }
        }
        if(dtt >= 240)
        {
          if(dtt <=300)
          {
            timerlcds = 0;
            timerlcds = dtt-240;
            timerlcdm = 4 ;
            }
        }
        if(dtt >= 300)
        {
          if(dtt <=360)
          {
            timerlcds = 0;
            timerlcds = dtt-300;
            timerlcdm = 5 ;
            }
        }
        if(dtt >= 360)
        {
          if(dtt <=420)
          {
            timerlcds = 0;
            timerlcds = dtt-360;
            timerlcdm = 6 ;
            }
        }
        if(dtt >= 420)
        {
          if(dtt <=480)
          {
            timerlcds = 0;
            timerlcds = dtt-420;
            timerlcdm = 7 ;
            }
        }
        if(dtt >= 480)
        {
          if(dtt <=540)
          {
            timerlcds = 0;
            timerlcds = dtt-480;
            timerlcdm = 8 ;
            }
        }
        if(dtt >= 540)
        {
          if(dtt <=600)
          {
            timerlcds = 0;
            timerlcds = dtt-120;
            timerlcdm = 9 ;
            }
        }

        
        delay(50);
      }}
    
  if (digitalRead(volumedown) == HIGH  )
  { 
    if(dtt>=1 )
    {
    dtt = dtt - 1;
    delay(50);
   }}

  
  delay(100);
 
 
 }
 while(seconds > 0)
 {
  start_time = 0;
  stopwatch = "stop";
  seconds =0;
  minutes = 0;
  seconds1 = 0;
  dtt = 10;
  timerlcdm = 0;
  timerlcds = 0;
  timerlcd = 0;
  
 }

  }
{
    digitalWrite(LEDPin, HIGH);
      lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("ADVANCE-TAPS");
  lcd.setCursor(2,1);
  lcd.print("PRESS BUTTON");
    LEDState=0;
  }
}
timerOld=timerNew;

delay(100);
}
