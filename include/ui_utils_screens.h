#ifndef UI_UTILS_SCREENS_H_
#define UI_UTILS_SCREENS_H_

#include "ui.h"

/**
 * @brief call the initialization function fro the specified `screen`
 * @param screen The screen to initialize
 */
void lv_utils_initScreen(s3_screens_t screen);

/**
 * @return The screen object of the `screen` specified
 */
lv_obj_t* lv_utils_getScreen(s3_screens_t screen);

/**
 * @deprecated Initial trial, replaced with `lv_utils_initScreen`
 * @brief Get the screen setup function of the specified `screen`
 */
void* lv_utils_getScreenInit(s3_screens_t screen);

#endif  // UI_UTILS_SCREENS_H_
