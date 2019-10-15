#pragma once
#include "pros/apix.h"



class GUI {
    private: 
    /**
     * The LVGL objects that make up the GUI. LVGL, short for Little Video Graphics Library, is a
     * free C graphics library, which is included in the PROS API, though it isn't developed by the
     * PROS team.
     * 
     * Commented out objects are ones I don't have a use for right now, but may need
     * in the future.
     */ 
        lv_obj_t * scr;

        lv_obj_t * tabview;

        lv_obj_t * tabMain;

        lv_obj_t * tabAuton;

        //lv_obj_t * tabDebug;

        lv_obj_t * autonBtnMatrix;

        //lv_obj_t * debugBtnMatrix;

        lv_obj_t * autonContainer;

        const char * autonMap[];

        //const char * debugMap[];
    public:

    //The constructor for the GUI
        GUI();

        
};