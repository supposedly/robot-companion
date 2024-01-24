#pragma once
#include "Common.h"

unsigned long lastDistanceRead = 0;

void setupDistance() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loopDistance() {
    //GuardSecond(lastDistanceRead)
    GuardSecond(lastDistanceRead)

    float duration;

    // turn off prepare to send a signal to trigger pin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    // send high signal to trigger sensor
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);

    // turn off
    digitalWrite(trigPin, LOW);

    // read the echo pin to get echo time in us
    RawDistance = pulseIn(echoPin, HIGH);
    duration = RawDistance / 2.f;  // divide by 2 bc the original number is a round trip

    float temp = TempInCelsius();

    // https://www.teachmemicro.com/ultrasonic-sensor-temperature-compensation/
    float soundSpeed = 331.3f + 0.606f * temp;
    soundSpeed /= 10000.f;  // website says this converts to centimeters per millisecond

    Distance = duration * soundSpeed;
    Serial.println("Distance");
    Serial.println(RawDistance);
    BruhSerial.write((byte) Sensor::Distance);
    // BruhSerial.write((byte*) &RawDistance, sizeof(RawDistance));
    byte buf[4] = {
        Filter(RawDistance),
        Filter(RawDistance >> 8),
        Filter(RawDistance >> 16),
        Filter(RawDistance >> 24)
    };
    BruhSerial.write(buf, 4);
    BruhSerial.write((byte) 255);

    //distance = (duration / 2.0) / 29.1;  // convert to cm without factoring temperature in
}
