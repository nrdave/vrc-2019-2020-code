#pragma once
#include "main.h"


#define ARM_MOTOR_PORT 8
class Arm{
    private:
        okapi::Motor armMotor;

    public:
        Arm();

        void driver(okapi::Controller controller);

        void moveTo();
}