#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led {
public:
    static const byte STATE_OFF = 0;
    static const byte STATE_ON = 1;
    static const byte STATE_BLINK = 2;

    Led(byte pin); 
    
    void setState(byte state);  
    void setBlinksPerSecond(byte bps);  
    void touch();  

private:
    byte pin;  
    byte state; 
    byte blinksPerSecond;  
    unsigned long previousMillis;  
    unsigned long blinkInterval;  
};

#endif
