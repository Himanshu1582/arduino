#include <Stepper.h>
//int IR = 26;

int direction1 = 0;

const int stepsPerRevolution = 200;
int stepCount = 0;
Stepper myStepper(stepsPerRevolution, 22,24, 26, 28);

void setup() {
 
   myStepper.setSpeed(60);
  
   Serial.begin(9600);
//   pinMode(IR , INPUT);
}

void loop() 
{
 if (direction1 == 0)
{
while(stepCount >=0 && stepCount <=600 )

      
      {
     myStepper.step(1);
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount++;
  delay(1);
  
  if (stepCount == 601)
  {
    direction1 = 1;
    }
    
    }
}
  

    else if(direction1 ==1)
    {
while(stepCount >=1 && stepCount <= 601 )
    {
           myStepper.step(-1);
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount--;
  delay(1);
  if(stepCount == 0)
  {
    direction1 = 0;
    }
    }
    }
}
  
