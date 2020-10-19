// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#define _XTAL_FREQ 8000
unsigned char get_key(void);
void single_inc(); 
void single_dec();
void stop_gen() ;
unsigned char is_mode_changed(); 
void wait_with_check();
void grayencode(); 
void only_one();
void johnson();
unsigned char invert_byte(unsigned char a); 
char logic_bits=0;
unsigned char gray=0;
unsigned char key=0; 
unsigned char johnson_mode=0; 

int main(int argc, char** argv) {

    INTCONbits.GIE=0;
    INTCONbits.RBIE=1;
    OPTION_REGbits.nRBPU=0;
    TRISA = 0X0;
    TRISB = 0b111;
    PORTA = 0b11111100; 
    PORTB = 0X0;
     
     
    while(1) 
    {      
        switch(key) {
    case 1:
       single_inc();
     break;
    case 2:
       single_dec();
     break;
    case 3:
       grayencode();
     break;
    case 4:
       only_one();
     break;
    case 5:
      johnson();
     break;
    default  :
      stop_gen();  ;
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
        if(!PORTBbits.RB2) 
        {       
            while(!PORTBbits.RB2)
            {
              __delay_ms(1);
            }
        break;
        }
        key++;
        if(!PORTBbits.RB1)
        {
         {       
            while(!PORTBbits.RB1)
            {
              __delay_ms(1);
            }
        break;
         }       
        }
        key++;
        if(!PORTBbits.RB0) 
        {
          while(!PORTBbits.RB0)
            {
              __delay_ms(1);
            }
        break;       
        }
        key++;
        template=template <<1;
    }
    
    if(key==13)   {key=0xff;}
    return key;
}

void single_inc() 
{
    while(key==1) 
    {
        PORTA = logic_bits;      
        logic_bits++;
        wait_with_check();
    }    
}

void grayencode() 
{
     while(key==3) 
    {
        gray = logic_bits ^ (logic_bits >> 1);
         
        PORTA = gray;      
        logic_bits++;
        wait_with_check();
     }    
}

void only_one() 
{
    if(logic_bits==0) 
    {
      logic_bits=1; 
    }
while(key== 4) 
    {
      PORTA = logic_bits;
      logic_bits=logic_bits <<1;
      if(logic_bits==16) logic_bits=1;
      wait_with_check();
    }    
}
void johnson() 
{
      while(key== 5) 
     {
      if(logic_bits==0) 
      {
          johnson_mode=0;
          logic_bits=0b10001111; 
      }
      
      if(johnson_mode==0) 
      {
        logic_bits= (logic_bits << 1) | (logic_bits >> (7));     
      }
       if(johnson_mode==1) 
      {
        logic_bits = (logic_bits >> 1) | (logic_bits << (7));   
      }
      PORTA = invert_byte(logic_bits);
      wait_with_check();
    }
}

void single_dec() 
{
    while(key== 2) 
    {
      PORTA = logic_bits;
      logic_bits--;
      wait_with_check();
    }    
}

void stop_gen() 
{
  is_mode_changed();  
}

unsigned char is_mode_changed() 
{
    unsigned char temp_key = get_key();
    if(temp_key!=0xff ) 
    {
        key=temp_key;
        logic_bits=0;
        PORTA = 0;
        return 1;
    }
    return 0;
}

void wait_with_check() 
{
    for(int i=0; i<800; i++) 
    {       
        if(is_mode_changed()) 
        {
            break;
        }
        __delay_ms(1);
    } 
}

unsigned char invert_byte(unsigned char a) 
{
    unsigned char b;
    for(int i = 0; i < 8; i++) 
    {
      b = b<<1;
      b += a%2;
      a = a>>1;
    }
    return b;
}