#include "ui.h"

lv_obj_t *lblBtScanning;
lv_obj_t *scanningSpinner;
char scanStatus[20];
int listStartY;

void ui_event_ble_switch_cb(lv_event_t *e);

void ui_settingsConnectivityBLEScreen_screen_init(void) {
  ui_settingsConnectivityBLEScreen = lv_obj_create(NULL);
  lv_obj_remove_flag(ui_settingsConnectivityBLEScreen,
                     LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  int yOffset = UI_ALIGN_TOP_LEFT_Y_OFFSET;

  ui_panelSettingsConnectivityBLE =
      lv_obj_create(ui_settingsConnectivityBLEScreen);
  lv_obj_set_width(ui_panelSettingsConnectivityBLE, 240);
  lv_obj_set_height(ui_panelSettingsConnectivityBLE, 320);
  lv_obj_remove_flag(ui_panelSettingsConnectivityBLE,
                     LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_image_src(ui_panelSettingsConnectivityBLE,
                                screenWallpaperImg,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_image_opa(ui_panelSettingsConnectivityBLE, 100,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_panelSettingsConnectivityBLE,
                                lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_panelSettingsConnectivityBLE, 0,
                              LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *lblConnectivity = lv_label_create(ui_panelSettingsConnectivityBLE);
  lv_obj_set_align(lblConnectivity, LV_ALIGN_TOP_LEFT);
  lv_obj_set_y(lblConnectivity, yOffset);
  lv_label_set_text(lblConnectivity, "Bluetoth LE");
  lv_obj_set_align(lblConnectivity, LV_ALIGN_TOP_MID);
  lv_obj_set_style_text_font(lblConnectivity, systemFontLarge,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  yOffset += 25;

  // BT classic switch
  lv_obj_t *lblBluetooth = lv_label_create(ui_panelSettingsConnectivityBLE);
  lv_obj_set_align(lblBluetooth, LV_ALIGN_TOP_LEFT);
  lv_obj_set_x(lblBluetooth, UI_ALIGN_TOP_LEFT_X_OFFSET + 5);
  lv_obj_set_y(lblBluetooth, yOffset);
  lv_label_set_text(lblBluetooth, "Bluetooth Low Energy");
  lv_obj_set_style_text_font(lblBluetooth, systemFontMedium,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_switchBluetooth =
      lv_switch_create(ui_panelSettingsConnectivityBLE);
  lv_obj_set_height(ui_switchBluetooth, 20);
  lv_obj_align_to(ui_switchBluetooth, ui_panelSettingsConnectivityBLE,
                  LV_ALIGN_TOP_RIGHT,
                  (lv_obj_get_width(ui_switchBluetooth) * -1) + 10, yOffset);
  if (bluetoothLEEnabled) {
    lv_obj_add_state(ui_switchBluetooth, LV_STATE_CHECKED);
  }
  lv_obj_add_event_cb(ui_switchBluetooth, ui_event_ble_switch_cb,
                      LV_EVENT_VALUE_CHANGED, NULL);

  yOffset += 25;

  lblBtScanning = lv_label_create(ui_panelSettingsConnectivityBLE);
  lv_obj_set_align(lblBtScanning, LV_ALIGN_TOP_LEFT);
  lv_obj_set_x(lblBtScanning, 5);
  lv_obj_set_y(lblBtScanning, yOffset);

  if (bluetoothLEEnabled) {
    strcpy(scanStatus, "Scanning...");
  } else {
    strcpy(scanStatus, "Bluetooth OFF");
  }
  lv_label_set_text(lblBtScanning, scanStatus);
  lv_obj_set_style_text_font(lblBtScanning, systemFontMedium,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  scanningSpinner = lv_spinner_create(ui_panelSettingsConnectivityBLE);
  lv_obj_set_width(scanningSpinner, 10);
  lv_obj_set_height(scanningSpinner, 10);
  if (!bluetoothLEEnabled) {
    lv_obj_add_flag(scanningSpinner, LV_OBJ_FLAG_HIDDEN);
  }
  lv_obj_align_to(scanningSpinner, ui_panelSettingsConnectivityBLE,
                  LV_ALIGN_TOP_RIGHT,
                  (lv_obj_get_width(scanningSpinner) * -1) + 10, yOffset);
  lv_spinner_set_anim_params(scanningSpinner, 1000, 270);

  yOffset += 20;

  ui_listBLEFoundDevices = lv_list_create(ui_panelSettingsConnectivityBLE);
  lv_obj_set_width(ui_listBLEFoundDevices, 240);
  lv_obj_set_height(ui_listBLEFoundDevices, 265);
  lv_obj_set_x(ui_listBLEFoundDevices, 0);
  lv_obj_set_y(ui_listBLEFoundDevices, yOffset);
  lv_obj_set_align(ui_listBLEFoundDevices, LV_ALIGN_TOP_LEFT);
  lv_obj_set_style_radius(ui_listBLEFoundDevices, 0,
                          LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_listBLEFoundDevices, 0,
                          LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_listBLEFoundDevices, lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_listBLEFoundDevices, 255,
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(ui_listBLEFoundDevices, 0,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_listBLEFoundDevices, LV_BORDER_SIDE_NONE,
                               LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_center(ui_listBLEFoundDevices);
  if (!bluetoothLEEnabled) {
    lv_obj_add_flag(ui_listBLEFoundDevices, LV_OBJ_FLAG_HIDDEN);
  }

  ui_add_bottom_bar(ui_panelSettingsConnectivityBLE, 0xFFFFFF, 10);
}

void ui_event_ble_switch_cb(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);

  bool switchOn = lv_obj_has_state(target, LV_STATE_CHECKED);
  lv_utils_setBluetooth(switchOn);

  if (switchOn) {
    lv_label_set_text(lblBtScanning, "Scanning...");
    lv_obj_remove_flag(scanningSpinner, LV_OBJ_FLAG_HIDDEN);
    lv_obj_remove_flag(ui_listBLEFoundDevices, LV_OBJ_FLAG_HIDDEN);
  } else {
    lv_label_set_text(lblBtScanning, "Bluetooth OFF");
    lv_obj_add_flag(scanningSpinner, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_listBLEFoundDevices, LV_OBJ_FLAG_HIDDEN);
  }
}
