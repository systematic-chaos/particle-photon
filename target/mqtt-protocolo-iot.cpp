/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/home/thanatos/Documentos/lab/src/mqtt-protocolo-iot.ino"
#include <stdio.h>
#include <string.h>
#include "MQTT.h"

inline uint8_t max_uint(uint8_t a,  uint8_t b);
void setup();
void loop();
#line 5 "/home/thanatos/Documentos/lab/src/mqtt-protocolo-iot.ino"
double readPhotoResistor();
void subscribePhotoResistor(char* topic, byte* payload, unsigned int length);

inline uint8_t max_uint(uint8_t a,  uint8_t b) { return a >= b ? a : b; }

MQTT mqttClient("192.168.1.63", 1881, subscribePhotoResistor);

#define PHOTO_RESISTOR A0
#define POWER_SOURCE A5

const char event[] = "lighting";
const char volts[] = " volts";

void setup() {
    pinMode(PHOTO_RESISTOR, INPUT);

    pinMode(POWER_SOURCE, OUTPUT);
    digitalWrite(POWER_SOURCE, HIGH);

    mqttClient.connect(System.deviceID());
    if (mqttClient.isConnected()) {
        mqttClient.subscribe(event);
    }
}

void loop() {
    readPhotoResistor();

    mqttClient.loop();

    delay(2000);
}

/**
 * Read photoresistor, compute value and publish to MQTT topic.
 */
double readPhotoResistor() {
    double lumen = analogRead(PHOTO_RESISTOR) * 3.3 / (0x1 << 12);

    if (mqttClient.isConnected()) {
        char voltage[7];
        sprintf(voltage, "%.2f", lumen);
        mqttClient.publish(event, voltage);
    }

    return lumen;
}

/**
 * Callback when a message is received in the "lighting" MQTT topic.
 * Append the unit name and publish it as a Particle event.
 */
void subscribePhotoResistor(char* topic, byte* payload, unsigned int length) {
    if (strcmp(event, topic) != 0 || !mqttClient.isConnected()) {
        return;
    }

    char data[max_uint(length, 10)];
    if (length) {
        memcpy(data, payload, length);
        data[length] = '\0';
    } else {
        strcpy(data, "undefined");
    }
    strcat(data, volts);
    
    Particle.publish(volts + 1 * sizeof(char), data);
}
