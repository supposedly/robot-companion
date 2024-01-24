#pragma once
#include "Common.h"

unsigned long lastIRRead;

/*
// IR JSR
void irL() {
    //noInterrupts();
    ObstacleL = !ObstacleL;
    // bool current = ObstacleL;
    //interrupts();
}

void irR() {
    //noInterrupts();
    ObstacleR = !ObstacleR;
    // bool current = ObstacleR;
    //interrupts();
}
*/

void setupIR() {
    ObstacleL = !digitalRead(irPinL);
    ObstacleR = !digitalRead(irPinR);

    // this proved unreliable :(
    /*
    attachInterrupt(digitalPinToInterrupt(irPinL), irL, CHANGE);
    attachInterrupt(digitalPinToInterrupt(irPinR), irR, CHANGE);
    */
}

void loopIR() {
    GuardTenthSecond(lastIRRead)

    ObstacleL = !digitalRead(irPinL);
    ObstacleR = !digitalRead(irPinR);
    BruhSerial.write((uint8_t) Sensor::IR);
    BruhSerial.write(ObstacleL);
    BruhSerial.write(ObstacleR);
    BruhSerial.write((byte) 255);
}
