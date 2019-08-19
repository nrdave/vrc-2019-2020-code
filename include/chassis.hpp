/**
 * The header file for the chassis class. This class is used for
 * controlling the chassis
 */ 

#pragma once
#include "okapi/api.hpp";

//Motor Ports
#define CHASSIS_MOTORPORT_LF 1
#define CHASSIS_MOTORPORT_RF 2
#define CHASSIS_MOTORPORT_LB 3
#define CHASSIS_MOTORPORT_RB 4

class Chassis {
    private:
    /**
     * Declaring the motors used in the base, along with the motor groups used to control
     * them easier. I opted for these over the okapi ChassisController as the
     * ChassisController doesn't offer the same low level control individual motor groups
     * have, which I wanted for programming autonomous.
     */ 
        okapi::Motor leftBackMtr;

        okapi::Motor leftFrontMtr;

        okapi::Motor rightBackMtr;

        okapi::Motor rightFrontMtr;

        okapi::MotorGroup rightWheels;

        okapi::MotorGroup leftWheels;
    public:
        /**
        * The constructor for the chassis class
        */
        Chassis();
        /**
        * The function used to control the robot in opcontrol
        */ 
        void driver(okapi::Controller controller);


};