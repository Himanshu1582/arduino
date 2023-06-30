int sensorPin = A0; 
int sensorValue;  
int limit = 550; 
int pump = 8;

void setup() {
 Serial.begin(9600);
 pinMode(pump, OUTPUT);
 digitalWrite(pump,HIGH);
}

void loop() {

 sensorValue = analogRead(sensorPin); 
 Serial.println("Analog Value : ");
 Serial.println(sensorValue);
 
 if (sensorValue >=limit)
 {
 digitalWrite(pump, LOW);
 
 }
 else if (sensorValue < limit){
 digitalWrite(pump, HIGH); 
 }
 
 delay(1000); 
}
