/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/home/thanatos/Documentos/lab/src/2-2-b-salida-analogica.ino"
void setup();
void loop();
#line 1 "/home/thanatos/Documentos/lab/src/2-2-b-salida-analogica.ino"
#define ANALOG_PIN A3

void setup() {
    pinMode(ANALOG_PIN, OUTPUT);
    analogWrite(ANALOG_PIN, 3350);
}

void loop() {
    delay(2000);
}
