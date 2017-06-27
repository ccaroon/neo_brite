#ifndef __TOUCHSCREEN_H__
#define __TOUCHSCREEN_H__

#include "arduino.h"
// #include "application.h"
#include <stdint.h>

const uint8_t y1 = A0;
const uint8_t x2 = A1;
const uint8_t y2 = A2;
const uint8_t x1 = A3;

namespace TouchScreen {
void begin();
int readX();
int readY();
};

#endif
