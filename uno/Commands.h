#define RIGHT_MOTOR_OFFSET 2
#define LEFT_MOTOR_OFFSET 0
#define PRIORITY_OFFSET 4

enum class Motor {
    Stop = 0b00,
    Slow = 0b01,
    Fast = 0b10,
    Reverse = 0b11
};

enum class Robot {
    Stop,
    Reverse,
    ReverseRight,
    ReverseLeft,
    Forward_Slow,
    Forward_Fast,
    HardRight_Slow,
    HardRight_Fast,
    WideRight,
    HardLeft_Slow,
    HardLeft_Fast,
    WideLeft,
};

enum class Priority {
    HumanControl = 0,
    Temperature = 1,
    ProximitySensors = 2,
    Photocell = 3
};

uint8_t Command(Priority cp, Motor leftMotor, Motor rightMotor) {
    return ((char)cp << PRIORITY_OFFSET) | ((char)leftMotor << LEFT_MOTOR_OFFSET) | ((char)rightMotor << RIGHT_MOTOR_OFFSET);
}

uint8_t Command(Priority cp, Robot rb) {
    switch (rb)
    {
        case Robot::Stop:
            return Command(
                cp,
                Motor::Stop,
                Motor::Stop
            );
            break;
        case Robot::Reverse:
            return Command(
                cp,
                Motor::Reverse,
                Motor::Reverse
            );
            break;
        case Robot::ReverseRight:
            return Command(
                cp,
                Motor::Reverse,
                Motor::Stop
            );
            break;
        case Robot::ReverseLeft:
            return Command(
                cp,
                Motor::Stop,
                Motor::Reverse
            );
            break;
        case Robot::Forward_Slow:
            return Command(
                cp,
                Motor::Slow,
                Motor::Slow
            );
            break;
        case Robot::Forward_Fast:
            return Command(
                cp,
                Motor::Fast,
                Motor::Fast
            );
            break;
        case Robot::HardRight_Slow:
            return Command(
                cp,
                Motor::Slow,
                Motor::Stop
            );
            break;
        case Robot::HardRight_Fast:
            return Command(
                cp,
                Motor::Fast,
                Motor::Stop
            );
            break;
        case Robot::WideRight:
            return Command(
                cp,
                Motor::Fast,
                Motor::Slow
            );
            break;
        case Robot::HardLeft_Slow:
            return Command(
                cp,
                Motor::Stop,
                Motor::Slow
            );
            break;
        case Robot::HardLeft_Fast:
            return Command(
                cp,
                Motor::Stop,
                Motor::Fast
            );
            break;
        case Robot::WideLeft:
            return Command(
                cp,
                Motor::Slow,
                Motor::Fast
            );
            break;
    }
}
