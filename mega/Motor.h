#pragma once

#include <Arduino.h>
#include <AFMotor.h>

int currentMotorPriority;

AF_DCMotor LeftMotor(1);
AF_DCMotor RightMotor(2);

void RunMotors(byte left, byte right) {
    switch (right) {
        case 0b00:
            RightMotor.run(RELEASE);
            break;
        case 0b01:
            RightMotor.setSpeed(90);
            RightMotor.run(FORWARD);
            break;
        case 0b10:
            RightMotor.setSpeed(170);
            RightMotor.run(FORWARD);
            break;
        case 0b11:
            RightMotor.setSpeed(170);
            RightMotor.run(BACKWARD);
            break;
    }

    switch (left) {
        case 0b00:
            LeftMotor.run(RELEASE);
            break;
        case 0b01:
            LeftMotor.setSpeed(80);
            LeftMotor.run(FORWARD);
            break;
        case 0b10:
            LeftMotor.setSpeed(150);
            LeftMotor.run(FORWARD);
            break;
        case 0b11:
            LeftMotor.setSpeed(150);
            LeftMotor.run(BACKWARD);
            break;
    }
}

bool SetMotors(byte command) {
    uint8_t priority = (command & (0b1111 << PRIORITY_OFFSET)) >> PRIORITY_OFFSET;
    uint8_t left = (command & (0b11 << LEFT_MOTOR_OFFSET)) >> LEFT_MOTOR_OFFSET;
    uint8_t right = (command & (0b11 << RIGHT_MOTOR_OFFSET)) >> RIGHT_MOTOR_OFFSET;

    if ((int)priority >= currentMotorPriority) {
        currentMotorPriority = priority;
        RunMotors(left, right);
        return true;
    }
    return false;
}

bool SetMotors(Priority priority, Robot command) {
    return SetMotors(Command(priority, command));
}

void ClearMotorPriority(byte priority) {
    if (priority == currentMotorPriority) {
        currentMotorPriority = -1;
    }
}

void ClearMotorPriority(Priority priority) {
    ClearMotorPriority((byte) priority);
}
