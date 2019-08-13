/**
 * This file contains declarations for the tray class, which is used for 
 * moving the cube tray
 */ 

#pragma once
#include "okapi/api.hpp"

#define TRAY_MOTOR_PORT 5

class Tray{
    private:
        okapi::Motor trayMotor;

        bool extended;

        bool pressed;
    
    public:

        Tray();


        void driver(okapi::Controller controller);

};