/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/home/thanatos/Documentos/lab/src/5-1-publicar-valor-fotorresistor.ino"
/*#include <iomanip>
#include <sstream>*/
#include <stdio.h>

void setup();
void loop();
#line 5 "/home/thanatos/Documentos/lab/src/5-1-publicar-valor-fotorresistor.ino"
#define PHOTO_RESISTOR A0
#define POWER_SOURCE A5

double lumen;

void setup() {
    pinMode(PHOTO_RESISTOR, INPUT);

    pinMode(POWER_SOURCE, OUTPUT);
    digitalWrite(POWER_SOURCE, HIGH);

    Particle.variable("photoresistor", &lumen, DOUBLE);
}

void loop() {
    lumen = analogRead(PHOTO_RESISTOR) * 3.3 / (0x1 << 12);

    char voltage[5];
    sprintf(voltage, "%.2f", lumen);
    /*std::stringstream voltage;
    voltage << std::fixed << std::setprecision(2) << lumen;

    Particle.publish("lighting", voltage.str().c_str());*/
    Particle.publish("lighting", voltage);

    delay(2000);
}
