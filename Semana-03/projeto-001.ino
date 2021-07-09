/*
 * File:   main.c
 * Author: julio
 *
 * Created on 9 de Julho de 2021, 15:33
 */


#include <xc.h> //ARQUIVO READER QUE CONTEM AS CONFIGURAÇÕES DO uC escolhido

#pragma config FOSC = INTIO67 //FONTE DE CLOCK
#pragma config BOREN = OFF //CASO AJA QUEDA DE ENERGIA ELE REINICIA O uC

#pragma config PBADEN = OFF //Comando necessario para poder utilizar as PORTB
//DESLIGANDO O CONVERSOR ANALOGICO/DIGITAL das portas PORTB

#define _XTAL_FREQ 1000000 //define a velocidade de repetição, *IGUAL CLOCK

void main(void) {
    
    OSCCONbits.IRCF = 0b011; //Configurando o oscilador para TRABALHA com 1MHz
    
    TRISD = 0; //Configurar todos os pinos da PORTD - PD0 até PD7 como saída
    
    TRISBbits.RB0 = 1; //Config. o pino RB0 para ser entrada (BOTAO SW1)
    
    while(1){
        PORTD = 0b00010101;
    }
    
    return;
}
