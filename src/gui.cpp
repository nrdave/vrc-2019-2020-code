#include "main.h"

lv_obj_t * autonLabel;
GUI::GUI(){
    scr = lv_obj_create(NULL, NULL);
    lv_scr_load(scr);

    tabview = lv_tabview_create(scr, NULL);
    tabMain = lv_tabview_add_tab(tabview, "Home");
    //tabDebug = lv_tabview_add_tab(tabview, "Debug Menu");
    tabAuton = lv_tabview_add_tab(tabview, "Auton Menu");


    autonLabel = lv_label_create(tabAuton, NULL);
    lv_obj_align(autonLabel, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);

    autonContainer = lv_cont_create(tabAuton, NULL);
    lv_obj_align(autonContainer, NULL, LV_ALIGN_IN_TOP_MID, 0,0);

    static const char * autonMap[] = {"Red Front", "Red Back", "\n", "Blue Front", "Blue Back", ""};
    autonBtnMatrix = lv_btnm_create(autonContainer, NULL);
    lv_btnm_set_map(autonBtnMatrix, autonMap);
    lv_btnm_set_action(autonBtnMatrix, updateAutonID);
}

lv_res_t GUI::updateAutonID(lv_obj_t * btnm, const char * txt){
    if(txt == "Red Front") autonID = AUTON_REDFRONT;
    else if(txt == "Red Back") autonID = AUTON_REDBACK;
    else if(txt == "Blue Front") autonID = AUTON_BLUEFRONT;
    else if(txt == "Blue Back") autonID = AUTON_BLUEBACK;
    else autonID = AUTON_NONE;
    updateAutonDisplay();
    return LV_RES_OK;
}

static void updateAutonDisplay(){
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
    case AUTON_NONE:
        lv_label_set_text(autonLabel, "No Auton");
        break;  
    default:
        lv_label_set_text(autonLabel, "No Auton");
        break;
    }
}