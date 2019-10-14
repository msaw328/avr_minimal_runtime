#ifndef __ATMEGA8_H__
#define __ATMEGA8_H__

#include "interrupt.h"

// vector defines taken from atmega8 pdf
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



#endif
