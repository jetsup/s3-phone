#include "ui.h"

void ui_settingsNetworkInternetWiFiScreen_screen_init(void) {
  wifiScreenVisible = true;

  ui_settingsNetworkInternetWiFiScreen = lv_obj_create(NULL);
  lv_obj_remove_flag(ui_settingsNetworkInternetWiFiScreen,
                     LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  int yOffset = UI_ALIGN_TOP_LEFT_Y_OFFSET;

  ui_panelSettingsNetworkInternetWiFi =
      lv_obj_create(ui_settingsNetworkInternetWiFiScreen);
  lv_obj_set_width(ui_panelSettingsNetworkInternetWiFi, 240);
  lv_obj_set_height(ui_panelSettingsNetworkInternetWiFi, 320);
  lv_obj_remove_flag(ui_panelSettingsNetworkInternetWiFi,
                     LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_image_src(ui_panelSettingsNetworkInternetWiFi,
                                screenWallpaperImg,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_image_opa(ui_panelSettingsNetworkInternetWiFi, 100,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_panelSettingsNetworkInternetWiFi,
                                lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_panelSettingsNetworkInternetWiFi, 0,
                              LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *lblNetworking =
      lv_label_create(ui_panelSettingsNetworkInternetWiFi);
  lv_obj_set_y(lblNetworking, yOffset);
  lv_label_set_text(lblNetworking, "WiFi Settings");
  lv_obj_set_align(lblNetworking, LV_ALIGN_TOP_MID);
  lv_obj_set_style_text_font(lblNetworking, systemFontLarge,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  yOffset += 25;

  lv_obj_t *lblNetwork = lv_label_create(ui_panelSettingsNetworkInternetWiFi);
  lv_obj_set_align(lblNetwork, LV_ALIGN_TOP_LEFT);
  lv_obj_set_y(lblNetwork, yOffset);
  lv_obj_set_x(lblNetwork, UI_ALIGN_TOP_LEFT_X_OFFSET + 5);
  lv_label_set_text(lblNetwork, "WiFi");
  lv_obj_set_style_text_font(lblNetwork, systemFontMedium,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *switchNetwork =
      lv_switch_create(ui_panelSettingsNetworkInternetWiFi);
  lv_obj_set_height(switchNetwork, 20);
  lv_obj_align_to(switchNetwork, ui_panelSettingsConnectivityBLE,
                  LV_ALIGN_TOP_RIGHT,
                  (lv_obj_get_width(switchNetwork) * -1) + 10, yOffset);
  if (wifiEnabled) {
    lv_obj_add_state(switchNetwork, LV_STATE_CHECKED);
  }
  lv_obj_add_event_cb(switchNetwork, ui_event_switch_cb, LV_EVENT_VALUE_CHANGED,
                      "wifi switch");

  yOffset += 25;

  ui_lblWiFiScanning = lv_label_create(ui_panelSettingsNetworkInternetWiFi);
  lv_obj_set_y(ui_lblWiFiScanning, yOffset);
  lv_obj_set_x(ui_lblWiFiScanning, 5);
  if (wifiEnabled) {
    lv_label_set_text(ui_lblWiFiScanning, "Scanning...");
  } else {
    lv_label_set_text(ui_lblWiFiScanning, "WiFi Off");
  }
  lv_obj_set_align(ui_lblWiFiScanning, LV_ALIGN_TOP_LEFT);
  lv_obj_set_style_text_font(ui_lblWiFiScanning, systemFontMedium,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_spinnerWiFiScanning =
      lv_spinner_create(ui_panelSettingsNetworkInternetWiFi);
  lv_obj_set_width(ui_spinnerWiFiScanning, 10);
  lv_obj_set_height(ui_spinnerWiFiScanning, 10);
  if (!wifiEnabled) {
    lv_obj_add_flag(ui_spinnerWiFiScanning, LV_OBJ_FLAG_HIDDEN);
  }
  lv_obj_align_to(ui_spinnerWiFiScanning, ui_panelSettingsNetworkInternetWiFi,
                  LV_ALIGN_TOP_RIGHT,
                  (lv_obj_get_width(ui_spinnerWiFiScanning) * -1) + 10,
                  yOffset);
  lv_spinner_set_anim_params(ui_spinnerWiFiScanning, 1000, 270);

  yOffset += 20;

  // list
  ui_listWiFiFoundDevices = lv_list_create(ui_panelSettingsNetworkInternetWiFi);
  lv_obj_set_width(ui_listWiFiFoundDevices, 240);
  lv_obj_set_height(ui_listWiFiFoundDevices, 265);
  lv_obj_set_x(ui_listWiFiFoundDevices, 0);
  lv_obj_set_y(ui_listWiFiFoundDevices, yOffset);
  lv_obj_set_align(ui_listWiFiFoundDevices, LV_ALIGN_TOP_LEFT);
  lv_obj_set_style_radius(ui_listWiFiFoundDevices, 0,
                          LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_listWiFiFoundDevices, 0,
                          LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_listWiFiFoundDevices, lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_listWiFiFoundDevices, 255,
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(ui_listWiFiFoundDevices, 0,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_listWiFiFoundDevices, LV_BORDER_SIDE_NONE,
                               LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_center(ui_listWiFiFoundDevices);
  if (!wifiEnabled) {
    lv_obj_add_flag(ui_listWiFiFoundDevices, LV_OBJ_FLAG_HIDDEN);
  }

  ui_add_bottom_bar(ui_panelSettingsNetworkInternetWiFi, 0xFFFFFF, 10);
}
