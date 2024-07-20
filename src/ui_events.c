#include "ui_events.h"

void ui_event_lblHomeTime(lv_event_t* e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t* target = lv_event_get_target(e);
  if (event_code == LV_EVENT_CLICKED) {
    _ui_screen_change(&ui_alarmMainScreen, LV_SCR_LOAD_ANIM_FADE_ON,
                      UI_ANIMATION_DURATION, 0,
                      &ui_alarmMainScreen_screen_init);
  }
}
void ui_event_imbClickEvent(lv_event_t* e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t* target = lv_event_get_target(e);

  const char* btnData = (const char*)e->user_data;

  if (event_code == LV_EVENT_CLICKED) {
    if (strcmp(btnData, "phone") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, ui_mainMenuScreen,
                          &ui_mainMenuScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(&ui_phoneScreen, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0,
                          &ui_phoneScreen_screen_init);
      }
    } else if (strcmp(btnData, "home phone") == 0) {
      if (screenStackPush(SCREEN_HOME, ui_homeScreen,
                          &ui_homeScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_LEFT)) {
        _ui_screen_change(&ui_phoneScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT,
                          UI_ANIMATION_DURATION, 0,
                          &ui_phoneScreen_screen_init);
      }
    } else if (strcmp(btnData, "messages") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, ui_mainMenuScreen,
                          &ui_mainMenuScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(&ui_messagesScreen, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0,
                          &ui_messagesScreen_screen_init);
      }
    } else if (strcmp(btnData, "home messages") == 0) {
      if (screenStackPush(SCREEN_HOME, ui_homeScreen,
                          &ui_homeScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_LEFT)) {
        _ui_screen_change(&ui_messagesScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT,
                          UI_ANIMATION_DURATION, 0,
                          &ui_messagesScreen_screen_init);
      }
    } else if (strcmp(btnData, "apps") == 0) {
      if (screenStackPush(SCREEN_HOME, ui_homeScreen,
                          &ui_homeScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(&ui_mainMenuScreen, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0,
                          &ui_mainMenuScreen_screen_init);
      }
    } else if (strcmp(btnData, "browser") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, ui_mainMenuScreen,
                          &ui_mainMenuScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(&ui_browserScreen, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0,
                          &ui_browserScreen_screen_init);
      }
    } else if (strcmp(btnData, "home browser") == 0) {
      if (screenStackPush(SCREEN_HOME, ui_homeScreen,
                          &ui_homeScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_RIGHT)) {
        _ui_screen_change(&ui_browserScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT,
                          UI_ANIMATION_DURATION, 0,
                          &ui_browserScreen_screen_init);
      }
    } else if (strcmp(btnData, "contacts") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, ui_mainMenuScreen,
                          &ui_mainMenuScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(&ui_contactsScreen, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0,
                          &ui_contactsScreen_screen_init);
      }
    } else if (strcmp(btnData, "home contacts") == 0) {
      if (screenStackPush(SCREEN_HOME, ui_homeScreen,
                          &ui_homeScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_RIGHT)) {
        _ui_screen_change(&ui_contactsScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT,
                          UI_ANIMATION_DURATION, 0,
                          &ui_contactsScreen_screen_init);
      }
    } else if (strcmp(btnData, "multimedia") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, ui_mainMenuScreen,
                          &ui_mainMenuScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(&ui_multimediaScreen, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0,
                          &ui_multimediaScreen_screen_init);
      }
    } else if (strcmp(btnData, "extra") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, ui_mainMenuScreen,
                          &ui_mainMenuScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(&ui_extraScreen, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0,
                          &ui_extraScreen_screen_init);
      }
    } else if (strcmp(btnData, "games") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, ui_mainMenuScreen,
                          &ui_mainMenuScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(&ui_gamesScreen, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0,
                          &ui_gamesScreen_screen_init);
      }
    } else if (strcmp(btnData, "my-zone") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, ui_mainMenuScreen,
                          &ui_mainMenuScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_TOP)) {
        _ui_screen_change(&ui_myZoneScreen, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0,
                          &ui_myZoneScreen_screen_init);
      }
    } else if (strcmp(btnData, "about") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, ui_mainMenuScreen,
                          &ui_mainMenuScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(&ui_settingsAboutScreen, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0,
                          &ui_settingsAboutScreen_screen_init);
      }
    } else if (strcmp(btnData, "tools") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, ui_mainMenuScreen,
                          &ui_mainMenuScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(&ui_toolsScreen, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0,
                          &ui_toolsScreen_screen_init);
      }
    } else if (strcmp(btnData, "settings") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, ui_mainMenuScreen,
                          &ui_mainMenuScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(&ui_settingsMainScreen, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0,
                          &ui_settingsMainScreen_screen_init);
      }
    } else if (strcmp(btnData, "clock") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, ui_mainMenuScreen,
                          &ui_mainMenuScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(&ui_timeScreen, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0, &ui_timeScreen_screen_init);
      }
    } else if (strcmp(btnData, "calculator") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, ui_mainMenuScreen,
                          &ui_mainMenuScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(&ui_calculatorScreen, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0,
                          &ui_calculatorScreen_screen_init);
      }
    } else if (strcmp(btnData, "calendar") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, ui_mainMenuScreen,
                          &ui_mainMenuScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(&ui_calendarScreen, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0,
                          &ui_calendarScreen_screen_init);
      }
    } else if (strcmp(btnData, "files") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, ui_mainMenuScreen,
                          &ui_mainMenuScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(&ui_filesScreen, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0,
                          &ui_filesScreen_screen_init);
      }
    } else if (strcmp(btnData, "todo") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, ui_mainMenuScreen,
                          &ui_mainMenuScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(&ui_todoScreen, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0, &ui_todoScreen_screen_init);
      }
    } else if (strcmp(btnData, "stk") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, ui_mainMenuScreen,
                          &ui_mainMenuScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(&ui_stkScreen, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0, &ui_stkScreen_screen_init);
      }
    } else if (strcmp(btnData, "contacts") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, ui_mainMenuScreen,
                          &ui_mainMenuScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(&ui_contactsScreen, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0,
                          &ui_contactsScreen_screen_init);
      }
    } else if (strcmp(btnData, "gallery") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, ui_mainMenuScreen,
                          &ui_mainMenuScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(&ui_galleryScreen, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0,
                          &ui_galleryScreen_screen_init);
      }
    } else if (strcmp(btnData, "music") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, ui_mainMenuScreen,
                          &ui_mainMenuScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(&ui_musicScreen, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0,
                          &ui_musicScreen_screen_init);
      }
    } else if (strcmp(btnData, "radio") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, ui_mainMenuScreen,
                          &ui_mainMenuScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(&ui_radioScreen, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0,
                          &ui_radioScreen_screen_init);
      }
    } else if (strcmp(btnData, "video") == 0) {
      if (screenStackPush(SCREEN_MAIN_MENU, ui_mainMenuScreen,
                          &ui_mainMenuScreen_screen_init,
                          LV_SCR_LOAD_ANIM_MOVE_BOTTOM)) {
        _ui_screen_change(&ui_videoScreen, LV_SCR_LOAD_ANIM_MOVE_TOP,
                          UI_ANIMATION_DURATION, 0,
                          &ui_videoScreen_screen_init);
      }
    }
  }
}
void ui_event_lblHomeContacts(lv_event_t* e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t* target = lv_event_get_target(e);
  if (event_code == LV_EVENT_CLICKED) {
    _ui_screen_change(&ui_contactsScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT,
                      UI_ANIMATION_DURATION, 0, &ui_contactsScreen_screen_init);
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
        _ui_screen_change(&ui_homeScreen, previousScreen.transitionAnimation,
                          UI_ANIMATION_DURATION, 0, &ui_homeScreen_screen_init);
      }
    } else if (strcmp(btnData, "navbar back") == 0) {
      if (!screenStackIsEmpty() && screenStackSize() > 0) {
        ScreenStackElement poppedScreen = screenStackPop();
        _ui_screen_change(
            &poppedScreen.previousScreen, poppedScreen.transitionAnimation,
            UI_ANIMATION_DURATION, 0, poppedScreen.previousScreenInit);
      } else {
        if (screenStackPush(SCREEN_HOME, ui_homeScreen,
                            &ui_homeScreen_screen_init,
                            LV_SCR_LOAD_ANIM_NONE)) {
          _ui_screen_change(&ui_homeScreen, LV_SCR_LOAD_ANIM_NONE,
                            UI_ANIMATION_DURATION, 0,
                            &ui_homeScreen_screen_init);
        }
      }
    } else if (strcmp(btnData, "navbar tasks") == 0) {
      // complex for now
      _ui_screen_change(&ui_homeScreen, LV_SCR_LOAD_ANIM_MOVE_TOP,
                        UI_ANIMATION_DURATION, 0, &ui_homeScreen_screen_init);
    }
  }
}

void ui_event_lblContactBack(lv_event_t* e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t* target = lv_event_get_target(e);
  if (event_code == LV_EVENT_CLICKED) {
    _ui_screen_change(&ui_homeScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT,
                      UI_ANIMATION_DURATION, 0, &ui_homeScreen_screen_init);
  }
}

void ui_event_fabContactAdd(lv_event_t* e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t* floatButton = lv_event_get_target(e);

  if (event_code == LV_EVENT_CLICKED) {
    if (screenStackPush(SCREEN_CONTACTS, ui_contactsScreen,
                        &ui_contactsScreen_screen_init,
                        LV_SCR_LOAD_ANIM_MOVE_RIGHT)) {
      _ui_screen_change(&ui_contactAddScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT,
                        UI_ANIMATION_DURATION, 0,
                        &ui_contactAddScreen_screen_init);
    }
  }
}

void ui_event_lblContactAddSave(lv_event_t* e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t* target = lv_event_get_target(e);

  if (event_code == LV_EVENT_CLICKED) {
    // TODO: will save the contact
    _ui_screen_change(&ui_contactsScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT,
                      UI_ANIMATION_DURATION, 0, &ui_contactsScreen_screen_init);
  }
}

void ui_event_lblContactAddDiscard(lv_event_t* e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t* target = lv_event_get_target(e);

  if (event_code == LV_EVENT_CLICKED) {
    _ui_screen_change(&ui_contactsScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT,
                      UI_ANIMATION_DURATION, 0, &ui_contactsScreen_screen_init);
  }
}

void ui_event_listContact(lv_event_t* e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t* target = lv_event_get_target(e);
  if (event_code == LV_EVENT_CLICKED) {
    const char* contact = lv_list_get_button_text(ui_listContact, target);
    char contactData[CONTACT_NAME_NUMBER_LENGTH];
    strcpy(contactData, contact);

    char* token;
    // FIXME: Handle words separated by " "
    token = strtok(contactData, contactSeparationDelimeter);
    if (token != NULL) {
      strlcpy(contactName, token, sizeof(contactName));
      token = strtok(NULL, contactSeparationDelimeter);
      if (token != NULL) {
        strlcpy(contactNumber, token, sizeof(contactNumber));
      }
    }
    screenStackPush(SCREEN_CONTACTS, ui_contactsScreen,
                    &ui_contactsScreen_screen_init,
                    LV_SCR_LOAD_ANIM_MOVE_RIGHT);
    _ui_screen_change(&ui_contactOptionsScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT,
                      UI_ANIMATION_DURATION, 0,
                      &ui_contactOptionsScreen_screen_init);
    lv_label_set_text(ui_lblContactDetailsTitle, (const char*)contactName);
  }
}

void ui_event_lblContactDetailsBack(lv_event_t* e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t* target = lv_event_get_target(e);
  if (event_code == LV_EVENT_CLICKED) {
    _ui_screen_change(&ui_contactsScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT,
                      UI_ANIMATION_DURATION, 0,
                      &ui_contactOptionsScreen_screen_init);
  }
}

void ui_event_listContactDetailsOptions(lv_event_t* e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t* target = lv_event_get_target(e);
  if (event_code == LV_EVENT_CLICKED) {
    LV_LOG_USER("Clicked: %s",
                lv_list_get_button_text(lv_obj_get_parent(target), target));
  }
}

void ui_event_btnOkPinPinScreen(lv_event_t* e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t* target = lv_event_get_target(e);
  if (event_code == LV_EVENT_CLICKED) {
    _ui_screen_change(&ui_homeScreen, LV_SCR_LOAD_ANIM_MOVE_BOTTOM,
                      UI_ANIMATION_DURATION, 0, &ui_homeScreen_screen_init);
  }
}

void ui_event_btnMatrixNumHandler(lv_event_t* e) {
  lv_obj_t* obj = lv_event_get_target(e);
  lv_obj_t* uData = lv_event_get_user_data(e);
  const char* txt = lv_buttonmatrix_get_button_text(
      obj, lv_buttonmatrix_get_selected_button(obj));

  if (lv_strcmp(txt, LV_SYMBOL_BACKSPACE) == 0)
    lv_textarea_delete_char(uData);
  else if (lv_strcmp(txt, LV_SYMBOL_NEW_LINE) == 0)
    lv_obj_send_event(uData, LV_EVENT_READY, NULL);
  else
    lv_textarea_add_text(uData, txt);
}

// General Events
void ui_event_textArea_full_cb(lv_event_t* e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t* ta = lv_event_get_target(e);
  if (code == LV_EVENT_CLICKED) {
    if (ui_keyboard_full == NULL) {
      ui_keyboard_full = lv_keyboard_create(lv_scr_act());
      lv_obj_add_event_cb(ui_keyboard_full, ui_event_keyboard_full_event_cb,
                          LV_EVENT_ALL, NULL);
    }
    lv_keyboard_set_textarea(ui_keyboard_full, ta);
  }

  if (code == LV_EVENT_DEFOCUSED) {
    if (ui_keyboard_full) {
      lv_obj_del(ui_keyboard_full);
      ui_keyboard_full = NULL;
    }
  }
}

void ui_event_textArea_num_cb(lv_event_t* e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t* ta = lv_event_get_target(e);

  if (code == LV_EVENT_CLICKED) {
    if (ui_keyboard_num == NULL) {
      ui_keyboard_num = lv_keyboard_create(lv_scr_act());
      lv_obj_add_event_cb(ui_keyboard_num, ui_event_keyboard_num_event_cb,
                          LV_EVENT_ALL, NULL);
      lv_keyboard_set_mode(ui_keyboard_num, LV_KEYBOARD_MODE_NUMBER);
    }
    lv_keyboard_set_textarea(ui_keyboard_num, ta);
  }

  if (code == LV_EVENT_DEFOCUSED) {
    if (ui_keyboard_num) {
      lv_obj_del(ui_keyboard_num);
      ui_keyboard_num = NULL;
    }
  }
}

void ui_event_keyboard_full_event_cb(lv_event_t* e) {
  lv_event_code_t code = lv_event_get_code(e);

  if (code == LV_EVENT_READY || code == LV_EVENT_CANCEL) {
    lv_obj_del(ui_keyboard_full);
    ui_keyboard_full = NULL;
  }
}

void ui_event_keyboard_num_event_cb(lv_event_t* e) {
  lv_event_code_t code = lv_event_get_code(e);

  if (code == LV_EVENT_READY || code == LV_EVENT_CANCEL) {
    lv_obj_del(ui_keyboard_num);
    ui_keyboard_num = NULL;
  }
}
