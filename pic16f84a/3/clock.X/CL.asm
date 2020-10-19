           LIST p=16F84A
	   #INCLUDE <p16f84a.inc>
            __CONFIG _XT_OSC & _WDT_OFF & _PWRTE_ON & _CP_OFF
SEG_1      equ 10h
SEG_2      equ 11h
SEG_3      equ 12h
SEG_4      equ 13h
SEG_5      equ 14h
SEG_6      equ 15h
SEG_7      equ 16h   
STATUS_C   equ 20h
W_C        equ 21h
CLICK_ST   equ 22h
	   org 0   
	   goto START
	   org 4	  	   	   
	   goto TIC	   

	   
START      bsf STATUS,5
           clrf TRISB
	   clrf TRISA
	   movlw b'00000111'
	   movwf OPTION_REG
	   bcf STATUS,5
           clrf PORTB
           clrf PORTA	   
	   bcf STATUS,RP0          
           clrf PORTA
	   clrf PORTB
	   bsf INTCON, T0IE
	   bsf INTCON, GIE
	   bsf PORTA, 4
           clrf TMR0
	   call INIT_TIME	  

LOOP	   movfw SEG_2
	   call NUM_MASS
	   bcf PORTB,7
	   call DISP_WAIT
	   bsf PORTB,7
	   movfw SEG_3
	   call NUM_MASS
	   bcf PORTB,6
	   call DISP_WAIT
	   bsf PORTB,6
	   movfw SEG_4
	   call NUM_MASS
	   bcf PORTB,5
	   call DISP_WAIT
	   bsf PORTB,5
	   movfw SEG_5
	   call NUM_MASS
	   bcf PORTB,4
	   call DISP_WAIT
	   bsf PORTB,4
	   movfw SEG_6
	   call NUM_MASS
	   bcf PORTB,3	 
	   call DISP_WAIT
	   bsf PORTB,3
	   movfw SEG_7
	   call NUM_MASS
	   bcf PORTB,2
	   call DISP_WAIT
	   bsf PORTB,2
	   goto LOOP

NUM_MASS   addwf PCL,f	   
	   goto NUME_0
	   goto NUME_1
	   goto NUME_2
	   goto NUME_3
	   goto NUME_4
	   goto NUME_5
	   goto NUME_6
	   goto NUME_7
	   goto NUME_8
	   goto NUME_9
	    
NUME_0     movlw b'11111'
	   movwf PORTA
	   movlw b'11111101'
	   movwf PORTB
	   return
NUME_1     movlw b'00110'
	   movwf PORTA
	   movlw b'11111100'
	   movwf PORTB
	   return
NUME_2     movlw b'11011'
	   movwf PORTA
	   movlw b'11111110'
	   movwf PORTB
	   return
NUME_3     movlw b'01111'
	   movwf PORTA
	   movlw b'11111110'
	   movwf PORTB
	   return
NUME_4     movlw b'00110'
	   movwf PORTA
	   movlw b'11111111'
	   movwf PORTB
	   return
NUME_5     movlw b'01101'
	   movwf PORTA
	   movlw b'11111111'
	   movwf PORTB
	   return
NUME_6     movlw b'11101'
	   movwf PORTA
	   movlw b'11111111'
	   movwf PORTB
	   return
NUME_7     movlw b'00111'
	   movwf PORTA
	   movlw b'11111100'
	   movwf PORTB
	   return
NUME_8     movlw b'11111'
	   movwf PORTA
	   movlw b'11111111'
	   movwf PORTB
	   return
NUME_9     movlw b'01111'
	   movwf PORTA
	   movlw b'11111111'
	   movwf PORTB
	   return
	   
TIC        	  
	   movwf W_C
	   swapf STATUS,w
	   movwf STATUS_C
;-------------------------------------
           incf  SEG_1,f
	   movlw d'10'
	   subwf SEG_1,w
	   btfss STATUS,Z
	   goto  INTE_EXIT
	   clrf SEG_1
	   incf  SEG_2,f
	   movlw d'10'
	   subwf SEG_2,w
	   btfss STATUS,Z
	   goto  INTE_EXIT
	   clrf SEG_2
	   incf  SEG_3,f
	   movlw d'6'
	   subwf SEG_3,w
	   btfss STATUS,Z
	   goto  INTE_EXIT
	   clrf SEG_3
	   incf  SEG_4,f
	   movlw d'10'
	   subwf SEG_4,w
	   btfss STATUS,Z
	   goto  INTE_EXIT
	   clrf SEG_4
	   incf  SEG_5,f
	   movlw d'6'
	   subwf SEG_5,w
	   btfss STATUS,Z
	   goto  INTE_EXIT
	   clrf SEG_5
	   incf  SEG_6,f
	   movlw d'4'
	   subwf SEG_6,w
	   btfss STATUS,Z
	   goto  INTE_EXIT
	   clrf SEG_6
	   incf  SEG_7,f
	   movlw d'3'
	   subwf SEG_7,w
	   btfss STATUS,Z
	   goto  INTE_EXIT
	   clrf SEG_7	  
;-------------------------------------
INTE_EXIT  swapf STATUS_C,w
	   movwf STATUS
	   swapf W_C,f
	   swapf W_C,w
	   bcf INTCON,T0IF
	   retfie
	   
DISP_WAIT  nop
	   nop
	   nop	   
	   return
	   
INIT_TIME  movlw d'6'
	   movwf SEG_2
	   movlw d'5'
	   movwf SEG_3
	   movlw d'8'
	   movwf SEG_4
	   movlw d'4'
	   movwf SEG_5
	   movlw d'3'
	   movwf SEG_6
	   movlw d'2'
	   movwf SEG_7
	   return
	   
	   end	    
	    