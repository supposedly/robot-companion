#pragma once

#include "Common.h"

unsigned long lastTempRead = 0;

void setupTemperature() {}

void loopTemperature() {
    GuardSecond(lastTempRead)

    Temperature = analogRead(tempPin);
    BruhSerial.write((byte) Sensor::Temperature);
    // BruhSerial.write((byte*) &Temperature, sizeof(Temperature));
    byte buf[2] = {
        Filter(Temperature),
        Filter(Temperature >> 8)
    };
    BruhSerial.write(buf, 2);
    BruhSerial.write((byte) 255);
}
