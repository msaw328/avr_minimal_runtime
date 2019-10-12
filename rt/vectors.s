.include "m8def.in"

# macro for defining a vector as a weak symbol
# allows it to be overwriten by a strong symbol
# (for instance in C part of the source code)
# pretty much copied from avr-libc source code
# i can't really think of a better way to handle ISR overwriting
# weak symbols are perfect for that

# the way it works:
# .macro defines a macro "vector" with argument "name" which will be a symbol name (name of the ISR)
# .weak defines a symbol a symbol as weak (can be overwriten by a symbol of same name but strong somewhere else)
# .weak also creates a symbol if it didnt exist before, here we give it the name from the argument
# .set sets value of the symbol to ISR_null, our default ISR
# now the symbols value is ISR_null address, but if anywhere theres another symbol of the same name and its not weak
# the value will be overwritten
# macro then evaluates to a rjmp to the symbol, this way by default its an rjmp to ISR_null, but can be overwritten with custom ISR
.macro      vector name
.weak       \name
.set        \name, ISR_builtin_null
    rjmp    \name
.endm

.section .vectors,"ax",@progbits
.global __vectors
__vectors:
    # reset interrupt shouldn't be overwritten (thats the job of the bootloader) so i hardcode it
    rjmp    ISR_builtin_reset
    vector  __vector_1
    vector  __vector_2
    vector  __vector_3
    vector  __vector_4
    vector  __vector_5
    vector  __vector_6
    vector  __vector_7
    vector  __vector_8
    vector  __vector_9
    vector  __vector_10
    vector  __vector_11
    vector  __vector_12
    vector  __vector_13
    vector  __vector_14
    vector  __vector_15
    vector  __vector_16
    vector  __vector_17
    vector  __vector_18

.section .text,"ax",@progbits
.global ISR_builtin_null
ISR_builtin_null:       ; default ISR
    reti

.global ISR_builtin_reset
ISR_builtin_reset:
    rjmp    _init
