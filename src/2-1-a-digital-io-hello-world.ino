void flash(uint16_t pin, uint8_t signal, unsigned long duration);

#define PIN D7
#define PERIOD 1000

void setup() {
    pinMode(PIN, OUTPUT);
}

void loop() {
    flash(PIN, HIGH, PERIOD);
    flash(PIN, LOW,  PERIOD);
}

void flash(uint16_t pin, uint8_t signal, unsigned long duration) {
    digitalWrite(pin, signal);
    delay(duration);
}
