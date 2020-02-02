/**
 * The header file for the chassis class. This class is used for
 * controlling the base wheels
 */ 

#pragma once
#include "okapi/api.hpp"

//Motor Ports
#define CHASSIS_MOTORPORT_LF 12
#define CHASSIS_MOTORPORT_RF 19
#define CHASSIS_MOTORPORT_LB 11
#define CHASSIS_MOTORPORT_RB 18

class Chassis {
    private:
        /**
         * okapi motor groups for each  side
         */ 
        okapi::MotorGroup rightBase;

        okapi::MotorGroup leftBase;

        static okapi::ChassisControllerIntegrated autonControl;
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
        */ 
        void moveDistance(float leftTarg, float rightTarg);

        void turnAngle(float angle);

        /**
         * -=-=-=-  NOT IMPLEMENTED YET -=-=-=-
         * 
         * 
         */
        void setVelocity(int velo);
};