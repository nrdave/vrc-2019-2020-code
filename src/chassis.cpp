/**
 * The implementation of the chassis class
 * This file contains the code for the functions defined in chassis.hpp
 */ 


#include "main.h"

Chassis::Chassis(): chassis(okapi::ChassisControllerFactory::create(
    {CHASSIS_MOTORPORT_LF, -CHASSIS_MOTORPORT_LB},
    {-CHASSIS_MOTORPORT_RF, CHASSIS_MOTORPORT_RB}, okapi::AbstractMotor::gearset::green)){

        auto chassis = okapi::ChassisControllerFactory::create(
            {CHASSIS_MOTORPORT_LF, -CHASSIS_MOTORPORT_LB}, 
            {-CHASSIS_MOTORPORT_RF, CHASSIS_MOTORPORT_RB}, okapi::AbstractMotor::gearset::green);
    }

void Chassis::driver(okapi::Controller controller) {
    double left;
    double right;
    left = controller.getAnalog(okapi::ControllerAnalog::leftY);
    right = controller.getAnalog(okapi::ControllerAnalog::rightY);
    chassis.tank(left, right, 0.05);
}

void Chassis::turnAngle(okapi::QAngle angle) {
    chassis.turnAngle(angle);
}

void Chassis::moveDistance(okapi::QLength distance){
    chassis.moveDistanceAsync(distance);
}