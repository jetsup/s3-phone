#include "ui_utils.h"

char lvCurrentTime[6] = {};   // 10:15
char lvCurrentDate[15] = {};  // 15/03/2021 Fri

const char contactSeparationDelimeter[] = " - ";
char contactName[30] = {};
char contactNumber[14] = {};

bool dateChanged = false;
int newYear = 0;
int newMonth = 0;
int newDay = 0;

ScreenStack screenStack;

//================================UI Update===============================
void ui_utils_updateTimeDate() {
  lv_label_set_text(ui_lblHomeTime, lvCurrentTime);
  lv_label_set_text(ui_lblHomeDate, lvCurrentDate);
}

void lv_utils_getDate(char *buffer) { lv_strncpy(buffer, lvCurrentDate, 11); }

void lv_utils_setDate(int year, int month, int day) {
  newYear = year;
  newMonth = month;
  newDay = day;
  dateChanged = true;
}

void ui_add_bottom_bar(lv_obj_t *parent, int colorRGB, int marginBottom) {
  ui_bottomBar = lv_obj_create(parent);
  lv_obj_remove_style_all(ui_bottomBar);
  lv_obj_set_width(ui_bottomBar, 240);
  lv_obj_set_height(ui_bottomBar, 20);
  lv_obj_set_x(ui_bottomBar, 0);
  lv_obj_set_y(ui_bottomBar, marginBottom);
  lv_obj_set_align(ui_bottomBar, LV_ALIGN_BOTTOM_MID);
  lv_obj_set_flex_flow(ui_bottomBar, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(ui_bottomBar, LV_FLEX_ALIGN_SPACE_AROUND,
                        LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
  lv_obj_remove_flag(ui_bottomBar,
                     LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_lblBottombarTasks = lv_label_create(ui_bottomBar);
  lv_obj_set_width(ui_lblBottombarTasks, LV_SIZE_CONTENT);       /// 1
  lv_obj_set_height(ui_lblBottombarTasks, LV_SIZE_CONTENT);      /// 1
  lv_obj_add_flag(ui_lblBottombarTasks, LV_OBJ_FLAG_CLICKABLE);  /// Flags
  lv_label_set_text(ui_lblBottombarTasks, LV_SYMBOL_STOP);
  lv_obj_set_style_text_color(ui_lblBottombarTasks, lv_color_hex(colorRGB),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_lblBottombarTasks, 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_lblBottombarHome = lv_label_create(ui_bottomBar);
  lv_obj_set_width(ui_lblBottombarHome, LV_SIZE_CONTENT);       /// 1
  lv_obj_set_height(ui_lblBottombarHome, LV_SIZE_CONTENT);      /// 1
  lv_obj_add_flag(ui_lblBottombarHome, LV_OBJ_FLAG_CLICKABLE);  /// Flags
  lv_label_set_text(ui_lblBottombarHome, LV_SYMBOL_HOME);
  lv_obj_set_style_text_color(ui_lblBottombarHome, lv_color_hex(colorRGB),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_lblBottombarHome, 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_lblBottombarBack = lv_label_create(ui_bottomBar);
  lv_obj_set_width(ui_lblBottombarBack, LV_SIZE_CONTENT);       /// 1
  lv_obj_set_height(ui_lblBottombarBack, LV_SIZE_CONTENT);      /// 1
  lv_obj_add_flag(ui_lblBottombarBack, LV_OBJ_FLAG_CLICKABLE);  /// Flags
  lv_label_set_text(ui_lblBottombarBack, LV_SYMBOL_LEFT LV_SYMBOL_LEFT);
  lv_obj_set_style_text_color(ui_lblBottombarBack, lv_color_hex(colorRGB),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_lblBottombarBack, 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_add_event_cb(ui_lblBottombarTasks, ui_event_evtBottombar, LV_EVENT_ALL,
                      "navbar tasks");
  lv_obj_add_event_cb(ui_lblBottombarHome, ui_event_evtBottombar, LV_EVENT_ALL,
                      "navbar home");
  lv_obj_add_event_cb(ui_lblBottombarBack, ui_event_evtBottombar, LV_EVENT_ALL,
                      "navbar back");
}

//==============================Screen Stack==============================
bool screenStackInit() {
  screenStack.screenStackElements = (ScreenStackElement *)malloc(
      SCREEN_STACK_SIZE * sizeof(ScreenStackElement));

  if (screenStack.screenStackElements == NULL) {
    return false;
  }

  screenStack.top = -1;
  return true;
}

bool screenStackIsEmpty() { return screenStack.top == -1; }

bool screenStackIsFull() { return screenStack.top == SCREEN_STACK_SIZE - 1; }

bool screenStackPush(enum SCREENS screen,
                     lv_screen_load_anim_t transitionAnimation) {
  if (screenStackIsFull()) {
    // TODO: update the SCREEN_STACK_SIZE to make this condition unreachable
    return false;
  }

  screenStack.top++;
  screenStack.screenStackElements[screenStack.top].screen = screen;
  screenStack.screenStackElements[screenStack.top].transitionAnimation =
      transitionAnimation;
  return true;
}

ScreenStackElement screenStackPop() {
  if (screenStackIsEmpty()) {
    screenStack.top = -1;
    // return SCREEN_HOME;
  }
  return screenStack.screenStackElements[screenStack.top--];
}

ScreenStackElement screenStackPeek() {
  if (screenStackIsEmpty()) {
    // NULL
    return screenStack.screenStackElements[0];
  }
  return screenStack.screenStackElements[screenStack.top];
}

void screenStackEmpty() {
  while (!screenStackIsEmpty()) {
    screenStackPop();
  }
  // screenStackPush(SCREEN_HOME, LV_SCR_LOAD_ANIM_NONE);
}

int screenStackSize() { return screenStack.top + 1; }
