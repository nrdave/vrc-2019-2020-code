/**
 * The implementation of the chassis class
 * This file contains the code for the functions defined in chassis.hpp
 */ 


#include "main.h"
Chassis::Chassis(): leftBackMtr(CHASSIS_MOTORPORT_LB), leftFrontMtr(CHASSIS_MOTORPORT_LF), 
                    rightBackMtr(CHASSIS_MOTORPORT_RB), rightFrontMtr(CHASSIS_MOTORPORT_RF),
                    rightWheels({rightBackMtr, rightFrontMtr}),
                    leftWheels({leftBackMtr, leftFrontMtr})
                    {
    okapi::Motor leftBackMtr(CHASSIS_MOTORPORT_LB);

    okapi::Motor leftFrontMtr(CHASSIS_MOTORPORT_LF);

    okapi::Motor rightBackMtr(CHASSIS_MOTORPORT_RB);

    okapi::Motor rightFrontMtr(CHASSIS_MOTORPORT_RF);

    okapi::MotorGroup rightWheels({rightBackMtr, rightFrontMtr});

    okapi::MotorGroup leftWheels({leftBackMtr, leftFrontMtr});

}

void Chassis::driver(okapi::Controller controller) {
    double left;
    double right;
    left = controller.getAnalog(okapi::ControllerAnalog::leftY);
    right = controller.getAnalog(okapi::ControllerAnalog::rightY);
    leftWheels.controllerSet(left);
    rightWheels.controllerSet(right);
}
