#pragma once
#define BLUETOOTH_SEND_FREQ 10000

#include <SoftwareSerial.h>
#include "Common.h"

unsigned long lastSentBluetooth;
unsigned long numMessagesSent;

// bluetooth pins
// SoftwareSerial BTSerial(btRx, btTx);

void setupBluetooth() {
    // BTSerial.begin(9600);
    // BTSerial.setTimeout(10);
}

void loopBluetooth() {
    /*
    // uncomment this when implementing controller mode
    if (BTSerial.available()) {
        Serial.write(BTSerial.read());
    }
    */

    GuardTime(lastSentBluetooth, BLUETOOTH_SEND_FREQ)

    // BTSerial.print("Report #");
    // BTSerial.print(numMessagesSent++);
    // BTSerial.print(" - Motor commands sent: ");
    // BTSerial.println(numMotorCommandsSent);
    // BTSerial.print("Distance (cm): ");
    // BTSerial.println(Distance);
    // BTSerial.print("IRs blocked: ");
    // BTSerial.println(
    //     ObstacleL && ObstacleR ? "left right" : (
    //         ObstacleL ? "left" : (ObstacleR ? "right" : "none")
    //     )
    // );
    // BTSerial.print("Light level: ");
    // BTSerial.println(Brightness);
    // BTSerial.print("Temperature (C): ");
    // BTSerial.println(Temperature);
}
