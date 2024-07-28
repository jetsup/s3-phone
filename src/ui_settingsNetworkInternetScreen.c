#include "ui.h"

char *networkOptions[] = {
    "WiFi", "GPRS",
    // other networks such as nrf later
};

void ui_settingsNetworkInternetScreen_screen_init(void) {
  ui_settingsNetworkInternetScreen = lv_obj_create(NULL);
  lv_obj_remove_flag(ui_settingsNetworkInternetScreen,
                     LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  int yOffset = UI_ALIGN_TOP_LEFT_Y_OFFSET;

  ui_panelSettingsNetworkInternet =
      lv_obj_create(ui_settingsNetworkInternetScreen);
  lv_obj_set_width(ui_panelSettingsNetworkInternet, 240);
  lv_obj_set_height(ui_panelSettingsNetworkInternet, 320);
  lv_obj_remove_flag(ui_panelSettingsNetworkInternet,
                     LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_image_src(ui_panelSettingsNetworkInternet,
                                screenWallpaperImg,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_image_opa(ui_panelSettingsNetworkInternet, 100,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_panelSettingsNetworkInternet,
                                lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_panelSettingsNetworkInternet, 0,
                              LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *lblNetworking = lv_label_create(ui_panelSettingsNetworkInternet);
  lv_obj_set_align(lblNetworking, LV_ALIGN_TOP_LEFT);
  lv_obj_set_y(lblNetworking, yOffset);
  lv_label_set_text(lblNetworking, "Network and Internet");
  lv_obj_set_align(lblNetworking, LV_ALIGN_TOP_MID);
  lv_obj_set_style_text_font(lblNetworking, systemFontLarge,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  yOffset += 25;

  // list for various network related options
  lv_obj_t *listNetworkOptions =
      lv_list_create(ui_panelSettingsNetworkInternet);
  lv_obj_set_width(listNetworkOptions, 240);
  lv_obj_set_height(listNetworkOptions, 275);
  lv_obj_set_x(listNetworkOptions, 0);
  lv_obj_set_y(listNetworkOptions, yOffset);
  lv_obj_set_align(listNetworkOptions, LV_ALIGN_TOP_LEFT);
  lv_obj_set_style_radius(listNetworkOptions, 0,
                          LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(listNetworkOptions, 0,
                          LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(listNetworkOptions, lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(listNetworkOptions, 255,
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(listNetworkOptions, 0,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(listNetworkOptions, LV_BORDER_SIDE_NONE,
                               LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_center(listNetworkOptions);

  int arrSize = sizeof(networkOptions) / sizeof(networkOptions[0]);
  lv_utils_populate_list_options(listNetworkOptions, networkOptions, arrSize,
                                 ui_event_list_button_cb, LV_EVENT_CLICKED,
                                 "network option");

  ui_add_bottom_bar(ui_panelSettingsNetworkInternet, 0xFFFFFF, 10);
}
