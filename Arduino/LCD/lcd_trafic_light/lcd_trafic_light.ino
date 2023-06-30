#include <LiquidCrystal.h>
LiquidCrystal lcd(6 ,1, 5, 4, 3, 2);
const int IR1 = 13;
const int IR2 = 12;
const int IR3 = 11;
const int IR4 = 10;
const int IR5 = 9;
const int ledPin1 =  8; 
const int ledPin2 = 7;



 int r = 2000;
 int g = 3000;
 int interval = 8000;
 int a = 0;

 void setup()
 {
  lcd.begin(16,2); 
    pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(IR5, INPUT);
  }

  void loop()
  {
    a = 0 ;
    lcd.clear();

    if (digitalRead(IR1)== 0)
    
    {
      lcd.clear();
      a = g/1000;

    
lcd.setCursor(0,0); 
lcd.print("Road "); 
lcd.print("1 to 2");

delay(10);
lcd.setCursor(0,1);
lcd.print("green light");
lcd.setCursor(13,1);
lcd.print(a);
delay(10);
digitalWrite(ledPin2,HIGH);
delay(g);
digitalWrite(ledPin2,LOW);
digitalWrite(ledPin1,HIGH);
delay(r);
digitalWrite(ledPin1,LOW);
      a = 0 ;

    }
if (digitalRead(IR1)== 1)
{
  lcd.clear();
  a = g/1000+8;
  lcd.setCursor(0,0); 
lcd.print("Road "); 
lcd.print("1 to 2");
delay(10);
lcd.setCursor(0,1);
lcd.print("green light");
lcd.setCursor(13,1);
lcd.print(a);
delay(10);
digitalWrite(ledPin2,HIGH);
delay(g+interval);
digitalWrite(ledPin2,LOW);
digitalWrite(ledPin1,HIGH);
delay(r);
digitalWrite(ledPin1,LOW);
  a = 0 ;
  }


      if (digitalRead(IR2)== 0)
    
    {
      lcd.clear();
      a = g/1000;
lcd.setCursor(0,0); 
lcd.print("Road "); 
lcd.print("3 to 4");
delay(10);
lcd.setCursor(0,1);
lcd.print("green light");
lcd.setCursor(13,1);
lcd.print(a);
delay(10);
digitalWrite(ledPin2,HIGH);
delay(g);
digitalWrite(ledPin2,LOW);
digitalWrite(ledPin1,HIGH);
delay(r);
digitalWrite(ledPin1,LOW);
      a = 0 ;
    }
if (digitalRead(IR2)== 1)
{
  lcd.clear();
  a = g/1000+8;
  lcd.setCursor(0,0); 
lcd.print("Road "); 
lcd.print("3 to 4");
delay(10);
lcd.setCursor(0,1);
lcd.print("green light");
lcd.setCursor(13,1);
lcd.print(a);
delay(10);
digitalWrite(ledPin2,HIGH);
delay(g+interval);
digitalWrite(ledPin2,LOW);
digitalWrite(ledPin1,HIGH);
delay(r);
digitalWrite(ledPin1,LOW);
  a = 0 ;
  }


    if (digitalRead(IR3)== 0)
    
    {
      lcd.clear();
      a = g/1000;
lcd.setCursor(0,0); 
lcd.print("Road "); 
lcd.print("2 to 1");
delay(10);
lcd.setCursor(0,1);
lcd.print("green light");
lcd.setCursor(13,1);
lcd.print(a);
delay(10);
digitalWrite(ledPin2,HIGH);
delay(g);
digitalWrite(ledPin2,LOW);
digitalWrite(ledPin1,HIGH);
delay(r);
digitalWrite(ledPin1,LOW);
      a = 0 ;
    }
if (digitalRead(IR3)== 1)
{
  lcd.clear();
  a = g/1000+8;
  lcd.setCursor(0,0); 
lcd.print("Road "); 
lcd.print("2 to 1");
delay(10);
lcd.setCursor(0,1);
lcd.print("green light");
lcd.setCursor(13,1);
lcd.print(a);
delay(10);
digitalWrite(ledPin2,HIGH);
delay(g+interval);
digitalWrite(ledPin2,LOW);
digitalWrite(ledPin1,HIGH);
delay(r);
digitalWrite(ledPin1,LOW);
  a = 0 ;
  }


  if (digitalRead(IR4)== 0)

{
  lcd.clear();
  a = g/1000;
lcd.setCursor(0,0); 
lcd.print("Road "); 
lcd.print("4 to 3");
delay(10);
lcd.setCursor(0,1);
lcd.print("green light");
lcd.setCursor(13,1);
lcd.print(a);
delay(10);
digitalWrite(ledPin2,HIGH);
delay(g);
digitalWrite(ledPin2,LOW);
digitalWrite(ledPin1,HIGH);
delay(r);
digitalWrite(ledPin1,LOW);
a = 0 ;      
    }
    
 if (digitalRead(IR4)== 1)
 {
  if(digitalRead(IR5)==0)
  {
    lcd.clear();
    a = g/1000+8;
    lcd.setCursor(0,0); 
lcd.print("Road "); 
lcd.print("4 to 3");
delay(10);
lcd.setCursor(0,1);
lcd.print("green light");
lcd.setCursor(13,1);
lcd.print(a);
delay(10);
digitalWrite(ledPin2,HIGH);
delay(g+interval);
digitalWrite(ledPin2,LOW);
digitalWrite(ledPin1,HIGH);
delay(r);
digitalWrite(ledPin1,LOW);
a = 0 ;  
  }

    if(digitalRead(IR5)==1)
  {
    lcd.clear();
    a = g/1000+16;
    lcd.setCursor(0,0); 
lcd.print("Road "); 
lcd.print("4 to 3");
delay(10);
lcd.setCursor(0,1);
lcd.print("green light");
lcd.setCursor(13,1);
lcd.print(a);
delay(10);
digitalWrite(ledPin2,HIGH);
delay(g+interval+interval);
digitalWrite(ledPin2,LOW);
digitalWrite(ledPin1,HIGH);
delay(r);
digitalWrite(ledPin1,LOW);
a = 0 ;
  
  }
 }

 }
