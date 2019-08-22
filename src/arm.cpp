#include "main.h"

Arm::Arm(armMotor(ARM_MOTOR_PORT)){
    okapi::Motor armMotor(ARM_MOTOR_PORT);

}

void Arm::driver(okapi::Controller controller) {
    if(armMotor.getPosition == 0){
        armMotor.moveVelocity(0);
    }
    else{

        if(controller.getDigital(okapi::ControllerDigital::L1)){
            armMotor.moveVelocity(50);
        }
        else if(controller.getDigital(okapi::ControllerDigital::L2)){
            armMotor.moveVelocity(-50);
        }
    }
}