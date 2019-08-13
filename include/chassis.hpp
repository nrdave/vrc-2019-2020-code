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
        * the okapi chassis controller object, used for 
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


};