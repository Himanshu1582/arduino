#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
#define trigpin 2
 #define echopin 3 
 int valve = 6;     
void setup()
{
  pinMode(valve, OUTPUT);
}
void loop()
{
  buttonValue = analogRead(A0); 
  
  
  if (buttonValue>=1010 && buttonValue<=1015){
    digitalWrite(yellowLed, HIGH);
  }
  
  else if (buttonValue>=1000 && buttonValue<=1008){
    digitalWrite(redLed, HIGH);
  }
 
  else if (buttonValue>=990  && buttonValue<=998){
    digitalWrite(blueLed, HIGH);
  }
 
  else if (buttonValue>=870  && buttonValue<=880){
    digitalWrite(greenLed, HIGH);
  }
  
  else{
    digitalWrite(yellowLed, LOW);
      digitalWrite(redLed, LOW);
      digitalWrite(blueLed, LOW);
      digitalWrite(greenLed, LOW);
  }
  delay(100);
}
