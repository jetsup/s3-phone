#include "ui_utils.h"

char lvCurrentTime[6] = {};   // 10:15
char lvCurrentDate[15] = {};  // 15/03/2021 Fri

const char contactSeparationDelimeter[] = "-";
char contactName[30] = {};
char contactNumber[14] = {};

bool dateChanged = false;
int newYear = 0;
int newMonth = 0;
int newDay = 0;

ScreenStack screenStack;

// Settings Display
int screenBrightnessLevel = 100;
bool brightnessChanged = false;

const char screenTimeoutSeparationDelimeter[] = " - ";
unsigned int screenTimeout = 15;  // Initial: if 0 set screenInteractive false
bool timeoutChanged = false;
bool screenInteractive = true;
unsigned long previousScreenTouch = 0;

uint8_t dropdownSelectedTimeout = 0;

// Settings Theme
bool darkThemeSelected = false;
bool themeChanged = false;
char selectedWallpaper[20];
uint8_t screenWallpaperID = 1;
int clickedWallpaperImage = -1;
lv_image_dsc_t *screenWallpaperImg;
bool wallpaperChanged = false;

//================================Prototypes==============================
s3_resource_num_t lv_utils_getResourceByID(int id);
void lv_utils_refreshUI();
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

void lv_utils_setBrightness(int brightness) {
  screenBrightnessLevel = brightness;
  brightnessChanged = true;
}

void lv_utils_setScreenTimeout(unsigned int timeout) {
  screenTimeout = timeout;
  dropdownSelectedTimeout = lv_set_selected_timeout();
  timeoutChanged = true;
}

uint8_t lv_set_selected_timeout() {
  switch (screenTimeout) {
    case TIMEOUT_NEVER:
      return DROP_TIMEOUT_NEVER;
    case TIMEOUT_5_SEC:
      return DROP_TIMEOUT_5_SEC;
    case TIMEOUT_10_SEC:
      return DROP_TIMEOUT_10_SEC;
    case TIMEOUT_15_SEC:
      return DROP_TIMEOUT_15_SEC;
    case TIMEOUT_30_SEC:
      return DROP_TIMEOUT_30_SEC;
    case TIMEOUT_1_MIN:
      return DROP_TIMEOUT_1_MIN;
    case TIMEOUT_2_MIN:
      return DROP_TIMEOUT_2_MIN;
    case TIMEOUT_5_MIN:
      return DROP_TIMEOUT_5_MIN;
    case TIMEOUT_10_MIN:
      return DROP_TIMEOUT_10_MIN;
  }
}

void lv_utils_setTheme(bool themeDark) {
  if (darkThemeSelected != themeDark) {
    themeChanged = true;
    darkThemeSelected = themeDark;
    // TODO: Refresh the UI
  }
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

bool screenStackPush(s3_screens_t screen, lv_obj_t *previousScreen,
                     void (*previousScreenInit)(void),
                     lv_screen_load_anim_t transitionAnimation) {
  if (screenStackIsFull()) {
    // TODO: update the SCREEN_STACK_SIZE to make this condition unreachable
    return false;
  }

  screenStack.top++;
  screenStack.screenStackElements[screenStack.top].screen = screen;
  screenStack.screenStackElements[screenStack.top].previousScreen =
      previousScreen;
  screenStack.screenStackElements[screenStack.top].previousScreenInit =
      previousScreen;
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

lv_image_dsc_t *lv_utils_getImage(s3_resource_num_t imageID) {
  switch (imageID) {
    case 1:
      return &ui_img_bg1_png;
    case 2:
      return &ui_img_bg2_png;
    case 3:
      return &ui_img_bg3_png;
    case 4:
      return &ui_img_bg4_png;
    case 5:
      return &ui_img_bg5_png;
  }
}

void lv_utils_getResourceName(int resID, char *nameBuf) {
  s3_resource_num_t resS3ID = lv_utils_getResourceByID(resID);

  switch (resS3ID) {
    case S3_IMG_BACKGROUND_BEAUTIFUL_SUNSET: {
      strcpy(nameBuf, "Beautiful Sunset");
      return;
    }
    case S3_IMG_BACKGROUND_DOCK_SUNSET: {
      strcpy(nameBuf, "Dock Sunset");
      return;
    }
    case S3_IMG_BACKGROUND_NATURE_FOOTPATH: {
      strcpy(nameBuf, "Nature Pathway");
      return;
    }
    case S3_IMG_BACKGROUND_GREEN_LAKE: {
      strcpy(nameBuf, "Green Lake");
      return;
    }
    case S3_IMG_BACKGROUND_GREEN_FOREST: {
      strcpy(nameBuf, "Green Forest");
      return;
    }
  }
}

void lv_utils_setWallpaper(uint8_t wallpaperID, bool refreshUI) {
  s3_resource_num_t resId = lv_utils_getResourceByID(wallpaperID);
  screenWallpaperImg = lv_utils_getImage(resId);
  screenWallpaperID = wallpaperID;
  wallpaperChanged = true;

  lv_utils_getResourceName(wallpaperID, selectedWallpaper);
  // TODO: refresh the UI
  if (refreshUI) {
    lv_utils_refreshUI();
  }
}

s3_resource_num_t lv_utils_getResourceByID(int id) {
  switch (id) {
    case 1:
      return S3_IMG_BACKGROUND_BEAUTIFUL_SUNSET;
    case 2:
      return S3_IMG_BACKGROUND_DOCK_SUNSET;
    case 3:
      return S3_IMG_BACKGROUND_NATURE_FOOTPATH;
    case 4:
      return S3_IMG_BACKGROUND_GREEN_LAKE;
    case 5:
      return S3_IMG_BACKGROUND_GREEN_FOREST;
  }
}

void lv_utils_refreshUI() {
  // TODO: register all main pannels with translucent background here. Find a
  // better way of doing this

  //   lv_obj_set_style_bg_image_src(ui_panelBrowserMain, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelCalculatorMain, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelCalendarMain, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelContactAdd, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelContactDetails, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelContactMain, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelExtraMain, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelFilesMain, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelGalleryMain, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelGamesMain, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelPhoneMain, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelMainMenu, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelMessagesMain, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelMultimediaMain, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelMusicMain, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelMyZoneMain, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelPhoneMain, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelRadioMain, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelSettingsAbout, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelSettingsConnectivity,
  //                                 screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelSettingsDisplayMain,
  //   screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelSettingsLockSecurity,
  //                                 screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelSettingsMain, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelSettingsNetworkInternet,
  //                                 screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelSettingsSound, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelSettingsStorage,
  //   screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelSettingsSystem, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelSettingsTheme, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelSettingsThemeWallpaper,
  //                                 screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelSTKMain, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelTimeMain, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelTodoMain, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelToolsMain, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   lv_obj_set_style_bg_image_src(ui_panelVideoMain, screenWallpaperImg,
  //                                 LV_PART_MAIN | LV_STATE_DEFAULT);

  //   ui_homeScreen_screen_init();
  //   ui_mainMenuScreen_screen_init();
  //   ui_contactsScreen_screen_init();
  //   ui_alarmMainScreen_screen_init();
  //   ui_simPinScreen_screen_init();
  //   ui_splashScreen_screen_init();
  //   ui_contactAddScreen_screen_init();
  //   ui_contactOptionsScreen_screen_init();
  //   ui_settingsMainScreen_screen_init();
  //   ui_settingsDisplayScreen_screen_init();
  //   ui_settingsThemesScreen_screen_init();
  //   ui_settingsThemeWallpaperScreen_screen_init();
  //   ui_settingsLockSecurityScreen_screen_init();
  //   ui_settingsNetworkInternetScreen_screen_init();
  //   ui_settingsConnectivityScreen_screen_init();
  //   ui_settingsStorageScreen_screen_init();
  //   ui_settingsSoundScreen_screen_init();
  //   ui_settingsSystemScreen_screen_init();
  //   ui_settingsAboutScreen_screen_init();
  //   ui_timeScreen_screen_init();
  //   ui_calculatorScreen_screen_init();
  //   ui_calendarScreen_screen_init();
  //   ui_filesScreen_screen_init();
  //   ui_todoScreen_screen_init();
  //   ui_stkScreen_screen_init();
  //   ui_galleryScreen_screen_init();
  //   ui_musicScreen_screen_init();
  //   ui_radioScreen_screen_init();
  //   ui_videoScreen_screen_init();

//   ui_init();
}
