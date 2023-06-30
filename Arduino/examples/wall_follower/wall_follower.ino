#include <rds3.h>


void setup() 
{
  
rds3.Init_LCD();
rds3.Motor_Settings();
rds3.Sensor_Settings();
}
void loop()
{
  int a;
  a=rds3.Sensor_1(Analog_IR);
   if(a<400)
    {
       rds3.Display_Variable(a);
   rds3.Motor_1(Clockwise, 165);
  
   }else 
    
   {
        rds3.Motor_1_OFF();
        
   }
    int b;
  b=rds3.Sensor_2(Analog_IR);
   if(b<400)
    {
       rds3.Display_Variable(b);
   rds3.Motor_4(Anticlockwise, 150);
  
   }else 
    
   {
       
        rds3.Motor_4_OFF();
   }
   
}
   
