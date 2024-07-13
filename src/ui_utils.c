#include "ui_utils.h"

char lvCurrentTime[6] = {};   // 10:15
char lvCurrentDate[15] = {};  // 10/15/2021 Fri

const char contactSeparationDelimeter[] = " - ";
char contactName[30] = {};
char contactNumber[14] = {};

void ui_utils_updateTimeDate() {
  lv_label_set_text(ui_lblHomeTime, lvCurrentTime);
  lv_label_set_text(ui_lblHomeDate, lvCurrentDate);
}