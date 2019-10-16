#ifndef __ATMEGA8_H__
#define __ATMEGA8_H__

#include "interrupt.h"
#include "io.h"

// all values copied directly from atmega8 pdf section
// look in "Register Summary" for register locations in memory
// and hyperlinks to register descriptions throughout the pdf

// vectors
// allows to specify a human readable vector name
// and maps it to symbol name from vector.s
#define VEC_RESET           VECTOR(1)
#define VEC_INT0            VECTOR(2)
#define VEC_INT1            VECTOR(3)
#define VEC_TIMER2_CMP      VECTOR(4)
#define VEC_TIMER2_OVF      VECTOR(5)
#define VEC_TIMER1_CAPT     VECTOR(6)
#define VEC_TIMER1_CMP_A    VECTOR(7)
#define VEC_TIMER1_CMP_B    VECTOR(8)
#define VEC_TIMER1_OVF      VECTOR(9)
#define VEC_TIMER0_OVF      VECTOR(10)
#define VEC_SPI_STC         VECTOR(11)
#define VEC_USART_RXC       VECTOR(12)
#define VEC_USART_UDRE      VECTOR(13)
#define VEC_USART_TXC       VECTOR(14)
#define VEC_ADC_CONV_COMP   VECTOR(15)
#define VEC_EE_RDY          VECTOR(16)
#define VEC_ANA_COMP        VECTOR(17)
#define VEC_TWI             VECTOR(18)
#define VEC_SPM_RDY         VECTOR(19)

// USART registers
#define UBRRL               0x29    // USART Baud rate lower 8 bits

#define UCSRB               0x2A    // USART control and status register B
    #define TXB8            0       // last bit of data frame to be sent when working on 9 bit frames
    #define RXB8            1       // last bit of data frame received when working on 9 bit frames
    #define UCSZ2           2       // bit 2 of bits used to set frame size (7, 8 or 9) together with two bits in UCSRC
    #define TXEN            3       // enable transmitter pin (disables other functions of the pin)
    #define RXEN            4       // enable receive pin (disables other functions of the pin)
    #define UDRIE           5       // USART Data Register Empty interrupt enable
    #define TXCIE           6       // USART Transmit Complete interrupt enable
    #define RXCIE           7       // USART Receive Complete interrupt enable

#define UCSRA               0x2B    // USART control and status register A
    #define MPCM            0       // Multi-processor communication mode
    #define U2X             1       // USART double transmission speed
    #define PE              2       // Parity Error
    #define DOR             3       // Data Overrun (buffer full, needs a read)
    #define FE              4       // Frame Error
    #define UDRE            5       // USART Data Register Empty flag (interrupt enable in UCSRB)
    #define TXC             6       // USART Transfer Complete (interrupt enable in UCSRB)
    #define RXC             7       // USART Receive Complete (interrupt enable in UCSRB)

#define UDR                 0x2C

// 2 registers below share IO space address
// URSEL bit decides to which you write (0 - UBRRH, 1 - UCSRC)
// if in previous clock cycle the location wasn't read (on first read)
// it returns UBRRH, if it was (reading same location 2 instructions in a row)
// it returns UCSRC. Both reads have to be atomic, since it takes into consideration
// previous clock cycle, so it may be a good idea to disable interrupts while doing so
#define UCSRC               0x40    // USART control and status register C
#define UBRRH               0x40    // USART Baud rate high bits
    #define URSEL           7       // Select between UCSRC/UBRRH during write (common for both)
    
    // lower 3 bits of UBRRH contain higher 3 bits of baud rate, but those can be just written by assigning
    // value to entire UBRRH register (highest bit kept at 0 for URSEL), so there aren't any other fields defined
    // UCSRC fields:
    #define UCPOL           0       // Clock polarity (synchronous mode only)
    #define UCSZ0           1       // bit 0 of bits used to set frame size (7, 8 or 9) together with 1 bit in UCSRB
    #define UCSZ1           2       // bit 1 of bits used to set frame size (7, 8 or 9) together with 1 bit in UCSRB
    #define USBS            3       // Stop bit select
    #define UPM0            4       // Parity Mode bit 0
    #define UPM1            5       // Parity Mode bit 1
    #define UMSEL           6       // USART mode select (Asynchronous/Synchronous)

// Timer0 registers
#define TCCR0               0x53    // Timer0 control register
    #define CS00            0       // bit 0 of clock source for timer0
    #define CS01            1       // bit 1 of clock source for timer0
    #define CS02            2       // bit 2 of clock source for timer0
    
#define TCNT0               0x52    // Current Timer0 state (no fields just 8 bit value)

#define TIMSK               0x59    // Timer interrupt mask register (shared with other timers, i only add one field related to Timer0)
    #define TOIE0           0       // Timer0 overflow interrupt enable

#define TIFR                0x58    // Timer flag register (shared with others too)
    #define TOV0            0       // Timer0 overflow flag

#endif
