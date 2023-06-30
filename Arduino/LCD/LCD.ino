/*
   Created by Pi BOTS MakerHub

   Email: pibotsmakerhub@gmail.com

   Github: https://github.com/pibotsmakerhub

   Copyright (c) 2020 Pi BOTS MakerHub
*/


//FirebaseESP8266.h must be included before ESP8266WiFi.h
#include "FirebaseESP8266.h"  // Install Firebase ESP8266 library
#include <ESP8266WiFi.h>



#define FIREBASE_HOST "himanshu-1defa-default-rtdb.firebaseio.com" //Without http:// or https:// schemes
#define FIREBASE_AUTH "l0w3m1BTHpYHQlJ49LYfiKJMk6U0As0YNFbmdQ0e"
#define WIFI_SSID "himanshu"
#define WIFI_PASSWORD "15aug2000"

int light1 = D1;    // Connect Data pin of DHT to D2
int light2 = D2; 
int light3 = D3;
// Connect LED to D5


//Define FirebaseESP8266 data object
FirebaseData firebaseData;
FirebaseData light1Data;
FirebaseData light2Data;
FirebaseData light3Data;


FirebaseJson json;


void setup()
{

  Serial.begin(9600);

  
  pinMode(D1,OUTPUT);
   pinMode(D2,OUTPUT);
    pinMode(D3,OUTPUT);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

}

void loop() {
 
  
  if (Firebase.getString(light1Data, "/himanshu/light1Data")){
    Serial.println(light1Data.stringData());
    if (light1Data.stringData() == "1") {
    digitalWrite(D1, HIGH);
    }
  else if (light1Data.stringData() == "0"){
    digitalWrite(D1, LOW);
    }
  }
  delay(100);
}

 if (Firebase.getString(light2Data, "/himanshu/light2Data")){
    Serial.println(light2Data.stringData());
    if (light2Data.stringData() == "1") {
    digitalWrite(D2, HIGH);
    }
  else if (light2Data.stringData() == "0"){
    digitalWrite(D2, LOW);
    }
  }
  delay(100);
}

 if (Firebase.getString(light3Data, "/himanshu/light3Data")){
    Serial.println(light3Data.stringData());
    if (light3Data.stringData() == "1") {
    digitalWrite(D3, HIGH);
    }
  else if (light3Data.stringData() == "0"){
    digitalWrite(D3, LOW);
    }
  }
  delay(100);
}
