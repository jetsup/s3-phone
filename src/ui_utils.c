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
lv_theme_t *screenTheme;
bool themeApplied = false;

lv_font_t *systemFontSmall;
lv_font_t *systemFontMedium;
lv_font_t *systemFontLarge;
uint8_t sFont, mFont, lFont;
bool fontChanged = false;

char selectedWallpaper[20];
uint8_t screenWallpaperID = 1;
int clickedWallpaperImage = -1;
lv_image_dsc_t *screenWallpaperImg;
bool wallpaperChanged = false;

// Settings Connectivity
bool bluetoothLEEnabled = false;
bool bluetoothStatusChanged = false;

// Settings Network and Internet
volatile bool wifiEnabled = false;
bool wifiReady = false;
bool wifiStatusChanged = false;
bool wifiScreenVisible = false;
char wifiName[30];
char wifiPassword[30];
char discoveredWiFiNames[MAX_WIFI_DISCOVERABLE][MAX_WIFI_NAME_LENGTH];
int discoveredWiFiRSSI[MAX_WIFI_DISCOVERABLE];
bool discoveredWiFiOpen[MAX_WIFI_DISCOVERABLE];
uint8_t discoveredWiFiCount = 0;

//================================Prototypes==============================
s3_resource_num_t lv_utils_getResourceByID(int id);
lv_font_t *lv_utils_getFont(uint8_t fontSize);
//================================UI Update===============================
void ui_utils_updateTimeDate() {
  if (lv_obj_has_class(ui_lblHomeTime, (&lv_label_class)) &&
      lv_obj_has_class(ui_lblHomeDate, (&lv_label_class))) {
    lv_label_set_text(ui_lblHomeTime, lvCurrentTime);
    lv_label_set_text(ui_lblHomeDate, lvCurrentDate);
  }
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

void lv_utils_setFonts(uint8_t sFont, uint8_t mFont, uint8_t lFont) {
  systemFontSmall = lv_utils_getFont(sFont);
  systemFontMedium = lv_utils_getFont(mFont);
  systemFontLarge = lv_utils_getFont(lFont);
}

lv_font_t *lv_utils_getFont(uint8_t fontSize) {
  switch (fontSize) {
    case 8:
      return &lv_font_montserrat_8;
    case 10:
      return &lv_font_montserrat_10;
    case 12:
      return &lv_font_montserrat_12;
    case 14:
      return &lv_font_montserrat_14;
    case 16:
      return &lv_font_montserrat_16;
    case 18:
      return &lv_font_montserrat_18;
    case 20:
      return &lv_font_montserrat_20;
    case 22:
      return &lv_font_montserrat_22;
    case 24:
      return &lv_font_montserrat_24;
    case 26:
      return &lv_font_montserrat_26;
    case 28:
      return &lv_font_montserrat_28;
    case 30:
      return &lv_font_montserrat_30;
    case 32:
      return &lv_font_montserrat_32;
    case 34:
      return &lv_font_montserrat_34;
    case 36:
      return &lv_font_montserrat_38;
    case 38:
      return &lv_font_montserrat_38;
    case 40:
      return &lv_font_montserrat_40;
    case 42:
      return &lv_font_montserrat_42;
    case 44:
      return &lv_font_montserrat_44;
    case 46:
      return &lv_font_montserrat_46;
    case 48:
      return &lv_font_montserrat_48;
    default:
      return &lv_font_montserrat_10;
  }
}

void lv_utils_setTheme(bool themeDark) {
  if (darkThemeSelected != themeDark) {
    themeChanged = true;
    darkThemeSelected = themeDark;
    themeApplied = false;
  }
}

void lv_utils_applyTheme() {
  if (themeApplied) {
    return;
  }
  themeApplied = true;

  lv_color_t themeColorPrimary, themeColorSecondary;
  systemFontMedium = &lv_font_montserrat_14;
  if (darkThemeSelected) {
    themeColorPrimary.red = 5;
    themeColorPrimary.green = 2;
    themeColorPrimary.blue = 5;

    themeColorSecondary.red = 50;
    themeColorSecondary.green = 20;
    themeColorSecondary.blue = 50;
  } else {
    themeColorPrimary.red = 150;
    themeColorPrimary.green = 120;
    themeColorPrimary.blue = 150;

    themeColorSecondary.red = 250;
    themeColorSecondary.green = 220;
    themeColorSecondary.blue = 250;
  }
  screenTheme =
      lv_theme_default_init(lv_display, themeColorPrimary, themeColorPrimary,
                            darkThemeSelected, systemFontMedium);
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

bool screenStackPush(s3_screens_t screen,
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
    return (ScreenStackElement){SCREEN_HOME, NULL, LV_SCR_LOAD_ANIM_MOVE_RIGHT,
                                NULL};
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

  lv_image_cache_drop(screenWallpaperImg);

  lv_utils_getResourceName(wallpaperID, selectedWallpaper);
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

void lv_utils_setBluetooth(bool bleEnabled) {
  bluetoothLEEnabled = bleEnabled;
  bluetoothStatusChanged = true;
}

void lv_utils_setWiFi(bool wifiState) {
  wifiEnabled = wifiState;
  wifiStatusChanged = true;
}

void lv_utils_populate_list_options(lv_obj_t *list, const char **listOptions,
                                    int optionsCount, lv_event_t *evt,
                                    lv_event_code_t eventFilter,
                                    const char *callbackData) {
  for (int i = 0; i < optionsCount; i++) {
    lv_obj_t *btn = lv_list_add_button(list, NULL, listOptions[i]);
    lv_obj_set_style_bg_opa(btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(btn, evt, eventFilter, callbackData);
  }
}

void lv_utils_refreshWiFiList() {
  // TODO: Find a way to clear the list
  // '*' + 'WiFi Name' + ' ' + '(' + 'rssi' + ')'
  char wifiOption[MAX_WIFI_NAME_LENGTH + 8];

  for (int i = 0; i < discoveredWiFiCount; i++) {
    memset(wifiOption, 0, sizeof(wifiOption));

    if (!discoveredWiFiOpen[i]) {
      strcat(wifiOption, "*");
    }
    strcat(wifiOption, discoveredWiFiNames[i]);
    strcat(wifiOption, " (");
    char rssi[5];
    itoa(discoveredWiFiRSSI[i], rssi, 10 /*base*/);
    strcat(wifiOption, rssi);
    strcat(wifiOption, ")");

    lv_obj_t *btn =
        lv_list_add_button(ui_listWiFiFoundDevices, LV_SYMBOL_WIFI, wifiOption);
    lv_obj_set_style_bg_opa(btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(btn, ui_event_list_button_cb, LV_EVENT_CLICKED,
                        "wifi name");
  }
}

void lv_utils_resetScreenVisibility() { wifiScreenVisible = false; }
