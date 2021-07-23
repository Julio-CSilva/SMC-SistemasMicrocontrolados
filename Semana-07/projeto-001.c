
#pragma config FOSC = INTIO67   // Oscilador
#pragma config BOREN = OFF      // Resetar o microcontrolador quando houver queda de tens�o.
#pragma config PBADEN = OFF     // Desligando conversor AC/DC de PORTB

#include <xc.h>
#define _XTAL_FREQ 1000000

void main(void) {
    TRISD = 0;
    PORTD = 0;
    
    // Cofigura��o para entrada de RB0 com interrupcao
    TRISB = 0b00000001;        // Configurar o bit RB0 como entrada.
    
    INTCONbits.INT0IE = 1;      // Habilitar interrup��o externa INT0
    INTCONbits.INT0IF = 0;      // Limpar flag da interrup��o INT0
    INTCON2bits.INTEDG0 = 0;	// Habilitar interrup��o INT0 na borda de descida
    RCONbits.IPEN = 0;          // Desligar todas as prioridades na interrup��o.
    
    OSCCONbits.IRCF = 0b011; // Oscilador interno 4MHz
    
    while(1) {
        
    }
    
    return;
}

void __interrupt() parada(){
    
    if (INTCONbits.INT0IF == 1) {
        INTCONbits.INT0IF = 0; // Limpar a flag para detectar uma nova interrup��o
        
        __delay_ms(3000);
        PORTD = 0b00000001;
        __delay_ms(2000);
        
        for(int i=0; i<2000; i+=200){
            PORTD = 0b00000100;
            __delay_ms(100);
            
            PORTD = 0b00000000;
            __delay_ms(100);
        }
        
        PORTD = 0b00010000;
        
        while(1){
            PORTD = PORTD << 1;
                
            if (PORTD == 0b00000000) {
                PORTD = 0b01000000;
            }
                
            __delay_ms(600);
        }
    }
}
