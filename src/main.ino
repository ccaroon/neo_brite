#include "TouchScreen.h"
#include "arduino.h"

void setup() {
    Serial.begin(9600);
    // TouchScreen::begin();
    pinMode(7, OUTPUT);
    digitalWrite(7, LOW);
}

void loop() {
    int x = TouchScreen::readX();
    int y = TouchScreen::readY();

    if (x > 0 && x < 1000) {
        Serial.print("x: ");
        Serial.print(x - 100);
    }

    if (y > 0 && y < 1000) {
        Serial.print("y: ");
        Serial.println(y - 130);
    }

    // digitalWrite(7, HIGH);
    // delay(1000);
    // digitalWrite(7, LOW);
    // delay(1000);
    delay(100);
}
