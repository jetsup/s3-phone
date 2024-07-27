#include "ui_events.h"

void ui_event_imagebutton_cb(lv_event_t* e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t* target = lv_event_get_target(e);

  const char* btnData = (const char*)e->user_data;

  if (event_code == LV_EVENT_CLICKED) {
    if (strcmp(btnData, "phone") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(SCREEN_PHONE, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "home phone") == 0) {
      if (screenStackPush(SCREEN_HOME, LV_SCR_LOAD_ANIM_MOVE_LEFT)) {
        _ui_screen_change(SCREEN_PHONE, LV_SCR_LOAD_ANIM_MOVE_RIGHT,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "messages") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(SCREEN_MESSAGES, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "home messages") == 0) {
      if (screenStackPush(SCREEN_HOME, LV_SCR_LOAD_ANIM_MOVE_LEFT)) {
        _ui_screen_change(SCREEN_MESSAGES, LV_SCR_LOAD_ANIM_MOVE_RIGHT,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "apps") == 0) {
      if (screenStackPush(SCREEN_HOME, LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(SCREEN_MAIN_MENU, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "browser") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(SCREEN_BROWSER_MAIN, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "home browser") == 0) {
      if (screenStackPush(SCREEN_HOME, LV_SCR_LOAD_ANIM_MOVE_RIGHT)) {
        _ui_screen_change(SCREEN_BROWSER_MAIN, LV_SCR_LOAD_ANIM_MOVE_LEFT,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "contacts") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(SCREEN_CONTACTS, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "home contacts") == 0) {
      if (screenStackPush(SCREEN_HOME, LV_SCR_LOAD_ANIM_MOVE_RIGHT)) {
        _ui_screen_change(SCREEN_CONTACTS, LV_SCR_LOAD_ANIM_MOVE_LEFT,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "multimedia") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(SCREEN_MULTIMEDIA_MAIN, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "extra") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(SCREEN_EXTRA_MAIN, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "games") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(SCREEN_GAMES_MAIN, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "my-zone") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, LV_SCR_LOAD_ANIM_MOVE_TOP)) {
        _ui_screen_change(SCREEN_MY_ZONE_MAIN, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "about") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(SCREEN_SETTINGS_ABOUT, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "tools") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(SCREEN_TOOLS_MAIN, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "settings") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(SCREEN_SETTINGS, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "clock") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(SCREEN_TIME_MAIN, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "calculator") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(SCREEN_CALCULATOR, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "calendar") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(SCREEN_CALENDAR, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "files") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(SCREEN_FILES_MAIN, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "todo") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(SCREEN_TODO_MAIN, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "stk") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(SCREEN_STK_MAIN, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "contacts") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(SCREEN_CONTACTS, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "gallery") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(SCREEN_GALLERY_MAIN, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "music") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(SCREEN_MUSIC_MAIN, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "radio") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(SCREEN_RADIO_MAIN, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "video") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(SCREEN_VIDEO_MAIN, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0);
      }
    }
  }
}

void ui_event_evtBottombar(lv_event_t* e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t* target = lv_event_get_target(e);
  const char* btnData = (const char*)e->user_data;

  if (event_code == LV_EVENT_CLICKED) {
    if (strcmp(btnData, "navbar home") == 0) {
      if (!screenStackIsEmpty()) {
        ScreenStackElement previousScreen = screenStackPeek();
        screenStackEmpty();
        _ui_screen_change(SCREEN_HOME, previousScreen.transitionAnimation,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "navbar back") == 0) {
      if (!screenStackIsEmpty() && screenStackSize() > 0) {
        ScreenStackElement poppedScreen = screenStackPop();
        lv_utils_initScreen(poppedScreen.screen);
        _ui_screen_change(poppedScreen.screen, poppedScreen.transitionAnimation,
                          UI_ANIMATION_DURATION, 0);
      } else {
        if (screenStackPush(SCREEN_HOME, LV_SCR_LOAD_ANIM_NONE)) {
          _ui_screen_change(SCREEN_HOME, LV_SCR_LOAD_ANIM_NONE,
                            UI_ANIMATION_DURATION, 0);
        }
      }
    } else if (strcmp(btnData, "navbar tasks") == 0) {
      _ui_screen_change(SCREEN_HOME, LV_SCR_LOAD_ANIM_NONE,
                        UI_ANIMATION_DURATION, 0);
    }
  }
}

void ui_event_fab_cb(lv_event_t* e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t* floatButton = lv_event_get_target(e);

  if (event_code == LV_EVENT_CLICKED) {
    if (screenStackPush(SCREEN_CONTACTS, LV_SCR_LOAD_ANIM_MOVE_RIGHT)) {
      _ui_screen_change(SCREEN_CONTACT_ADD, LV_SCR_LOAD_ANIM_MOVE_LEFT,
                        UI_ANIMATION_DURATION, 0);
    }
  }
}

// General Events
void ui_event_textarea_cb(lv_event_t* e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t* ta = lv_event_get_target(e);
  const char* textData = (const char*)e->user_data;

  if (code == LV_EVENT_CLICKED) {
    if (strcmp(textData, "contact add name") == 0) {
      if (ui_keyboard_full == NULL) {
        ui_keyboard_full = lv_keyboard_create(lv_scr_act());
        lv_obj_add_event_cb(ui_keyboard_full, ui_event_keyboard_cb,
                            LV_EVENT_ALL, NULL);
      }
      lv_keyboard_set_textarea(ui_keyboard_full, ta);
    } else if (strcmp(textData, "contact add num") == 0) {
      if (ui_keyboard_num == NULL) {
        ui_keyboard_num = lv_keyboard_create(lv_scr_act());
        lv_obj_add_event_cb(ui_keyboard_num, ui_event_keyboard_cb, LV_EVENT_ALL,
                            "keyboard num");
        lv_keyboard_set_mode(ui_keyboard_num, LV_KEYBOARD_MODE_NUMBER);
      }
      lv_keyboard_set_textarea(ui_keyboard_num, ta);
    }
  }

  if (code == LV_EVENT_DEFOCUSED) {
    if (strcmp(textData, "contact add name") == 0) {
      if (ui_keyboard_full) {
        lv_obj_del(ui_keyboard_full);
        ui_keyboard_full = NULL;
      }
    } else if (strcmp(textData, "contact add name") == 0) {
      if (ui_keyboard_num) {
        lv_obj_del(ui_keyboard_num);
        ui_keyboard_num = NULL;
      }
    }
  }
}

void ui_event_keyboard_cb(lv_event_t* e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t* target = lv_event_get_target(e);
  const char* keyboardData = (const char*)e->user_data;

  if (code == LV_EVENT_READY || code == LV_EVENT_CANCEL) {
    if (strcmp(keyboardData, "keyboard full") == 0) {
      lv_obj_del(ui_keyboard_full);
      ui_keyboard_full = NULL;
    } else if (strcmp(keyboardData, "keyboard num") == 0) {
      lv_obj_del(ui_keyboard_num);
      ui_keyboard_num = NULL;
    } else if (strcmp(keyboardData, "sim unlock") == 0) {
      lv_obj_t* uData = lv_event_get_user_data(e);

      const char* txt = lv_buttonmatrix_get_button_text(
          target, lv_buttonmatrix_get_selected_button(target));

      if (lv_strcmp(txt, LV_SYMBOL_BACKSPACE) == 0)
        lv_textarea_delete_char(uData);
      else if (lv_strcmp(txt, LV_SYMBOL_NEW_LINE) == 0)
        lv_obj_send_event(uData, LV_EVENT_READY, NULL);
      else
        lv_textarea_add_text(uData, txt);
    }
  }
}

void ui_event_slider_cb(lv_event_t* e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t* target = lv_event_get_target(e);
  const char* sliderData = (const char*)e->user_data;

  if (code == LV_EVENT_VALUE_CHANGED) {
    if (strcmp(sliderData, "settings brightness") == 0) {
      lv_utils_setBrightness(lv_slider_get_value(target));

      uint8_t brightnessPercentage =
          ((float)screenBrightnessLevel / (float)UI_BRIGHTNESS_SLIDER_MAX) *
          100;
      char sBrightness[5];
      lv_snprintf(sBrightness, 5, "%d%%", brightnessPercentage);

      lv_label_set_text(ui_lblBrightnessValue, sBrightness);
    }
  }
}

void ui_event_dropdown_cb(lv_event_t* e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t* target = lv_event_get_target(e);
  const char* dropdownData = (const char*)e->user_data;

  int selected = lv_dropdown_get_selected(target);

  if (code == LV_EVENT_VALUE_CHANGED) {
    if (strcmp(dropdownData, "settings screen timeout") == 0) {
      char bufSelection[7];
      lv_dropdown_get_selected_str(target, bufSelection, 7);

      if (strcmp(bufSelection, "Never") == 0) {
        lv_utils_setScreenTimeout(0);
      } else if (strcmp(bufSelection, "5 sec") == 0) {
        lv_utils_setScreenTimeout(5);
      } else if (strcmp(bufSelection, "10 sec") == 0) {
        lv_utils_setScreenTimeout(10);
      } else if (strcmp(bufSelection, "15 sec") == 0) {
        lv_utils_setScreenTimeout(15);
      } else if (strcmp(bufSelection, "30 sec") == 0) {
        lv_utils_setScreenTimeout(30);
      } else if (strcmp(bufSelection, "1 min") == 0) {
        lv_utils_setScreenTimeout(1 * 60);
      } else if (strcmp(bufSelection, "2 min") == 0) {
        lv_utils_setScreenTimeout(2 * 60);
      } else if (strcmp(bufSelection, "5 min") == 0) {
        lv_utils_setScreenTimeout(5 * 60);
      } else if (strcmp(bufSelection, "10 min") == 0) {
        lv_utils_setScreenTimeout(10 * 60);
      }

      dropdownSelectedTimeout = lv_set_selected_timeout();
    }
  }
}

void ui_event_switch_cb(lv_event_t* e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t* target = lv_event_get_target(e);
  const char* switchData = (const char*)e->user_data;

  bool switchOn = lv_obj_has_state(target, LV_STATE_CHECKED);

  if (code == LV_EVENT_VALUE_CHANGED) {
    if (strcmp(switchData, "theme switch") == 0) {
      lv_utils_setTheme(switchOn);
    } else if (strcmp(switchData, "bt ble switch") == 0) {
      if (screenStackPush(SCREEN_SETTINGS_CONNECTIVITY_BLE,
                          LV_SCR_LOAD_ANIM_MOVE_RIGHT)) {
        _ui_screen_change(SCREEN_SETTINGS_CONNECTIVITY_BLE,
                          LV_SCR_LOAD_ANIM_MOVE_LEFT, UI_ANIMATION_DURATION, 0);
      }
    }
  }
}

void ui_event_image_cb(lv_event_t* e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t* target = lv_event_get_target(e);
  const char* switchData = (const char*)e->user_data;
}

void ui_event_label_cb(lv_event_t* e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t* target = lv_event_get_target(e);
  const char* labelData = (const char*)e->user_data;

  if (code == LV_EVENT_CLICKED) {
    if (strcmp(labelData, "time home") == 0) {
      if (screenStackPush(SCREEN_HOME, LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(SCREEN_TIME_MAIN, LV_SCR_LOAD_ANIM_FADE_ON,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(labelData, "contact discard") == 0) {
      ScreenStackElement prevScreen = screenStackPop();

      _ui_screen_change(prevScreen.screen, prevScreen.transitionAnimation,
                        UI_ANIMATION_DURATION, 0);
    } else if (strcmp(labelData, "contact save") == 0) {
      ScreenStackElement prevScreen = screenStackPop();

      _ui_screen_change(prevScreen.screen, prevScreen.transitionAnimation,
                        UI_ANIMATION_DURATION, 0);
    } else if (strcmp(labelData, "wallpaper select") > 0) {
      const char delimiter[] = " ";

      char wallpaperTag[19];
      strcpy(wallpaperTag, labelData);

      char* token;
      token = strtok(wallpaperTag, delimiter);
      if (token != NULL) {
        token = strtok(NULL, delimiter);
        if (token != NULL) {
          clickedWallpaperImage = atoi(token);

          if (screenStackPush(SCREEN_SETTINGS_THEMES,
                              LV_SCR_LOAD_ANIM_MOVE_RIGHT)) {
            _ui_screen_change(SCREEN_SETTINGS_THEMES_WALLPAPERS,
                              LV_SCR_LOAD_ANIM_MOVE_LEFT, UI_ANIMATION_DURATION,
                              0);
          }
        }
      }
    } else if (strcmp(labelData, "connectivity ble") == 0) {
      if (screenStackPush(SCREEN_SETTINGS_CONNECTIVITY,
                          LV_SCR_LOAD_ANIM_MOVE_RIGHT)) {
        _ui_screen_change(SCREEN_SETTINGS_CONNECTIVITY_BLE,
                          LV_SCR_LOAD_ANIM_MOVE_LEFT, UI_ANIMATION_DURATION, 0);
      }
    }
  }
}

void ui_event_button_cb(lv_event_t* e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t* target = lv_event_get_target(e);
  const char* buttonData = (const char*)e->user_data;

  if (code == LV_EVENT_CLICKED) {
    if (strcmp(buttonData, "calendar discard") == 0) {
      char bufDate[11];  // DD/MM/YYYY
      uint32_t year, month, day;
      lv_utils_getDate(bufDate);
      year = atoi(bufDate + 6);
      month = atoi(bufDate + 3);
      day = atoi(bufDate);

      lv_calendar_set_today_date(ui_calendar, year, month, day);

      lv_obj_add_state(ui_btnCalendarApply, LV_STATE_DISABLED);
      lv_obj_add_state(ui_btnCalendarDiscard, LV_STATE_DISABLED);
    } else if (strcmp(buttonData, "calendar update") == 0) {
      uint32_t year, month, day;
      const lv_calendar_date_t* date = lv_calendar_get_today_date(ui_calendar);
      lv_utils_setDate(date->year, date->month, date->day);

      lv_obj_add_state(ui_btnCalendarApply, LV_STATE_DISABLED);
      lv_obj_add_state(ui_btnCalendarDiscard, LV_STATE_DISABLED);
    } else if (strcmp(buttonData, "wallpaper apply") == 0) {
      lv_image_cache_drop(NULL);

      lv_utils_setWallpaper(clickedWallpaperImage, true);

      ScreenStackElement prevScreen = screenStackPop();
      lv_utils_initScreen(prevScreen.screen);

      _ui_screen_change(prevScreen.screen, prevScreen.transitionAnimation,
                        UI_ANIMATION_DURATION, 0);
    } else if (strcmp(buttonData, "contact option") == 0) {
    } else if (strcmp(buttonData, "contact list") == 0) {
      const char* contact = lv_list_get_button_text(ui_listContact, target);
      char contactData[CONTACT_NAME_NUMBER_LENGTH];
      strcpy(contactData, contact);

      char* token;
      token = strtok(contactData, contactSeparationDelimeter);
      if (token != NULL) {
        strlcpy(contactName, token, sizeof(contactName));
        token = strtok(NULL, contactSeparationDelimeter);
        if (token != NULL) {
          strlcpy(contactNumber, token, sizeof(contactNumber));
        }
      }
      if (screenStackPush(SCREEN_CONTACTS, LV_SCR_LOAD_ANIM_MOVE_RIGHT)) {
        _ui_screen_change(SCREEN_CONTACT_OPTIONS, LV_SCR_LOAD_ANIM_MOVE_LEFT,
                          UI_ANIMATION_DURATION, 0);

        lv_label_set_text(ui_lblContactDetailsTitle, (const char*)contactName);
      }
    }
  }
}
