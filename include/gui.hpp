#pragma once
#include "main.h"



class GUI {
    private: 

        lv_obj_t * scrMain;

        lv_obj_t * scrAuton;

        lv_obj_t * scrDebug;

        lv_obj_t * goToAuton;

        lv_obj_t * autonBtnLabel;

        lv_obj_t * goToDebug;

        lv_obj_t * autonReturn;

        lv_obj_t * debugReturn;
        
    public:
        GUI();
};