#include "TouchScreen.h"
#include "arduino.h"
// #include "application.h"

namespace TouchScreen {
void begin() {
}

int readX() {
    pinMode(y1, INPUT);
    pinMode(x2, OUTPUT);
    pinMode(y2, INPUT);
    pinMode(x1, OUTPUT);

    digitalWrite(x2, LOW);
    digitalWrite(x1, HIGH);

    delay(5); // pause to allow lines to power up

    return analogRead(y1);
}

int readY() {

    pinMode(y1, OUTPUT);
    pinMode(x2, INPUT);
    pinMode(y2, OUTPUT);
    pinMode(x1, INPUT);

    digitalWrite(y1, LOW);
    digitalWrite(y2, HIGH);

    delay(5); // pause to allow lines to power up

    return analogRead(x2);
}
};
