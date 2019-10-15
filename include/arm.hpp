#pragma once
#include "okapi/api.hpp"

//The port of the arm motor
#define ARM_LMOTOR_PORT 19
#define ARM_RMOTOR_PORT 9
//the speed for the arm motor to run at in opcontrol
#define ARM_MOTOR_SPEED 100
class Arm{
    private:
        okapi::Motor leftArmMotor;
        
        okapi::Motor rightArmMotor;

    public:
        Arm();

        void driver(okapi::Controller controller);

        void moveTo(double input);
        
};