 int button1 = 2; // Push Button1 Pin D 2  
 int button2 = 3; // Push Button2 Pin D 3  
 int led1 = 12;  // Led1 Pin D 12  
 int led2 = 11;  // Led2 Pin D 11  
 int status1 = false;  
 int status2 = false;  
 void setup()  
 {  
 pinMode(led1, OUTPUT);  
 pinMode(led2, OUTPUT);  
 pinMode(button1, INPUT_PULLUP);   
 pinMode(button2, INPUT_PULLUP);   
 }  
 void loop()  
 {  
 if (digitalRead(button1) == true) // For Button 1  
 {  
 status1 = !status1 ;  
 digitalWrite(led1, status1);  
 }   
 if (digitalRead(button2) == true) // For Button 2  
 {  
 status2 = !status2 ;  
 digitalWrite(led2, status2);  
 }  
 while(digitalRead(button1) == true);  
 while(digitalRead(button2) == true);  
 delay(50);  
 } 
