#include "ui_contacts.h"

void contact_add_to_list(lv_obj_t* list, const char* text,
                         const char* symbol_icon, lv_event_cb_t event_cb/*,
                         lv_event_code_t filter, void* user_data*/) {
  lv_obj_t* btn;
  btn = lv_list_add_button(list, symbol_icon, text);
  lv_obj_add_event_cb(btn, event_cb, LV_EVENT_CLICKED, NULL);
}

void contacts_add_data(char* names[], char* numbers[], int count) {
  cCount = count;

  for (int i = 0; i < count; i++) {
    cNames[i] = names[i];
    cNumbers[i] = numbers[i];
  }
}

void contact_set_contact_list(lv_obj_t* list) {
  for (int i = 0; i < cCount; i++) {
    char nameNumber[55];
    strcpy(nameNumber, cNames[i]);
    strcat(nameNumber, " - ");
    strcat(nameNumber, cNumbers[i]);

    contact_add_to_list(list, nameNumber, LVC_SYMBOL_SD_CARD,
                        ui_event_listContact);
  }
}

void contacts_add_contact_to_array(char** names, char** numbers) {
  for (int i = 0; i < 4; i++) {
    cNames[i] = names[i];
    cNumbers[i] = numbers[i];
    cCount++;
  }
}