#define PIN_PULLUP D3

static int button = 0;

void setup() {
    pinMode(PIN_PULLUP, INPUT_PULLUP);

    Particle.variable("switch", &button, INT);
}

void loop() {
    button = !digitalRead(PIN_PULLUP);
    delay(100);
}
