//MOTOR1 PINS
int in1 = 6; //making all the pin integers
int in2 = 7;
int in3 = 10;
int in4 = 11;

void setup() {

  pinMode(in1, OUTPUT); //Setting all the pins as outputs
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

digitalWrite(in1, HIGH); //Making car go straight
digitalWrite(in2, LOW);
digitalWrite(in4, LOW);
digitalWrite(in3, HIGH);
delay(2000); //Delaying it for 2 seconds

  digitalWrite(in1,LOW); //Stopping the car
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(2000); //Stopping the car


digitalWrite(in1, HIGH); //Making the car go left
digitalWrite(in2, LOW);
delay(2000);

  digitalWrite(in1,LOW); //Making the car stop
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(2000); //Stopping the car

digitalWrite(in1, LOW); //Making the car go backwards
digitalWrite(in2, HIGH);
digitalWrite(in4, HIGH);
digitalWrite(in3, LOW);
delay(2000); //Stopping the car

  digitalWrite(in1,LOW); //Stopping the car
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);

}

void loop() {
                  
 
}
