#define ANALOG_PIN A4

void setup() {
    pinMode(ANALOG_PIN, OUTPUT);
    
    analogWrite(ANALOG_PIN, 128, 500);
}

void loop() {
    delay(2000);
}
