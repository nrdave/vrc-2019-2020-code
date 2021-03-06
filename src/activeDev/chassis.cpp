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
    leftBase.controllerSet(controller.getAnalog(okapi::ControllerAnalog::leftY));
    rightBase.controllerSet(controller.getAnalog(okapi::ControllerAnalog::rightY));
}

void Chassis::moveDistance(float leftTarg, float rightTarg, int maxVelo){
    leftTarg *= 90;
    rightTarg *= 90;
    leftBase.tarePosition();
    rightBase.tarePosition();
    float leftError = leftTarg - leftBase.getPosition(); 
    float rightError = rightTarg - rightBase.getPosition(); 
    while(abs(leftError) > 20 && abs(rightError) > 20){
        float leftOutput = leftError * 0.5;
        float rightOutput = rightError * 0.5;
        if(leftOutput > maxVelo)
            if(leftOutput < 0)
                leftOutput = -maxVelo;
            else
                leftOutput = maxVelo;
        if(rightOutput > maxVelo)
            if(rightOutput < 0)
                rightOutput = -maxVelo;
            else
                rightOutput = maxVelo;        
        setVelocity(leftOutput, rightOutput);
        leftError = leftTarg - leftBase.getPosition(); 
        rightError = rightTarg - rightBase.getPosition(); 
        pros::delay(20);
    }
    setVelocity(0,0);
}

void Chassis::turnAngle(float angle, float speed){
    double turnLength = 6.65/3 * angle * (3.1415926535/180);
    moveDistance(turnLength, -turnLength, speed);
}

void Chassis::setVelocity(float leftVelo, float rightVelo){
    leftBase.moveVelocity(leftVelo);
    rightBase.moveVelocity(rightVelo);
}