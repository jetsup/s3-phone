#include "ui.h"

void ui_settingsConnectivityScreen_screen_init(void) {
  ui_settingsConnectivityScreen = lv_obj_create(NULL);
  lv_obj_remove_flag(ui_settingsConnectivityScreen,
                     LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  int yOffset = UI_ALIGN_TOP_LEFT_Y_OFFSET;

  ui_panelSettingsConnectivity = lv_obj_create(ui_settingsConnectivityScreen);
  lv_obj_set_width(ui_panelSettingsConnectivity, 240);
  lv_obj_set_height(ui_panelSettingsConnectivity, 320);
  lv_obj_set_align(ui_panelSettingsConnectivity, LV_ALIGN_TOP_LEFT);
  lv_obj_remove_flag(ui_panelSettingsConnectivity,
                     LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_image_src(ui_panelSettingsConnectivity,
                                screenWallpaperImg,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_image_opa(ui_panelSettingsConnectivity, 100,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_panelSettingsConnectivity,
                                lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_panelSettingsConnectivity, 0,
                              LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *lblConnectivity = lv_label_create(ui_panelSettingsConnectivity);
  lv_obj_set_align(lblConnectivity, LV_ALIGN_TOP_LEFT);
  lv_obj_set_y(lblConnectivity, yOffset);
  lv_label_set_text(lblConnectivity, "Connectivity");
  lv_obj_set_align(lblConnectivity, LV_ALIGN_TOP_MID);
  lv_obj_set_style_text_font(lblConnectivity, systemFontLarge,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  yOffset += 25;

  // BT classic switch
  lv_obj_t *lblBluetooth = lv_label_create(ui_panelSettingsConnectivity);
  lv_obj_set_align(lblBluetooth, LV_ALIGN_TOP_LEFT);
  lv_obj_set_x(lblBluetooth, UI_ALIGN_TOP_LEFT_X_OFFSET + 5);
  lv_obj_set_y(lblBluetooth, yOffset);
  lv_label_set_text(lblBluetooth, "Bluetooth Classic");
  lv_obj_set_style_text_font(lblBluetooth, systemFontMedium,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_switchBluetooth = lv_switch_create(ui_panelSettingsConnectivity);
  lv_obj_set_height(ui_switchBluetooth, 20);
  lv_obj_align_to(
      ui_switchBluetooth, lblBluetooth, LV_ALIGN_LEFT_MID,
      240 - (UI_ALIGN_TOP_LEFT_X_OFFSET +
             lv_text_get_width("Bluetooth Classic", 10, systemFontMedium, 0) +
             lv_obj_get_width(ui_switchBluetooth)),
      0);
  if (bluetoothClassicEnabled) {
    lv_obj_add_state(ui_switchBluetooth, LV_STATE_CHECKED);
  }
  lv_obj_add_event_cb(ui_switchBluetooth, ui_event_switch_cb,
                      LV_EVENT_VALUE_CHANGED, "bt classic switch");

  yOffset += 25;

  // BLE Switch
  lblBluetooth = lv_label_create(ui_panelSettingsConnectivity);
  lv_obj_set_align(lblBluetooth, LV_ALIGN_TOP_LEFT);
  lv_obj_set_x(lblBluetooth, UI_ALIGN_TOP_LEFT_X_OFFSET + 5);
  lv_obj_set_y(lblBluetooth, yOffset);
  lv_label_set_text(lblBluetooth, "Bluetooth LE");
  lv_obj_set_style_text_font(lblBluetooth, systemFontMedium,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_switchBluetooth = lv_switch_create(ui_panelSettingsConnectivity);
  lv_obj_set_height(ui_switchBluetooth, 20);
  lv_obj_align_to(
      ui_switchBluetooth, lblBluetooth, LV_ALIGN_LEFT_MID,
      240 - (UI_ALIGN_TOP_LEFT_X_OFFSET +
             lv_text_get_width("Bluetooth LE", 10, systemFontMedium, 0) +
             lv_obj_get_width(ui_switchBluetooth)),
      0);
  if (bluetoothLEEnabled) {
    lv_obj_add_state(ui_switchBluetooth, LV_STATE_CHECKED);
  }
  lv_obj_add_event_cb(ui_switchBluetooth, ui_event_switch_cb,
                      LV_EVENT_VALUE_CHANGED, "bt ble switch");

  ui_add_bottom_bar(ui_panelSettingsConnectivity, 0xFFFFFF, 10);
}
