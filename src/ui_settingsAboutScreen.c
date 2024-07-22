#include "ui.h"

void ui_settingsAboutScreen_screen_init(void) {
  ui_settingsAboutScreen = lv_obj_create(NULL);
  lv_obj_remove_flag(ui_settingsAboutScreen, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_panelSettingsAbout = lv_obj_create(ui_settingsAboutScreen);
  lv_obj_set_width(ui_panelSettingsAbout, 240);
  lv_obj_set_height(ui_panelSettingsAbout, 320);
  lv_obj_remove_flag(ui_panelSettingsAbout, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_image_src(ui_panelSettingsAbout, screenWallpaperImg,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_image_opa(ui_panelSettingsAbout, 100,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_panelSettingsAbout, lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_panelSettingsAbout, 0,
                              LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_add_bottom_bar(ui_panelSettingsAbout, 0xFFFFFF, 10);
}
