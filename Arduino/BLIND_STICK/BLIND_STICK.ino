#define echoPin 2 
#define trigPin 3 
#define beeper 7
#define vibrator 8


long duration; 
int distance; 

void setup() {
  pinMode(beeper,OUTPUT);
  pinMode(vibrator,OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); 
  Serial.println("with Arduino UNO R3");
}
void loop() {
  
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.034 / 2; 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

    if (distance < 70)
    {
      if (distance > 30)
      {
      digitalWrite(beeper,HIGH);
      digitalWrite(vibrator,LOW);
      } 
      else if (distance < 30)
      {
        digitalWrite(vibrator,HIGH);
        digitalWrite(beeper,HIGH);
        
      }
    }
    else if (distance > 70)
    {
      digitalWrite(vibrator,LOW);
        digitalWrite(beeper,LOW);
    }
    
    
  }
  
