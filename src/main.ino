#include "TouchScreen.h"
#include <stdint.h>

#define YP A2 // must be an analog pin, use "An" notation!
#define XM A3 // must be an analog pin, use "An" notation!
#define YM A0 // can be a digital pin (8)
#define XP A1 // can be a digital pin (9)

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

void setup(void) {
    // Serial.begin(9600);
    pinMode(7, OUTPUT);
    digitalWrite(7, LOW);
}

void loop(void) {
    TSPoint p = ts.getPoint();

    if (p.z > ts.pressureThreshhold) {
        digitalWrite(7, HIGH);
        // Serial.print("X = ");
        // Serial.print(p.x);
        // Serial.print("\tY = ");
        // Serial.print(p.y);
        // Serial.print("\tPressure = ");
        // Serial.println(p.z);
    } else {
        digitalWrite(7, LOW);
    }

    delay(100);
}
