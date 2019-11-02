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
    if(controller.getDigital(okapi::ControllerDigital::A)){
        trayDown();
    }    
    if(controller.getDigital(okapi::ControllerDigital::B)){
        trayUp();
    }
}

void Tray::trayDown(){
    trayMotor.moveRelative(-TRAY_MOTOR_ROTATION,100);
}

void Tray::trayUp(){
    trayMotor.moveRelative(TRAY_MOTOR_ROTATION, 100);
}