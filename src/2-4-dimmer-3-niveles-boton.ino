#define LEVELS 4

void setup() {
    pinMode(A4, OUTPUT);
    
    pinMode(D5, INPUT_PULLDOWN);
    pinMode(D0, OUTPUT);
    digitalWrite(D0, HIGH);
}

void loop() {
    static uint32_t currentLevel = 0;
    static int32_t dimmer = LOW;
    
    int32_t switchStatus = digitalRead(D5);
    if (switchStatus != dimmer) {
        dimmer = switchStatus;
        currentLevel = (currentLevel + 1) % LEVELS;
        analogWrite(A4, (currentLevel << 8) / LEVELS);
    }
    
    delay(200);
}
