#pragma once

#include "Commands.h"
#include "Motor.h"
#include "Display.h"

// #include <SoftwareSerial.h>
#include <AFMotor.h>

#define Guard(lastRead, ms) if (Time - lastRead < ms) return; lastRead = Time;
#define GuardTenthSecond(lastRead) Guard(lastRead, 100)
#define GuardHalfSecond(lastRead) Guard(lastRead, 500)
#define GuardSecond(lastRead) Guard(lastRead, 1000)

#define btRx 27
#define btTx 26

// SoftwareSerial Bluetooth(btRx, btTx);
#define Bluetooth Serial3

enum class Sensor {
    Distance,
    IR,
    Photocell,
    Temperature
};

// mode of robot (more could be added)
enum class Mode {
    Follow,
    Control
};
Mode MODE;

unsigned long numMotorCommandsSent;
unsigned long numDisplayCommandsSent;

// sensors.h
unsigned long RawDistance;
int RawTemperature;
float TemperatureInCelsius;
float DistanceInCm;
int Brightness;
bool ObstacleL;
bool ObstacleR;
/*
inline float TempInCelsius() { return (Temperature * 5.0f / 1024.f - 0.5f) * 100; }
inline float DistanceInCm() { 
    // https://www.teachmemicro.com/ultrasonic-sensor-temperature-compensation/
    float soundSpeed = (331.3f + 0.606f * TempInCelsius()) / 10000.f;
    return ((RawDistance / 2.f) * soundSpeed);
}
*/


// time.h
unsigned long Time;
