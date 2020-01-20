/**
 * The implementation of the chassis class
 * This file contains the code for the functions defined in chassis.hpp
 */ 


#include "main.h"

Chassis::Chassis(): chassis(okapi::ChassisControllerFactory::create(
    {CHASSIS_MOTORPORT_LF, CHASSIS_MOTORPORT_LB},
    {-CHASSIS_MOTORPORT_RF, -CHASSIS_MOTORPORT_RB},
    okapi::AbstractMotor::gearset::green, {4_in, 13.25_in})),
    rfMotor(CHASSIS_MOTORPORT_RF), 
    lfMotor(CHASSIS_MOTORPORT_LF), 
    rbMotor(CHASSIS_MOTORPORT_RB), 
    lbMotor(CHASSIS_MOTORPORT_LB) 
    {

        auto chassis = okapi::ChassisControllerFactory::create(
            {CHASSIS_MOTORPORT_LF, CHASSIS_MOTORPORT_LB},
            {-CHASSIS_MOTORPORT_RF, -CHASSIS_MOTORPORT_RB},
            okapi::AbstractMotor::gearset::green, {4_in, 13.25_in});

        okapi::Motor rfMotor(CHASSIS_MOTORPORT_RF, true,
        okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);

        okapi::Motor lfMotor(CHASSIS_MOTORPORT_LF, false,            
        okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);

        okapi::Motor lbMotor(CHASSIS_MOTORPORT_LB, false,            
        okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);

        okapi::Motor rbMotor(CHASSIS_MOTORPORT_RB, true,            
        okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
    }

void Chassis::driver(okapi::Controller controller) {
    double left = controller.getAnalog(okapi::ControllerAnalog::leftY);
    double right = controller.getAnalog(okapi::ControllerAnalog::rightY);
    chassis.tank(left, right, 0.05);
}

void Chassis::turnAngle(okapi::QAngle angle) {
    chassis.turnAngle(angle);
}

void Chassis::moveDistance(okapi::QLength distance, double velocity){
    chassis.setMaxVelocity(velocity);
    chassis.moveDistance(distance);
    chassis.setMaxVelocity(200);
}

void Chassis::moveSide(char side, double rotation){
    
    if(side == 'l'){

    }
    else if(side == 'r'){
        
    }
}
