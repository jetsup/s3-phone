// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 9.1.0
// Project name: s3-phone

#include "ui.h"

void ui_settingsThemesScreen_screen_init(void) {
  ui_settingsThemesScreen = lv_obj_create(NULL);
  lv_obj_remove_flag(ui_settingsThemesScreen,
                     LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_panelSettingsTheme = lv_obj_create(ui_settingsThemesScreen);
  lv_obj_set_width(ui_panelSettingsTheme, 240);
  lv_obj_set_height(ui_panelSettingsTheme, 320);
  lv_obj_remove_flag(ui_panelSettingsTheme, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_image_src(ui_panelSettingsTheme, &ui_img_bg1_png,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_image_opa(ui_panelSettingsTheme, 100,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_panelSettingsTheme, lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_panelSettingsTheme, 0,
                              LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_add_bottom_bar(ui_panelSettingsTheme, 0xFFFFFF, 10);
}