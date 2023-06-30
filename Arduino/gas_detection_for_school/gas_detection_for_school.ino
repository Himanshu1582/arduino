int redLed = 12;
int greenLed = 11;
int buzzer = 10;
#define gasSensor A0
#define HIGH 600

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(gasSensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  int gas_value = analogRead(gasSensor);

  Serial.println(gas_value);

  
  if (gas_value > 500)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(buzzer,HIGH);
    
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(buzzer,LOW);
  }
  delay(100);
}
