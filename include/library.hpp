/**
 * This file is a collection of global objects and variables
 * These could be put in main.h, but creating a separate file
 * keeps things better organized
 */ 
#pragma once
#include "main.h"

//Auton Identifiers
#define AUTON_NONE 0
#define AUTON_REDFRONT 1
#define AUTON_BLUEFRONT 2
#define AUTON_REDBACK 3
#define AUTON_BLUEBACK 4

// The chassis object used to control chassis motors
extern Chassis chassis;

//The tray object for moving the cube tray
extern Tray tray;

// The okapi controller object, used to get controller input
extern okapi::Controller controller;

//The variable that holds the currently selected autonomous
extern int autonIdentifier;

//The gui object
extern GUI gui;

//The arm object
extern Arm arm;