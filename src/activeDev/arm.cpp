#include "main.h"

Arm::Arm(): armMotor(ARM_MOTOR_PORT, true, 
    okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees){
    okapi::Motor armMotor(ARM_MOTOR_PORT, true, 
    okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);

    armMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);        
}

void Arm::driver(okapi::Controller controller) {
    if(controller.getDigital(okapi::ControllerDigital::X)) {
        armMotor.moveAbsolute(15,100);
    }
        if(controller.getDigital(okapi::ControllerDigital::L1)){
            armMotor.moveVelocity(ARM_MOTOR_SPEED);
        }
        else if(controller.getDigital(okapi::ControllerDigital::L2)){
            armMotor.moveVelocity(-ARM_MOTOR_SPEED);
        }
        else{
            armMotor.moveVelocity(0);
        }
    
}

void Arm::moveTo(double input){
    //making sure the arm doesn't move more than 180 degrees
    if(input < 370){
        //Accounting for the arm gear ratio
        input *= 5;
        armMotor.moveAbsolute(input, 100);
    }
}