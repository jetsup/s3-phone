#include "ui/helpers/ui_events.h"

void ui_event_image_button_cb(lv_event_t *e) {
  const lv_event_code_t event_code = lv_event_get_code(e);

  const char *btnData = lv_event_get_user_data(e);

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

void ui_event_evtBottombar(lv_event_t *e) {
  const lv_event_code_t event_code = lv_event_get_code(e);
  const char *btnData = lv_event_get_user_data(e);

  if (event_code == LV_EVENT_CLICKED) {
    if (strcmp(btnData, "navbar home") == 0) {
      if (!screenStackIsEmpty()) {
        const ScreenStackElement previousScreen = screenStackPeek();
        screenStackEmpty();
        _ui_screen_change(SCREEN_HOME, previousScreen.transitionAnimation,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(btnData, "navbar back") == 0) {
      if (!screenStackIsEmpty() && screenStackSize() > 0) {
        const ScreenStackElement poppedScreen = screenStackPop();
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

void ui_event_fab_cb(lv_event_t *e) {
  const lv_event_code_t event_code = lv_event_get_code(e);

  if (event_code == LV_EVENT_CLICKED) {
    if (screenStackPush(SCREEN_CONTACTS, LV_SCR_LOAD_ANIM_MOVE_RIGHT)) {
      _ui_screen_change(SCREEN_CONTACT_ADD, LV_SCR_LOAD_ANIM_MOVE_LEFT,
                        UI_ANIMATION_DURATION, 0);
    }
  }
}

// General Events
void ui_event_textarea_cb(lv_event_t *e) {
  const lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *ta = lv_event_get_target(e);
  const char *textData = lv_event_get_user_data(e);

  if (code == LV_EVENT_CLICKED) {
    if (strcmp(textData, "full") == 0) {
      if (ui_keyboard_full == NULL) {
        ui_keyboard_full = lv_keyboard_create(lv_screen_active());
        lv_obj_add_event_cb(ui_keyboard_full, ui_event_keyboard_cb,
                            LV_EVENT_ALL, "keyboard full");
      }
      lv_keyboard_set_textarea(ui_keyboard_full, ta);
    } else if (strcmp(textData, "num") == 0) {
      if (ui_keyboard_num == NULL) {
        ui_keyboard_num = lv_keyboard_create(lv_screen_active());
        lv_obj_add_event_cb(ui_keyboard_num, ui_event_keyboard_cb, LV_EVENT_ALL,
                            "keyboard num");
        lv_keyboard_set_mode(ui_keyboard_num, LV_KEYBOARD_MODE_NUMBER);
      }
      lv_keyboard_set_textarea(ui_keyboard_num, ta);
    }
  }

  if (code == LV_EVENT_DEFOCUSED) {
    if (strcmp(textData, "full") == 0) {
      if (ui_keyboard_full) {
        lv_obj_del(ui_keyboard_full);
        ui_keyboard_full = NULL;
      }
    } else if (strcmp(textData, "num") == 0) {
      if (ui_keyboard_num) {
        lv_obj_del(ui_keyboard_num);
        ui_keyboard_num = NULL;
      }
    }
  }
}

void ui_event_keyboard_cb(lv_event_t *e) {
  const lv_event_code_t code = lv_event_get_code(e);
  const lv_obj_t *target = lv_event_get_target(e);
  const char *keyboardData = lv_event_get_user_data(e);

  if (code == LV_EVENT_READY || code == LV_EVENT_CANCEL) {
    if (strcmp(keyboardData, "keyboard full") == 0) {
      lv_obj_delete(ui_keyboard_full);
      ui_keyboard_full = NULL;
    } else if (strcmp(keyboardData, "keyboard num") == 0) {
      lv_obj_delete(ui_keyboard_num);
      ui_keyboard_num = NULL;
    } else if (strcmp(keyboardData, "sim unlock") == 0) {
      lv_obj_t *uData = lv_event_get_user_data(e);

      const char *txt = lv_buttonmatrix_get_button_text(
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

void ui_event_slider_cb(lv_event_t *e) {
  const lv_event_code_t code = lv_event_get_code(e);
  const lv_obj_t *target = lv_event_get_target(e);
  const char *sliderData =
      (const char *)(const char *)lv_event_get_user_data(e);

  if (code == LV_EVENT_VALUE_CHANGED) {
    if (strcmp(sliderData, "settings brightness") == 0) {
      lv_utils_setBrightness(lv_slider_get_value(target));

      const uint8_t brightnessPercentage =
          ((float)screenBrightnessLevel / (float)UI_BRIGHTNESS_SLIDER_MAX) *
          100;
      char sBrightness[5];
      lv_snprintf(sBrightness, 5, "%d%%", brightnessPercentage);

      lv_label_set_text(ui_lblBrightnessValue, sBrightness);
    }
  }
}

void ui_event_dropdown_cb(lv_event_t *e) {
  const lv_event_code_t code = lv_event_get_code(e);
  const lv_obj_t *target = lv_event_get_target(e);
  const char *dropdownData = lv_event_get_user_data(e);

  const uint32_t selected = lv_dropdown_get_selected(target);

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
    } else if (strcmp(dropdownData, "ts timezone select") == 0) {
      lv_utils_setTimeZone(selected);
    }
  }
}

void ui_event_switch_cb(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  const char *switchData =
      (const char *)(const char *)lv_event_get_user_data(e);

  bool switchOn = lv_obj_has_state(target, LV_STATE_CHECKED);

  if (code == LV_EVENT_VALUE_CHANGED) {
    if (strcmp(switchData, "theme switch") == 0) {
      lv_utils_setTheme(switchOn);
    } else if (strcmp(switchData, "bt ble switch") == 0) {
      lv_utils_setBluetooth(switchOn);

      if (switchOn) {
        lv_label_set_text(ui_lblBtScanning, "Scanning...");
        lv_obj_remove_flag(ui_spinnerBtScanning, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(ui_listBLEFoundDevices, LV_OBJ_FLAG_HIDDEN);
      } else {
        lv_label_set_text(ui_lblBtScanning, "Bluetooth OFF");
        lv_obj_add_flag(ui_spinnerBtScanning, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_listBLEFoundDevices, LV_OBJ_FLAG_HIDDEN);
      }
    } else if (strcmp(switchData, "wifi switch") == 0) {
      lv_utils_setWiFi(switchOn);

      if (switchOn) {
        lv_label_set_text(ui_lblWiFiScanning, "Scanning...");
        lv_obj_remove_flag(ui_spinnerWiFiScanning, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(ui_listWiFiFoundDevices, LV_OBJ_FLAG_HIDDEN);
      } else {
        lv_label_set_text(ui_lblWiFiScanning, "WiFi OFF");
        lv_obj_add_flag(ui_spinnerWiFiScanning, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_listWiFiFoundDevices, LV_OBJ_FLAG_HIDDEN);
      }
    }
  }
}

void ui_event_checkbox_cb(lv_event_t *e) {
  const lv_event_code_t code = lv_event_get_code(e);
  const lv_obj_t *target = lv_event_get_target(e);
  const char *checkboxData = lv_event_get_user_data(e);

  if (code == LV_EVENT_VALUE_CHANGED) {
    if (strcmp(checkboxData, "time auto sync") == 0) {
      syncTimeAutomatically = lv_obj_has_state(target, LV_STATE_CHECKED);
      if (syncTimeAutomatically) {
        lv_obj_add_state(ui_timeScreenInputHour, LV_STATE_DISABLED);
        lv_obj_add_state(ui_timeScreenInputMinute, LV_STATE_DISABLED);
      } else {
        lv_obj_remove_state(ui_timeScreenInputHour, LV_STATE_DISABLED);
        lv_obj_remove_state(ui_timeScreenInputMinute, LV_STATE_DISABLED);
      }

      lv_utils_updateSyncTime();
    }
  }
}

void ui_event_image_cb(lv_event_t *e) {}

void ui_event_label_cb(lv_event_t *e) {
  const lv_event_code_t code = lv_event_get_code(e);
  const char *labelData = lv_event_get_user_data(e);

  if (code == LV_EVENT_CLICKED) {
    if (strcmp(labelData, "time home") == 0) {
      if (screenStackPush(SCREEN_HOME, LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(SCREEN_TIME_MAIN, LV_SCR_LOAD_ANIM_FADE_ON,
                          UI_ANIMATION_DURATION, 0);
      }
    } else if (strcmp(labelData, "contact discard") == 0) {
      const ScreenStackElement prevScreen = screenStackPop();

      _ui_screen_change(prevScreen.screen, prevScreen.transitionAnimation,
                        UI_ANIMATION_DURATION, 0);
    } else if (strcmp(labelData, "contact save") == 0) {
      strlcpy(contactSaveName, lv_textarea_get_text(ui_txtContactAddName),
              sizeof(contactSaveName));

      strlcpy(contactSaveNumber, lv_textarea_get_text(ui_txtContactAddNumber),
              sizeof(contactSaveNumber));

      ui_utils_trim(contactSaveName, " ");
      ui_utils_trim(contactSaveNumber, " ");

      LV_LOG_USER("Name: '%s'\tNumber: '%s'", contactSaveName,
                  contactSaveNumber);

      if (strlen(contactSaveName) < 3) {
        LV_LOG_USER("Name too short. The name '%s' has %d characters!",
                    contactSaveName, strlen(contactSaveName));
        return;
      }

      if (strlen(contactSaveNumber) < 11) {
        LV_LOG_USER("Invalid contact number '%s'. Only has %d characters!",
                    contactSaveNumber, strlen(contactSaveNumber));
        return;
      }

      if (contactSaveNumber[0] != '+') {
        LV_LOG_USER(
            "The phone number should include a country code. You entered '%s'!",
            contactSaveNumber);
        return;
      }

      //   const ScreenStackElement prevScreen = screenStackPop();

      //   _ui_screen_change(prevScreen.screen, prevScreen.transitionAnimation,
      //                     UI_ANIMATION_DURATION, 0);

      shouldSaveContact = true;
      // TODO: Go back to the previous page
    } else if (strcmp(labelData, "wallpaper select") > 0) {
      const char delimiter[] = " ";

      char wallpaperTag[19];
      strcpy(wallpaperTag, labelData);

      const char *token = strtok(wallpaperTag, delimiter);
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

void ui_event_button_cb(lv_event_t *e) {
  const lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  const char *buttonData = lv_event_get_user_data(e);

  if (code == LV_EVENT_CLICKED) {
    if (strcmp(buttonData, "calendar discard") == 0) {
      char bufDate[11];  // DD/MM/YYYY
      lv_utils_getDate(bufDate);

      const uint32_t year = atoi(bufDate + 6);
      const uint32_t month = atoi(bufDate + 3);
      const uint32_t day = atoi(bufDate);

      lv_calendar_set_today_date(ui_calendar, year, month, day);

      lv_obj_add_state(ui_btnCalendarApply, LV_STATE_DISABLED);
      lv_obj_add_state(ui_btnCalendarDiscard, LV_STATE_DISABLED);
    } else if (strcmp(buttonData, "calendar update") == 0) {
      const lv_calendar_date_t *date = lv_calendar_get_today_date(ui_calendar);
      lv_utils_setDate(date->year, date->month, date->day);

      lv_obj_add_state(ui_btnCalendarApply, LV_STATE_DISABLED);
      lv_obj_add_state(ui_btnCalendarDiscard, LV_STATE_DISABLED);
    } else if (strcmp(buttonData, "wallpaper apply") == 0) {
      lv_image_cache_drop(NULL);

      lv_utils_setWallpaper(clickedWallpaperImage, true);

      const ScreenStackElement prevScreen = screenStackPop();
      lv_utils_initScreen(prevScreen.screen);

      _ui_screen_change(prevScreen.screen, prevScreen.transitionAnimation,
                        UI_ANIMATION_DURATION, 0);
    } else if (strcmp(buttonData, "contact option") == 0) {
    } else if (strcmp(buttonData, "contact list") == 0) {
      // FIXME: confirm the working of this and remove
      const char *contact = lv_list_get_button_text(ui_listContact, target);
      char contactData[CONTACT_NAME_NUMBER_LENGTH];
      strcpy(contactData, contact);

      const char *token = strtok(contactData, contactSeparationDelimiter);
      if (token != NULL) {
        strlcpy(contactName, token, sizeof(contactName));
        token = strtok(NULL, contactSeparationDelimiter);
        if (token != NULL) {
          strlcpy(contactNumber, token, sizeof(contactNumber));
        }
      }
      if (screenStackPush(SCREEN_CONTACTS, LV_SCR_LOAD_ANIM_MOVE_RIGHT)) {
        _ui_screen_change(SCREEN_CONTACT_OPTIONS, LV_SCR_LOAD_ANIM_MOVE_LEFT,
                          UI_ANIMATION_DURATION, 0);

        lv_label_set_text(ui_lblContactDetailsTitle, (const char *)contactName);
      }
    } else if (strcmp(buttonData, "network option") == 0) {
      lv_obj_t *list = lv_obj_get_parent(target);
      const buttonText = lv_list_get_button_text(list, target);

      if (strcmp(buttonText, "WiFi") == 0) {
        if (screenStackPush(SCREEN_SETTINGS_NETWORK_INTERNET,
                            LV_SCR_LOAD_ANIM_MOVE_RIGHT)) {
          _ui_screen_change(SCREEN_SETTINGS_NETWORK_INTERNET_WIFI,
                            LV_SCR_LOAD_ANIM_MOVE_LEFT, UI_ANIMATION_DURATION,
                            0);
        }
      } else if (strcmp(buttonText, "GPRS") == 0) {
        if (screenStackPush(SCREEN_SETTINGS_NETWORK_INTERNET,
                            LV_SCR_LOAD_ANIM_MOVE_RIGHT)) {
          _ui_screen_change(SCREEN_SETTINGS_NETWORK_INTERNET_GPRS,
                            LV_SCR_LOAD_ANIM_MOVE_LEFT, UI_ANIMATION_DURATION,
                            0);
        }
      }
    } else if (strcmp(buttonData, "wifi connect") == 0) {
      // TODO: Display loading until connected, if connected go to prev screen
      const char *enteredPassword = lv_textarea_get_text(ui_txtWiFiPassword);
      strcpy(wifiPassword, enteredPassword);
      LV_LOG_USER("WiFi Password: '%s'\n", wifiPassword);

      lv_utils_connectWiFi();

      // TODO: don't go back if the connection was not successful
      const ScreenStackElement prevScreen = screenStackPop();
      _ui_screen_change(prevScreen.screen, prevScreen.transitionAnimation,
                        UI_ANIMATION_DURATION, 0);
    } else if (strcmp(buttonData, "ts time update") == 0) {
      const uint8_t hour = atoi(lv_textarea_get_text(ui_timeScreenInputHour));
      const uint8_t minute =
          atoi(lv_textarea_get_text(ui_timeScreenInputMinute));

      lv_utils_setTime(hour, minute, 0);
    } else if (strcmp(buttonData, "ts time cancel") == 0) {
      ui_timeScreenInputHour = currentTimeHour;
      ui_timeScreenInputMinute = currentTimeMinute;
    }
  }
}

void ui_event_msg_button_cb(lv_event_t *e) {
  const char *buttonData = lv_event_get_user_data(e);
  if (strcmp(buttonData, "delete") == 0) {
    shouldDeleteSelectedContact = true;
    lv_msgbox_close(ui_msgBoxContactDetails);
    LV_LOG_USER("Deleting '%s'", selectedContactName);
  } else if (strcmp(buttonData, "cancel") == 0) {
    lv_msgbox_close(ui_msgBoxContactDetails);
  }
}

void toggle_password_visibility_cb(lv_event_t *e) {
  const lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *eyeBtn = lv_event_get_target(e);
  lv_obj_t *txtPasswordField = lv_event_get_user_data(e);

  if (code == LV_EVENT_CLICKED) {
    const bool isPasswordMode = lv_textarea_get_password_mode(txtPasswordField);
    lv_textarea_set_password_mode(txtPasswordField, !isPasswordMode);

    if (isPasswordMode) {
      lv_obj_clear_flag(eyeBtn, LV_OBJ_FLAG_CHECKABLE);
      lv_label_set_text(eyeBtn, LV_SYMBOL_EYE_CLOSE);
    } else {
      lv_obj_clear_flag(eyeBtn, LV_OBJ_FLAG_CHECKABLE);
      lv_label_set_text(eyeBtn, LV_SYMBOL_EYE_OPEN);
    }
  }
}

void ui_event_list_button_cb(lv_event_t *e) {
  const lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  lv_obj_t *list = lv_obj_get_parent(target);

  const char *buttonData = lv_event_get_user_data(e);
  const char *buttonText = lv_list_get_button_text(list, target);

  if (code == LV_EVENT_CLICKED) {
    if (strcmp(buttonData, "contact option") == 0) {
      // Get the text of the option
      const char *optionText = lv_list_get_button_text(list, target);
      LV_LOG_USER("Selected contact option: %s", optionText);

      if (strcmp(optionText, "Delete") == 0) {
        // open a confirmation dialog
        ui_msgBoxContactDetails = lv_msgbox_create(NULL);
        char tmpDeleteTitle[7 + 30 + 1];
        lv_snprintf(tmpDeleteTitle, sizeof(tmpDeleteTitle), "Delete %s",
                    selectedContactName);
        lv_msgbox_add_title(ui_msgBoxContactDetails, tmpDeleteTitle);
        lv_msgbox_add_text(ui_msgBoxContactDetails,
                           "Are you sure you want to delete this contact?");
        lv_obj_set_width(ui_msgBoxContactDetails, 230);

        ui_msgBoxBtnPositiveContactDetails =
            lv_msgbox_add_footer_button(ui_msgBoxContactDetails, "Yes");
        lv_obj_set_style_bg_color(ui_msgBoxBtnPositiveContactDetails,
                                  lv_color_hex(0xf52222),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_width(ui_msgBoxBtnPositiveContactDetails, 90);
        lv_obj_add_event_cb(ui_msgBoxBtnPositiveContactDetails,
                            ui_event_msg_button_cb, LV_EVENT_CLICKED, "delete");

        ui_msgBoxBtnNegativeContactDetails =
            lv_msgbox_add_footer_button(ui_msgBoxContactDetails, "Cancel");
        lv_obj_set_style_bg_color(ui_msgBoxBtnNegativeContactDetails,
                                  lv_color_hex(0x27c22c),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_width(ui_msgBoxBtnNegativeContactDetails, 90);
        lv_obj_add_event_cb(ui_msgBoxBtnNegativeContactDetails,
                            ui_event_msg_button_cb, LV_EVENT_CLICKED, "cancel");
      } else if (strcmp(optionText, "Edit") == 0) {
        if (screenStackPush(SCREEN_CONTACTS, LV_SCR_LOAD_ANIM_MOVE_RIGHT)) {
          _ui_screen_change(SCREEN_CONTACT_EDIT, LV_SCR_LOAD_ANIM_MOVE_LEFT,
                            UI_ANIMATION_DURATION, 0);

          //   lv_textarea_set_text(ui_txtContactEditName, contactName);
          //   lv_textarea_set_text(ui_txtContactEditNumber, contactNumber);
        }
      }
    } else if (strcmp(buttonData, "contact list") == 0) {
      char contactData[CONTACT_NAME_NUMBER_LENGTH];
      strcpy(contactData, buttonText);

      ui_utils_name_number(contactData, selectedContactName,
                           selectedContactNumber);

      strcpy(contactName, selectedContactName);
      strcpy(contactNumber, selectedContactNumber);

      if (screenStackPush(SCREEN_CONTACTS, LV_SCR_LOAD_ANIM_MOVE_RIGHT)) {
        _ui_screen_change(SCREEN_CONTACT_OPTIONS, LV_SCR_LOAD_ANIM_MOVE_LEFT,
                          UI_ANIMATION_DURATION, 0);

        lv_label_set_text(ui_lblContactDetailsTitle, contactName);
      }
    } else if (strcmp(buttonData, "network option") == 0) {
      if (strcmp(buttonText, "WiFi") == 0) {
        if (screenStackPush(SCREEN_SETTINGS_NETWORK_INTERNET,
                            LV_SCR_LOAD_ANIM_MOVE_RIGHT)) {
          _ui_screen_change(SCREEN_SETTINGS_NETWORK_INTERNET_WIFI,
                            LV_SCR_LOAD_ANIM_MOVE_LEFT, UI_ANIMATION_DURATION,
                            0);
        }
      } else if (strcmp(buttonText, "GPRS") == 0) {
        if (screenStackPush(SCREEN_SETTINGS_NETWORK_INTERNET,
                            LV_SCR_LOAD_ANIM_MOVE_RIGHT)) {
          _ui_screen_change(SCREEN_SETTINGS_NETWORK_INTERNET_GPRS,
                            LV_SCR_LOAD_ANIM_MOVE_LEFT, UI_ANIMATION_DURATION,
                            0);
        }
      }
    }
  }
}

void ui_event_list_wifi_cb(lv_event_t *e) {
  lv_obj_t *target = lv_event_get_target(e);
  lv_obj_t *list = lv_obj_get_parent(target);

  const char *wifiNameData = (char *)(const char *)lv_event_get_user_data(e);
  const char *btnText = lv_list_get_button_text(list, target);

  LV_LOG_USER("WiFi Data: `%s`::`%d`", wifiNameData,
              strncmp(btnText, "*", 1) == 0);

  if (strncmp(btnText, "*", 1) == 0) {
    strcpy(wifiName, wifiNameData);
    LV_LOG_USER("WiFi Name: `%s`", wifiName);

    if (screenStackPush(SCREEN_SETTINGS_NETWORK_INTERNET_WIFI,
                        LV_SCR_LOAD_ANIM_MOVE_RIGHT)) {
      _ui_screen_change(SCREEN_SETTINGS_NETWORK_INTERNET_WIFI_PASSWORD,
                        LV_SCR_LOAD_ANIM_MOVE_LEFT, UI_ANIMATION_DURATION, 0);
    }
  } else {
    strcpy(wifiName, wifiNameData);
    strcpy(wifiPassword, "");  // clear the previous password

    lv_utils_connectWiFi();
  }
}
