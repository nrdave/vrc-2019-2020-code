#include "main.h"

Arm::Arm(): leftArmMotor(ARM_LMOTOR_PORT), rightArmMotor(ARM_RMOTOR_PORT){
    okapi::Motor leftArmMotor(ARM_LMOTOR_PORT, true, 
    okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);

    leftArmMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);    

    okapi::Motor rightArmMotor(ARM_RMOTOR_PORT, false, 
    okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
    
    rightArmMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
}

void Arm::driver(okapi::Controller controller) {

        if(controller.getDigital(okapi::ControllerDigital::X)) {
            leftArmMotor.moveAbsolute(15,100);
            rightArmMotor.moveAbsolute(15,100);            
        }
        if(controller.getDigital(okapi::ControllerDigital::L1)){
            leftArmMotor.moveVelocity(ARM_MOTOR_SPEED);
            rightArmMotor.moveVelocity(ARM_MOTOR_SPEED);
        }
        else if(controller.getDigital(okapi::ControllerDigital::L2)){
            leftArmMotor.moveVelocity(-ARM_MOTOR_SPEED);
            rightArmMotor.moveVelocity(-ARM_MOTOR_SPEED);
        }
        else{
            leftArmMotor.moveVelocity(0);
            rightArmMotor.moveVelocity(0);
        }
}

void Arm::moveTo(double input){

    //constraining the value so that the arm doesnt go too far
    if(input > 180){
        input = 180;
    }
    else if(input < 0){
        input = 0;
    }
    leftArmMotor.moveAbsolute(input, 100);
    //rightArmMotor.moveAbsolute(input, 100);
}