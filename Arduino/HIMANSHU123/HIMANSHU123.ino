#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
#define trigpin 3
 #define echopin 2
 #define scl 0
 #define sda 1
 int normalbutton  = 12; // Push Button1 Pin D 2  
 int overflowbutton = 13;
 int volumemodebutton = 9;
 int volumeup = 10;
 int volumedown = 11;
 int timermode = 6;   
 int valve = 5;  // Led1 Pin D 12    
 int status1 = false;  
 int status2 = false;
 int status3 = false; 
 int status4 = false; 
 int status5 = false; 
 int status6 = false;  
 long duration ;
 int distance;
int s = 10;
 int r = 20; 
 int k = 30;
 int H = 200;
  int A = 200;
  int B = k ;
  int V = A;
  

 int interval = 10;
 void setup()  
 {  
 pinMode(valve, OUTPUT);  
 pinMode(normalbutton, INPUT_PULLUP);  
 pinMode(overflowbutton, INPUT_PULLUP);   
 pinMode(volumemodebutton, INPUT_PULLUP);
  pinMode(volumeup, INPUT_PULLUP);
   pinMode(volumedown, INPUT_PULLUP);
    pinMode(timermode, INPUT_PULLUP); 
 pinMode(trigpin,OUTPUT);
 pinMode(echopin,INPUT);
 Serial.begin(9600);
 Serial.println("Ultrasonic sensor");
 Serial.println("Water label");
  lcd.init();
  lcd.backlight();
 }  
 void loop()  
 { 
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance=duration*0.034/2;
  Serial.print(distance);
  Serial.print('\n');
  digitalWrite(valve, LOW);


if(digitalRead(normalbutton) == true )
status1=!status1;



 {
  digitalWrite(valve,status1);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("normal mode"); 
 }
 
 
   
if(digitalRead(overflowbutton) == true && distance >= 20 ) // For Button 2  
 {  
 status2 = !status2 ;
   while(r <= distance || digitalRead(normalbutton) == true)
  {
  digitalWrite(valve,HIGH);
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance=duration*0.034/2;
  Serial.print(distance);
  Serial.print('\n');
    lcd.clear();
    lcd.setCursor(0,0);
  lcd.print("overflow mode");
  

 }
   {
    digitalWrite(valve,LOW);
   }

}
   
if(digitalRead(volumemodebutton) == true && distance > 20 ) // For Button  3
 { 
 status3 = !status3 ;
  while(B <= distance || digitalRead(normalbutton) == true)
  {

     lcd.clear();
    lcd.setCursor(0,0);
  lcd.print("volume mode");
  lcd.setCursor(14,1);
  lcd.println(B);
  digitalWrite(valve,  HIGH);
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance=duration*0.034/2;
  Serial.print(distance);
  Serial.print('\n');
  if (digitalRead(volumeup) == HIGH && distance >=20 )
  { 
      if (B <= 100)
      {
        B = B + interval;
      }
 
      Serial.println(k);
  }
      delay(100);
     
  if (digitalRead(volumedown) == HIGH && distance >=20 )
  { 
    if(B >= 10)
    {
    B = B - interval ;
    }
  
    Serial.println(k);
   }
   delay(100);
      
 }
   {
    digitalWrite(valve,LOW);
   }
   }
 if(digitalRead(timermode) == true && distance > 20 ) // For Button  3
 { 
 status3 = !status3 ;
      
   for ( int i = 0; i <= V; i++ ) 
   {
    digitalRead(normalbutton);
    lcd.clear();
    lcd.setCursor(0,0);
  lcd.print("timer mode");
  lcd.setCursor(10,1);
  lcd.print(V);
  lcd.setCursor(0,1);
  lcd.print(i);
  digitalWrite(valve,HIGH);
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance=duration*0.034/2;
  Serial.print(distance);
  Serial.print('\n');
    if (digitalRead(volumeup) == HIGH && distance >=20 ){ 
      if(V <=  50000){
        V = V + H; 
        Serial.println(A); 
        delay(200);
      }
    
      }
  if (digitalRead(volumedown) == HIGH && distance >=20 )
  { 
    if(V >=100 )
    {
    V = V - H;
    
    Serial.println(A);
    delay(200);
   }
  }
 }
 
   {
    digitalWrite(valve,LOW);
   }
   }
   


  
 while(digitalRead(normalbutton) == true);  
 while(digitalRead(overflowbutton) == true);
 while(digitalRead(volumemodebutton) == true); 
 while(digitalRead(timermode ) == true);
 delay(20);  
    } 
