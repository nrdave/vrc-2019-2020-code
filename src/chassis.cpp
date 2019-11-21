/**
 * The implementation of the chassis class
 * This file contains the code for the functions defined in chassis.hpp
 */ 


#include "main.h"

Chassis::Chassis(): chassis(okapi::ChassisControllerFactory::create(
    CHASSIS_MOTORPORT_L, -CHASSIS_MOTORPORT_R, okapi::AbstractMotor::gearset::green, {4_in, 13.25_in})){

        auto chassis = okapi::ChassisControllerFactory::create(
            CHASSIS_MOTORPORT_L, -CHASSIS_MOTORPORT_R, 
            okapi::AbstractMotor::gearset::green,
            {4_in, 13.25_in});
    }

void Chassis::driver(okapi::Controller controller) {
    double left = controller.getAnalog(okapi::ControllerAnalog::leftY);
    double right = controller.getAnalog(okapi::ControllerAnalog::rightY);
    chassis.tank(.8 * left, .8 * right, 0.05);
}

void Chassis::turnAngle(okapi::QAngle angle) {
    chassis.turnAngle(angle);
}

void Chassis::moveDistance(okapi::QLength distance, double velocity){
    chassis.setMaxVelocity(velocity);
    chassis.moveDistance(distance);
    chassis.setMaxVelocity(200);
}