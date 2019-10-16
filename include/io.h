#ifndef __IO_H__
#define __IO_H__

// bit value macro, similar to avr-libc one
#define _BV(N) (1 << N)

// deref for memory addresses (used when accessing registers)
#define REG(addr) (*(volatile uint8_t*) (addr))

#endif
