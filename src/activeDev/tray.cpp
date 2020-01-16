/**
 * This file contains the implementation of the tray class
 * Here, all the functions and variables declared in tray.hpp are implemented, i.e.
 * the actual code for them is written
 */ 


#include "main.h"

Tray::Tray(): trayMotor(TRAY_MOTOR_PORT){
    
    okapi::Motor trayMotor(TRAY_MOTOR_PORT, true, 
    okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
    trayMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    extended = false;
};

void Tray::driver(okapi::Controller controller){
    if(controller.getDigital(okapi::ControllerDigital::Y)){
        trayMotor.moveAbsolute(0,100);
    }
    if(controller.getDigital(okapi::ControllerDigital::A)){
        if(extended == false)
        {
            trayDown();
            extended = true;
        }
    }    
    if(controller.getDigital(okapi::ControllerDigital::B)){
        if(extended == true)
        {
            trayUp();
            extended = false;
        }
    }
}

void Tray::trayDown(){
    trayMotor.moveRelative(TRAY_MOTOR_ROTATION,100);
    extended = true;
}

void Tray::trayUp(){
    trayMotor.moveRelative(-TRAY_MOTOR_ROTATION, 100);
    extended = false;
}