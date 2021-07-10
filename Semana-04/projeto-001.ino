#include <xc.h> //Config. do uC escolhido

#pragma config FOSC = INTIO67

#define _XTAL_FREQ 1000000


void main(void) {
    OSCCONbits.IRCF = 0b011;
    
    TRISD = 0;
    
    while(1){
        PORTD = 0b10000001;
        __delay_ms(3000);
        PORTD = 0b10000010;
        __delay_ms(1000);
        PORTD = 0b00100100;
        __delay_ms(3000);
        PORTD = 0b01000100;
        __delay_ms(1000);
    }
    
    return;
}
