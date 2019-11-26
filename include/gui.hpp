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

        lv_obj_t * goToAuton;

        lv_obj_t * gtAutoLabel;

        lv_obj_t * returnAuton;

        lv_obj_t * rAutoLabel;

        lv_obj_t * autonBtnMatrix;

        //lv_obj_t * debugBtnMatrix;

        static const char * autonMap[];
    

        //const char * debugMap[];
    public:

    //The constructor for the GUI
        GUI();

        static lv_res_t updateAutonID(lv_obj_t * btnm, const char * text);

        static void updateAutonDisplay();

        static lv_res_t goToAutonDisplay(lv_obj_t * btn);

        static lv_res_t returnToMain(lv_obj_t * btn);
};