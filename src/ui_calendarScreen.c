#include "ui.h"

void ui_event_uiComponentsChangeEvent(lv_event_t *e);

void ui_calendarScreen_screen_init(void) {
  ui_calendarScreen = lv_obj_create(NULL);
  lv_obj_remove_flag(ui_calendarScreen, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_panelCalendarMain = lv_obj_create(ui_calendarScreen);
  lv_obj_set_width(ui_panelCalendarMain, 240);
  lv_obj_set_height(ui_panelCalendarMain, 320);
  lv_obj_remove_flag(ui_panelCalendarMain, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_image_src(ui_panelCalendarMain, screenWallpaperImg,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_image_opa(ui_panelCalendarMain, 100,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_panelCalendarMain, lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_panelCalendarMain, 0,
                              LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *lblCalendar = lv_label_create(ui_panelCalendarMain);
  lv_label_set_text(lblCalendar, "Calendar");
  lv_obj_set_align(lblCalendar, LV_ALIGN_TOP_MID);
  lv_obj_set_x(lblCalendar, 0);
  lv_obj_set_y(lblCalendar, UI_ALIGN_TOP_LEFT_Y_OFFSET);
  lv_obj_set_style_text_font(lblCalendar, &lv_font_montserrat_18, 0);

  ui_calendar = lv_calendar_create(ui_panelCalendarMain);
  lv_obj_set_size(ui_calendar, 240, 235);
  lv_obj_set_x(ui_calendar, 0);
  lv_obj_set_y(ui_calendar, 10);
  lv_obj_set_align(ui_calendar, LV_ALIGN_TOP_MID);
  lv_obj_add_event_cb(ui_calendar, ui_event_uiComponentsChangeEvent,
                      LV_EVENT_ALL, "date clicked");
  char bufDate[11];  // DD/MM/YYYY
  uint32_t year, month, day;

  lv_utils_getDate(bufDate);

  year = atoi(bufDate + 6);
  month = atoi(bufDate + 3);
  day = atoi(bufDate);

  lv_calendar_set_today_date(ui_calendar, year, month, day);
  lv_calendar_set_showed_date(ui_calendar, year, month);

  lv_calendar_header_dropdown_create(ui_calendar);

  ui_btnCalendarApply = lv_button_create(ui_panelCalendarMain);
  lv_obj_add_event_cb(ui_btnCalendarApply, ui_event_button_cb, LV_EVENT_CLICKED,
                      "calendar update");
  lv_obj_set_align(ui_btnCalendarApply, LV_ALIGN_BOTTOM_RIGHT);
  lv_obj_set_x(ui_btnCalendarApply, -5);
  lv_obj_set_y(ui_btnCalendarApply, UI_ALIGN_TOP_LEFT_Y_OFFSET);
  lv_obj_add_state(ui_btnCalendarApply, LV_STATE_DISABLED);
  lv_color_t btnColor = {.red = 50, .green = 255, .blue = 50};
  lv_obj_set_style_bg_color(ui_btnCalendarApply, btnColor, NULL);
  lv_obj_t *lblUpdateDate = lv_label_create(ui_btnCalendarApply);
  lv_label_set_text(lblUpdateDate, "Update");
  lv_obj_set_style_text_font(lblUpdateDate, &lv_font_montserrat_10, 0);
  lv_obj_set_style_text_color(lblUpdateDate, lv_color_hex(0x000000),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(lblUpdateDate, 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_btnCalendarDiscard = lv_button_create(ui_panelCalendarMain);
  lv_obj_add_event_cb(ui_btnCalendarDiscard, ui_event_button_cb,
                      LV_EVENT_CLICKED, "calendar discard");
  lv_obj_set_align(ui_btnCalendarDiscard, LV_ALIGN_BOTTOM_LEFT);
  lv_obj_set_x(ui_btnCalendarDiscard, 5);
  lv_obj_set_y(ui_btnCalendarDiscard, UI_ALIGN_TOP_LEFT_Y_OFFSET);
  lv_obj_add_state(ui_btnCalendarDiscard, LV_STATE_DISABLED);
  btnColor.red = 255;
  btnColor.green = 50;
  btnColor.blue = 50;
  lv_obj_set_style_bg_color(ui_btnCalendarDiscard, btnColor, NULL);
  lv_obj_t *lblDiscard = lv_label_create(ui_btnCalendarDiscard);
  lv_label_set_text(lblDiscard, "Discard");
  lv_obj_set_style_text_font(lblDiscard, &lv_font_montserrat_10, 0);
  lv_obj_set_style_text_color(lblDiscard, lv_color_hex(0xFFFFFF),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(lblDiscard, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_add_bottom_bar(ui_panelCalendarMain, 0xFFFFFF, 10);
}

void ui_event_uiComponentsChangeEvent(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);
  const char *data = (const char *)e->user_data;

  if (code == LV_EVENT_VALUE_CHANGED) {
    if (strcmp(data, "date clicked") == 0) {
      lv_calendar_date_t date;
      if (lv_calendar_get_pressed_date(ui_calendar, &date)) {
        lv_calendar_set_today_date(ui_calendar, date.year, date.month,
                                   date.day);
        lv_obj_remove_state(ui_btnCalendarApply, LV_STATE_DISABLED);
        lv_obj_remove_state(ui_btnCalendarDiscard, LV_STATE_DISABLED);
      }
    }
  }
}
