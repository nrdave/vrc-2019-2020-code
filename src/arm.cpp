#include "main.h"

Arm::Arm(): armMotor(ARM_MOTOR_PORT){
    okapi::Motor armMotor(ARM_MOTOR_PORT, false, 
    okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
    armMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
}

void Arm::driver(okapi::Controller controller) {

    //else{

        if(controller.getDigital(okapi::ControllerDigital::L1)){
            armMotor.moveVelocity(ARM_MOTOR_VELOCITY);
        }
        else if(controller.getDigital(okapi::ControllerDigital::L2)){
            armMotor.moveVelocity(-ARM_MOTOR_VELOCITY);
        }
        else{
            armMotor.moveVelocity(0);
        }
   // }
}

void Arm::moveTo(double input){

    //constraining the value so that the arm doesnt go too far
    if(input > 180){
        input = 180;
    }
    else if(input < 0){
        input = 0;
    }
    armMotor.moveAbsolute(input, 120);
}