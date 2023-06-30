#include <LiquidCrystal.h>
LiquidCrystal lcd(6 ,1, 5, 4, 3, 2);
const int trigPin = 11;
const int echoPin = 10;
long duration;
int distanceCm, distanceInch;

void setup() {
  
lcd.begin(16,2); 
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

}

void loop() {
  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;

lcd.setCursor(0,0); 
lcd.print("Distance: "); 
lcd.print(distanceCm); 
lcd.print("  cm");
delay(10);
lcd.setCursor(0,1);
lcd.print("Distance: ");
lcd.print(distanceInch);
lcd.print("inch");
delay(10);

}
