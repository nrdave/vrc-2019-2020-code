#pragma once
#include "okapi/api.hpp"

//The port of the arm motor
#define ARM_LMOTOR_PORT 12
#define ARM_RMOTOR_PORT 19
//the speed for the arm motor ttotototoo run at in opcontrol
#define ARM_MOTOR_SPEED 100
class Arm{
    private:

    //Declarations for the motors on the arm
        okapi::Motor leftArmMotor;
        
        okapi::Motor rightArmMotor;

    public:
    //The constructor for an arm object
        Arm();
    /**The driver function for the arm. This uses the controller input from the L1 and L2 buttons to 
     * control the position of the arm
     */ 
        void driver(okapi::Controller controller);
    //A function to move the arm to a specific position, in degrees.
        void moveTo(double input);
        
};