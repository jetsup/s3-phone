#include "ui.h"

void ui_settingsThemeWallpaperScreen_screen_init(void) {
  ui_settingsThemeWallpaperScreen = lv_obj_create(NULL);
  lv_obj_remove_flag(ui_settingsThemeWallpaperScreen,
                     LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  int yOffset = UI_ALIGN_TOP_LEFT_Y_OFFSET;

  ui_panelSettingsThemeWallpaper =
      lv_obj_create(ui_settingsThemeWallpaperScreen);
  lv_obj_set_width(ui_panelSettingsThemeWallpaper, 240);
  lv_obj_set_height(ui_panelSettingsThemeWallpaper, 320);
  lv_obj_remove_flag(ui_panelSettingsThemeWallpaper,
                     LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_image_src(ui_panelSettingsThemeWallpaper,
                                screenWallpaperImg,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_image_opa(ui_panelSettingsThemeWallpaper, 100,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_panelSettingsThemeWallpaper,
                                lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_panelSettingsThemeWallpaper, 0,
                              LV_PART_MAIN | LV_STATE_DEFAULT);

  // wall paper select
  lv_obj_t *lblWallpaper = lv_label_create(ui_panelSettingsThemeWallpaper);
  lv_obj_set_align(lblWallpaper, LV_ALIGN_TOP_MID);
  lv_obj_set_y(lblWallpaper, yOffset);
  lv_label_set_text(lblWallpaper, "Wallpaper Select");
  lv_obj_set_style_text_font(lblWallpaper, &lv_font_montserrat_18,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  yOffset += 25;

  ui_imageViewWallpaper = lv_image_create(ui_panelSettingsThemeWallpaper);
  lv_obj_set_width(ui_imageViewWallpaper, 200);
  lv_obj_set_height(ui_imageViewWallpaper, 260);
  lv_obj_set_y(ui_imageViewWallpaper, yOffset);
  lv_image_set_src(ui_imageViewWallpaper,
                   lv_utils_getImage(clickedWallpaperImage));
  lv_obj_set_align(ui_imageViewWallpaper, LV_ALIGN_TOP_MID);

  //
  lv_obj_t *btnApply = lv_button_create(ui_panelSettingsThemeWallpaper);
  lv_obj_add_event_cb(btnApply, ui_event_button_cb, LV_EVENT_CLICKED,
                      "wallpaper apply");
  lv_obj_set_align(btnApply, LV_ALIGN_BOTTOM_RIGHT);
  lv_obj_set_x(btnApply, -10);
  lv_obj_set_y(btnApply, -25);
  lv_color_t btnColor = {.red = 50, .green = 255, .blue = 50};
  lv_obj_set_style_bg_color(btnApply, btnColor, NULL);
  lv_obj_t *lblApply = lv_label_create(btnApply);
  lv_label_set_text(lblApply, "Apply");
  lv_obj_set_style_text_font(lblApply, &lv_font_montserrat_10, 0);
  lv_obj_set_style_text_color(lblApply, lv_color_hex(0xFFFFFF),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(lblApply, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_add_bottom_bar(ui_panelCalendarMain, 0xFFFFFF, 10);
  //

  ui_add_bottom_bar(ui_panelSettingsThemeWallpaper, 0xFFFFFF, 10);
}
