
#define _XTAL_FREQ 8000
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
__EEPROM_DATA(10,1,2,3,4,12,1,1); //user 1234 pas 1111
__EEPROM_DATA(1,1,10,1,1,1,1,12); //user 1111 pas 2222
__EEPROM_DATA(2,2,2,2,10,2,2,2); //user 2222 pas 3333
__EEPROM_DATA(2,12,3,3,3,3,10,3); //user 3333 pas 4444
__EEPROM_DATA(3,3,3,12,4,4,4,4);

void check_user(char keys[10]); 
unsigned char check_imput_string(char keys[10]);
unsigned char get_key(void);
void show_error();

int main(void) {
unsigned char data;
char keys[10]; 
unsigned char key;
unsigned char quantityChar;
    
    TRISA = 0X0;
    TRISB = 0b111;
    PORTA = 0b11111100; 
    PORTB = 0X0;
    INTCONbits.GIE=0;
    INTCONbits.RBIE=1;
    OPTION_REGbits.nRBPU=0;
    
    while(1) 
    {      
        key= get_key();
        if(key!=0xff) 
          {
            if(quantityChar<10) 
            {
               keys[quantityChar] = key;
               quantityChar++;
            }
            if(quantityChar==10) 
            {
               check_imput_string(keys);
               quantityChar=0;
            }
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

unsigned char check_imput_string(char keys[10]) 
{   
    if(keys[0]==10 && keys[5]==12) 
    {             
        check_user(keys);       
       
    }
    return 0xff;
}


void check_user(char keys[10]) 
{ 
    char is_exist=0;
    volatile unsigned char value = 0x00;
    unsigned char address = 0x00;  
    for(int j=0; j<40; j=j+10)
    {       
     for(int i =0+j; i<10+j; i++) 
    {             
         value=eeprom_read(i);
        if(keys[i-j]!=value) 
        {                                 
            is_exist=0;
            break;           
        }
        else 
        {           
            address++;
        }
        is_exist=1;
    }
    
      if(is_exist==1) 
    {
          PORTA = 0b00000000;
          __delay_ms(3000);
          break;   
    }
     
      else 
      {
          void show_error();           
      }
    
    }     
}

void show_error(void) 
{
 PORTA = 0b00001111;
          __delay_ms(3000);
}




