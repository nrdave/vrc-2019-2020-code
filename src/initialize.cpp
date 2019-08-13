#include "main.h"

//initializing objects
Chassis chassis;
Tray tray;
okapi::Controller controller;



//creating an lvgl image
LV_IMG_DECLARE(laser_jude);
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

	Chassis chassis = Chassis();

	/**
	 * 
	 * lvgl object declaration to get an object to appear on the v5 brain
	 * 
	 */ 
	/**
	lv_obj_t * scr = lv_obj_create(NULL, NULL);
	lv_scr_load(scr);  

	lv_obj_t * judeIMG = lv_img_create(lv_scr_act(), NULL);
	lv_img_set_src(judeIMG, &laser_jude);

	lv_obj_align(judeIMG, NULL,LV_ALIGN_IN_TOP_LEFT, 0,0);
	*/
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
