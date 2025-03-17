#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H

#include <Arduino.h>

#define SOUND_SPEED 0.0343

class DistanceSensor {
private:
  byte trigPin;
  byte echoPin;

public:
  DistanceSensor(byte trigPin, byte echoPin);
  float getDistance();
};

#endif 
