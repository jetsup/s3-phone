#include "ui.h"

void ui_settingsNetworkInternetGPRSScreen_screen_init(void) {
  ui_settingsNetworkInternetGPRSScreen = lv_obj_create(NULL);
  lv_obj_remove_flag(ui_settingsNetworkInternetGPRSScreen,
                     LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  int yOffset = UI_ALIGN_TOP_LEFT_Y_OFFSET;

  ui_panelSettingsNetworkInternetGPRS =
      lv_obj_create(ui_settingsNetworkInternetGPRSScreen);
  lv_obj_set_width(ui_panelSettingsNetworkInternetGPRS, 240);
  lv_obj_set_height(ui_panelSettingsNetworkInternetGPRS, 320);
  lv_obj_remove_flag(ui_panelSettingsNetworkInternetGPRS,
                     LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_image_src(ui_panelSettingsNetworkInternetGPRS,
                                screenWallpaperImg,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_image_opa(ui_panelSettingsNetworkInternetGPRS, 100,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_panelSettingsNetworkInternetGPRS,
                                lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_panelSettingsNetworkInternetGPRS, 0,
                              LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *lblNetworking =
      lv_label_create(ui_panelSettingsNetworkInternetGPRS);
  lv_obj_set_align(lblNetworking, LV_ALIGN_TOP_LEFT);
  lv_obj_set_y(lblNetworking, yOffset);
  lv_label_set_text(lblNetworking, "GPRS Broadband");
  lv_obj_set_align(lblNetworking, LV_ALIGN_TOP_MID);
  lv_obj_set_style_text_font(lblNetworking, systemFontLarge,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  yOffset += 25;

  ui_add_bottom_bar(ui_panelSettingsNetworkInternetGPRS, 0xFFFFFF, 10);
}
