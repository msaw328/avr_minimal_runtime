#define F_CPU 1000000UL
#include "stdint.h"
#include "interrupt.h"
#include "io.h"
#include "atmega8.h"

#define BAUD_RATE 2400

// main.c - UART demo, outputs "Hello World!" a lot of times

// initializes registers to configure UART and Timer0
void HW_init() {
    // UART
    uint16_t ubrr_value = (F_CPU / 8 / BAUD_RATE) - 1;

    REG(UBRRH) = (uint8_t) (ubrr_value >> 8); // set baud rate
    REG(UBRRL) = (uint8_t) ubrr_value;

    REG(UCSRA) = _BV(U2X); // enable double speed for better error rate
    REG(UCSRB) = _BV(RXEN) | _BV(TXEN); // enable TX and RX pins, dont enable interrupts or 9 bit frames
    REG(UCSRC) = _BV(URSEL) | _BV(UCSZ0) | _BV(UCSZ1); // enable 8 bit frames, dont enable synchronous communication, parity, 2 stop bits and other stuff

    // Timer0
    REG(TIMSK) = _BV(TOIE0); // enable overflow interrupt
    REG(TCCR0) = _BV(CS00) | _BV(CS02); // enable clock and set prescaler to 1024
    REG(TCNT0) = 0;
}

// Outputs a character via UART in a blocking manner
void UART_put_char(char c) {
    while( !(REG(UCSRA) & _BV(UDRE))) {}; // block until DRE - data register empty, it means that we can transmit another character

    REG(UDR) = c; // udr - uart data register
}

// outputs a buffer of characters through UART
void UART_put_string(char* str) {
    int i = 0;

    while(str[i] != '\0') {
        UART_put_char(str[i]);
        i++;
    }
}

ISR_custom(VEC_TIMER0_OVF) {
    UART_put_string("Hello World!\n");
};

int main(void) {
    HW_init();

    while(1) {};
}
