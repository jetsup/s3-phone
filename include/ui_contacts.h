#ifndef UI_CONFIG_H_
#define UI_CONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

// ===========================CONTACT DETAILS============================
extern char contactOptions[9][18];

// ===============================CONTACTS===============================
#define MAX_CONTACTS 254
#define MAX_CONTACT_NAME_LENGTH 30
#define MAX_CONTACT_NUMBER_LENGTH 14

extern char* cNames[MAX_CONTACTS];
extern char* cNumbers[MAX_CONTACTS];
extern int cCount;

void contact_add_to_list(lv_obj_t* list, const char* text,
                         const char* symbol_icon, lv_event_cb_t event_cb/*,
                         lv_event_code_t filter, void* user_data*/);

/**
 * @brief Set the contact list and display it
 * @param names The names of the contacts
 * @param numbers The numbers of the contacts
 * @param count The number of contacts
 * @return void
 */
void contact_set_contact_list(lv_obj_t* list);
// void contact_set_contact_list( char** names,  char** numbers,
//                               int count);

void contacts_add_data(char* name[], char* number[], int count);

void contacts_add_contact_to_array(char** name, char** number);

// ===============================CONTACT DETAILS===============================
void contact_details_set_options_list(lv_obj_t* list);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif  // UI_CONFIG_H_