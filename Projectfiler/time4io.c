#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"

int getsw(void) {
    return (PORTD >> 8) & 0xf;
}

int getbtns432(void) {
	return (PORTD >> 5) & 0x7;
}


int getbtns1(void) {
	return PORTF & 0x2; //första biten
}
