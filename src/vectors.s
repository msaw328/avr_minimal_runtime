.include "m8def.in"

.section .vectors,"ax",@progbits
__vectors:
vec_reset:
    rjmp    ISR_reset
vec_int0:
    rjmp    ISR_null
vec_int1:
    rjmp    ISR_null
vec_timer2_comp:
    rjmp    ISR_null
vec_timer2_ovf:
    rjmp    ISR_null
vec_timer1_capt:
    rjmp    ISR_null
vec_timer1_compa:
    rjmp    ISR_null
vec_timer1_compb:
    rjmp    ISR_null
vec_timer1_ovf:
    rjmp    ISR_null
vec_timer0_ovf:
    rjmp    ISR_null
vec_spi_complete:
    rjmp    ISR_null
vec_usart_rx_complete:
    rjmp    ISR_null
vec_usart_dre_empty:
    rjmp    ISR_null
vec_usart_tx_complete:
    rjmp    ISR_null
vec_adc_conv_complete:
    rjmp    ISR_null
vec_eeprom_ready:
    rjmp    ISR_null
vec_analog_comp:
    rjmp    ISR_null
vec_i2c:
    rjmp    ISR_null
vec_spm_ready:
    rjmp    ISR_null

.section .text,"ax",@progbits
ISR_null:       ; default ISR
    reti

ISR_reset:
    rjmp    _init
