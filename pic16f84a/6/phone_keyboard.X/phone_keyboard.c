

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#define _XTAL_FREQ 8000
__EEPROM_DATA(1,2,3,4,5,6,7,8);
__EEPROM_DATA(9,10,11,12,5,6,7,8);
void read_tone(unsigned char key);
void sound_1();
void sound_2();
void sound_3();
void sound_4();
void sound_5();
void sound_6();
void sound_7();
void sound_8();
void sound_9();
void sound_10();
void sound_11();
void sound_12();
void make_sound(unsigned char n); 
unsigned char get_key(void);
int main(int argc, char** argv) {

    TRISA = 0X0;
    TRISB = 0b1111;
    PORTA = 0b11111100; 
    PORTB = 0X0;
    INTCONbits.GIE=0;
    INTCONbits.RBIE=1;
    OPTION_REGbits.nRBPU=0;
    unsigned char key=0;
    while(1) 
    {
        key = get_key();
        if(key!=0xff) 
        {
                   
        }
    }
    return (EXIT_SUCCESS);
}

unsigned char get_key(void)
{
    char key, template;
    key =1; template=0b11101111;
    while(key<13) 
    {
        PORTB = template;
        if(!PORTBbits.RB3) 
        {       
            while(!PORTBbits.RB3)
            {
              read_tone(key);
            }
        break;
        }
        key++;
        if(!PORTBbits.RB2)
        {
         {       
            while(!PORTBbits.RB2)
            {
              read_tone(key); 
            }
        break;
         }       
        }
        key++;
        if(!PORTBbits.RB1) 
        {
          while(!PORTBbits.RB1)
            {
               read_tone(key);  
            }
        break;       
        }
        key++;
        template=template <<1;
    }
    
    if(key==13)   {key=0xff;}
    return key;
}

void sound_1() 
{  
          PORTAbits.RA0=1;
          __delay_ms(5);
          PORTAbits.RA0=0;
          __delay_ms(10);
}

void sound_2() 
{
     PORTAbits.RA0=1;
          __delay_ms(10);
          PORTAbits.RA0=0;
          __delay_ms(10);
}

void sound_3() 
{
    PORTAbits.RA0=1;
          __delay_ms(20);
          PORTAbits.RA0=0;
          __delay_ms(60);
}

void sound_4() 
{
    PORTAbits.RA0=1;
          __delay_ms(40);
          PORTAbits.RA0=0;
          __delay_ms(5);
}

void sound_5() 
{
    PORTAbits.RA0=1;
          __delay_ms(50);
          PORTAbits.RA0=0;
          __delay_ms(20);
}

void sound_6() 
{
    PORTAbits.RA0=1;
          __delay_ms(1);
          PORTAbits.RA0=0;
          __delay_ms(60);
}

void sound_7() 
{
    PORTAbits.RA0=1;
          __delay_ms(3);
          PORTAbits.RA0=0;
          __delay_ms(88);
}

void sound_8() 
{
    PORTAbits.RA0=1;
          __delay_ms(56);
          PORTAbits.RA0=0;
          __delay_ms(90);
}

void sound_9() 
{
    PORTAbits.RA0=1;
          __delay_ms(3);
          PORTAbits.RA0=0;
          __delay_ms(2);
}

void sound_10() 
{
    PORTAbits.RA0=1;
          __delay_ms(1);
          PORTAbits.RA0=0;
          __delay_ms(90);
}

void sound_11() 
{
    PORTAbits.RA0=1;
          __delay_ms(3);
          PORTAbits.RA0=0;
          __delay_ms(45);
}

void sound_12() 
{
    PORTAbits.RA0=1;
          __delay_ms(9);
          PORTAbits.RA0=0;
          __delay_ms(90);
}

void make_sound(unsigned char n) 
{
    switch(n) {
case 1:
    sound_1();
   break;
case 2:
    sound_2();
   break;
case 3:
    sound_3();
   break;
case 4:
    sound_4();
   break;
case 5:
    sound_5();
   break;
case 6:
    sound_6();   
   break;
case 7:
    sound_7();   
   break;
case 8:
    sound_8();   
   break;
case 9:
    sound_9();   
   break;
case 10:
    sound_10();   
   break;
case 11:
    sound_11();   
   break;
case 12:
    sound_12();   
   break;
  }    
}

void read_tone(unsigned char key) 
{
   volatile unsigned char value = 0x00;
   unsigned char address = 0x00;        
   value=eeprom_read(key);
   make_sound(value);
}