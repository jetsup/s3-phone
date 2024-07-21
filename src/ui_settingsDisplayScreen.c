#include "ui.h"

int yOffset = UI_ALIGN_TOP_LEFT_Y_OFFSET;

void ui_settingsDisplayScreen_screen_init(void) {
  ui_settingsDisplayScreen = lv_obj_create(NULL);
  lv_obj_remove_flag(ui_settingsDisplayScreen,
                     LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_panelSettingsDisplayMain = lv_obj_create(ui_settingsDisplayScreen);
  lv_obj_set_width(ui_panelSettingsDisplayMain, 240);
  lv_obj_set_height(ui_panelSettingsDisplayMain, 320);
  lv_obj_remove_flag(ui_panelSettingsDisplayMain,
                     LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_image_src(ui_panelSettingsDisplayMain, &ui_img_bg1_png,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_image_opa(ui_panelSettingsDisplayMain, 100,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_panelSettingsDisplayMain,
                                lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_panelSettingsDisplayMain, 0,
                              LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t* lblBrightness = lv_label_create(ui_panelSettingsDisplayMain);
  lv_obj_set_align(lblBrightness, LV_ALIGN_TOP_LEFT);
  lv_obj_set_x(lblBrightness, 0);
  lv_obj_set_y(lblBrightness, yOffset);
  lv_label_set_text(lblBrightness, "Brightness");
  lv_obj_set_style_text_font(lblBrightness, &lv_font_montserrat_14,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  yOffset += 25;

  sliderBrightness = lv_slider_create(ui_panelSettingsDisplayMain);
  lv_obj_set_align(sliderBrightness, LV_ALIGN_TOP_LEFT);
  lv_obj_set_width(sliderBrightness, 185);
  lv_obj_set_height(sliderBrightness, 5);
  lv_obj_set_x(sliderBrightness, UI_ALIGN_TOP_LEFT_X_OFFSET + 10);
  lv_obj_set_y(sliderBrightness, yOffset);
  lv_slider_set_range(sliderBrightness, UI_BRIGHTNESS_SLIDER_MIN,
                      UI_BRIGHTNESS_SLIDER_MAX);
  lv_slider_set_value(sliderBrightness, screenBrightnessLevel, LV_ANIM_ON);

  uint8_t brightnessPercentage =
      ((float)screenBrightnessLevel / (float)UI_BRIGHTNESS_SLIDER_MAX) * 100;
  char sBrightness[5];
  lv_snprintf(sBrightness, 5, "%d%%", brightnessPercentage);

  ui_lblBrightnessValue = lv_label_create(ui_panelSettingsDisplayMain);
  lv_label_set_text(ui_lblBrightnessValue, sBrightness);
  lv_obj_align_to(ui_lblBrightnessValue, sliderBrightness,
                  LV_ALIGN_OUT_RIGHT_MID, 10, 0);

  yOffset += 20;

  // screen timeout
  lv_obj_t* lblScreenTimeout = lv_label_create(ui_panelSettingsDisplayMain);
  lv_obj_set_y(lblScreenTimeout, yOffset);
  lv_label_set_text(lblScreenTimeout, "Screen Timeout");
  lv_obj_set_style_text_font(lblScreenTimeout, &lv_font_montserrat_14,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  yOffset += 25;

  ui_dropDownSettingsScreenTimeout =
      lv_dropdown_create(ui_panelSettingsDisplayMain);
  lv_dropdown_set_options(ui_dropDownSettingsScreenTimeout,
                          "15 sec\n30 Sec\n1 min\n2 min\n5 min\n10 min\nNever");
  lv_obj_set_width(ui_dropDownSettingsScreenTimeout, 230);
  lv_obj_set_height(ui_dropDownSettingsScreenTimeout, 36);
  lv_obj_set_x(ui_dropDownSettingsScreenTimeout,
               UI_ALIGN_TOP_LEFT_X_OFFSET + 5);
  lv_obj_set_y(ui_dropDownSettingsScreenTimeout, yOffset);
  lv_obj_set_align(ui_dropDownSettingsScreenTimeout, LV_ALIGN_TOP_LEFT);
  lv_obj_add_flag(ui_dropDownSettingsScreenTimeout,
                  LV_OBJ_FLAG_SCROLL_ON_FOCUS);  /// Flags
  lv_obj_set_style_bg_opa(ui_dropDownSettingsScreenTimeout, 0,
                          LV_PART_MAIN | LV_STATE_DEFAULT);

  yOffset += 20;

  // Events
  lv_obj_add_event_cb(sliderBrightness, ui_event_slider_cb, LV_EVENT_ALL,
                      "settings brightness");
  lv_obj_add_event_cb(ui_dropDownSettingsScreenTimeout, ui_event_dropdown_cb,
                      LV_EVENT_ALL, "settings screen timeout");

  ui_add_bottom_bar(ui_panelSettingsDisplayMain, 0xFFFFFF, 10);
}
