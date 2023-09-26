/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/home/thanatos/Documentos/lab/src/4-1-monitorizacion-fotorresistor.ino"
void setup();
void loop();
#line 1 "/home/thanatos/Documentos/lab/src/4-1-monitorizacion-fotorresistor.ino"
#define PHOTO_RESISTOR A0
#define POWER_SOURCE A5

static double voltage;

void setup() {
    pinMode(PHOTO_RESISTOR, INPUT);

    pinMode(POWER_SOURCE, OUTPUT);
    digitalWrite(POWER_SOURCE, HIGH);
    
    Particle.variable("lighting", &voltage, DOUBLE);
}

void loop() {
    int32_t lumen = analogRead(PHOTO_RESISTOR);
    voltage = ((double) lumen) * 3.3 / (double) (0x1 << 12);
    
    delay(5000);
}
