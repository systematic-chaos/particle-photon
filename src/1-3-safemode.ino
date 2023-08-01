// Configuración de estado, pines E/S
void setup() {
    pinMode(D7, OUTPUT);
    RGB.control(true);
    RGB.color(0, 0, 255);
}

// Código de programa
void loop() {
    digitalWrite(D7, HIGH);
    
    RGB.brightness(64);
    
    delay(3000);
    
    // Raising runtime error
    int err = 1 / 0;
    delay(err);
    
    RGB.brightness(0);
    delay(10000);
}
