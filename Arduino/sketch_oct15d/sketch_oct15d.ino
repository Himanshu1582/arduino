int c    = 3;
int s    = 5;
int k    = 6;
int m    = 9;
int d   = 10;
int ATL  = 11;  

int brightness = 0;   
int fadeAmount = 5;  



void setup()
{
  pinMode(c, OUTPUT);
  pinMode(s, OUTPUT);
  pinMode(k, OUTPUT);
  pinMode(m, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(ATL, OUTPUT);
}

void loop()
{
  for (int i = 0; i <= 9; i++) 
  {
    digitalWrite(c, HIGH);
    delay(250);
    digitalWrite(c, LOW);
    digitalWrite(s, HIGH);
    delay(250);
    digitalWrite(s, LOW);
    digitalWrite(k, HIGH);
    delay(250);
    digitalWrite(k, LOW);
    digitalWrite(m, HIGH);
    delay(250);
    digitalWrite(m, LOW);
    digitalWrite(d, HIGH);
    delay(250);
    digitalWrite(d, LOW);
    digitalWrite(ATL, HIGH);
    delay(250);
    digitalWrite(ATL, LOW);

  }

  for (int i = 0; i <= 999; i++)

  {
  analogWrite(c, brightness);
  analogWrite(s, brightness);
  analogWrite(k, brightness);
  analogWrite(m, brightness);
  analogWrite(d, brightness);
  analogWrite(ATL, brightness);
  brightness = brightness + fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  delay(30);
    
    }


        for (int i = 0; i <= 39; i++)

  {
    digitalWrite(ATL, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(s, HIGH);
    digitalWrite(k, HIGH);
    digitalWrite(m, HIGH);
    digitalWrite(d, HIGH);
    delay(100);
    digitalWrite(c, LOW);
    digitalWrite(s, LOW);
    digitalWrite(k, LOW);
    digitalWrite(m, LOW);
    digitalWrite(d, LOW);
    digitalWrite(ATL, HIGH);
    delay(100);

    
    }
    
        for (int i = 0; i <= 39; i++)

  {
    digitalWrite(ATL, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(s, LOW);
    digitalWrite(k, LOW);
    digitalWrite(m, LOW);
    digitalWrite(d, LOW);
    delay(500);
    digitalWrite(c, HIGH);
    digitalWrite(s, HIGH);
    digitalWrite(k, LOW);
    digitalWrite(m, LOW);
    digitalWrite(d, LOW);
    digitalWrite(ATL, LOW);
    delay(500);
    digitalWrite(c, HIGH);
    digitalWrite(s, HIGH);
    digitalWrite(k, HIGH);
    digitalWrite(m, LOW);
    digitalWrite(d, LOW);
    digitalWrite(ATL, LOW);
    delay(500);
        digitalWrite(c, HIGH);
    digitalWrite(s, HIGH);
    digitalWrite(k, HIGH);
    digitalWrite(m, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(ATL, LOW);
    delay(500);
        digitalWrite(c, HIGH);
    digitalWrite(s, HIGH);
    digitalWrite(k, HIGH);
    digitalWrite(m, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(ATL, LOW);
    delay(500);
        digitalWrite(c, HIGH);
    digitalWrite(s, HIGH);
    digitalWrite(k, HIGH);
    digitalWrite(m, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(ATL, HIGH);
    delay(500);
    digitalWrite(c, LOW);
    digitalWrite(s, HIGH);
    digitalWrite(k, HIGH);
    digitalWrite(m, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(ATL, HIGH);
    delay(500);
        digitalWrite(c, LOW);
    digitalWrite(s, LOW);
    digitalWrite(k, HIGH);
    digitalWrite(m, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(ATL, HIGH);
    delay(500);
        digitalWrite(c, LOW);
    digitalWrite(s, LOW);
    digitalWrite(k, LOW);
    digitalWrite(m, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(ATL, HIGH);
    delay(500);
    digitalWrite(c, LOW);
    digitalWrite(s, LOW);
    digitalWrite(k,LOW);
    digitalWrite(m, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(ATL, HIGH);
    delay(500);
    digitalWrite(c, LOW);
    digitalWrite(s,USBC`E��     
*  �2h         Մ�g    s�g            (                      (   (                     ����������g                    �                       ( @ h @   8     �%      �%     ��+���+���+�                                      c��+�c��+�c��+�                                      �