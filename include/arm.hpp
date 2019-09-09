#pragma once
#include "okapi/api.hpp"


#define ARM_MOTOR_PORT 19
#define ARM_MOTOR_VELOCITY 20
class Arm{
    private:
        okapi::Motor armMotor;

    public:
        Arm();

        void driver(okapi::Controller controller);

        void moveTo(double input);
};