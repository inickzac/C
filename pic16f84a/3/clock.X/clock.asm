; LIST p=16F84A
	   #INCLUDE <p16f84a.inc>
;	   __CONFIG _XT_OSC & _WDT_OFF & _PWRTE_ON & _CP_OFF
	   org 0	   
 LOOP      bsf PORTB, 3
           GOTO LOOP
;SET_NUL    movlw b'10000000'
;	   movwf PORTA
;	   movlw b'00000000'
;	   movwf PORTB
;	   return
	   end
    



