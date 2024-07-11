#ifndef UI_UTILS_H_
#define UI_UTILS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

extern char lvCurrentTime[6];
extern char lvCurrentDate[15];

void ui_utils_updateTimeDate();

#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // UI_UTILS_H_