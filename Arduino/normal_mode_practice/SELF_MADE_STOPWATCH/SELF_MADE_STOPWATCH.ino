#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int start_pause_pin = 13, resetpin = 12;
String stopwatch = "stop";
long start_time = 0, seconds = 0;
int dt = 10;
int volumeup = 11;
int volumedown = 10; 
void setup()
{
  pinMode(start_pause_pin, INPUT);
  pinMode(resetpin, INPUT);
  lcd.init();// initialize the lcd
  lcd.backlight();// Backlight ON
  lcd.setCursor(0, 1);
  lcd.print("Press START");
}
void loop() 
{
  if (digitalRead(volumeup) == HIGH  ){ 
      if(dt <=  50){
        dt = dt + 1;  
        delay(200);
      }
    
      }
  if (digitalRead(volumedown) == HIGH  )
  { 
    if(dt>=5 )
    {
    dt = dt - 1;
    delay(200);
   }
  }
 times();
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
    loop();

  }

  if (digitalRead(start_pause_pin) == HIGH && stopwatch == "stop") {
    //Start stopwatch
    start_time = millis();
    lcd.clear();
    stopwatch = "run";
  }
  }
