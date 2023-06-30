#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
#define trigpin 2
 #define echopin 3

 int normalbutton  = 7; // Push Button1 Pin D 2  
 int overflowbutton = 8;
 int volumemodebutton = 9;
 int volumeup = 11;
 int volumedown = 12;
 int timermode = 10;   
 int valve = 6;  // Led1 Pin D 12    
 int status1 = false ;  
 int status2 = false;
 int status3 = false; 
 int status4 = false; 
 int status5 = false; 
 int status6 = false;  
 long duration ;
 int distance;
int s = 10;
 int r = 14; 
 int k = 14;
 int H = 243;
  int A = 243;
  int B = k ;
  int V = A;
  int T;
  int n ;
  

 int interval = 1.5 ;
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
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Normal mode");
  lcd.setCursor(0,1);
  lcd.print("TAP"); 
  if (status1 == true)
 {
 lcd.setCursor(10,1);
 lcd.print("ON");
 digitalWrite(valve,HIGH);

 } 
 if (status1 == false)
 {
  lcd.setCursor(10,1);
  lcd.print("OFF");
  digitalWrite(valve,LOW);
 }
 


if(digitalRead(normalbutton) == true )
{
  status1=!status1;
 
}
 
 
 
 
   
if(digitalRead(overflowbutton) == true && distance >= 14) // For Button 2  
 {  
 status2 = !status2 ;
   while(r <= distance )
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
   
if(digitalRead(volumemodebutton) == true && distance > 14 ) // For Button  3
 { 
 status3 = !status3 ;
  while(B <= distance)
  {

    

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
  if (digitalRead(volumeup) == HIGH && distance >=14 )
  { 
      if (B <= 15.5)
      {
        B = B - interval;
      }
               
      
 
      Serial.println(k);
  }
      delay(100);
     
  if (digitalRead(volumedown) == HIGH && distance >=14 )
  { 
    if(B >= 42.5)
    {
    B = B + interval ;
    }
  
        
    
  
    Serial.println(k);
   }
   delay(100);
      
 }
   {
    digitalWrite(valve,LOW);
   }
   }
 if(digitalRead(timermode) == true ) // For Button  3
 { 
 status3 = !status3 ;
      
   for ( int i = 0; i <= V; i++ ) 
   {
    lcd.clear();
    lcd.setCursor(0,0);
  lcd.print("timer mode");
  lcd.setCursor(10,1);
  lcd.print(T);
  lcd.setCursor(0,1);
  lcd.print(i/24.3);
  T = V/24.3;
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
    if (digitalRead(volumeup) == HIGH && distance >=14 ){ 
      if(V <=  50000){
        V = V + H; 
        Serial.println(A); 
        delay(200);
      }
    
      }
  if (digitalRead(volumedown) == HIGH && distance >=14 )
  { 
    if(V >=486 )
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
   



delay(200);
    } 
