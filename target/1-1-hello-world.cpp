/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/home/thanatos/Documentos/lab/src/1-1-hello-world.ino"
void setup();
void loop();
#line 1 "/home/thanatos/Documentos/lab/src/1-1-hello-world.ino"
unsigned char on = 0;

void setup() {
    // Configuración de estado, pines E/S
    RGB.control(true);
    RGB.color(255, 255, 255);
}

void loop() {
    // Código de programa
    RGB.brightness((on = !on) << 6);
    delay(1000);
}
