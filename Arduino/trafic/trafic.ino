
const int IR1 = 13;
const int IR2 = 12;
const int IR3 = 11;
const int IR4 = 10;
const int IR5 = 9;
const int ledPin1 =  8; 
const int ledPin2 = 7;

 int r = 100;
 int g = 100;


void setup() {

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
  if(digitalRead(IR1)== HIGH)
  {
    r = 1000;
    g = 500;
    }
  if(digitalRead(IR2)== HIGH)
  {
        r = 1000;
    g = 50;
    }
  if(digitalRead(IR2)== HIGH)
  {
        r = 100;
    g = 50;
    }
  if(digitalRead(IR2)== HIGH)
  {
        r = 100;
    g = 50;
    }
  if(digitalRead(IR2)== HIGH)
  {
        r = 1000;
    g = 50;
    }
  
  digitalWrite(ledPin1,HIGH);
  delay(r);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,HIGH);
  delay(g);
  digitalWrite(ledPin2,LOW);
  
}
