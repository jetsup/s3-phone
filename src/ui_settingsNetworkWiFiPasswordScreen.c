#include "ui.h"

void ui_settingsNetworkWiFiPasswordScreen_screen_init(void) {
  ui_settingsNetworkWiFiPasswordScreen = lv_obj_create(NULL);
  lv_obj_remove_flag(ui_settingsNetworkWiFiPasswordScreen,
                     LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  int yOffset = UI_ALIGN_TOP_LEFT_Y_OFFSET;

  ui_panelSettingsNetworkWiFiPassword =
      lv_obj_create(ui_settingsNetworkWiFiPasswordScreen);
  lv_obj_set_width(ui_panelSettingsNetworkWiFiPassword, 240);
  lv_obj_set_height(ui_panelSettingsNetworkWiFiPassword, 320);
  lv_obj_remove_flag(ui_panelSettingsNetworkWiFiPassword,
                     LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_image_src(ui_panelSettingsNetworkWiFiPassword,
                                screenWallpaperImg,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_image_opa(ui_panelSettingsNetworkWiFiPassword, 100,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_panelSettingsNetworkWiFiPassword,
                                lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_panelSettingsNetworkWiFiPassword, 0,
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_center(ui_panelSettingsNetworkWiFiPassword);

  lv_obj_t *lblNetworking =
      lv_label_create(ui_panelSettingsNetworkWiFiPassword);
  lv_obj_set_y(lblNetworking, yOffset);
  lv_label_set_text(lblNetworking, "WiFi Auth");
  lv_obj_set_align(lblNetworking, LV_ALIGN_TOP_MID);
  lv_obj_set_style_text_font(lblNetworking, systemFontLarge,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  yOffset += 25;

  lv_obj_t *lblNetwork = lv_label_create(ui_panelSettingsNetworkWiFiPassword);
  lv_obj_set_align(lblNetwork, LV_ALIGN_TOP_LEFT);
  lv_obj_set_y(lblNetwork, yOffset);
  lv_obj_set_x(lblNetwork, UI_ALIGN_TOP_LEFT_X_OFFSET + 5);
  lv_label_set_text(lblNetwork, wifiName);
  lv_obj_set_style_text_font(lblNetwork, systemFontMedium,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  yOffset += 25;

  ui_txtWiFiPassword = lv_textarea_create(ui_panelSettingsNetworkWiFiPassword);
  lv_obj_set_align(ui_txtWiFiPassword, LV_ALIGN_TOP_MID);
  lv_obj_set_width(ui_txtWiFiPassword, 230);
  lv_obj_set_height(ui_txtWiFiPassword, 35);
  lv_obj_set_y(ui_txtWiFiPassword, yOffset);
  lv_obj_add_event_cb(ui_txtWiFiPassword, ui_event_textarea_cb, LV_EVENT_ALL,
                      "full");
  lv_textarea_set_one_line(ui_txtWiFiPassword, true);
  lv_textarea_set_password_mode(ui_txtWiFiPassword, true);
  lv_textarea_set_placeholder_text(ui_txtWiFiPassword, "WiFi Password");
  lv_textarea_set_one_line(ui_txtWiFiPassword, true);

  yOffset += 40;

  // connect button
  lv_color_t btnColor = {66, 172, 42};
  lv_obj_t *btnWiFiConnect =
      lv_button_create(ui_panelSettingsNetworkWiFiPassword);
  lv_obj_set_y(btnWiFiConnect, yOffset);
  lv_obj_set_align(btnWiFiConnect, LV_ALIGN_TOP_MID);
  lv_obj_set_width(btnWiFiConnect, 230);
  lv_obj_set_height(btnWiFiConnect, 35);
  lv_obj_set_style_bg_color(btnWiFiConnect, btnColor, 0);
  lv_obj_add_event_cb(btnWiFiConnect, ui_event_button_cb, LV_EVENT_CLICKED,
                      "wifi connect");

  lv_obj_t *btnLabel = lv_label_create(btnWiFiConnect);
  lv_label_set_text(btnLabel, "Connect");
  lv_obj_center(btnLabel);

  ui_add_bottom_bar(ui_panelSettingsNetworkWiFiPassword, 0xFFFFFF, 10);
}
