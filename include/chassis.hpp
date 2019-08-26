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
         * This is just a passthrough of the okapi::turnAngle function,
         * as the okapi chassis object is private to the chassis class
         */ 

        void turnAngle(okapi::QAngle angle);
        /**
         * Similar to turnAngle, this function acts as a passthrough to the
         * okapi::moveDistanceAsyc.
         */ 
        void moveDistance(okapi::QLength distance);
};