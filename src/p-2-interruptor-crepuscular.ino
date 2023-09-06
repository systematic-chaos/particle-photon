#define THRESHOLD 3000

void setup() {
    pinMode(A5, INPUT);
    pinMode(A0, OUTPUT);
    digitalWrite(A0, HIGH);
    
    pinMode(D0, OUTPUT);
}

void loop() {
    digitalWrite(D0, analogRead(A5) > THRESHOLD ? LOW : HIGH);
    delay(2000);
}
