#include "Common.h"

void setupBrightness() {}

void loopBrightness() {
    if (Brightness < 200) {
        if (SetMotors(Priority::Photocell, Robot::Stop)) {
            numMotorCommandsSent++;
        }
        if (SetDisplays(Priority::Photocell, Expression::Sleep)) {
            numDisplayCommandsSent++;
        }
    } else {
        ClearMotorPriority(Priority::Photocell);
        ClearDisplayPriority(Priority::Photocell);
    }
}
