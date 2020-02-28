#include "main.h"

//initializing objects
Chassis chassis;
Tray tray;
okapi::Controller controller;
GUI gui;
Arm arm;
Intake intake;
int autonID;


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	GUI gui = GUI();
	Chassis chassis = Chassis();
	Tray tray = Tray();
	Arm arm = Arm();
	Intake intake = Intake();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	arm.moveTo(60);
	pros::delay(1000);
	arm.moveTo(0);
	pros::delay(750);
	intake.rollIn();
	switch (autonID)
    {
    case AUTON_BLUEPZ:
		chassis.moveDistance(6 , 6, 100);
		pros::delay(250);
		chassis.turnAngle(90);
		chassis.moveDistance(6, 6, 100);
		pros::delay(500);
		intake.stop();
		chassis.turnAngle(40);
		chassis.moveDistance(3, 3, 50);
		tray.trayDown();
		pros::delay(4000);
		tray.trayUp();
		chassis.moveDistance(-4, -4, 50);        
		break;
    case AUTON_REDPZ:
		chassis.moveDistance(6 , 6, 100);
		pros::delay(250);
		chassis.turnAngle(-90);
		chassis.moveDistance(6, 6, 100);
		pros::delay(500);
		intake.stop();
		chassis.turnAngle(-40);
		chassis.moveDistance(3, 3, 50);
		tray.trayDown();
		pros::delay(4000);
		tray.trayUp();
		chassis.moveDistance(-4, -4, 50);
        break;    
    case AUTON_BLUEFRONT:
		chassis.moveDistance(14, 14, 75);
		chassis.turnAngle(-160);
		intake.stop();
		chassis.moveDistance(14, 14, 100);
		tray.trayDown();
		pros::delay(2000);
		intake.rollOut();
		chassis.moveDistance(-10,-10, 50);
		intake.stop();
		tray.trayUp();
        break;    
    case AUTON_REDFRONT:
		chassis.moveDistance(14, 14, 75);
		chassis.turnAngle(160);
		intake.stop();
		chassis.moveDistance(14, 14, 100);
		tray.trayDown();
		pros::delay(2000);
		intake.rollOut();
		chassis.moveDistance(-10,-10, 50);
		intake.stop();
		tray.trayUp();
        break;    
    case AUTON_TEST:

        break;     
	case AUTON_SIMPLE:
		chassis.moveDistance(10, 10, 100);
		pros::delay(500);
		chassis.moveDistance(-10, -10, 100);
    case AUTON_NONE:
        break;
	}
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	
	while (true) {
		arm.driver(controller);
		chassis.driver(controller);
		tray.driver(controller);
		intake.driver(controller);
		pros::delay(20);
	}
}
