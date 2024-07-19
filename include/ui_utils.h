#ifndef UI_UTILS_H_
#define UI_UTILS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

extern char lvCurrentTime[6];
extern char lvCurrentDate[15];

#define CONTACT_NAME_NUMBER_LENGTH 44
extern const char contactSeparationDelimeter[4];
extern char contactName[30];
extern char contactNumber[14];

void ui_utils_updateTimeDate();

/**
 * @brief Creates a bottom bar with navigation buttons
 * @param parent The parent object
 * @param colorRGB The color of the icons
 * @param marginBottom The margin from the bottom. Preferred `-5`
 */
void ui_add_bottom_bar(lv_obj_t *parent, int colorRGB, int marginBottom);

#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // UI_UTILS_H_