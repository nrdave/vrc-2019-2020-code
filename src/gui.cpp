#include "main.h"


GUI::GUI(){
    scr = lv_obj_create(NULL, NULL);
    lv_scr_load(scr);

    tabview = lv_tabview_create(scr, NULL);
    tabMain = lv_tabview_add_tab(tabview, "Home");
    //tabDebug = lv_tabview_add_tab(tabview, "Debug Menu");
    tabAuton = lv_tabview_add_tab(tabview, "Auton Menu");

    autonContainer = lv_cont_create(tabAuton, NULL);
    lv_obj_align(autonContainer, NULL, LV_ALIGN_IN_TOP_MID, 0,0);

    const char * autonMap[] = {"Red Front", "Red Back", "\n", "Blue Front", "Blue Back", ""};
    autonBtnMatrix = lv_btnm_create(autonContainer, NULL);
    lv_btnm_set_map(autonBtnMatrix, autonMap);
}
