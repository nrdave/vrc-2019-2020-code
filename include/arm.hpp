#pragma once
#include "okapi/api.hpp"

//The port of the arm motor
#define ARM_MOTOR_PORT 1
//the speed for the arm motor ttotototoo run at in opcontrol
#define ARM_MOTOR_SPEED 100
class Arm{
    private:

    //Declarations for the motor on the arm
        okapi::Motor armMotor;
        
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