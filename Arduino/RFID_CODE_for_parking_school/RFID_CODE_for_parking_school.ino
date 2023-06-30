#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 Servo myservo; 
 int buzz = 7;
int pos = 0; 
void setup() 
{
  myservo.attach(8); 
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  pinMode(buzz,OUTPUT);

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "63 EF 3E 3D") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("AUTHORISED");
    Serial.println();
    for(pos = 0; pos <= 90; pos += 1) 
  { 
    myservo.write(pos); 
    delay(20); 
    Serial.print(pos);
  }
  delay(3000);
  
  for(pos = 90; pos>=0; pos-=1) 
  {
    myservo.write(pos);
    delay(20);
    Serial.print(pos);
  }
    delay(2000);
  }
    if (content.substring(1) == "F7 BB AF D6") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("AUTHORISED");
    Serial.println();
    for(pos = 0; pos <= 90; pos += 1) 
  { 
    myservo.write(pos); 
    delay(20); 
    Serial.print(pos);
  }
  delay(3000);
  
  for(pos = 90; pos>=0; pos-=1) 
  {
    myservo.write(pos);
    delay(20);
    Serial.print(pos);
  }
    delay(2000);
  }

      if (content.substring(1) == "DC 1A 5A 2F") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("AUTHORISED");
    Serial.println();
    for(pos = 0; pos <= 90; pos += 1) 
  { 
    myservo.write(pos); 
    delay(20); 
    Serial.print(pos);
  }
  delay(3000);
  
  for(pos = 90; pos>=0; pos-=1) 
  {
    myservo.write(pos);
    delay(20);
    Serial.print(pos);
  }
    delay(2000);
  }
 
 else   if (content.substring(1) == "B2 5B 8F 31") 
  { 
    Serial.println(" NOT AUTHORISED");
    digitalWrite(buzz,HIGH);
    delay(2000);
    digitalWrite(buzz,LOW);
  }
}
