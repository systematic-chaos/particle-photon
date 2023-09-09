/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/home/thanatos/Documentos/lab/src/4-3-a-variables-trigger-ifttt.ino"
void setup();
void loop();
#line 1 "/home/thanatos/Documentos/lab/src/4-3-a-variables-trigger-ifttt.ino"
#define PIN_PULLUP D3

static int button = 0;

void setup() {
    pinMode(PIN_PULLUP, INPUT_PULLUP);

    Particle.variable("switch", &button, INT);
}

void loop() {
    button = !digitalRead(PIN_PULLUP);
    delay(100);
}
