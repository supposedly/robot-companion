#pragma once
#include "Common.h"

unsigned long lastPhotocellRead;

void setupPhotocell() {}

void loopPhotocell() {
    GuardHalfSecond(lastPhotocellRead)

    Brightness = analogRead(photocellPin);
    BruhSerial.write((byte) Sensor::Photocell);
    // BruhSerial.write((byte*) &Brightness, sizeof(Brightness));
    byte buf[2] = {
        Filter(Brightness),
        Filter(Brightness >> 8)
    };
    BruhSerial.write(buf, 2);
    BruhSerial.write((byte) 255);
}
