#include "ui.h"
#include "ui_contacts.h"

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

  ui_listContactDetailsOptions = lv_list_create(ui_panelContactDetails);
  lv_obj_set_width(ui_listContactDetailsOptions, 239);
  lv_obj_set_height(ui_listContactDetailsOptions, 275);
  lv_obj_set_x(ui_listContactDetailsOptions, 25);
  lv_obj_set_y(ui_listContactDetailsOptions, 120);
  lv_obj_set_align(ui_listContactDetailsOptions, LV_ALIGN_CENTER);
  lv_obj_set_style_radius(ui_listContactDetailsOptions, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_listContactDetailsOptions, lv_color_hex(0xFFFFFF),
                            LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_listContactDetailsOptions, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_listContactDetailsOptions, lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_listContactDetailsOptions, 255,
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(ui_listContactDetailsOptions, 0,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_listContactDetailsOptions, LV_BORDER_SIDE_NONE,
                               LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_center(ui_listContactDetailsOptions);
  contact_details_set_options_list(ui_listContactDetailsOptions);

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