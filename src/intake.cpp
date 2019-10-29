#include "main.h"

Intake::Intake(): leftIntakeMotor(INTAKE_LMOTOR_PORT), rightIntakeMotor(INTAKE_RMOTOR_PORT){
    okapi::Motor leftIntakeMotor(INTAKE_LMOTOR_PORT, true,
    okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
    okapi::Motor rightIntakeMotor(INTAKE_RMOTOR_PORT, false, 
    okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);    
}

void Intake::driver(okapi::Controller controller){
    if(controller.getDigital(okapi::ControllerDigital::up)){
        rollIn();
    }
    else if(controller.getDigital(okapi::ControllerDigital::down)){
        rollOut();
    }
    else{
        stop();
    }  
}

void Intake::rollIn(){
    rightIntakeMotor.moveVelocity(INTAKE_VELOCITY);
    leftIntakeMotor.moveVelocity(INTAKE_VELOCITY);
}

void Intake::rollOut(){
    rightIntakeMotor.moveVelocity(-INTAKE_VELOCITY);
    leftIntakeMotor.moveVelocity(-INTAKE_VELOCITY);
}

void Intake::stop(){
    rightIntakeMotor.moveVelocity(0);
    leftIntakeMotor.moveVelocity(0);
}