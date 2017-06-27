#include "TouchScreen.h"

void setup() {
    // Serial.begin(9600);
    TouchScreen::begin();
}

void loop() {
    int x = TouchScreen::readX();
    int y = TouchScreen::readY();

    if (x < 1000 & y < 1000) {
        Serial.print("x: ");
        Serial.print(x - 100);
        Serial.print(" - y: ");
        Serial.println(y - 130);
    }

    delay(100);
}
