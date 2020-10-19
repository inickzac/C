/* 
 * File:   buttoms.c
 * Author: ???
 *
 * Created on 9 ??????? 2020 ?., 19:00
 */
#define _XTAL_FREQ 8000
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>


int main(int argc, char** argv) {

    TRISA=0;
    TRISB=0xff;
    PORTA=0b00001;
    while(1) 
    {
        if(PORTBbits.RB0==0 || PORTBbits.RB1==0) 
        {
            PORTAbits.RA0=!PORTAbits.RA0;
        
            while(PORTBbits.RB0==0 || PORTBbits.RB1==0) 
            {
              __delay_ms(1);
            }
        
        }
                 
    }
    
    return (EXIT_SUCCESS);
}

