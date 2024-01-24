#include "bluetooth.h"
#include "distance.h"
#include "ir.h"
#include "photocell.h"
#include "temperature.h"
#include "time.h"

void setup()
{
    Serial.begin(9600);
    BruhSerial.begin(9600);
    Serial.setTimeout(10);

    Serial.println("Hi");

    setupBluetooth();
    setupDistance();
    setupIR();
    setupPhotocell();
    setupTemperature();
    setupTime();
}

void loop()
{
    // if (BruhSerial.available()) {
    //     Serial.println("bruh");
    //     Serial.println(BruhSerial.read());
    // }
    loopTime();
    loopIR();
    loopDistance();
    loopPhotocell();
    loopTemperature();
    loopBluetooth();
    BruhSerial.flush();
}
