#include <xc.h> //ARQUIVO .READER COM AS CONFIGURAÇÕES DO uC

#pragma config FOSC = INTIO67 //OSCILADOR INTERNO
#pragma config PBADEN = OFF //DESATIVANDO CONVERSOR ANALOGICO/DIGITAL

#define _XTAL_FREQ 1000000 //SETTANDO FREQUENCIA 1MHz

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
        
        PORTD = 0b00001000;
        
        while(1){
            PORTD = PORTD << 1;
                
            if (PORTD == 0b00000000) {
                PORTD = 0b00010000;
            }
                
            __delay_ms(600);
        }
    }
}

void main(void) {
    OSCCONbits.IRCF = 0b011; //SELECIONANDO A CHAVE DE 1MHz
    
    TRISD = 0; //CONFIGURANDO AS PORTAS D COMO SAIDA
    TRISBbits.RB0 = 1; //CONFIGURANDO A PORTA RB0(BOTAO: SW0) COMO ENTRADA
    
    INTCONbits.INT0IE = 1; //ATIVANDO INTERRUPÇÃO EXTERNA
    INTCONbits.INT0IF = 0; //LIMPANDO A FLAG DE INTERRUPÇÕES
    INTCON2bits.INTEDG0 = 0; //HABILITANDO INTERRUPÇÕES POR BORDA DE DESCIDA
    RCONbits.IPEN = 0; //DESLIGANDO PRIORIDADES NA INTERRUPÇÃO
    INTCONbits.GIE = 1; //HABILITANDO INTERRUPÇÃO GERAL
    
    while(1){
        PORTD = 0;
    }
    
    return;
}