#pragma once

#include "Common.h"

unsigned long lastSentFollowCommand;

void setupFollow() {
}

void loopFollow() {
    GuardTenthSecond(lastSentFollowCommand)

    bool success;

    if (DistanceInCm <= 15) {
        // stop bc dunno where the hand even is
        success = SetMotors(Priority::ProximitySensors, Robot::Stop);
    } else if (ObstacleL && ObstacleR) {
        // stop cuz there's an obstacle on both sides
        success = SetMotors(Priority::ProximitySensors, Robot::Stop);
    } else if (ObstacleL) {
        // turn to the right
        success = SetMotors(Priority::ProximitySensors, Robot::WideLeft);
    } else if (ObstacleR) {
        // turn to the left
        success = SetMotors(Priority::ProximitySensors, Robot::WideRight);
    } else {
        // move forward bc it's all clear
        ClearMotorPriority(Priority::ProximitySensors);
        SetMotors(Priority::Default, Robot::Forward_Fast);
        success = false;
    }

    if (success) {
        numMotorCommandsSent++;
    }
}
