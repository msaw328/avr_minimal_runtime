#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

// VECTOR(N) converts vector index to symbol name defined in vectors.s
#define VECTOR(N) __vector_ ## N

// declares ISR function with specific VEC_NAME taken from custom model includes
// attribute signal explained here: https://gcc.gnu.org/onlinedocs/gcc/AVR-Function-Attributes.html
// avr libc also allows other useful attributes to be used, but signal is enough
#define ISR_custom(vec_name)  __attribute__ ((signal)) void vec_name(void)

#endif
