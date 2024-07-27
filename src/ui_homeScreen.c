#include "ui.h"

void ui_homeScreen_screen_init(void) {
  ui_homeScreen = lv_obj_create(NULL);
  lv_obj_remove_flag(ui_homeScreen, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_panelMain = lv_obj_create(ui_homeScreen);
  lv_obj_set_width(ui_panelMain, 240);
  lv_obj_set_height(ui_panelMain, 320);
  lv_obj_set_x(ui_panelMain, 0);
  lv_obj_set_y(ui_panelMain, 0);
  lv_obj_set_align(ui_panelMain, LV_ALIGN_CENTER);
  lv_obj_remove_flag(ui_panelMain, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_color(ui_panelMain, lv_color_hex(0xFFFFFF),
                            LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_panelMain, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_image_src(ui_panelMain, screenWallpaperImg,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_panelMain, lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_panelMain, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_radius(ui_panelMain, 0,
                          LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_panelMain, lv_color_hex(0xFFFFFF),
                            LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_panelMain, 0,
                          LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_image_src(ui_panelMain, screenWallpaperImg,
                                LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

  ui_homeContainerTopBar = lv_obj_create(ui_panelMain);
  lv_obj_remove_style_all(ui_homeContainerTopBar);
  lv_obj_set_width(ui_homeContainerTopBar, 240);
  lv_obj_set_height(ui_homeContainerTopBar, 15);
  lv_obj_set_x(ui_homeContainerTopBar, -16);
  lv_obj_set_y(ui_homeContainerTopBar, UI_ALIGN_TOP_LEFT_Y_OFFSET);
  lv_obj_remove_flag(ui_homeContainerTopBar,
                     LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_lblHomeBatteryLevel = lv_label_create(ui_homeContainerTopBar);
  lv_obj_set_width(ui_lblHomeBatteryLevel, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblHomeBatteryLevel, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_x(ui_lblHomeBatteryLevel, -5);
  lv_obj_set_y(ui_lblHomeBatteryLevel, 0);
  lv_obj_set_align(ui_lblHomeBatteryLevel, LV_ALIGN_TOP_RIGHT);
  lv_label_set_text_fmt(ui_lblHomeBatteryLevel, "%s%s%%", LV_SYMBOL_BATTERY_2,
                        "65");
  lv_obj_set_style_text_color(ui_lblHomeBatteryLevel, lv_color_hex(0xFFFFFF),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_lblHomeBatteryLevel, 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

  //======label for bluetooth and other indicators beside battery======
  bool activatedSettings[] = {bluetoothLEEnabled};
  char *activatedSettingsSymbols[] = {LV_SYMBOL_BLUETOOTH};
  char strSystemIndicators[21] = {};  // LV_SYMBOL_* 3bytes?
  uint8_t indicatorsAdded = 0;        // for spacing of the indicators

  lv_obj_t *systemIndicators = lv_label_create(ui_panelMain);
  lv_label_set_long_mode(systemIndicators, LV_LABEL_LONG_SCROLL_CIRCULAR);
  lv_obj_set_width(systemIndicators, 60);                /// 1
  lv_obj_set_height(systemIndicators, LV_SIZE_CONTENT);  /// 1
  // FIXME: RTL not working
  lv_obj_set_style_base_dir(systemIndicators, LV_BASE_DIR_RTL, 0);
  lv_obj_set_x(systemIndicators, -5);
  lv_obj_set_y(systemIndicators, 0);
  lv_obj_align_to(systemIndicators, ui_lblHomeBatteryLevel,
                  LV_ALIGN_OUT_LEFT_MID, -5, 0);
  lv_obj_set_style_text_color(systemIndicators, lv_color_hex(0xFFFFFF),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(systemIndicators, 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

  for (int i = 0; i < sizeof(activatedSettings) / sizeof(activatedSettings[0]);
       i++) {
    if (activatedSettings[i]) {
      if (indicatorsAdded > 0) {
        strcat(strSystemIndicators, " ");
      }
      strcat(strSystemIndicators, activatedSettingsSymbols[i]);
      indicatorsAdded++;
    }
  }
  lv_label_set_text(systemIndicators, strSystemIndicators);
  //===================================================================

  ui_lblHomeSignalLevel = lv_label_create(ui_homeContainerTopBar);
  lv_obj_set_width(ui_lblHomeSignalLevel, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblHomeSignalLevel, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_x(ui_lblHomeSignalLevel, 5);
  lv_obj_set_y(ui_lblHomeSignalLevel, 0);
  lv_label_set_text(ui_lblHomeSignalLevel, "SIGNAL");
  lv_obj_set_style_text_color(ui_lblHomeSignalLevel, lv_color_hex(0xFFFFFF),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_lblHomeSignalLevel, 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_homeContainerDateISP = lv_obj_create(ui_panelMain);
  lv_obj_remove_style_all(ui_homeContainerDateISP);
  lv_obj_set_height(ui_homeContainerDateISP, 85);
  lv_obj_set_width(ui_homeContainerDateISP, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_x(ui_homeContainerDateISP, 0);
  lv_obj_set_y(ui_homeContainerDateISP, 30);
  lv_obj_set_align(ui_homeContainerDateISP, LV_ALIGN_TOP_MID);
  lv_obj_remove_flag(ui_homeContainerDateISP,
                     LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_lblHomeTime = lv_label_create(ui_homeContainerDateISP);
  lv_obj_set_width(ui_lblHomeTime, LV_SIZE_CONTENT);       /// 1
  lv_obj_set_height(ui_lblHomeTime, LV_SIZE_CONTENT);      /// 1
  lv_obj_add_flag(ui_lblHomeTime, LV_OBJ_FLAG_CLICKABLE);  /// Flags
  lv_label_set_text(ui_lblHomeTime, lvCurrentTime);
  lv_obj_set_style_text_color(ui_lblHomeTime, lv_color_hex(0xFFFFFF),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_lblHomeTime, 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_letter_space(ui_lblHomeTime, 2,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_line_space(ui_lblHomeTime, 0,
                                   LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_align(ui_lblHomeTime, LV_TEXT_ALIGN_CENTER,
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_lblHomeTime, &lv_font_montserrat_44,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_lblHomeDate = lv_label_create(ui_homeContainerDateISP);
  lv_obj_set_width(ui_lblHomeDate, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblHomeDate, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_x(ui_lblHomeDate, 0);
  lv_obj_set_y(ui_lblHomeDate, 45);
  lv_label_set_text(ui_lblHomeDate, lvCurrentDate);
  lv_obj_set_style_text_color(ui_lblHomeDate, lv_color_hex(0xF0F0F0),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_lblHomeDate, 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_lblHomeDate, &lv_font_montserrat_16,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_lblHomeISP = lv_label_create(ui_homeContainerDateISP);
  lv_obj_set_width(ui_lblHomeISP, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblHomeISP, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_x(ui_lblHomeISP, 0);
  lv_obj_set_y(ui_lblHomeISP, 65);
  lv_label_set_text(ui_lblHomeISP, "Safaricom");
  lv_obj_set_style_text_color(ui_lblHomeISP, lv_color_hex(0xF0F0F0),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_lblHomeISP, 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_lblHomeISP, &lv_font_montserrat_16,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_homeContainerStart = lv_obj_create(ui_panelMain);
  lv_obj_remove_style_all(ui_homeContainerStart);
  lv_obj_set_width(ui_homeContainerStart, 240);
  lv_obj_set_height(ui_homeContainerStart, 40);
  lv_obj_set_x(ui_homeContainerStart, 0);
  lv_obj_set_y(ui_homeContainerStart, 5);
  lv_obj_set_align(ui_homeContainerStart, LV_ALIGN_BOTTOM_MID);
  lv_obj_set_flex_flow(ui_homeContainerStart, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(ui_homeContainerStart, LV_FLEX_ALIGN_SPACE_EVENLY,
                        LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
  lv_obj_remove_flag(ui_homeContainerStart,
                     LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_imbHomePhone = lv_imagebutton_create(ui_homeContainerStart);
  lv_imagebutton_set_src(ui_imbHomePhone, LV_IMAGEBUTTON_STATE_RELEASED, NULL,
                         &ui_img_openphone40_png, NULL);
  lv_obj_set_width(ui_imbHomePhone, 40);
  lv_obj_set_height(ui_imbHomePhone, 40);
  lv_obj_set_align(ui_imbHomePhone, LV_ALIGN_TOP_MID);

  ui_imbHomeMessages = lv_imagebutton_create(ui_homeContainerStart);
  lv_imagebutton_set_src(ui_imbHomeMessages, LV_IMAGEBUTTON_STATE_RELEASED,
                         NULL, &ui_img_messages40_png, NULL);
  lv_obj_set_width(ui_imbHomeMessages, 40);
  lv_obj_set_height(ui_imbHomeMessages, 40);
  lv_obj_set_align(ui_imbHomeMessages, LV_ALIGN_TOP_MID);

  ui_imbHomeApps = lv_imagebutton_create(ui_homeContainerStart);
  lv_imagebutton_set_src(ui_imbHomeApps, LV_IMAGEBUTTON_STATE_RELEASED, NULL,
                         &ui_img_apps40_png, NULL);
  lv_obj_set_width(ui_imbHomeApps, 40);
  lv_obj_set_height(ui_imbHomeApps, 40);
  lv_obj_set_align(ui_imbHomeApps, LV_ALIGN_TOP_MID);

  ui_imbHomeBrowser = lv_imagebutton_create(ui_homeContainerStart);
  lv_imagebutton_set_src(ui_imbHomeBrowser, LV_IMAGEBUTTON_STATE_RELEASED, NULL,
                         &ui_img_browser40_png, NULL);
  lv_obj_set_width(ui_imbHomeBrowser, 40);
  lv_obj_set_height(ui_imbHomeBrowser, 40);
  lv_obj_set_align(ui_imbHomeBrowser, LV_ALIGN_TOP_MID);

  ui_imbHomeContacts = lv_imagebutton_create(ui_homeContainerStart);
  lv_imagebutton_set_src(ui_imbHomeContacts, LV_IMAGEBUTTON_STATE_RELEASED,
                         NULL, &ui_img_usergroup40_png, NULL);
  lv_obj_set_width(ui_imbHomeContacts, 40);
  lv_obj_set_height(ui_imbHomeContacts, 40);
  lv_obj_set_align(ui_imbHomeContacts, LV_ALIGN_TOP_MID);

  lv_obj_add_event_cb(ui_lblHomeTime, ui_event_label_cb, LV_EVENT_CLICKED,
                      "time home");
  lv_obj_add_event_cb(ui_imbHomePhone, ui_event_imagebutton_cb, LV_EVENT_ALL,
                      "home phone");
  lv_obj_add_event_cb(ui_imbHomeMessages, ui_event_imagebutton_cb, LV_EVENT_ALL,
                      "home messages");
  lv_obj_add_event_cb(ui_imbHomeApps, ui_event_imagebutton_cb, LV_EVENT_ALL,
                      "apps");
  lv_obj_add_event_cb(ui_imbHomeBrowser, ui_event_imagebutton_cb, LV_EVENT_ALL,
                      "home browser");
  lv_obj_add_event_cb(ui_imbHomeContacts, ui_event_imagebutton_cb, LV_EVENT_ALL,
                      "home contacts");
}
