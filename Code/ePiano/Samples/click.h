#ifndef click_H_
#define click_H_
 
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <avr/pgmspace.h>
 
#define click_NUM_CELLS 19
#define click_SAMPLERATE 16384
 
const int8_t __attribute__((section(".progmem.data"))) click_DATA [] = {24, -92,
-53, 113, 34, 34, -6, -9, -23, -19, -11, -5, 3, 7, 11, 8, 5, 0, -2, };
 
 #endif /* click_H_ */
