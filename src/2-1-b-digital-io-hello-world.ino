void flash(int signal, unsigned int duration, int* pins);

#define PERIOD 1000

static uint16_t PINS[2] = { 7, 0 };
const unsigned int N_PINS = sizeof(PINS) / sizeof(uint16_t);

void setup() {
    for (unsigned int p = 0; p < N_PINS; p++) {
        pinMode(PINS[p], OUTPUT);
    }
}

void loop() {
    flash(HIGH, PERIOD, PINS, N_PINS);
    flash(LOW,  PERIOD / 2, PINS, N_PINS);
}

void flash(int signal, unsigned int duration, uint16_t* pins, unsigned int nPins) {
    for (unsigned int p = 0; p < nPins; p++) {
        digitalWrite(pins[p], signal);
    }
    delay(duration);
}
