#pragma once
#include "okapi/api.hpp"

//The port of the arm motor
#define ARM_MOTOR_PORT 19
//the speed for the arm motor to run at in opcontrol
#define ARM_MOTOR_SPEED 20
class Arm{
    private:
        okapi::Motor armMotor;

    public:
        Arm();

        void driver(okapi::Controller controller);

        void moveTo(double input);
        
};