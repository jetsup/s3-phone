#include "ui.h"

void ui_stkScreen_screen_init(void) {
  ui_stkScreen = lv_obj_create(NULL);
  lv_obj_remove_flag(ui_stkScreen, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_panelSTKMain = lv_obj_create(ui_stkScreen);
  lv_obj_set_width(ui_panelSTKMain, 240);
  lv_obj_set_height(ui_panelSTKMain, 320);
  lv_obj_remove_flag(ui_panelSTKMain, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_image_src(ui_panelSTKMain, &ui_img_bg1_png,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_image_opa(ui_panelSTKMain, 100,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_panelSTKMain, lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_panelSTKMain, 0,
                              LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_add_bottom_bar(ui_panelSTKMain, 0xFFFFFF, 10);
}
