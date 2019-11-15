/**
 * This file contains declarations for the tray class, which is used for 
 * moving the cube tray
 */ 

#pragma once
#include "okapi/api.hpp"

#define TRAY_MOTOR_PORT 5
#define TRAY_MOTOR_ROTATION 750

class Tray{
    private:
    //The motor used to move the tray
        okapi::Motor trayMotor;
    //A variable used to see if the tray is extended or not
        bool extended;

    
    public:
    //The constructor for a tray object
        Tray();

    //The function for controlling the tray in opcontrol
        void driver(okapi::Controller controller);
    //A function that runs motor commands to put the tray in the position to release cubes
        void trayDown();
    //A function to run motor commands to pull the tray to its default, collecting position.
        void trayUp();

};