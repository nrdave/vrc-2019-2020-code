/**
 * 
 */ 


#include "main.h"

Chassis::Chassis(): chassis(okapi::ChassisControllerFactory::create(
    {CHASSIS_MOTORPORT_LF, -CHASSIS_MOTORPORT_LB},
    {-CHASSIS_MOTORPORT_RF, CHASSIS_MOTORPORT_RB})){

        auto chassis = okapi::ChassisControllerFactory::create(
            {CHASSIS_MOTORPORT_LF, -CHASSIS_MOTORPORT_LB}, 
            {-CHASSIS_MOTORPORT_RF, CHASSIS_MOTORPORT_RB});
    }

void Chassis::driver(okapi::Controller controller) {
    double left;
    double right;
    chassis.tank(left, right);
}
