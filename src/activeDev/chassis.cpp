/**
 * The implementation of the chassis class
 * This file contains the code for the functions defined in chassis.hpp
 */ 


#include "main.h"

Chassis::Chassis():rightBase({okapi::Motor(CHASSIS_MOTORPORT_RF, 
                true, okapi::AbstractMotor::gearset::green,
                okapi::AbstractMotor::encoderUnits::degrees), 
                okapi::Motor(CHASSIS_MOTORPORT_RB, 
                true, okapi::AbstractMotor::gearset::green,
                okapi::AbstractMotor::encoderUnits::degrees)}), 
                leftBase({okapi::Motor(CHASSIS_MOTORPORT_LF, 
                false, okapi::AbstractMotor::gearset::green,
                okapi::AbstractMotor::encoderUnits::degrees), 
                okapi::Motor(CHASSIS_MOTORPORT_LB, 
                false, okapi::AbstractMotor::gearset::green,
                okapi::AbstractMotor::encoderUnits::degrees)})
    {
        okapi::MotorGroup rightBase({okapi::Motor(CHASSIS_MOTORPORT_RF, 
                true, okapi::AbstractMotor::gearset::green,
                okapi::AbstractMotor::encoderUnits::degrees), 
                okapi::Motor(CHASSIS_MOTORPORT_RB, 
                true, okapi::AbstractMotor::gearset::green,
                okapi::AbstractMotor::encoderUnits::degrees)});
        okapi::MotorGroup leftBase({okapi::Motor(CHASSIS_MOTORPORT_LF, 
                false, okapi::AbstractMotor::gearset::green,
                okapi::AbstractMotor::encoderUnits::degrees), 
                okapi::Motor(CHASSIS_MOTORPORT_LB, 
                false, okapi::AbstractMotor::gearset::green,
                okapi::AbstractMotor::encoderUnits::degrees)});

    }

void Chassis::driver(okapi::Controller controller) {
    double left = controller.getAnalog(okapi::ControllerAnalog::leftY);
    double right = controller.getAnalog(okapi::ControllerAnalog::rightY);
    leftBase.controllerSet(left);
    rightBase.controllerSet(right);
}

void Chassis::moveDistance(float leftTarg, float rightTarg){
    //leftTarg *= 90;
    //rightTarg *= 90;
    leftBase.tarePosition();
    rightBase.tarePosition();
    float leftError = leftTarg - leftBase.getPosition(); 
    float rightError = rightTarg - rightBase.getPosition(); 
    while(abs(leftError) > 20){
        pros::delay(20);
        float leftOutput = leftError * 0.5;
        float rightOutput = rightError * 0.5;
        leftBase.moveVelocity(leftOutput);
        rightBase.moveVelocity(rightOutput);
        float leftError = leftTarg - leftBase.getPosition(); 
        float rightError = rightTarg - rightBase.getPosition(); 
    }
    leftBase.moveVelocity(0);
    rightBase.moveVelocity(0);
}

void Chassis::turnAngle(float angle){
    
}

void Chassis::setVelocity(int velo){
    leftBase.moveVelocity(velo);
    rightBase.moveVelocity(velo);
}