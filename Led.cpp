#include "Led.h"

Led::Led(byte pin) {
    this->pin = pin;
    pinMode(pin, OUTPUT);
    state = STATE_OFF;
    blinksPerSecond = 2;  
    previousMillis = 0;
    blinkInterval = 1000 / blinksPerSecond;  
}

void Led::setState(byte state) {
    this->state = state;
    if (state == STATE_OFF) {
        digitalWrite(pin, LOW);  
    } else if (state == STATE_ON) {
        digitalWrite(pin, HIGH); 
    }
}

void Led::setBlinksPerSecond(byte bps) {
    blinksPerSecond = bps;
    blinkInterval = 1000 / blinksPerSecond;  
}

void Led::touch() {
    if (state == STATE_BLINK) {
        unsigned long currentMillis = millis();
        
        if (currentMillis - previousMillis >= blinkInterval) {
            previousMillis = currentMillis;  
            digitalWrite(pin, !digitalRead(pin));
        }
    }
}
