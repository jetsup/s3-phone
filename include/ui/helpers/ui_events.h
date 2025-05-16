#ifndef _UI_EVENTS_H
#define _UI_EVENTS_H

#include "ui/ui.h"

#ifdef __cplusplus
extern "C" {
#endif

void ui_event_image_button_cb(lv_event_t* e);
void ui_event_evtBottombar(lv_event_t* e);
void ui_event_fab_cb(lv_event_t* e);
void ui_event_textarea_cb(lv_event_t* e);
void ui_event_keyboard_cb(lv_event_t* e);
void ui_event_slider_cb(lv_event_t* e);
void ui_event_dropdown_cb(lv_event_t* e);
void ui_event_switch_cb(lv_event_t* e);
void ui_event_checkbox_cb(lv_event_t* e);
void ui_event_image_cb(lv_event_t* e);
void ui_event_label_cb(lv_event_t* e);
void ui_event_button_cb(lv_event_t* e);
void toggle_password_visibility_cb(lv_event_t* e);
void ui_event_list_button_cb(lv_event_t* e);
void ui_event_list_wifi_cb(lv_event_t* e);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
