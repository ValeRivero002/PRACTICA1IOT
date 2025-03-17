#include "DistanceSensor.h"

DistanceSensor::DistanceSensor(byte trigPin, byte echoPin) {
  this->trigPin = trigPin;
  this->echoPin = echoPin;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float DistanceSensor::getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) return -1;

  float distance = (duration * SOUND_SPEED) / 2.0;
  return distance;
}
