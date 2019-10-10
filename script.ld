MEMORY
{
    flash   (RX!W):     ORIGIN = 0x0, LENGTH = 0x2000
    sram    (WR!X):     ORIGIN = 0x800060, LENGTH = 0x400
}

SECTIONS
{
    .text   :
    AT (0x0)
    {
        _text = .;
        *(.vectors)
        *(.text*)
        _etext = .;
    } > flash

    .data   :
    AT (ADDR(.text) + SIZEOF(.text))
    {
        _data = .;
        *(.data*)
        *(.bss*)
        *(.rodata*)
        _edata = .;
    } > sram
}

ENTRY(_init)
