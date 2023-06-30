#include <LiquidCrystal_I2C.h>

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
 

void setup()
{
  pinMode(normal,INPUT_PULLUP);

  lcd.init();                      
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Hello, world");
  lcd.setCursor(0,1);
  lcd.print("OF INTELIGENT MINDS");

}

void loop()
{
  if (digitalRead(normal) == true)
  {
 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("HI himanshu");
  lcd.setCursor(0,1);
  lcd.print("U R VERY SWEET");
  delay(200);
  
  }
  else 
   {
        lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("HI akshit");
  lcd.setCursor(0,1);
  lcd.print("U Rnot"); 
  }

delay(200);


 
}
