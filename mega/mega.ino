// #define TEST_MOTORS

// #include "motor.h"
#include "Common.h"
#include "time.h"
#include "sensors.h"
#include "follow.h"
#include "brightness.h"
#include "temperature.h"

void setup() {
    Serial.begin(9600);
    Serial2.begin(9600);
    Bluetooth.begin(9600);
    Bluetooth.setTimeout(15);
    setupSensors();
    setupFollow();
    setupMatrix();
}

unsigned long reportNumber = 1;
unsigned long bluetoothCommandsProcessed;

void printBluetooth() {
    Bluetooth.print("REPORT #");
    Bluetooth.println(reportNumber++);
    Bluetooth.print("Distance: ");
    Bluetooth.println(DistanceInCm);
    Bluetooth.print("Temperature: ");
    Bluetooth.println(TemperatureInCelsius);
    Bluetooth.print("Brightness: ");
    Bluetooth.println(Brightness);
    Bluetooth.print("Obstacle L: ");
    Bluetooth.println(ObstacleL);
    Bluetooth.print("Obstacle R: ");
    Bluetooth.println(ObstacleR);
    Bluetooth.print("Motor commands: ");
    Bluetooth.println(numMotorCommandsSent);
    Bluetooth.print("Display commands: ");
    Bluetooth.println(numDisplayCommandsSent);
    Bluetooth.print("Bluetooth commands: ");
    Bluetooth.println(bluetoothCommandsProcessed);
    Bluetooth.println("---");
}

unsigned long lastBluetoothPrint;
unsigned int bluetoothDelay = 5000; // this can be changed with the "bt" command

bool printedBluetooth;
// sloppy last-minute globals used to implement some commands
bool ded = false;
bool aaaaa = false;
bool stopped = false;

char first = 0;
char second = 0;

byte humanCommand = Command(Priority::HumanControl, Robot::Stop);

void handleBluetoothCommand() {
    if (!Bluetooth.available()) {
        return;
    }

    char c = Bluetooth.read();
    bool invalid = c <= ' ' || c == '\r' || c == '\n';
    if (!invalid && first == 0) {
        first = c;
    } else if (!invalid && second == 0) {
        second = c;
    }
    if (!(first && second)) {
        return;
    }

    if (MODE == Mode::Control) {
        SetMotors(humanCommand);
        if (first == 'f' && second == 'f') {
            bluetoothCommandsProcessed++;
            humanCommand = Command(Priority::HumanControl, Robot::Forward_Fast);
        } else if (first == 'f' && second == 's') {
            bluetoothCommandsProcessed++;
            humanCommand = Command(Priority::HumanControl, Robot::Forward_Slow);
        } else if (first == 'b' && second == 'k') {
            bluetoothCommandsProcessed++;
            humanCommand = Command(Priority::HumanControl, Robot::Reverse);
        } else if (first == 'r' && second == 'w') {
            bluetoothCommandsProcessed++;
            humanCommand = Command(Priority::HumanControl, Robot::WideRight);
        } else if (first == 'r' && second == 'f') {
            bluetoothCommandsProcessed++;
            humanCommand = Command(Priority::HumanControl, Robot::HardRight_Fast);
        } else if (first == 'r' && second == 'f') {
            bluetoothCommandsProcessed++;
            humanCommand = Command(Priority::HumanControl, Robot::HardRight_Slow);
        } else if (first == 'l' && second == 'w') {
            bluetoothCommandsProcessed++;
            humanCommand = Command(Priority::HumanControl, Robot::WideLeft);
        } else if (first == 'l' && second == 'f') {
            bluetoothCommandsProcessed++;
            humanCommand = Command(Priority::HumanControl, Robot::HardLeft_Fast);
        } else if (first == 'l' && second == 'f') {
            bluetoothCommandsProcessed++;
            humanCommand = Command(Priority::HumanControl, Robot::HardLeft_Slow);
        } else if (first == 'c' && second == 'n') {
            bluetoothCommandsProcessed++;
            MODE = Mode::Follow;
        }
    }

    if (first == 'p' && second == 'd') {
        bluetoothCommandsProcessed++;
        // print data on demand
        printedBluetooth = true;
        printBluetooth();
    } else if (first == 'd' && second == 'y') {
        bluetoothCommandsProcessed++;
        // play dead or wake up
        if (ded) {
            bluetoothCommandsProcessed++;
            ClearDisplayPriority(Priority::GodMode);
            ClearMotorPriority(Priority::GodMode);
        } else {
            SetDisplays(Priority::GodMode, Expression::Dead);
            SetMotors(Priority::GodMode, Robot::Stop);
        }
        ded = !ded;
    } else if (first == 'c' && second == 'n') {
        bluetoothCommandsProcessed++;
        MODE = Mode::Control;
    } else if (first == 'b' && second == 't') {
        bluetoothCommandsProcessed++;
        // set bluetooth report frequency
        // using String here oh well
        bluetoothDelay = Bluetooth.readStringUntil('\n').toInt();
    } else if (first == 'a' && second == 'a') {
        bluetoothCommandsProcessed++;
        if (aaaaa) {
            ClearDisplayPriority(Priority::GodMode);
        } else {
            SetDisplays(Priority::GodMode, Expression::AAAAA);
        }
        aaaaa = !aaaaa;
    } else if (first == 's' && second == 'p') {
        if (stopped) {
            ClearMotorPriority(Priority::GodMode);
        } else {
            SetMotors(Priority::GodMode, Robot::Stop);
        }
        stopped = !stopped;
    }

    first = 0;
    second = 0;
}

void loop() {
    printedBluetooth = false;
    loopTime();
    loopSensors();
    loopFollow();
    loopTemperature();
    loopBrightness();

    SetDisplays(Priority::Default, Expression::Happy);
    SetMotors(Priority::Default, Robot::Forward_Fast);

    handleBluetoothCommand();

    // print data regularly
    Guard(lastBluetoothPrint, bluetoothDelay)

    if (!printedBluetooth) {
        printBluetooth();
    }
}
