#include <xc.h> //ARQUIVO .READER COM AS CONFIGURAÇÕES DO uC

#pragma config FOSC = INTIO67 //OSCILADOR INTERNO
#pragma config PBADEN = OFF //DESATIVANDO CONVERSOR ANALOGICO/DIGITAL

#define _XTAL_FREQ 1000000 //SETTANDO FREQUENCIA 1MHz

int parada = 0;

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
        PORTD = 0b10000001; // liga vermelho e verde
        __delay_ms(3000);
        PORTD = 0b10000010; // liga vermelho e amarelo
        __delay_ms(1000);
        PORTD = 0b00100100; // liga verde e vermelho
        __delay_ms(3000);
        PORTD = 0b01000100; // liga amarelo  e vermelho
        __delay_ms(1000);
    }
    
    return;
}

void __interrupt() paradaSolicitada(){
    if(INTCONbits.INT0IF == 1){
        INTCONbits.INT0IF = 0;
        
        parada++;
        if(parada == 3){
            parada = 0;
            PORTD = 0b10000100;
            __delay_ms(2000);
        }
    }
}
