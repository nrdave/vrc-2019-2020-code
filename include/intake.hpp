#pragma once
#include "okapi/api.hpp"

#define INTAKE_LMOTOR_PORT 18
#define INTAKE_RMOTOR_PORT 8
#define INTAKE_VELOCITY 200

class Intake{
    private:
        okapi::Motor leftIntakeMotor;

        okapi::Motor rightIntakeMotor;

    public:
        Intake();

        void driver(okapi::Controller controller);

        void rollIn();

        void rollOut();
};