#pragma once

#include "Common.h"

Sensor currentSensor;
bool currentlyReading = false;
int currentByte = 0;
uint8_t b[4];

void setupSensors() {
}

void setByte() {
    switch (currentSensor) {
        case Sensor::Distance: {
            RawDistance = (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | (b[0]);
            float soundSpeed = (331.3f + 0.606f * TemperatureInCelsius) / 10000.f;
            DistanceInCm = ((RawDistance / 2.f) * soundSpeed);
            break;
        }
        case Sensor::IR: {
            ObstacleL = b[0] & 0b1;
            ObstacleR = b[1] & 0b1;
            break;
        }
        case Sensor::Photocell: {
            Brightness = (b[1] << 8) | (b[0]);
            break;
        }
        case Sensor::Temperature: {
            RawTemperature = (b[1] << 8) | (b[0]);
            TemperatureInCelsius = (RawTemperature * 5.0f / 1024.f - 0.5f) * 100;
            break;
        }
    }
}

unsigned long e;

void loopSensors() {
    if (Serial2.available()) {
        uint8_t newByte = Serial2.read();
        if (newByte == 255) {
            setByte();
            b[0] = 0;
            b[1] = 0;
            b[2] = 0;
            b[3] = 0;
            currentByte = -1;
        } else if (currentByte >= 0) {
            b[currentByte++] = newByte;
        } else {
            currentSensor = (Sensor) newByte;
            currentByte++;
        }
    }
}
