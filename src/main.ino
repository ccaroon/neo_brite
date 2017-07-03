#include "TouchScreen.h"
#include <Adafruit_NeoPixel.h>
#include <stdint.h>

#define YP A2 // must be an analog pin, use "An" notation!
#define XM A3 // must be an analog pin, use "An" notation!
#define YM A0 // can be a digital pin (8)
#define XP A1 // can be a digital pin (9)

Adafruit_NeoPixel strip = Adafruit_NeoPixel(5, 7, NEO_GRB + NEO_KHZ800);
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

void setup(void) {
    Serial.begin(9600);
    strip.begin();
}

// x --> 0 to 830
// y --> 0 to 750

void printLocation(TSPoint &p) {
    Serial.print("X = ");
    Serial.print(p.x);
    Serial.print("\tY = ");
    Serial.print(p.y);
    Serial.print("\tPressure = ");
    Serial.println(p.z);
}

void loop(void) {
    TSPoint p = ts.getPoint();

    if (p.z > ts.pressureThreshhold) {
        printLocation(p);

        for (uint8_t i = 0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, 0, 0, 0);
        }

        // X axis determines which NeoPixel to turn on
        uint8_t x = 0;
        if (p.x <= 160) {
            x = 0;
        } else if (p.x > 160 && p.x <= 320) {
            x = 1;
        } else if (p.x > 320 && p.x < 480) {
            x = 2;
        } else if (p.x > 480 && p.x < 640) {
            x = 3;
        } else if (p.x > 640) {
            x = 4;
        }

        // Y determines color of NeoPixel
        uint32_t color = 0;
        if (p.y < 150) {
            color = strip.Color(128, 0, 0);
        } else if (p.y > 150 && p.y <= 300) {
            color = strip.Color(0, 128, 0);
        } else if (p.y > 300 && p.y <= 450) {
            color = strip.Color(0, 0, 128);
        } else if (p.y > 450 && p.y <= 600) {
            color = strip.Color(128, 0, 128);
        } else if (p.y > 600) {
            color = strip.Color(random(0, 128), random(0, 128), random(0, 128));
        }

        strip.setPixelColor(x, color);
        strip.show();
    }

    delay(100);
}
