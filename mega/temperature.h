#include "Common.h"

unsigned long lastSentTemperatureCommand;

void setupTemperature() {}

void loopTemperature() {
    GuardTenthSecond(lastSentTemperatureCommand)

    bool success;

    if (TemperatureInCelsius < 21.00) {
        success = SetDisplays(Priority::Temperature, Expression::Shiver);
    } else if (TemperatureInCelsius > 39.00) {
        success = SetDisplays(Priority::Temperature, Expression::Sweat);
    } else {
        ClearDisplayPriority(Priority::Temperature);
    }

    if (success) {
        numDisplayCommandsSent++;
    }
}
