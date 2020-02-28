/**
 * This file contains the implementation of the tray class
 * Here, all the functions and variables declared in tray.hpp are implemented, i.e.
 * the actual code for them is written
 */ 


#include "main.h"

Tray::Tray(): trayMotor(TRAY_MOTOR_PORT, false, 
    okapi::AbstractMotor::gearset::red, okapi::AbstractMotor::encoderUnits::degrees){
    
    okapi::Motor trayMotor(TRAY_MOTOR_PORT, false, 
    okapi::AbstractMotor::gearset::red, okapi::AbstractMotor::encoderUnits::degrees);
    trayMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    extended = false;
};

void Tray::driver(okapi::Controller controller){
    if(controller.getDigital(okapi::ControllerDigital::Y)){
        trayMotor.moveAbsolute(0,100);
    }
    if(controller.getDigital(okapi::ControllerDigital::up)){
        trayMotor.moveVelocity(100);
    }
    else if(controller.getDigital(okapi::ControllerDigital::down)){
        trayMotor.moveVelocity(-100);
    }
    else
        trayMotor.moveVelocity(0);    
}

void Tray::trayDown(){
    trayMotor.moveRelative(TRAY_MOTOR_ROTATION,100);
    extended = true;
}

void Tray::trayUp(){
    trayMotor.moveRelative(-TRAY_MOTOR_ROTATION, 100);
    extended = false;
}