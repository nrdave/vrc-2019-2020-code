#pragma once
#include "pros/apix.h"



class GUI {
    private: 
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
        GUI();

        
};