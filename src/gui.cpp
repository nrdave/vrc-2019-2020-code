#include "main.h"
GUI::GUI(){

    scrMain = lv_obj_create(NULL, NULL);
    scrAuton = lv_obj_create(NULL, NULL);
    scrDebug = lv_obj_create(NULL, NULL);

    lv_scr_load(scrMain);

    goToAuton = lv_btn_create(scrMain, NULL);
    autonBtnLabel = lv_label_create(goToAuton, NULL);
    lv_label_set_text(autonBtnLabel, "Auton Menu");
    lv_obj_align(goToAuton, NULL, LV_ALIGN_CENTER, -50, 0);
    
    
}