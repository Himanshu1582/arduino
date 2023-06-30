#include <rds3.h>

long randNumber;

void setup()
{
    rds3.Init_LCD();
    rds3.Motor_Settings();
    rds3.Sensor_Settings();
      Serial.begin(9600); 

}


void loop()
{
  if(rds3.Sensor_1(5)==1)
  (randNumber = random(0, 5));
  
  if(randNumber==1)
  {forword();}
  
  if(randNumber==2)
  {back();}
  
  if(randNumber==3)
  {left();}
  
  if(randNumber==4)
  {right();}
  
  if(randNumber==5)
  {circle();}
  
  if(randNumber==0)
  {stoprobo();}
  
  Serial.println(randNumber);

 }

void forword()
{
  rds3.Motor_1(Clockwise, 255);
   rds3.Motor_4(Anticlockwise,255);
}

void back()
{
  rds3.Motor_4(Clockwise, 255);
   rds3.Motor_1(Anticlockwise,255);
}

void left()
{
  rds3.Motor_1(Clockwise, 255);
   rds3.Motor_4_OFF();
}

void right()
{
  rds3.Motor_4(Clockwise, 255);
   rds3.Motor_1_OFF();
}

void circle()
{
  rds3.Motor_1(Clockwise, 255);
   rds3.Motor_4(Clockwise,255);
}

void stoprobo()
{
  rds3.Motor_1_OFF();
  rds3.Motor_4_OFF();
}

