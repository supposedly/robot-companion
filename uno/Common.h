#pragma once

#include "Commands.h"
#include <SoftwareSerial.h>

SoftwareSerial BruhSerial(8, 9);

#define GuardTime(lastRead, ms) if (Time - lastRead < ms) return; lastRead = Time;
#define GuardTenthSecond(lastRead) GuardTime(lastRead, 100)
#define GuardHalfSecond(lastRead) GuardTime(lastRead, 500)
#define GuardSecond(lastRead) GuardTime(lastRead, 1000)

// analog pins
#define tempPin 0
#define photocellPin 1

// digital pins
#define irPinL 2
#define irPinR 3
#define trigPin 4
#define echoPin 5

enum class Sensor {
    Distance,
    IR,
    Photocell,
    Temperature
};

byte Filter(byte b) {
    b &= 255;
    return b == 255 ? 254 : b;
}

// bluetooth.h
/* nothing */

// distance.h
unsigned long RawDistance;
float Distance;

// follow.h
unsigned long numMotorCommandsSent;
uint8_t lastMotorCommand;

// ir.h
volatile boolean ObstacleL = 0, ObstacleR = 0;

// matrix.h
/* nothing */

// photocell.h
int Brightness;

// temperature.h
int Temperature;
inline float TempInCelsius() { return (Temperature * 5.0f / 1024.f - 0.5f) * 100; }

// time.h
unsigned long Time;

// uart.h
/* nothing */
