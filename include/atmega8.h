#ifndef __ATMEGA8_H__
#define __ATMEGA8_H__

#include "interrupt.h"

// vector defines taken from atmega8 pdf
// allows to specify a human readable vector name
// and maps it to symbol name from vector.s
// numbers are 1 off compared to pdf i'm using, since i count interrupts from 0 (RESET is 0)
#define VEC_INT0            VECTOR(1)
#define VEC_INT1            VECTOR(2)
#define VEC_TIMER2_CMP      VECTOR(3)
#define VEC_TIMER2_OVF      VECTOR(4)
#define VEC_TIMER1_CAPT     VECTOR(5)
#define VEC_TIMER1_CMP_A    VECTOR(6)
#define VEC_TIMER1_CMP_B    VECTOR(7)
#define VEC_TIMER1_OVF      VECTOR(8)
#define VEC_TIMER0_OVF      VECTOR(9)
#define VEC_SPI_STC         VECTOR(10)
#define VEC_USART_RXC       VECTOR(11)
#define VEC_USART_UDRE      VECTOR(12)
#define VEC_USART_TXC       VECTOR(13)
#define VEC_ADC_CONV_COMP   VECTOR(14)
#define VEC_EE_RDY          VECTOR(15)
#define VEC_ANA_COMP        VECTOR(16)
#define VEC_TWI             VECTOR(17)
#define VEC_SPM_RDY         VECTOR(18)

#endif
