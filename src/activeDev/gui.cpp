#include "main.h"
//declaring objects that need to be accessed by more than just the constructor
lv_obj_t * scr;
lv_obj_t * scrAuton;
lv_obj_t * autonLabel;

LV_IMG_DECLARE(background);

GUI::GUI(){
    scr = lv_obj_create(NULL, NULL);
    scrAuton = lv_obj_create(NULL, NULL);
    lv_scr_load(scr);

    backgroundIMG = lv_img_create(scr, NULL);
    lv_img_set_src(backgroundIMG ,&background);
    lv_obj_align(backgroundIMG, NULL, LV_ALIGN_IN_TOP_LEFT,0,0);

    goToAuton = lv_btn_create(scr, NULL);
    lv_btn_set_action(goToAuton, LV_BTN_ACTION_CLICK, goToAutonDisplay);
    lv_obj_set_size(goToAuton, 100, 50);
    lv_obj_align(goToAuton, NULL, LV_ALIGN_IN_LEFT_MID, 20, 0);

    gtAutoLabel = lv_label_create(goToAuton, NULL);
    lv_label_set_text(gtAutoLabel, "Auton\nMenu");
    lv_obj_align(gtAutoLabel, NULL, LV_ALIGN_CENTER, 0 ,0);

    returnAuton = lv_btn_create(scrAuton, NULL);
    lv_btn_set_action(returnAuton, LV_BTN_ACTION_CLICK, returnToMain);
    lv_obj_align(returnAuton, NULL, LV_ALIGN_IN_LEFT_MID, 20,0);

    rAutoLabel = lv_label_create(returnAuton, NULL);
    lv_label_set_text(rAutoLabel, "Main Menu");
    lv_obj_align(rAutoLabel, NULL, LV_ALIGN_CENTER, 0 ,0);

    autonLabel = lv_label_create(scrAuton, NULL);
    lv_obj_align(autonLabel, NULL, LV_ALIGN_IN_TOP_LEFT, 10, 10);

    static const char * autonMap[] = {"Red Front", "Red Back", "Test", "\n", "Blue Front", "Blue Back", "Basic", "\n", "None",""};
    autonBtnMatrix = lv_btnm_create(scrAuton, NULL);
    lv_btnm_set_map(autonBtnMatrix, autonMap);
    lv_btnm_set_action(autonBtnMatrix, updateAutonID);
    lv_obj_align(autonBtnMatrix, NULL, LV_ALIGN_IN_TOP_MID, 35, 20);
    lv_obj_set_size(autonBtnMatrix, 300, 200);
}

lv_res_t GUI::updateAutonID(lv_obj_t * btnm, const char * txt){
    if(txt == "Red Front") autonID = AUTON_REDFRONT;
    else if(txt == "Red Back") autonID = AUTON_REDBACK;
    else if(txt == "Blue Front") autonID = AUTON_BLUEFRONT;
    else if(txt == "Blue Back") autonID = AUTON_BLUEBACK;
    else if(txt == "Test") autonID = AUTON_TEST;
    else if(txt == "Basic") autonID = AUTON_SIMPLE;
    else if(txt == "None") autonID = AUTON_NONE;
    else autonID = AUTON_NONE;
    updateAutonDisplay();
    return LV_RES_OK;
}

void GUI::updateAutonDisplay(){
    switch (autonID)
    {
    case AUTON_BLUEBACK:
        lv_label_set_text(autonLabel, "Blue Back");
        break;
    case AUTON_REDBACK:
        lv_label_set_text(autonLabel, "Red Back");
        break;    
    case AUTON_BLUEFRONT:
        lv_label_set_text(autonLabel, "Blue Front");
        break;    
    case AUTON_REDFRONT:
        lv_label_set_text(autonLabel, "Red Front");
        break;    
    case AUTON_TEST:
        lv_label_set_text(autonLabel, "Test");
        break;     
    case AUTON_NONE:
        lv_label_set_text(autonLabel, "No Auton");
        break;      
    case AUTON_SIMPLE:
        lv_label_set_text(autonLabel, "1 point");
        break;  
    default:
        lv_label_set_text(autonLabel, "No Auton");
        break;
    }
}

lv_res_t GUI::goToAutonDisplay(lv_obj_t * btn){
    lv_scr_load(scrAuton);
    return LV_RES_OK;
}
lv_res_t GUI::returnToMain(lv_obj_t * btn){
    lv_scr_load(scr);
    return LV_RES_OK;
}