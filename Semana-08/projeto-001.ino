#include <xc.h> //ARQUIVO .READER COM AS CONFIGURAÇÕES DO uC

#pragma config FOSC = INTIO67 //OSCILADOR INTERNO

#define _XTAL_FREQ 4000000 //SETTANDO FREQUENCIA 1MHz

void main(void) {
    
    TRISD = 0; //CONFIGURANDO AS PORTAS D COMO SAIDA

    OSCCONbits.IRCF = 0b110; // Configurar oscilador interno para 4MHz
	ADCON2bits.ADCS = 0b110; // Clock: Fosc/64
	ADCON2bits.ACQT = 0b101; // Tempo de aquisição: 12*TAD
	ADCON2bits.ADFM = 1; // Formato do valor digital justificado à direita.
	ADCON1 = 0b00000000; // ADC Vref = Vdd,Vss
	ANSEL |= 0b00000001; // Configura RA0 como analógica
	TRISA |= 0b00000001; // Configura RA0 como entrada
	ADCON0bits.CHS = 0b0000; // Configura canal AN0 (RA0)
	ADCON0bits.ADON = 1; // Habilitar conversor AD
    
    while(1){
        ADCON0bits.GO = 1; // Iniciar conversão
		while (ADCON0bits.GO){};  // Esperar a conversão finalizar
		int valor = (ADRESH << 8) + ADRESL;
        //__delay_ms(1000);
        PORTD = valor;
    }
    
    return;
}

