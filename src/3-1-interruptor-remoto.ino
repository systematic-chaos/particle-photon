#define LED D4

int remoteLedBlink(String command);

void setup() {
    pinMode(LED, OUTPUT);
    Particle.function("ledBlink", remoteLedBlink);
}

void loop() {
}

int remoteLedBlink(String command) {
    const String ON  = "on";
    const String OFF = "off";
    
    if (ON.equalsIgnoreCase(command)) {
        digitalWrite(LED, HIGH);
        return 1;
    } else if (OFF.equalsIgnoreCase(command)) {
        digitalWrite(LED, LOW);
        return 0;
    } else {
        return -1;
    }
}
