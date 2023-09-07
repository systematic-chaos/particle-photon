/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/home/thanatos/Documentos/lab/src/p-1-maquina-morse.ino"
void setup();
void loop();
void flash(unsigned short duration, unsigned short gap);
#line 1 "/home/thanatos/Documentos/lab/src/p-1-maquina-morse.ino"
#define DOT     300
#define DASH    1000

void flash(unsigned short duration, unsigned short gap = DOT);
void flashMessage(String message);
void flashLetter(char letter);
void flashDotsAndDashes(String dotsAndDashes);

static const String sosMsg = "SOS";

// Variables for the duration of dots, dashes and spaces

static const String letters[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",    // A-G
    "....", "..", ".---", "-.-", ".-..", "--", "-.",    // H-N
    "---", ".--.", "--.-", ".-.", "...", "-", "..-",    // O-U
    "...-", ".--", "-..-", "-.--", "--.."               // V-Z
};

// Status configuration and interfaces for I/O pins
void setup() {
    RGB.control(true);
    RGB.color(0xFF, 0, 0);
}

void loop() {
    flashMessage(sosMsg);
    delay(DOT * 7);    // delay before starting again
}

// Flash for duration and finish gap as specified by parameters
void flash(unsigned short duration, unsigned short gap) {
    RGB.brightness(0x40);
    delay(duration);
    RGB.brightness(0);
    delay(gap); // gap between dots and dashes of a letter
}

void flashMessage(String message) {
    for (unsigned int c = 0; c < message.length(); c++) {
        flashLetter(message[c]);
    }
}

void flashLetter(char letter) {
    if (letter >= 'a' && letter <= 'z') {
        flashDotsAndDashes(letters[letter - 'a']);
    } else if (letter >= 'A' && letter <= 'Z') {
        flashDotsAndDashes(letters[letter - 'A']);
    } else if (letter == ' ') {
        delay(DASH * 2); // gap between words
    }
}

void flashDotsAndDashes(String dotsAndDashes) {
    const unsigned int numSymbols = dotsAndDashes.length();
    for (unsigned int i = 0; i < numSymbols; i++) {
        // Dots and dashes of a letter
        flash(dotsAndDashes[i] == '.' ? DOT : DASH);
    }
    delay(DOT * 2); // gap between letters of a word
}
