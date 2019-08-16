#pragma once
#include "main.h"



class gui {
    private: 
    /**
     * Declaring all the lvgl objects.
     * These are used for the debug menu and autonomous 
     * selection system.
     * 
     * Here I am simply declaring them as objects,
     * in gui.cpp I initialize them as a specific object
     */ 


        lv_obj_t * tabview;

        lv_obj_t * tabAuton;

        lv_obj_t * tabDebug;

        lv_obj_t * guiHeader;

        static const char * autonMap[];

        lv_obj_t * autoBtnMatrix;

        lv_obj_t * autoRunBtn;

        static const char * debugMap[];

        lv_obj_t * debugBtnMatrix;
    public:
    //the constructor for a gui, called in initialize
        gui();
    //updates the auton label displayed on the screen
        static void updateAutonDisplay();
    /* the function to get the pressed button in the auton selection map, then
     * set the text value to a variable, which determines the actual auton run
     */ 
        static lv_res_t autonSelect(lv_obj_t * btmn, const char * txt);
    /**
     * Like the autonSelect function, but instead for selecting which debug elements 
     * are opened
     */ 
        static lv_res_t debugSelect(lv_obj_t * btmn, const char * txt);
};