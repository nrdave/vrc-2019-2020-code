#pragma once
#include "okapi/api.hpp"

#define INTAKE_LMOTOR_PORT 2
#define INTAKE_RMOTOR_PORT 9
#define INTAKE_SPEED 200

class Intake{
    private:
    //The motor objects for the motors on the intake
        okapi::Motor leftIntakeMotor;

        okapi::Motor rightIntakeMotor;

    public:
    //The constructor for the Intake
        Intake();
    //The intake driver function. It takes the controller input from the up and down arrow buttons
        void driver(okapi::Controller controller);
    //A function that abstracts the motor commands to run the intake so that it pulls in cubes
        void rollIn();
    //Similar to rollIN, this function abstracts the pushing out of a cube
        void rollOut();
    //Function to stop the rollers, useful in autonomous
        void stop();
};