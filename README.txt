When building AVR firmwares using avr-gcc it automatically links them with avr-libc and c runtime, which provides a lot

This repo builds an AVR firmware for atmega8 without support from C runtime

Each source file gets compiled into an object file, which are afterwards linked using a custom linker script to achieve correct memory layout

Things that runtime.s does:
    - sets up a stack pointer to last available address in SRAM
    - copies .data from flash to SRAM
    - calls main() from main.s

vectors.s sets up a vector table, main.s provides a main function and some basic static variables to be copied in runtime.s
m8def.in is a file to be included by other source files, contains defines for IO registers and memory sizes for atmega8a (taken from datasheet)

build with "make all", clear with "make clear"

// TODO:Explain in detail atmega8 boot process, memory layout etc. in this README with code references
