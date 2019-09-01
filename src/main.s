.include "m8def.in"

.section .data
    funny_string:       .asciz  "Hello World!\n"

.section .text,"ax",@progbits
.global main ; main has to be global to be called from runtime.s
main:
    ldi     r16, 0x59
    push    r16
    pop     r16
    rjmp    main
