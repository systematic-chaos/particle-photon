/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/home/thanatos/Documentos/lab/src/2-2-a-salida-analogica.ino"
void setup();
void loop();
#line 1 "/home/thanatos/Documentos/lab/src/2-2-a-salida-analogica.ino"
#define ANALOG_PIN A4

void setup() {
    pinMode(ANALOG_PIN, OUTPUT);
    
    analogWrite(ANALOG_PIN, 128, 500);
}

void loop() {
    delay(2000);
}
