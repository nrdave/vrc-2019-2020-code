#include "main.h"

Intake::Intake(): leftIntakeMotor(INTAKE_LMOTOR_PORT), rightIntakeMotor(INTAKE_RMOTOR_PORT){
    okapi::Motor leftIntakeMotor(INTAKE_LMOTOR_PORT, false,
    okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
    okapi::Motor rightIntakeMotor(INTAKE_RMOTOR_PORT, true, 
    okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);    
}

void Intake::driver(okapi::Controller controller){
    if(controller.getDigital(okapi::ControllerDigital::R1)){
        rollIn();
    }
    else if(controller.getDigital(okapi::ControllerDigital::R2)){
        rollOut();
    }
    else{
        stop();
    }  
}

void Intake::rollIn(){
    rightIntakeMotor.moveVelocity(INTAKE_SPEED);
    leftIntakeMotor.moveVelocity(INTAKE_SPEED);
}

void Intake::rollOut(){
    rightIntakeMotor.moveVelocity(-INTAKE_SPEED);
    leftIntakeMotor.moveVelocity(-INTAKE_SPEED);
}

void Intake::stop(){
    rightIntakeMotor.moveVelocity(0);
    leftIntakeMotor.moveVelocity(0);
}