#define PHOTO_RESISTOR A0
#define POWER_SOURCE A5

static double voltage;

void setup() {
    pinMode(PHOTO_RESISTOR, INPUT);

    pinMode(POWER_SOURCE, OUTPUT);
    digitalWrite(POWER_SOURCE, HIGH);
    
    Particle.variable("lighting", &voltage, DOUBLE);
}

void loop() {
    int32_t lumen = analogRead(PHOTO_RESISTOR);
    voltage = ((double) lumen) * 3.3 / (double) (0x1 << 12);
    
    delay(5000);
}
