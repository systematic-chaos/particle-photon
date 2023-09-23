#define LED_PIN A4

short mano(String data);
void turnLed(bool status);

void setup() {
    pinMode(LED_PIN, OUTPUT);
    mano("no_esta");

    Particle.function("fraferp9_mano", mano);
}

void loop() {
    delay(200);
}

/** Published function
 *  If the string received equals si_esta/no_esta,
 *  turn on/off the led and publish the matching event. */
short mano(String data) {
    short esta = -1;
    if (data.length() == 7 && data.endsWith("_esta")) {
        if (data.startsWith("si")) {
            esta = 1;
        } else if (data.startsWith("no")) {
            esta = 0;
        }
    }

    switch (esta) {
        case 1:
            turnLed(true);
            break;
        case 0:
            turnLed(false);
            break;
    }

    return esta;
}

void turnLed(bool status) {
    if (status) {
        digitalWrite(LED_PIN, HIGH);
        Particle.publish("encendido");
    } else {
        digitalWrite(LED_PIN, LOW);
        Particle.publish("apagado");
    }
}
