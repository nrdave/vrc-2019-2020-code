#include "main.h"

//initializing objects
Chassis chassis;
Tray tray;
okapi::Controller controller;
//GUI gui;
int autonIdentifier;


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	lv_obj_t * test = lv_btn_create(lv_scr_act(), NULL);
	lv_obj_align(test, NULL, LV_ALIGN_CENTER, 0, 0);
	Chassis chassis = Chassis();
	Tray tray = Tray();
	//GUI gui = GUI();

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
