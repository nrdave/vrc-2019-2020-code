#include "main.h"

Intake::Intake(): leftIntakeMotor(INTAKE_LMOTOR_PORT), rightIntakeMotor(INTAKE_RMOTOR_PORT){
    okapi::Motor leftIntakeMotor(INTAKE_LMOTOR_PORT);
    okapi::Motor rightIntakeMotor(INTAKE_RMOTOR_PORT);
    rightIntakeMotor.setReversed(true);
    
}

void Intake::driver(okapi::Controller controller){
    if(controller.getDigital(okapi::ControllerDigital::up)){
        rollIn();
    }
    else if(controller.getDigital(okapi::ControllerDigital::down)){
        rollOut();
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