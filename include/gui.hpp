#pragma once
#include "pros/apix.h"



class GUI {
    private: 

        lv_obj_t * scrMain;

        lv_obj_t * scrAuton;

        lv_obj_t * scrDebug;

        lv_obj_t * goToAuton;

        lv_obj_t * autonBtnLabel;

        lv_obj_t * goToDebug;

        lv_obj_t * debugBtnLabel;

        lv_obj_t * autonReturn;

        lv_obj_t * returnAutonLabel;    

        lv_obj_t * debugReturn;

        lv_obj_t * returnDebugLabel;
        
    public:
        GUI();

        lv_action_t changeScreen(lv_obj_t * scr);
};