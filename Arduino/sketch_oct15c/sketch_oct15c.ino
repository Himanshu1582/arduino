void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}int pinOne      = 0;
int pinTwo      = 2;
int pinThree    = 4;
int pinFour     = 6;
int pinFive     = 8;

int buttonPin   = 11;
int buttonState = 0;

int blinkMode   = 0;

void setup()
{
  pinMode(pinOne, OUTPUT);
  pinMode(pinTwo, OUTPUT);
  pinMode(pinThree, OUTPUT);
  pinMode(pinFour, OUTPUT);
  pinMode(pinFive, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop()
{
  while(blinkMode == 0)
  {
    digitalWrite(pinOne, HIGH);
    delay(250);
    digitalWrite(pinOne, LOW);
    digitalWrite(pinTwo, HIGH);
    delay(250);
    digitalWrite(pinTwo, LOW);
    digitalWrite(pinThree, HIGH);
    delay(250);
    digitalWrite(pinThree, LOW);
    digitalWrite(pinFour, HIGH);
    delay(250);
    digitalWrite(pinFour, LOW);
    digitalWrite(pinFive, HIGH);
    delay(250);
    digitalWrite(pinFive, LOW);
    buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH)
  {
    if(blinkMode == 1)
    {
    blinkMode = 0;
    }
    else 
    {
    blinkMode++;
    }
  }
  }
  while(blinkMode == 1)
  {
    digitalWrite(pinOne, HIGH);
    digitalWrite(pinTwo, HIGH);
    digitalWrite(pinThree, HIGH);
    digitalWrite(pinFour, HIGH);
    digitalWrite(pinFive, HIGH);
    delay(250);
    digitalWrite(pinOne, LOW);
    digitalWrite(pinTwo, LOW);
    digitalWrite(pinThree, LOW);
    digitalWrite(pinFour, LOW);
    digitalWrite(pinFive, LOW);
    delay(250);
      buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH)
  {
    if(blinkMode == 1)
    {
    blinkMode = 0;
    }
    else
    {
    blinkMode++;
    }
  }
  }
}
