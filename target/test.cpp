/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/home/thanatos/Documentos/lab/src/test.ino"
#include <string.h>

void setup();
void loop();
int brew(String infusion);
#line 3 "/home/thanatos/Documentos/lab/src/test.ino"
int brew(String param);
void turtle(String eventName, String arg);
void flash(const char* data);

const String function = "brew";
const String event = "brewing";

void setup() {
    RGB.control(true);
    RGB.color(0, 0xFF, 0);
    RGB.brightness(0);

    Particle.function(function, &brew);
    Particle.subscribe(event, &turtle, "positronic");
}

void loop() {
    delay(2000);
}

int brew(String infusion) {
    int returnCode = -1;

    if (!infusion.trim().length()) {
        returnCode = 0;
    }

    if (infusion.equals("tea")) {
        returnCode = 1;
    }
    if (infusion.equals("coffee")) {
        returnCode = 2;
    }

    if (returnCode >= 0) {
        Particle.publish(event, String(returnCode));
    }

    return returnCode;
}

void turtle(String eventName, String arg) {
    if (!(event.equals(eventName) && arg.length() == 1)) {
        Particle.unsubscribe();
        return;
    }

    String message = "";
    switch (arg.charAt(0))  {
        case '2':
            message = "10110";
            break;
        case '1':
            message = "01110";
            break;
    }
    flash(message);
}

void flash(const char* data) {
    char symbol;
    for (unsigned int c = 0; c < strlen(data); c++) {
        symbol = data[c] - 48;

        RGB.brightness(symbol ? 0xC0 : 0x40);
        delay(500);
    }
    RGB.brightness(0);
}
