           LIST p=16F84A
	   #INCLUDE <p16f84a.inc>
DELAY_REG1 equ 25h
DELAY_REG2 equ 26h
DELAY_REG3 equ 27h
NUMBER_OF_FLASHES equ 4 
           org 0
           bsf STATUS,5
           clrf TRISB
	   clrf TRISA
	   bcf STATUS,5
           clrf PORTB
           clrf PORTA
;----------------------------------------------
START      movlw b'10000100'
	   movwf PORTB
	   movlw b'0001'
	   movwf PORTA
	   call  LOOP3S
;-----------------------------------------------
           call  BLINC_TF1
;-----------------------------------------------           
           movlw b'01000100'
	   movwf PORTB
	   movlw b'0001'
	   movwf PORTA
	   call  LOOP1S
;-----------------------------------------------
	   movlw b'00101100'
	   movwf PORTB
	   movlw b'0001'
	   movwf PORTA
	   call  LOOP1S
;-----------------------------------------------
	   movlw b'00110000'
	   movwf PORTB
	   movlw b'0001'
	   movwf PORTA
	   call  LOOP3S
;-----------------------------------------------
           call  BLINC_TF2
;-----------------------------------------------
	   movlw b'00101000'
	   movwf PORTB
	   movlw b'0001'
	   movwf PORTA
	   call  LOOP1S
;-----------------------------------------------
	   movlw b'00100100'
	   movwf PORTB
	   movlw b'0011'
	   movwf PORTA
	   call  LOOP1S
;-----------------------------------------------
	   movlw b'00100100'
	   movwf PORTB
	   movlw b'0100'
	   movwf PORTA
	   call  LOOP3S
;-----------------------------------------------
           call  BLINC_TF3
;-----------------------------------------------
	   movlw b'00100100'
	   movwf PORTB
	   movlw b'0010'
	   movwf PORTA
	   call  LOOP1S
;-----------------------------------------------
	   movlw b'01100100'
	   movwf PORTB
	   movlw b'0001'
	   movwf PORTA
	   call  LOOP1S
;-----------------------------------------------
           goto  START
       
LOOP3S       
            movlw       .13
            movwf       DELAY_REG1
            movlw       .57
            movwf       DELAY_REG2
            movlw       .16
            movwf       DELAY_REG3
            decfsz      DELAY_REG1,F
            goto        $-1
            decfsz      DELAY_REG2,F
            goto        $-3
            decfsz      DELAY_REG3,F
            goto        $-5
            nop
            nop
            return
	    
LOOP0.5S       
            movlw       .85
            movwf       DELAY_REG1
            movlw       .138
            movwf       DELAY_REG2
            movlw       .3
            movwf       DELAY_REG3
            decfsz      DELAY_REG1,F
            goto        $-1
            decfsz      DELAY_REG2,F
            goto        $-3
            decfsz      DELAY_REG3,F
            goto        $-5
            nop
            nop
            return
LOOP1S       
            movlw       .173
            movwf       DELAY_REG1
            movlw       .19
            movwf       DELAY_REG2
            movlw       .6
            movwf       DELAY_REG3
            decfsz      DELAY_REG1,F
            goto        $-1
            decfsz      DELAY_REG2,F
            goto        $-3
            decfsz      DELAY_REG3,F
            goto        $-5
            nop
            nop
            return

BLINC_TF1   movlw       NUMBER_OF_FLASHES
	    movwf       20h
LOOP_TF1    bcf         PORTB, 7
	    call        LOOP0.5S
            bsf         PORTB, 7
	    call        LOOP0.5S
	    decfsz      20h, f
	    goto        LOOP_TF1
            return

BLINC_TF2   movlw       NUMBER_OF_FLASHES
	    movwf       20h
LOOP_TF2    bcf         PORTB, 4
	    call        LOOP0.5S
            bsf         PORTB, 4
	    call        LOOP0.5S
	    decfsz      20h, f
	    goto        LOOP_TF2
            return
	    
 
BLINC_TF3   movlw       NUMBER_OF_FLASHES
	    movwf       20h
LOOP_TF3    bcf         PORTA, 2
	    call        LOOP0.5S
            bsf         PORTA, 2
	    call        LOOP0.5S
	    decfsz      20h, f
	    goto        LOOP_TF3
            return
	    end	    
	    
	    


