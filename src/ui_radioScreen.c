// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 9.1.0
// Project name: s3-phone

#include "ui.h"

void ui_radioScreen_screen_init(void) {
  ui_radioScreen = lv_obj_create(NULL);
  lv_obj_remove_flag(ui_radioScreen, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_panelRadioMain = lv_obj_create(ui_radioScreen);
  lv_obj_set_width(ui_panelRadioMain, 240);
  lv_obj_set_height(ui_panelRadioMain, 320);
  lv_obj_remove_flag(ui_panelRadioMain, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_image_src(ui_panelRadioMain, &ui_img_bg1_png,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_image_opa(ui_panelRadioMain, 100,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_panelRadioMain, lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_panelRadioMain, 0,
                              LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_add_bottom_bar(ui_panelRadioMain, 0xFFFFFF, 10);
}