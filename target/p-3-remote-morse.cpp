/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/home/thanatos/Documentos/lab/src/p-3-remote-morse.ino"
void setup();
void loop();
void flash(unsigned short duration, unsigned short gap);
#line 1 "/home/thanatos/Documentos/lab/src/p-3-remote-morse.ino"
#define DOT  150
#define DASH 500
#define PIN_LED D7
#define PIN_EXT_LED D3

void flash(unsigned short duration, unsigned short gap = DOT);
int flashMessage(String message);
int flashLetter(char letter);
int flashDotsAndDashes(String dotsAndDashes);

// Variables for the duration of dots, dashes and spaces

const String letters[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",    // A-G
    "....", "..", ".---", "-.-", ".-..", "--", "-.",    // H-N
    "---", ".--.", "--.-", ".-.", "...", "-", "..-",    // O-U
    "...-", ".--", "-..-", "-.--", "--.."               // V-Z
};

// Configuración de estado, interfaces pines E/S
void setup() {
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_EXT_LED, OUTPUT);

    RGB.control(true);
    RGB.color(0xFF, 0, 0);
    RGB.brightness(0);
    
    Particle.function("morse", flashMessage);
}

void loop() {
    delay(0xC8);
}

// Flash for duration and finish gap as specified by parameters
void flash(unsigned short duration, unsigned short gap) {
    // Flash on
    RGB.brightness(0x40);
    digitalWrite(PIN_LED, HIGH);
    digitalWrite(PIN_EXT_LED, HIGH);
    
    delay(duration);

    // Flash off
    RGB.brightness(0);
    digitalWrite(PIN_LED, LOW);
    digitalWrite(PIN_EXT_LED, LOW);

    delay(gap); // gap between dots and dashes of a letter
}

int flashMessage(String message) {
    unsigned int numSymbols = 0, letterLength;
    for (unsigned int c = 0; c < message.length(); c++) {
        if ((letterLength = flashLetter(message[c])) > 0) {
            numSymbols += letterLength;
        }
    }
    return numSymbols;
}

int flashLetter(char letter) {
    int numSymbols = -1;
    if (letter >= 'a' && letter <= 'z') {
        numSymbols = flashDotsAndDashes(letters[letter - 'a']);
    } else if (letter >= 'A' && letter <= 'Z') {
        numSymbols = flashDotsAndDashes(letters[letter - 'A']);
    } else if (letter == ' ') {
        delay(DASH * 2);    // gap between words
        numSymbols = 0;
    }
    return numSymbols;
}

int flashDotsAndDashes(String dotsAndDashes) {
    const unsigned int numSymbols = dotsAndDashes.length();
    for (unsigned int i = 0; i < numSymbols; i++) {
        // Dots and dashes of a letter
        flash(dotsAndDashes[i] == '.' ? DOT : DASH);
    }
    delay(DOT * 2); // gap between letters of a word
    return numSymbols;
}
