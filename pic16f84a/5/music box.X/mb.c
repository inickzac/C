#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

void make_sound(unsigned char n);
void sound_11();
void sound_12();
void sound_13();
void sound_14();
void sound_15();
void sound_16();
void song_2();
void song_1(); 
#define _XTAL_FREQ 8000
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
__EEPROM_DATA(1,2,3,4,5,6,4,33);
__EEPROM_DATA(1,234,5,16,2,56,4,3);
 unsigned char state=0;
 unsigned char is_time_over=0;
 unsigned char sec=0;


/*
 * 
 */
int main(int argc, char** argv) {

    OPTION_REGbits.INTEDG=0;
    INTCONbits.T0IE=1;
    INTCONbits.RBIE=0;
    INTCONbits.INTE=1;
    INTCONbits.T0IF=0;
    TMR0=0;
    INTCONbits.GIE=1;
    
    TRISB = 0b01111111;
    OPTION_REG = 0b00000111;
    while(1) 
    {
     if(state==1)  song_1(); 
     if(state==2)  song_2();  
        TRISA=0;
        
    }
    
    return (EXIT_SUCCESS);
}

void sound_11() 
{
    for(char i=0; i<16; i++)        
        {
           if(state==0) 
          {
             break;
          }
          PORTBbits.RB7=1;
          __delay_ms(1000);
          PORTBbits.RB7=0;
          __delay_ms(10);
        }  
}

void sound_12() 
{
    for(char i=0; i<16; i++)        
        {
           if(state==0) 
          {
             break;
          } 
          PORTBbits.RB7=1;
          __delay_ms(5);
          PORTBbits.RB7=0;
          __delay_ms(20);
        }  
}

void sound_13() 
{
    for(char i=0; i<16; i++)        
        {
           if(state==0) 
          {
             break;
          }
          PORTBbits.RB7=1;
          __delay_ms(50);
          PORTBbits.RB7=0;
          __delay_ms(4000);
        }  
}

void sound_14() 
{
    for(char i=0; i<16; i++)        
        {
           if(state==0) 
          {
             break;
          }
         PORTBbits.RB7=1;
          __delay_ms(200);
          PORTBbits.RB7=0;
          __delay_ms(100);
        }  
}

void sound_15() 
{
    for(char i=0; i<5; i++)        
        {
           if(state==0) 
          {
             break;
          }
          PORTBbits.RB7=1;
          __delay_ms(4000);
          PORTBbits.RB7=0;
          __delay_ms(1);
        }  
}

void sound_16() 
{
    for(char i=0; i<6; i++)        
        {
            if(state==0) 
          {
             break;
          }
          PORTBbits.RB7=1;
          __delay_ms(200);
          PORTBbits.RB7=0;
          __delay_ms(200);
        }  
}



void make_sound(unsigned char n) 
{
    switch(n) {
case 1:
    sound_11();
   break;
case 2:
    sound_12();
   break;
case 3:
    sound_13();
case 4:
    sound_14();
   break;
case 5:
    sound_15();
   break;
case 6:
    sound_16();   
   break;
  }    
    }

void song_1() 
{
     volatile unsigned char value = 0x00;
     unsigned char address = 0x00;
     for(char i=0; i<3; i++) 
     {
       value=eeprom_read(i);
       make_sound(value);
     }
}

void song_2() 
{
    volatile unsigned char value = 0x00;
     unsigned char address = 0x00;
     for(char i=3; i<6; i++) 
     {
       value=eeprom_read(i);
       make_sound(value);
     }
}

void __interrupt () my_isr_routine (void) 
{
    if(INTCONbits.T0IF )    
    {     
        sec++;
        if(state==1 && sec==10) 
        {
            is_time_over = 1;
            sec=0;
        }
        if(sec==10) sec=0;
        
        INTCONbits.T0IF=0;          
    }
    if(INTCONbits.INTF )    
    {     
        while(PORTBbits.RB0==0) 
        {
          __delay_ms(0);
        }
        INTCONbits.INTF=0;  
        
        
        if(state==0) 
        {
            TMR0=0;
            state++;
            is_time_over = 0;
            sec=0;
            return;
        }     
        
        if(state==2) 
        {
          state=0;       
          return;
        }      
        
        if(state==1 && is_time_over==0) 
        {
          state++;
          return;
        }        
        
        if(state==1 && is_time_over==1) 
        {
          state=0;  
          return;
        }         
     
    }

}
