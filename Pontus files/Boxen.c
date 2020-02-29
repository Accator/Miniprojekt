﻿//Hejehj
//Bit bas 2 till bas 10, detta är vad displayen läser in. Ser ut som udner i verkligheten.
//Eftersom det är en array kan vi uppdatera dem byte vis


#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */


const uint8_t box[] = {
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
244,000,000,000,000,000,000,000,000,000,000,000,000,000,000,007,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
244,000,000,000,000,000,000,000,000,000,000,000,000,000,000,007,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
};

//Bit reprensation

/*
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
*/



//Bit bas 2 till bas 10, detta är vad displayen läser in. Ser ut som ovan i verkligheten.
//Eftersom det är en array kan vi uppdatera dem byte vis

const uint8_t const boxBlink[] = {
000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
};


const uint8_t box[] = {
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
244,000,000,000,000,000,000,000,000,000,000,000,000,000,000,007,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,
244,000,000,000,000,000,000,000,000,000,000,000,000,000,000,007,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
};

//Bit reprensation

/*
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111
11100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
*/



//Bit bas 2 till bas 10, detta är vad displayen läser in. Ser ut som ovan i verkligheten.
//Eftersom det är en array kan vi uppdatera dem byte vis

const uint8_t const boxBlink[] = {
000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
015,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,
000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
};