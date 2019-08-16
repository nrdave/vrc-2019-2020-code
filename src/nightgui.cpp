#include "main.h"

lv_obj_t * autoDescription;

nightGUI::nightGUI(){
    tabview = lv_tabview_create(lv_scr_act(), NULL);
    lv_obj_align(tabview, NULL, LV_ALIGN_IN_TOP_MID, 0, 10);

    tabAuton = lv_tabview_add_tab(tabview, "Auton Selection");
    tabDebug = lv_tabview_add_tab(tabview, "Debug Menu");

    guiHeader = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(guiHeader, "nightGUI v0.1.0");
    lv_obj_align(guiHeader, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);

}