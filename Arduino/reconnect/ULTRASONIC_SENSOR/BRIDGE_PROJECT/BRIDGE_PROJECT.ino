

const int butonforwardpin = 5 ;
const int buttonreversePin = 4;     
const int motorpostivepin  =  2;  
const int motornegativepin =  3;   


int buttonState1 = 0;
int buttonState2 = 0;            

void setup() {

  pinMode(motorpostivepin, OUTPUT);
  pinMode(motornegativepin, OUTPUT);
 
  pinMode(butonforwardpin, INPUT);
   pinMode(buttonreversePin, INPUT);
}

void loop() 
{  buttonState1 = digitalRead(butonforwardpin);
buttonState2 = digitalRead(buttonreversePin);


 
  if (buttonState1 == HIGH)
  {
  
    digitalWrite(motorpostivepin, HIGH);
    digitalWrite(motornegativepin, LOW);
  } 
  else if (buttonState2 == HIGH) 
  {
  
    digitalWrite(motorpostivepin, LOW);
    digitalWrite(motornegativepin, HIGH);
  }
  else 
  
  {
   
     digitalWrite(motorpostivepin, LOW);
    digitalWrite(motornegativepin, LOW);
  }
}
