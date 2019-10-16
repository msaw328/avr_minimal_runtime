.include "m8def.in"

.section .text,"ax",@progbits

.global _init ; _init declared global so that it can be called from vectors.s, ISR_reset
_init:
    ; setup stack
    ldi     r16, hi8(RAMEND - 1)
    out     SPH, r16
    ldi     r16, lo8(RAMEND - 1)
    out     SPL, r16

    ; copy data to SRAM
    ldi     ZH, hi8(_etext)     ; Z register is used with lpm to load program memory, so it's our src pointer
    ldi     ZL, lo8(_etext)
    ldi     XH, hi8(_data)      ; X register is used with st to store in data memory, so it'd our dst pointer
    ldi     XL, lo8(_data)      ; _text, _etext, _data and _edata defined in linker script

    ldi     r16, hi8(_edata)    ; r16:r17 will store _edata, our end condition
    ldi     r17, lo8(_edata)

    rjmp    copy_loop_comp      ; rjmp to skip lpm and st the first time its executed
copy_loop_store:    
    lpm     r0, Z+              ; read 1 byte from Z to r0 and postincrement
    st      X+, r0              ; write 1 byte from r0 to X and postincrement
copy_loop_comp:
    cp      XH, r16             ; compare 16bit values X and _edata (first high 8 bits and then low 8 bits but with carry from prev)
    cpc     XL, r17

    brlo    copy_loop_store     ; branch if lower (unsigned less than) - if X is less than _edata we loop again
    sei
    rcall   main                ; if all data copied, call main (defined in other file)
exitloop:
    rjmp exitloop
