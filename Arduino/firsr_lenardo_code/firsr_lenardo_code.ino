#include <rds3.h>
int i=0;
void setup()
{
  rds3.Init_LCD();
  rds3.Motor_Settings();
  rds3.Sensor_Settings();
  Serial.begin(9600); 

}


void loop()
{
  int x;
  x= rds3.Sensor_2(Analog_IR);

  Serial.println(x); 
  if(x>800)
    i++;
  {

    if(i<=10)
    {
      rds3.Motor_1(Clockwise, 100);
      rds3.Motor_4(Anticlockwise,100);
      rds3.Display_Variable(i);
      delay(1000);
    }
    else 
    {
      rds3.Motor_1_OFF();
      rds3.Motor_4_OFF();
    }
  }
}
