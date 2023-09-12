/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/home/thanatos/Documentos/lab/src/3-2-interruptor-blinking-web.ino"
void setup();
void loop();
#line 1 "/home/thanatos/Documentos/lab/src/3-2-interruptor-blinking-web.ino"
#define LED A4

int remoteLedBlink(String param);
void blink(int pin, unsigned int period);
void signal(int pin, int value, unsigned int period);

bool blinking = false;

void setup() {
    pinMode(LED, OUTPUT);
    
    Particle.function("led", remoteLedBlink);
}

void loop() {
    if (blinking) {
        blink(LED, 500);
    }
}


int remoteLedBlink(String param) {
    const String ON = "on";
    const String OFF = "off";
    
    if (ON.equalsIgnoreCase(param)) {
        blinking = true;
        return 1;
    } else if (OFF.equalsIgnoreCase(param)) {
        blinking = false;
        return 0;
    } else {
        blinking = !blinking;
        return -1;
    }
}

void blink(int pin, unsigned int period) {
    signal(pin, HIGH, period);
    signal(pin, LOW, period);
}

void signal(int pin, int value, unsigned int period) {
    digitalWrite(pin, value);
    delay(period);
}
