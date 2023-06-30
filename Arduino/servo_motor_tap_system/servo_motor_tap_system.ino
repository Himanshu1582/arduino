#include <Stepper.h>
int IR = 45;

int direction1 = 0;
int OT = 0; 

const int stepsPerRevolution = 200;
int stepCount = 0;
Stepper myStepper(stepsPerRevolution, 50, 51, 52, 53);

void setup() {
 
   myStepper.setSpeed(60);
  
   Serial.begin(9600);
   pinMode(IR , INPUT);
}

void loop() 
{
  if (digitalRead(IR) == 1)
  { 
  myStepper.step(0);

  OT = stepCount;
   Serial.println(OT);
  delay(200);
  
  }
  
  if(digitalRead(IR) ==0)
  {
  if (direction1 == 0)
  {

while(stepCount >=0 && stepCount <=800 && digitalRead(IR)==0)

      
      {
     myStepper.step(1);
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount++;
  delay(1);
  OT = 0;
  
  if (stepCount == 801)
  {direction1 = 1;
    }
    
    }
  }

    else if(direction1 ==1)
    {
while(stepCount >=1 && stepCount <= 801 &&digitalRead(IR)==0)
    {
           myStepper.step(-1);
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount--;
  OT = 0;
  delay(1);
  if(stepCount == 0)
  {
    direction1 = 0;
    }
    }
    }
}
  }
