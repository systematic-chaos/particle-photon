#define ANALOG_PIN A3

void setup() {
    pinMode(ANALOG_PIN, OUTPUT);
    analogWrite(ANALOG_PIN, 3350);
}

void loop() {
    delay(2000);
}
