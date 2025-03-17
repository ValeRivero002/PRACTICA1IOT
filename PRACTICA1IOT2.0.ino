#include <Arduino.h>
#include "Led.h"
#include "DistanceSensor.h"

// Pines del ESP32
#define TRIG_PIN 15
#define ECHO_PIN 4
#define INTERVALO_CAMBIO 10000 


#define LED_ROJO 23
#define LED_AMARILLO 22
#define LED_VERDE 21
#define DISTANCE_RED_LED 10
#define DISTANCE_YELLOW_LED 20
#define DISTANCE_GREEN_LED 35



DistanceSensor sensor(TRIG_PIN, ECHO_PIN);


Led RedLed(LED_ROJO);
Led YellowLed(LED_AMARILLO);
Led GreenLed(LED_VERDE);


unsigned long previousMillis = 0;

void setup() {
    Serial.begin(115200);
}

void loop() {
    unsigned long currentMillis = millis();
    
    float distance = sensor.getDistance();


    Serial.print("Distancia: ");
    Serial.print(distance);
    Serial.println(" cm");

    RedLed.setState(Led::STATE_OFF);
    YellowLed.setState(Led::STATE_OFF);
    GreenLed.setState(Led::STATE_OFF);

    if (distance == -1) {
        Serial.println("Error: No se detecta señal del sensor");
        return;
    }

    if (distance >= 0 && distance <= DISTANCE_RED_LED) {
        RedLed.setState(Led::STATE_ON);
    } else if (distance > DISTANCE_RED_LED && distance <= DISTANCE_YELLOW_LED) {
        RedLed.setState(Led::STATE_ON);
        YellowLed.setState(Led::STATE_ON);
    } else if (distance > DISTANCE_YELLOW_LED && distance <= DISTANCE_GREEN_LED) {
        RedLed.setState(Led::STATE_ON);
        YellowLed.setState(Led::STATE_ON);
        GreenLed.setState(Led::STATE_ON);
    } else if (distance > DISTANCE_GREEN_LED) {
        RedLed.setBlinksPerSecond(3);
        YellowLed.setBlinksPerSecond(3);
        GreenLed.setBlinksPerSecond(3);
        RedLed.setState(Led::STATE_BLINK);
        YellowLed.setState(Led::STATE_BLINK);
        GreenLed.setState(Led::STATE_BLINK);
    }

    RedLed.touch();
    YellowLed.touch();
    GreenLed.touch();

    delay(50);  
}