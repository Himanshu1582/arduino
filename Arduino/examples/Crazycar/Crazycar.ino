#include<rds3.h>


void setup()
{
  rds3.Init_LCD();
    rds3.Motor_Settings();
      Serial.begin(9600); 


}

void loop()
{

    rds3.Motor_1(Clockwise, 255);
    rds3.Motor_2(Anticlockwise, 255);
      delay(1000);
    rds3.Motor_3(Clockwise, 255);
     delay(300);
    

 
 
}

