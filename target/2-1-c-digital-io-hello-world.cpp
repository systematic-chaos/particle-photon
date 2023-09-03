/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/home/thanatos/Documentos/lab/src/2-1-c-digital-io-hello-world.ino"
void setup();
void loop();
#line 1 "/home/thanatos/Documentos/lab/src/2-1-c-digital-io-hello-world.ino"
#define PIN_PULLUP 3
#define PIN_LED 7

#define PERIOD 500

void flash(uint16_t pin, uint8_t signal, unsigned long duration);

void setup() {
    pinMode(PIN_PULLUP, INPUT_PULLUP);
    pinMode(PIN_LED, OUTPUT);
}

void loop() {
    if (digitalRead(PIN_PULLUP)) {
        flash(PIN_LED, HIGH, PERIOD);
        flash(PIN_LED, LOW,  PERIOD);
    }
}

void flash(uint16_t pin, uint8_t signal, unsigned long duration) {
    digitalWrite(pin, signal);
    delay(duration);
}
