#include "ui.h"

void ui_contactDetailsScreen_screen_init(void) {
  ui_contactDetailsScreen = lv_obj_create(NULL);
  lv_obj_remove_flag(ui_contactDetailsScreen,
                     LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_panelContactDetails = lv_obj_create(ui_contactDetailsScreen);
  lv_obj_set_width(ui_panelContactDetails, 239);
  lv_obj_set_height(ui_panelContactDetails, 319);
  lv_obj_set_align(ui_panelContactDetails, LV_ALIGN_CENTER);
  lv_obj_remove_flag(ui_panelContactDetails, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_lblContactDetailsTitle = lv_label_create(ui_panelContactDetails);
  lv_obj_set_width(ui_lblContactDetailsTitle, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblContactDetailsTitle, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_x(ui_lblContactDetailsTitle, 0);
  lv_obj_set_y(ui_lblContactDetailsTitle, -145);
  lv_obj_set_align(ui_lblContactDetailsTitle, LV_ALIGN_CENTER);
  lv_label_set_text(ui_lblContactDetailsTitle, (const char*)contactName);

  ui_lblContactDetailsBack = lv_label_create(ui_panelContactDetails);
  lv_obj_set_width(ui_lblContactDetailsBack, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblContactDetailsBack, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_x(ui_lblContactDetailsBack, 95);
  lv_obj_set_y(ui_lblContactDetailsBack, 145);
  lv_obj_set_align(ui_lblContactDetailsBack, LV_ALIGN_CENTER);
  lv_label_set_text(ui_lblContactDetailsBack, "Back");
  lv_obj_add_flag(ui_lblContactDetailsBack, LV_OBJ_FLAG_CLICKABLE);  /// Flags


  lv_obj_add_event_cb(ui_lblContactDetailsBack, ui_event_lblContactDetailsBack,
                        LV_EVENT_ALL, NULL);
}