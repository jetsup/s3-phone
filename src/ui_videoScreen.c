#include "ui.h"

void ui_videoScreen_screen_init(void) {
  ui_videoScreen = lv_obj_create(NULL);
  lv_obj_remove_flag(ui_videoScreen, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_panelVideoMain = lv_obj_create(ui_videoScreen);
  lv_obj_set_width(ui_panelVideoMain, 240);
  lv_obj_set_height(ui_panelVideoMain, 320);
  lv_obj_remove_flag(ui_panelVideoMain, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_image_src(ui_panelVideoMain, screenWallpaperImg,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_image_opa(ui_panelVideoMain, 100,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_panelVideoMain, lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_panelVideoMain, 0,
                              LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_add_bottom_bar(ui_panelVideoMain, 0xFFFFFF, 10);
}
