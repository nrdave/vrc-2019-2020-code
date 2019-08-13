/**
 * This file is a collection of global objects and variables
 * These could be put in main.h, but creating a separate file
 * keeps things better organized
 */ 

#include "main.h"

// The chassis object used to control chassis motors
extern Chassis chassis;

//The tray object for moving the cube tray
extern Tray tray;

// The okapi controller object, used to get controller input
extern okapi::Controller controller;