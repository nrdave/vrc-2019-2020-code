/**
 * The header file for the chassis class. This class is used for
 * controlling the chassis
 */ 

#pragma once
#include "okapi/api.hpp"

//Motor Ports
#define CHASSIS_MOTORPORT_L 11
#define CHASSIS_MOTORPORT_R 20

class Chassis {
    private:
        /**
        * the okapi chassis controller object, used for controlling the 
        * robot in driver
        */
        okapi::ChassisControllerIntegrated chassis;

    public:
        /**
        * The constructor for the chassis class
        * 
        * 
        * Right now I haven't planned any parameters, but in the future
        * I may add a way to specify how many motors are on the base, but
        * based on the way okapi's chassis controller factory works,
        * this may or may not be difficult
        */
        Chassis();
        /**
        * The function used to control the robot in opcontrol
        */ 
        void driver(okapi::Controller controller);
        /**
         * A function used in auton for turning to a specific angle
         * This is just a passthrough of the okapi::turnAngle function,
         * as the okapi chassis object is private to the chassis class
         */ 

        void turnAngle(okapi::QAngle angle);
        /**
         * This function is, as it name says, a function for making the robot move a specific distance
         * in autonomous. Unlike turnAngle, this function is more than a passthrough for the
         * okapiLib function of the same name. 
         * The first parameter, distance, is what you might think. The 
         * distance to travel (Using okapiLib's unit literals, I can enter a real distance, such as 10 inches)
         * The second parameter, velocity, determines the maximum velocity the chassis can run at
         */ 
        void moveDistance(okapi::QLength distance, double velocity);
};