#include <xc.h> //ARQUIVO .READER COM AS CONFIGURAÇÕES DO uC

#pragma config FOSC = INTIO67 //OSCILADOR INTERNO
#pragma config PBADEN = OFF //DESATIVANDO CONVERSOR ANALOGICO/DIGITAL

#define _XTAL_FREQ 1000000 //SETTANDO FREQUENCIA 1MHz

void __interrupt() bingo(){ //ACIONAMENTO DA INTERRUPÇÃO
    if(INTCONbits.INT0IF == 1){ //DETECÇÃO DE INTERRUPÇÃO
        INTCONbits.INT0IF = 0; //LIMPEZA DA FLAG
        
        if(PORTD == 0b00011000){ //CASO O ERRO ACONTEÇA NO MOMENTO DA SEQ 4
            for(int i=0; i<10; i++){ //10X CICLO DE SUBIDA(100) E DESCIDA (100))
                PORTD = 0b11111111;
                __delay_ms(100);
                PORTD = 0b00000000;
                __delay_ms(100);
            }
        }
        
        __delay_ms(150);
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
        PORTD = 0b00000011; //SEQUENCIA 1
        __delay_ms(70);
        PORTD = 0b00000110; //SEQUENCIA 2
        __delay_ms(70);
        PORTD = 0b00001100; //SEQUENCIA 3
        __delay_ms(70);
        PORTD = 0b00011000; //SEQUENCIA 4
        __delay_ms(70);
        PORTD = 0b00110000; //SEQUENCIA 5
        __delay_ms(70);
        PORTD = 0b01100000; //SEQUENCIA 6
        __delay_ms(70);
        PORTD = 0b11000000; //SEQUENCIA 7
        __delay_ms(70);
        PORTD = 0b10000001; //SEQUENCIA 8
        __delay_ms(70);
        
    }
    
    return;
}

