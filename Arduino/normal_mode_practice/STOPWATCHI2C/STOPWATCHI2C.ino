#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); //16x2 display

const int start_pause_pin = 4, resetpin = 5;
String stopwatch = "stop", start_pause = "low";
long start_time = 0, seconds = 0;
void setup()
{
  pinMode(start_pause_pin, INPUT);
  pinMode(resetpin, INPUT);
  lcd.init();// initialize the lcd
  lcd.backlight();// Backlight ON
  lcd.setCursor(0, 1);
  lcd.print("Press START");
}

void loop() {
  if (stopwatch == "run") {
    lcd.setCursor(0, 0);
    seconds = (millis() - start_time) / 1000;
    long  centisecond = ((millis() - start_time) / 10) % 100;
    lcd.print(seconds);
    lcd.print(" : ");
    lcd.print(centisecond);
  }
  if (digitalRead(resetpin) == HIGH) {
    //Reset stopwatch
    stopwatch = "stop";
    start_time = 0;
    lcd.setCursor(0, 1);
    lcd.print("Press START");
  }
  if (digitalRead(start_pause_pin) == HIGH && stopwatch == "stop") {
    //Start stopwatch
    start_time = millis();
    lcd.clear();
    stopwatch = "run";
    start_pause = "high";
  }
  else if (digitalRead(start_pause_pin) == HIGH && stopwatch == "run" && start_pause == "low") {
    //Pause stopwatch
    stopwatch = "pause";
    start_pause = "high";
  }
  else if (digitalRead(start_pause_pin) == HIGH && stopwatch == "pause" && start_pause == "low") {
    //Resume stopwatch
    start_time = millis() - (seconds * 1000);
    stopwatch = "run";
    start_pause = "high";
    lcd.clear();

  }
  else if (digitalRead(start_pause_pin) == LOW) {
    start_pause = "low";
  }
  delay(10);
}
