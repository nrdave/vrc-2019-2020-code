#include "main.h"

Tray::Tray(): trayMotor(TRAY_MOTOR_PORT){
    okapi::Motor trayMotor(TRAY_MOTOR_PORT);

    extended = false;

    pressed = false;
};

void Tray::driver(okapi::Controller controller){
    if(controller.getDigital(okapi::ControllerDigital::R1)){
        flipperMotor
    }
}