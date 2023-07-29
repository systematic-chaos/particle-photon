void flash(unsigned short flash, unsigned short stop);
void flashTimes(unsigned short duration, unsigned short gap, unsigned char times);

#define S() (flashTimes(300,  300, 3))
#define O() (flashTimes(1000, 300, 3))
#define BLANK() (flashTimes(0, 1000, 1))

void setup() {
    // Configuración de estado, pines E/S
    RGB.control(true);
    RGB.color(255, 0, 0);
}

void loop() {
    // Código de programa
    S();
    O();
    S();
    BLANK();
}

void flash(unsigned short duration, unsigned short gap) {
    // Generar flash de duración y espera pasados como parámetro
    RGB.brightness(0x40);
    delay(duration);
    RGB.brightness(0);
    delay(gap);
}

void flashTimes(unsigned short duration, unsigned short gap, unsigned char times) {
    for (unsigned char n = 0; n < times; n++) {
        flash(duration, gap);
    }
}
