#include "ui.h"
#include "ui_contacts.h"
#include "ui_utils.h"

void ui_contactOptionsScreen_screen_init(void) {
  ui_contactOptionsScreen = lv_obj_create(NULL);
  lv_obj_remove_flag(ui_contactOptionsScreen,
                     LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_panelContactDetails = lv_obj_create(ui_contactOptionsScreen);
  lv_obj_set_width(ui_panelContactDetails, 240);
  lv_obj_set_height(ui_panelContactDetails, 320);
  lv_obj_set_align(ui_panelContactDetails, LV_ALIGN_TOP_LEFT);
  lv_obj_remove_flag(ui_panelContactDetails, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_image_src(ui_panelContactDetails, screenWallpaperImg,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_image_opa(ui_panelContactDetails, 100,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_panelContactDetails, lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_panelContactDetails, 0,
                              LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_lblContactDetailsTitle = lv_label_create(ui_panelContactDetails);
  lv_obj_set_width(ui_lblContactDetailsTitle, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblContactDetailsTitle, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_x(ui_lblContactDetailsTitle, 0);
  lv_obj_set_y(ui_lblContactDetailsTitle, UI_ALIGN_TOP_LEFT_Y_OFFSET);
  lv_obj_set_align(ui_lblContactDetailsTitle, LV_ALIGN_TOP_MID);
  lv_label_set_text(ui_lblContactDetailsTitle, (const char*)contactName);
  lv_obj_set_style_text_opa(ui_lblContactDetailsTitle, 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_lblContactDetailsTitle, &lv_font_montserrat_14,
                             LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_letter_space(ui_lblContactDetailsTitle, 2,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_line_space(ui_lblContactDetailsTitle, 2,
                                   LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_align(ui_lblContactDetailsTitle, LV_TEXT_ALIGN_CENTER,
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_decor(ui_lblContactDetailsTitle, LV_TEXT_DECOR_NONE,
                              LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_listContactDetailsOptions = lv_list_create(ui_panelContactDetails);
  lv_obj_set_width(ui_listContactDetailsOptions, 240);
  lv_obj_set_height(ui_listContactDetailsOptions, 275);
  lv_obj_set_x(ui_listContactDetailsOptions, 0);
  lv_obj_set_y(ui_listContactDetailsOptions, 5);
  lv_obj_set_align(ui_listContactDetailsOptions, LV_ALIGN_TOP_LEFT);
  lv_obj_set_style_radius(ui_listContactDetailsOptions, 0,
                          LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_listContactDetailsOptions, 0,
                          LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_listContactDetailsOptions,
                                lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_listContactDetailsOptions, 255,
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(ui_listContactDetailsOptions, 0,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_listContactDetailsOptions,
                               LV_BORDER_SIDE_NONE,
                               LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_center(ui_listContactDetailsOptions);
  contact_details_set_options_list(ui_listContactDetailsOptions);

  ui_add_bottom_bar(ui_panelContactDetails, 0xFFFFFF, 10);
}
