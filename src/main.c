#include "interrupt.h"
#include "atmega8.h"

void halo(void) {};

ISR_custom(VEC_INT0) {
    halo();
}

int main() {
}
