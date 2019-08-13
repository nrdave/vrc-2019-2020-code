#include "main.h"

Tray::Tray(): trayMotor(TRAY_MOTOR_PORT){
    okapi::Motor trayMotor(TRAY_MOTOR_PORT);

    extended = false;
};

void Tray::driver(okapi::Controller controller){
    if(controller.getDigital(okapi::ControllerDigital::R1)){
        if(extended == false){
        trayMotor.moveRelative(180,120);
        extended == true;
        }
    }
    if(controller.getDigital(okapi::ControllerDigital::R2)){
        if(extended == true){
        trayMotor.moveRelative(-180,120);
        extended == false;
        }
    }
}