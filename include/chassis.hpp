/**
 * The header file for the chassis class. This class is used for
 * controlling the chassis
 */ 

#pragma once
#include "okapi/api.hpp"

//Motor Ports
#define CHASSIS_MOTORPORT_L 20
#define CHASSIS_MOTORPORT_R 10


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
         * This is just a slight simplification of the okapi chassis
         * turnAngle function. Instead of specifying that the parameter
         * is of type okapi::QAngle each time I call it, I only have to do 
         * so in chassis.cpp 
         */ 

        void turnAngle(okapi::QAngle angle);
        /**
         * Similar to turnAngle, this function acts as a simplifier
         * to the okapi::moveDistanceAsync function, removing the need to 
         * specify the parameter's type as okapi::QLength
         */ 
        void moveDistance(okapi::QLength distance);
};