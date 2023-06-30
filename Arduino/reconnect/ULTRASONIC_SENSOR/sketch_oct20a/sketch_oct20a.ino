/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled 2"
  https://create.arduino.cc/cloud/things/c0c2f0d2-2759-4e66-9ccd-200155d08a57 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  CloudLight bulbtwo;
  CloudLight bulbone;
  CloudLight bulbthree;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"

void setup() {
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  digitalWrite(D0,HIGH);
  digitalWrite(D1,HIGH);
  digitalWrite(D2,HIGH);
  
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  
  
}

/*
  Since Bulbtwo is READ_WRITE variable, onBulbtwoChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onBulbtwoChange()  {
  if(bulbtwo == 1) 
    {
      digitalWrite(D1,LOW);
    }
    else 
    {
      digitalWrite(D1,HIGH);
    }
  // Add your code here to act upon Bulbtwo change
}
/*
  Since Bulbone is READ_WRITE variable, onBulboneChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onBulboneChange()  {
    if(bulbone == 1) 
    {
      digitalWrite(D0,LOW);
    }
    else 
    {
      digitalWrite(D0,HIGH);
    }
  // Add your code here to act upon Bulbone change
}
/*
  Since Bulbthree is READ_WRITE variable, onBulbthreeChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onBulbthreeChange()  {
    if(bulbthree == 1) 
    {
      digitalWrite(D2,LOW);
    }
    else 
    {
      digitalWrite(D2,HIGH);
    }
  // Add your code here to act upon Bulbthree change
}