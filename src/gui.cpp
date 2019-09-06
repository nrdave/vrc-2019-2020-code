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
    lv_btn_set_action(goToAuton, LV_BTN_ACTION_CLICK, changeScreen(scrAuton));
    
    autonReturn = lv_btn_create(scrAuton, NULL);
    returnAutonLabel = lv_label_create(autonReturn, NULL);
    lv_label_set_text(returnAutonLabel, "Return");
    lv_obj_align(autonReturn, NULL, LV_ALIGN_IN_TOP_LEFT, 0,0);
    lv_btn_set_action(autonReturn, LV_BTN_ACTION_CLICK, changeScreen(scrMain));
}

lv_action_t GUI::changeScreen(lv_obj_t * scr){
    lv_scr_load(scr);
}