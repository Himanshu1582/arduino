int blue = 9;
int yellow = 10;

int brightness = 0;   
int fadeAmount = 5;

void setup() {

  pinMode(blue, OUTPUT);
  pinMode(yellow, OUTPUT);
}

// the loop function runs over and over again forever
void loop() 
{
  for (int i = 0; i <= 500; i++)

  {
  analogWrite(blue, brightness);
  analogWrite(yellow, brightness);

  brightness = brightness + fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  delay(100);
    
    }
      for (int i = 0; i <= 500; i++)

  {
  analogWrite(blue, brightness);
 
digitalWrite(yellow,LOW);
  brightness = brightness + fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
    
    delay(50);
    digitalWrite(yellow,HIGH);
  }
  delay(100);
    
    }

    for (int i = 0; i <= 500; i++)

  {
  analogWrite(yellow, brightness);
 
  digitalWrite(blue,LOW);
  brightness = brightness + fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
    
    delay(50);
    digitalWrite(blue,HIGH);
  }
  delay(100);
    
    }
  digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);  

    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);  


    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  

    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  

    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  
    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  

      digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  

    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  

    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  
    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  

      digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  

    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  

    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  
    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  

      digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  

    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  

    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  
    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  

      digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  

    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  

    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(500);  
    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(500);  

     digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(500);  
    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(500); 
     digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(500);  
    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(500); 
     digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(500);  
    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(500); 

     digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  
    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100); 

       digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  
    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);      digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  
    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);      digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  
    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);      digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  
    digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(100); 
}
