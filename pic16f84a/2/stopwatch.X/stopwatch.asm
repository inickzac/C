           LIST p=16F84A
	   #INCLUDE <p16f84a.inc>
	   org 0
	   goto START
	   org 4
	   goto TIC
SEG_1      equ 10h
SEG_2      equ 11h
SEG_3      equ 12h
SEG_4      equ 13h  
STATUS_C   equ 20h
W_C        equ 21h
START	   bsf STATUS,RP0
	   clrf TRISA
	   clrf TRISB
           movlw b'00000001'
	   movwf OPTION_REG
	   bcf STATUS,RP0          
           clrf PORTA
	   clrf PORTB
           bsf INTCON, T0IE
	   bsf INTCON, INTE
	   bsf INTCON, GIE
	   bsf PORTA, 4
           clrf TMR0

LOOP	   movfw SEG_1
	   call NUM_MASS
	   movwf PORTB
	   bsf PORTA, 0
;-------------------------------------------	   
	   movfw SEG_2
	   call NUM_MASS
	   movwf PORTB
	   bsf PORTA, 1
	   bcf PORTA, 1
;-------------------------------------------
	   movfw SEG_3
	   call NUM_MASS
	   movwf PORTB
	   bsf PORTA, 2
	   bcf PORTA, 2
;-------------------------------------------
	   movfw SEG_4
	   call NUM_MASS
	   movwf PORTB
	   bsf PORTA, 3
	   bcf PORTA, 3
;-------------------------------------------
	   goto LOOP
	   
	   
NUM_MASS   addwf PCL,f	   
	   retlw b'10000000'
	   retlw b'11110010'
	   retlw b'01001000'
	   retlw b'01100000'
	   retlw b'00110010'
	   retlw b'00100100'
	   retlw b'00000100'
	   retlw b'11110000'
	   retlw b'00000000'
	   retlw b'00100000'
	   
TIC        movwf W_C
	   swapf STATUS,w
	   movwf STATUS_C
;-------------------------------------
;           incf  SEG_1
;	   movlw d'10'
;	   subwf SEG_1,w
;	   btfsc STATUS,Z
;	   clrf SEG_1
;-------------------------------------
INTE_EXIT  swapf STATUS_C,w
	   movwf STATUS
	   swapf W_C,f
	   swapf W_C,w
	   retfie
	   
	   end
    
    



