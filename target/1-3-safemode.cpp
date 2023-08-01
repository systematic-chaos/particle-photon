/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/home/thanatos/Documentos/lab/src/1-3-safemode.ino"
// Configuración de estado, pines E/S
void setup();
void loop();
#line 2 "/home/thanatos/Documentos/lab/src/1-3-safemode.ino"
void setup() {
    pinMode(D7, OUTPUT);
    RGB.control(true);
    RGB.color(0, 0, 255);
}

// Código de programa
void loop() {
    digitalWrite(D7, HIGH);
    
    RGB.brightness(64);
    
    delay(3000);
    
    // Raising runtime error
    int err = 1 / 0;
    delay(err);
    
    RGB.brightness(0);
    delay(10000);
}
