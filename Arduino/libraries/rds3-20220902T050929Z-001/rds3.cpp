#include<avr/io.h>
#include<util/delay.h>
#include <inttypes.h>
#include <Arduino.h>
#include <rds3.h>





#define BIT(x)	(1 << (x))
#define LINE1	0x80
#define LINE2	0xC0
unsigned char k=0,j=0;
unsigned char save=0;

unsigned char ch[10] = {'0','1','2','3','4','5','6','7','8','9'};
 unsigned char tenthousand=0,thousand=0,hundred=0,ten=0,one=0;

void lcd_init(void);
void lcd_cmd(unsigned char cmd);
void toggleE(void);
void dely_ns(int tim);
void lcd_char(unsigned char single);
void lcd_DATAing(unsigned char DATA[32]);
void lcd_showvalue(unsigned char num);
void lcd_gotoxy1(unsigned char pos);
void lcd_gotoxy2(unsigned char pos);
void lcd_exit(void);
void WaitMs(unsigned int ms);
void lcd_int(unsigned int);
void lcd_signedint(signed int);

int count;

     int u_sonic_1()
    {
         count=0;
         CLEARBIT(PORTF, BIT5);
         SETBIT(PORTF, BIT6);
         _delay_us(10);
         CLEARBIT(PORTF, BIT6);
         for (int i=0;	i< 10000; i++)// Checking port in loop 10,000 times
         {
             if (CHECKBIT(PINF,BIT5))
             {       	 // read PORTF pin 5 for echo pulse
                 count++;  				 // count if still high count
             } //else{count=count;}
         }
		 _delay_ms(30);
         return count/91;
		 
    }

     int u_sonic_2()
    {
         count=0;
         CLEARBIT(PORTF, BIT4);
         SETBIT(PORTF, BIT6);
         _delay_us(10);
         CLEARBIT(PORTF, BIT6);
         for (int i=0;i < 10000;i++)// Checking port in loop 10,000 times
         {
             if (CHECKBIT(PINF,BIT4))
             {       	 // read PORTF pin 5 for echo pulse
                 count++;  				 // count if still high count
             } //else{count=count;}
         }
		 _delay_ms(30);
         return count/91;
     }

     int u_sonic_3()
    {
         count=0;
         CLEARBIT(PORTF, BIT1);
         SETBIT(PORTF, BIT6);
         _delay_us(10);
         CLEARBIT(PORTF, BIT6);
         for (int i=0;i < 10000;i++)// Checking port in loop 10,000 times
         {
             if (CHECKBIT(PINF,BIT1))
             {       	 // read PORTF pin 5 for echo pulse
                 count++;  				 // count if still high count
             } //else{count=count;}
         }
		 _delay_ms(30);
         return count/91;
     }

     int u_sonic_4()
     {
         count=0;
         CLEARBIT(PORTF, BIT0);
         SETBIT(PORTF, BIT6);
         _delay_us(10);
         CLEARBIT(PORTF, BIT6);
         for (int i=0;i < 10000;i++)// Checking port in loop 10,000 times
         {
             if (CHECKBIT(PINF,BIT0))
             {       	 // read PORTF pin 5 for echo pulse
                 count++;  				 // count if still high count
             } //else{count=count;}
         }
		 _delay_ms(30);
         return count/91;
     }



     void initadc()
    {
        ADMUX=(1<<REFS0);                         // For Aref=AVcc;
        ADCSRA = BIT7 | BIT3 | BIT2 | BIT1 | BIT0;

    }


     int ReadADC(char ch)
    {
       //Select ADC Channel ch must be 0-7
       ch=ch&0b00000111;

       ADMUX|=ch;

       //Start Single conversion
       ADCSRA|=(1<<ADSC);

       //Wait for conversion to complete
       while(!(ADCSRA & (1<<ADIF)));
       //Clear ADIF by writing one to it
       //Note you may be wondering why we have write one to clear it
       //This is standard way of clearing bits in io as said in datasheets.
       //The code writes '1' but it result in setting bit to '0' !!!

       ADCSRA|=(1<<ADIF);
       return(ADC/4);
    }



     void CLEAR_LCD()
    {
         lcd_cmd(0x01);
        _delay_ms(10);
        lcd_cmd(0x02);
        _delay_ms(10);
    }

     void RDS3::Init_LCD()	//init the lcd
    {
        save=PORTD;
        DDRD=0xFF;
        CLEARBIT(DDRD, BIT1);
        CLEARBIT(DDRD, BIT3);
        SETBIT(PORTD,BIT1);
        SETBIT(PORTD,BIT3);
        //DDRB=0xFF;
        WaitMs(15);
        CLEARBIT(PORTD,BIT(0)+BIT(2));
        PORTD=0x22;
        lcd_cmd(0x01);
        lcd_cmd(0x0F);
        lcd_cmd(0x02);
        //lcd_cmd(0x38);
       // lcd_cmd(LINE1);
	   CLEAR_LCD();
    }

     void toggleE()
    {
        SETBIT(PORTD,BIT(2));
        dely_ns(230);
        CLEARBIT(PORTD,BIT(2));
    }

     void dely_ns(int tim)
    {
        for(j=0;j<tim;j++)
        {
            for(k=0;k<10;k++)
            {};
        }
    }

     void lcd_cmd(unsigned char cmd)
    {
        CLEARBIT(PORTD,BIT(0)+BIT(2));
        PORTD=((cmd&0xF0));
        toggleE();
        dely_ns(230);
        PORTD=(((cmd&(0x0F))*16));
        toggleE();
        dely_ns(230);
    }


     void lcd_char(unsigned char single)
    {
        SETBIT(PORTD, BIT0);
        CLEARBIT(PORTD, BIT2);

        PORTD=(single&0xF0)|0x01;
        toggleE();
        dely_ns(230);
        PORTD=((single&(0x0F))*16)|0x01;
        toggleE();
        dely_ns(230);
    }

     void lcd_int(unsigned int value)
    {
        tenthousand=value/10000;
        value=value%10000;
        thousand=value/1000;
        value=value%1000;
        hundred=value/100;
        value=value%100;
        ten=value/10;
        one=value%10;
        //ten=(value - (hundred*100))/10;
        //one=(value - (hundred*100) - (ten*10));

       // lcd_char(ch[tenthousand]);
        //lcd_char(ch[thousand]);
        lcd_char(ch[hundred]);
        lcd_char(ch[ten]);
        lcd_char(ch[one]);
        //lcd_char('');

        /*if(lcd_count==3)
            {
            lcd_count=0;
            lcd_cmd(PUTLINE1);
            line_count++;
            if(line_count%2==0)
                {

                lcd_cmd(PUTLINE2);
                }
            else
                {
                lcd_cmd(PUTLINE1);
                }
            }*/
    }



     void lcd_showvalue(unsigned char num)	//prints the decimal 3digit value of num
    {
        unsigned char H=0,T=0,O=0;
        H=num/100;
        T=(num - (H*100))/10;
        O=(num - (H*100) - (T*10));

        lcd_char(H+48);
        lcd_char(T+48);
        lcd_char(O+48);
        lcd_char(' ');
    }

     void lcd_gotoxy1(unsigned char pos)
    {
        lcd_cmd(LINE1+pos);
    }

     void lcd_gotoxy2(unsigned char pos)
    {
        lcd_cmd(LINE2+pos);
    }

     void lcd_exit(void)
    {
        PORTD=save;
    }

    /* waits (pauses) for ms milliseconds (assumes clock at 16MHz) */
     void WaitMs(unsigned int ms)
    {
        int i;

        while (ms-- > 0)
        {
            /* 16380 (16k) clock cycles for 1ms; each time through loop
               is 5 cycles (for loop control + nop) */
            for (i = 0; i < 3276; ++i)
                asm("nop");
        }
    }
	
	void Display_string(char DATA[16])
	{
		unsigned int k;
		k=0;
		lcd_cmd(0x80);
           
            SETBIT(PORTD, BIT0);
            CLEARBIT(PORTD, BIT2);
			
                while(DATA[k]!='\0')	//Till null character is encountered
                {
                    if(k==8)
                    lcd_cmd(LINE2);
                 //   SETBIT(PORTD, BIT0);
                    PORTD=((DATA[k])&0xF0)|0x01;
                    toggleE();
                    dely_ns(230);
                    PORTD=((DATA[k]&(0x0F))*16)|0x01;
                    toggleE();
                    dely_ns(230);
                    k++;
                }
	}


    /****************************************** CASE TO DISPLAY CHARACTER ON LCD ******************************************/

     void RDS3::Display_Data( int POS, char DATA[16])
    {
		
        unsigned int k;
		k=0;

        switch (POS)
        {
            case 1:
			//lcd_cmd(0x02);
            lcd_cmd(0x80);
           
            SETBIT(PORTD, BIT0);
            CLEARBIT(PORTD, BIT2);
			
                while(DATA[k]!='\0')	//Till null character is encountered
                {
                    if(k==8)
                    lcd_cmd(LINE2);
                 //   SETBIT(PORTD, BIT0);
                    PORTD=((DATA[k])&0xF0)|0x01;
                    toggleE();
                    dely_ns(230);
                    PORTD=((DATA[k]&(0x0F))*16)|0x01;
                    toggleE();
                    dely_ns(230);
                    k++;
                }
            break;

            case 2:
         //  lcd_cmd(0x02);
            lcd_cmd(0xc0);
            
			
                while(DATA[k]!='\0')	//Till null character is encountered
                {
                    if(k==8)
                    lcd_cmd(LINE1);
                  //  SETBIT(PORTD, BIT0);
                    PORTD=((DATA[k])&0xF0)|0x01;
                    toggleE();
                    dely_ns(230);
                    PORTD=((DATA[k]&(0x0F))*16)|0x01;
                    toggleE();
                    dely_ns(230);
                    k++;
                }
             break;
         }
    }

    /****************************************** DISPLAY VARAIBLE VALUE ON LCD ******************************************/
	
     void RDS3::Display_Variable(int x)
	{
		lcd_cmd(0x80);
	  lcd_int(x);
	}
		
	

   

    /****************************************** SENSOR SETTINGS ******************************************/

     void RDS3::Sensor_Settings()
    {
         pinMode(A2, INPUT);
         pinMode(A3, INPUT);
         pinMode(A4, INPUT);
         pinMode(A5, INPUT);
         pinMode(A1, OUTPUT);
         digitalWrite(A2, HIGH);
         digitalWrite(A3, HIGH);
         digitalWrite(A4, HIGH);
         digitalWrite(A5, HIGH);
    }
    /*********************************  SENSOR 1 *********************************/

         int RDS3::Sensor_1(char y)
         {
            int f;
            switch (y)
            {
            case 0:                     //analog ir
                f=analogRead(A2);
            break;

            case 1:                     //ultrasonic
                f=u_sonic_1();
            break;

            case 2:                     //Temprature
                f=analogRead(A2);
            break;

            case 3:                     //light
                f=analogRead(A2);
            break;

            case 4:                     //touch
                f=digitalRead(A2);
                delay(10);

            break;

            case 5:                     //sound
                f=digitalRead(A2);
                delay(10);
            break;
            }

            return f;
        }


         /*********************************  SENSOR 2 *********************************/

         int RDS3::Sensor_2(char y)
         {
            int f;
            switch (y)
            {
            case 0:                     //analog ir
                f=analogRead(A3);
            break;

            case 1:                     //ultrasonic
                f=u_sonic_2();
            break;

            case 2:                     //Temprature
                f=analogRead(A3);
            break;

            case 3:                     //light
                f=analogRead(A3);
            break;

            case 4:                     //touch
                f=digitalRead(A3);
                delay(10);

            break;

            case 5:                     //sound
                f=digitalRead(A3);
                delay(10);
            break;
            }

            return f;
        }

         /*********************************  SENSOR 3 *********************************/

         int RDS3::Sensor_3(char y)
         {
            int f;
            switch (y)
            {
            case 0:                     //analog ir
                f=analogRead(A4);
            break;

            case 1:                     //ultrasonic
                f=u_sonic_3();
            break;

            case 2:                     //Temprature
                f=analogRead(A4);
            break;

            case 3:                     //light
                f=analogRead(A4);
            break;

            case 4:                     //touch
                f=digitalRead(A4);
                delay(10);

            break;

            case 5:                     //sound
                f=digitalRead(A4);
                delay(10);
            break;
            }

            return f;
        }

         /*********************************  SENSOR 4 *********************************/

         int RDS3::Sensor_4(char y)
         {
            int f;
            switch (y)
            {
            case 0:                     //analog ir
                f=analogRead(A5);
            break;

            case 1:                     //ultrasonic
                f=u_sonic_4();
            break;

            case 2:                     //Temprature
                f=analogRead(A5);
            break;

            case 3:                     //light
                f=analogRead(A5);
            break;

            case 4:                     //touch
                f=digitalRead(A5);
                delay(10);

            break;

            case 5:                     //sound
                f=digitalRead(A5);
                delay(10);
            break;
            }

            return f;
        }


    /****************************************** END SENSOR SETTINGS ******************************************/



             /*
                   MOTOR Connection

                    PORTB 0 to 3-----------	Motor1 Driver connection

                    PORTD 4 to 7 --------		Motor2 Driver Connection
               */


     /****************************************** MOTOR SETTINGS ******************************************/


      void RDS3::Motor_Settings()
      {
          /* MOTOR 1 */
          SETBIT(DDRB, BIT1);
          SETBIT(DDRB, BIT5);
          /* MOTOR 2 */
          SETBIT(DDRB, BIT2);
          SETBIT(DDRB, BIT6);
          /* MOTOR 3 */
          SETBIT(DDRB, BIT3);
          SETBIT(DDRC, BIT6);
          /* MOTOR 4 */
          SETBIT(DDRF, BIT7);
          SETBIT(DDRC, BIT7);
		  
		  /* MOTOR 1 */
          SETBIT(PORTB, BIT1);
          SETBIT(PORTB, BIT5);
          /* MOTOR 2 */
          SETBIT(PORTB, BIT2);
          SETBIT(PORTB, BIT6);
          /* MOTOR 3 */
          SETBIT(PORTB, BIT3);
          SETBIT(PORTC, BIT6);
          /* MOTOR 4 */
          SETBIT(PORTF, BIT7);
          SETBIT(PORTC, BIT7);
		  
		  Motor_1_OFF();
		  Motor_2_OFF();
		  Motor_3_OFF();
		  Motor_4_OFF();
		  
		 

      }


     /****************************************** PWM SETTINGS ******************************************/

      void InitPWM()
      {
          //Set 8-bit PWM mode
         TCCR0A |= (1<<WGM00)|(1<<COM0A1)|(1<<COM0A0);
          TCCR0B |= (1<<CS00);

          //Set 8-bit  PWM mode
          TCCR1A |= (1<<WGM10)|(1<<WGM12)|(1<<COM1A1)| (1<<COM1B1);
          TCCR1B |= (1<<CS10);

          //Set 8-bit  PWM mode
          TCCR3A |= (1<<WGM30)|(1<<WGM32)|(1<<COM3A1) ;
          TCCR3B |= (1<<CS30);

          //Set 8-bit  PWM mode
          TCCR4A |= (1 << COM4A1)|  (1 << PWM4A ) ; // Enable outputs A and B in PWM mode
          TCCR4B |= (1 << CS40);
          TCCR4D |= (1<<WGM40);
      }

      void motor1(uint8_t duty)
      {
          OCR1A=(duty);                //PIN 32
      }

      void motor2(uint8_t duty)
      {
          OCR1B=(duty);               //PIN 31
      }

      void motor3(uint8_t duty)
      {
          OCR3A=(duty);                //PIN 29
      }

      void motor4(uint8_t duty)
      {
          OCR4A=(duty);               //PIN 30
      }
	  
	  void buzzer(uint8_t duty)
      {
          OCR1C=(duty);               //PIN 30
      }


      /****************************************** MOTOR1  ******************************************/
      void RDS3::Motor_1(char y, char x)
      {

          InitPWM();
          switch (y)
          {
          case 0:
              SETBIT(PORTB, BIT1);
              motor1(255-x);
           break;

           case 1:
              motor1(x);
              CLEARBIT(PORTB, BIT1);
            break;
           }

      }

      /****************************************** MOTOR2 ******************************************/
      void RDS3::Motor_2(char y, char x)
      {
          InitPWM();
          switch (y)
          {
          case 0:
              SETBIT(PORTB, BIT2);
              motor2(255-x);
          break;

          case 1:
              motor2(x);
              CLEARBIT(PORTB, BIT2);
          break;
          }

      }

      /****************************************** MOTOR3  ******************************************/
      void RDS3::Motor_3(char y, char x)
      {
          InitPWM();
          switch (y)
          {
          case 0:
              SETBIT(PORTB, BIT3);
              motor3(255-x);
          break;

          case 1:
              motor3(x);
              CLEARBIT(PORTB, BIT3);
          break;
          }

      }

      /****************************************** MOTOR4 ******************************************/
      void RDS3::Motor_4(char y, char x)
      {
          InitPWM();
          switch (y)
          {
          case 0:
              SETBIT(PORTF, BIT7);
              motor4(255-x);
          break;
          case 1:
              motor4(x);
              CLEARBIT(PORTF, BIT7);
          break;

      }
      }


      /****************************************** MOTOR1 OFF ******************************************/
      void RDS3::Motor_1_OFF()
      {
          SETBIT(PORTB, BIT1);
          motor1(255);
      }

      /****************************************** MOTOR2 OFF ******************************************/
      void RDS3::Motor_2_OFF()
      {
          SETBIT(PORTB, BIT2);
          motor2(255);
      }

      /****************************************** MOTOR3 OFF ******************************************/
      void RDS3::Motor_3_OFF()
      {
          SETBIT(PORTB, BIT3);
          motor3(255);
      }

      /****************************************** MOTOR4 OFF ******************************************/
      void RDS3::Motor_4_OFF()
      {
          SETBIT(PORTF, BIT7);
          motor4(255);
      }

        void RDS3::Buzzer_Settings()
        {
            SETBIT(DDRB, BIT7);
        }

        void RDS3::Buzzer(int x)
        {
			InitPWM();
			if(x>0)
			{
            buzzer(255);              //PIN 12
            Delay_Sec(x);
			buzzer(0);
			}else
			{
			buzzer(255);
			}
        }
		
        void RDS3::Buzzer_Off()
		{
			buzzer(0);	
		}



      void RDS3::Switch_Settings()
      {
          CLEARBIT(DDRB, BIT0);		/* SWITCH 1 */
          CLEARBIT(DDRB, BIT4);		/* SWITCH 2 */
          CLEARBIT(DDRD, BIT1);		/* SWITCH 3 */
          CLEARBIT(DDRD, BIT3);    	/* SWITCH 4 */

          SETBIT(PORTB,BIT0);       /* SWITCH 1 PULL UP*/
          SETBIT(PORTB,BIT4);     	/* SWITCH 2 PULL UP*/
          SETBIT(PORTD,BIT1);     	/* SWITCH 3 PULL UP*/
          SETBIT(PORTD,BIT3);     	/* SWITCH 4 PULL UP*/
      }


      /****************************************** SWITCH 1 ******************************************/

      int RDS3::Switch_3()
      {
          if(!CHECKBIT(PINB, BIT4))
          {return 1;}
          else{return 0;}
      }

      /****************************************** SWITCH 2 ******************************************/

      int RDS3::Switch_1()
      {
           if(!CHECKBIT(PINB, BIT0))
           {return 1;}
           else{return 0;}
      }

      /****************************************** SWITCH 3 ******************************************/

      int RDS3::Switch_2()
      {
            if(!CHECKBIT(PIND, BIT1))
            {return 1;}
            else{return 0;}
      }

      /****************************************** SWITCH 4 ******************************************/

      int RDS3::Switch_4()
      {
          if(!CHECKBIT(PIND, BIT3))
          {return 1;}
          else{return 0;}
      }

RDS3 rds3;
