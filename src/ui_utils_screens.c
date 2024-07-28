#include "ui_utils_screens.h"

void lv_utils_initScreen(s3_screens_t screen) {
  switch (screen) {
    case SCREEN_HOME:
      ui_homeScreen_screen_init();
      return;
    case SCREEN_MAIN_MENU:
      ui_mainMenuScreen_screen_init();
      return;
    case SCREEN_PHONE:
      ui_phoneScreen_screen_init();
      return;
    case SCREEN_CONTACTS:
      ui_contactsScreen_screen_init();
      return;
    case SCREEN_CONTACT_OPTIONS:
      ui_contactOptionsScreen_screen_init();
      return;
    case SCREEN_CONTACT_ADD:
      ui_contactAddScreen_screen_init();
      return;
    case SCREEN_MESSAGES:
      ui_messagesScreen_screen_init();
      return;
    case SCREEN_SIM_PIN_UNLOCK:
      ui_simPinScreen_screen_init();
      return;
    case SCREEN_ALARM_MAIN:
      ui_alarmMainScreen_screen_init();
      return;
    case SCREEN_SETTINGS:
      ui_settingsMainScreen_screen_init();
      return;
    case SCREEN_SETTINGS_CONNECTIVITY:
      ui_settingsConnectivityScreen_screen_init();
      return;
    case SCREEN_SETTINGS_CONNECTIVITY_BLE:
      ui_settingsConnectivityBLEScreen_screen_init();
      return;
    case SCREEN_SETTINGS_NETWORK_INTERNET:
      ui_settingsNetworkInternetScreen_screen_init();
      return;
    case SCREEN_SETTINGS_NETWORK_INTERNET_WIFI:
      ui_settingsNetworkInternetWiFiScreen_screen_init();
      return;
    case SCREEN_SETTINGS_NETWORK_INTERNET_GPRS:
      ui_settingsNetworkInternetGPRSScreen_screen_init();
      return;
    case SCREEN_SETTINGS_DISPLAY:
      ui_settingsDisplayScreen_screen_init();
      return;
    case SCREEN_SETTINGS_THEMES:
      ui_settingsThemesScreen_screen_init();
      return;
    case SCREEN_SETTINGS_THEMES_WALLPAPERS:
      ui_settingsThemeWallpaperScreen_screen_init();
      return;
    case SCREEN_SETTINGS_LOCK_SCREEN_SECURITY:
      ui_settingsLockSecurityScreen_screen_init();
      return;
    case SCREEN_SETTINGS_SOUND:
      ui_settingsSoundScreen_screen_init();
      return;
    case SCREEN_SETTINGS_STORAGE:
      ui_settingsStorageScreen_screen_init();
      return;
    case SCREEN_SETTINGS_SYSTEM:
      ui_settingsSystemScreen_screen_init();
      return;
    case SCREEN_SETTINGS_ABOUT:
      ui_settingsAboutScreen_screen_init();
      return;
    case SCREEN_TIME_MAIN:
      ui_timeScreen_screen_init();
      return;
    case SCREEN_CALCULATOR:
      ui_calculatorScreen_screen_init;
      return;
    case SCREEN_CALENDAR:
      ui_calendarScreen_screen_init();
      return;
    case SCREEN_FILES_MAIN:
      ui_filesScreen_screen_init();
      return;
    case SCREEN_TODO_MAIN:
      ui_todoScreen_screen_init();
      return;
    case SCREEN_STK_MAIN:
      ui_stkScreen_screen_init();
      return;
    case SCREEN_GALLERY_MAIN:
      ui_galleryScreen_screen_init();
      return;
    case SCREEN_MUSIC_MAIN:
      ui_musicScreen_screen_init();
      return;
    case SCREEN_RADIO_MAIN:
      ui_radioScreen_screen_init();
      return;
    case SCREEN_VIDEO_MAIN:
      ui_videoScreen_screen_init();
      return;
    case SCREEN_MULTIMEDIA_MAIN:
      ui_multimediaScreen_screen_init();
      return;
    case SCREEN_EXTRA_MAIN:
      ui_extraScreen_screen_init();
      return;
    case SCREEN_GAMES_MAIN:
      ui_gamesScreen_screen_init();
      return;
    case SCREEN_MY_ZONE_MAIN:
      ui_myZoneScreen_screen_init();
      return;
    case SCREEN_TOOLS_MAIN:
      ui_toolsScreen_screen_init();
      return;
    case SCREEN_BROWSER_MAIN:
      ui_browserScreen_screen_init();
      return;
    default:
      LV_LOG_USER("Screen not defined");
      while (1);
  }
}

lv_obj_t* lv_utils_getScreen(s3_screens_t screen) {
  switch (screen) {
    case SCREEN_HOME:
      return ui_homeScreen;
    case SCREEN_MAIN_MENU:
      return ui_mainMenuScreen;
    case SCREEN_PHONE:
      return ui_phoneScreen;
    case SCREEN_CONTACTS:
      return ui_contactsScreen;
    case SCREEN_CONTACT_OPTIONS:
      return ui_contactOptionsScreen;
    case SCREEN_CONTACT_ADD:
      return ui_contactAddScreen;
    case SCREEN_MESSAGES:
      return ui_messagesScreen;
    case SCREEN_SIM_PIN_UNLOCK:
      return ui_simPinScreen;
    case SCREEN_ALARM_MAIN:
      return ui_alarmMainScreen;
    case SCREEN_SETTINGS:
      return ui_settingsMainScreen;
    case SCREEN_SETTINGS_CONNECTIVITY:
      return ui_settingsConnectivityScreen;
    case SCREEN_SETTINGS_CONNECTIVITY_BLE:
      return ui_settingsConnectivityBLEScreen;
    case SCREEN_SETTINGS_NETWORK_INTERNET:
      return ui_settingsNetworkInternetScreen;
    case SCREEN_SETTINGS_NETWORK_INTERNET_WIFI:
      return ui_settingsNetworkInternetWiFiScreen;
    case SCREEN_SETTINGS_NETWORK_INTERNET_GPRS:
      return ui_settingsNetworkInternetGPRSScreen;
    case SCREEN_SETTINGS_DISPLAY:
      return ui_settingsDisplayScreen;
    case SCREEN_SETTINGS_THEMES:
      return ui_settingsThemesScreen;
    case SCREEN_SETTINGS_THEMES_WALLPAPERS:
      return ui_settingsThemeWallpaperScreen;
    case SCREEN_SETTINGS_LOCK_SCREEN_SECURITY:
      return ui_settingsLockSecurityScreen;
    case SCREEN_SETTINGS_SOUND:
      return ui_settingsSoundScreen;
    case SCREEN_SETTINGS_STORAGE:
      return ui_settingsStorageScreen;
    case SCREEN_SETTINGS_SYSTEM:
      return ui_settingsSystemScreen;
    case SCREEN_SETTINGS_ABOUT:
      return ui_settingsAboutScreen;
    case SCREEN_TIME_MAIN:
      return ui_timeScreen;
    case SCREEN_CALCULATOR:
      return ui_calculatorScreen;
    case SCREEN_CALENDAR:
      return ui_calendarScreen;
    case SCREEN_FILES_MAIN:
      return ui_filesScreen;
    case SCREEN_TODO_MAIN:
      return ui_todoScreen;
    case SCREEN_STK_MAIN:
      return ui_stkScreen;
    case SCREEN_GALLERY_MAIN:
      return ui_galleryScreen;
    case SCREEN_MUSIC_MAIN:
      return ui_musicScreen;
    case SCREEN_RADIO_MAIN:
      return ui_radioScreen;
    case SCREEN_VIDEO_MAIN:
      return ui_videoScreen;
    case SCREEN_MULTIMEDIA_MAIN:
      return ui_multimediaScreen;
    case SCREEN_EXTRA_MAIN:
      return ui_extraScreen;
    case SCREEN_GAMES_MAIN:
      return ui_gamesScreen;
    case SCREEN_MY_ZONE_MAIN:
      return ui_myZoneScreen;
    case SCREEN_TOOLS_MAIN:
      return ui_toolsScreen;
    case SCREEN_BROWSER_MAIN:
      return ui_browserScreen;
    default:
      LV_LOG_USER("Screen not found");
      while (1);
  }
}

void* lv_utils_getScreenInit(s3_screens_t screen) {
  switch (screen) {
    case SCREEN_HOME:
      return &ui_homeScreen_screen_init;
    case SCREEN_MAIN_MENU:
      return &ui_mainMenuScreen_screen_init;
    case SCREEN_PHONE:
      return &ui_phoneScreen_screen_init;
    case SCREEN_CONTACTS:
      return &ui_contactsScreen_screen_init;
    case SCREEN_CONTACT_OPTIONS:
      return &ui_contactOptionsScreen_screen_init;
    case SCREEN_CONTACT_ADD:
      return &ui_contactAddScreen_screen_init;
    case SCREEN_MESSAGES:
      return &ui_messagesScreen_screen_init;
    case SCREEN_SIM_PIN_UNLOCK:
      return &ui_simPinScreen_screen_init;
    case SCREEN_ALARM_MAIN:
      return &ui_alarmMainScreen_screen_init;
    case SCREEN_SETTINGS:
      return &ui_settingsMainScreen_screen_init;
    case SCREEN_SETTINGS_CONNECTIVITY:
      return &ui_settingsConnectivityScreen_screen_init;
    case SCREEN_SETTINGS_CONNECTIVITY_BLE:
      return &ui_settingsConnectivityBLEScreen_screen_init;
    case SCREEN_SETTINGS_NETWORK_INTERNET:
      return &ui_settingsNetworkInternetScreen_screen_init;
    case SCREEN_SETTINGS_DISPLAY:
      return &ui_settingsDisplayScreen_screen_init;
    case SCREEN_SETTINGS_THEMES:
      return &ui_settingsThemesScreen_screen_init;
    case SCREEN_SETTINGS_THEMES_WALLPAPERS:
      return &ui_settingsThemeWallpaperScreen_screen_init;
    case SCREEN_SETTINGS_LOCK_SCREEN_SECURITY:
      return &ui_settingsLockSecurityScreen_screen_init;
    case SCREEN_SETTINGS_SOUND:
      return &ui_settingsSoundScreen_screen_init;
    case SCREEN_SETTINGS_STORAGE:
      return &ui_settingsStorageScreen_screen_init;
    case SCREEN_SETTINGS_SYSTEM:
      return &ui_settingsSystemScreen_screen_init;
    case SCREEN_SETTINGS_ABOUT:
      return &ui_settingsAboutScreen_screen_init;
    case SCREEN_TIME_MAIN:
      return &ui_timeScreen_screen_init;
    case SCREEN_CALCULATOR:
      return &ui_calculatorScreen_screen_init;
    case SCREEN_CALENDAR:
      return &ui_calendarScreen_screen_init;
    case SCREEN_FILES_MAIN:
      return &ui_filesScreen_screen_init;
    case SCREEN_TODO_MAIN:
      return &ui_todoScreen_screen_init;
    case SCREEN_STK_MAIN:
      return &ui_stkScreen_screen_init;
    case SCREEN_GALLERY_MAIN:
      return &ui_galleryScreen_screen_init;
    case SCREEN_MUSIC_MAIN:
      return &ui_musicScreen_screen_init;
    case SCREEN_RADIO_MAIN:
      return &ui_radioScreen_screen_init;
    case SCREEN_VIDEO_MAIN:
      return &ui_videoScreen_screen_init;
    case SCREEN_MULTIMEDIA_MAIN:
      return &ui_multimediaScreen_screen_init;
    case SCREEN_EXTRA_MAIN:
      return &ui_extraScreen_screen_init;
    case SCREEN_GAMES_MAIN:
      return &ui_gamesScreen_screen_init;
    case SCREEN_MY_ZONE_MAIN:
      return &ui_myZoneScreen_screen_init;
    case SCREEN_TOOLS_MAIN:
      return &ui_toolsScreen_screen_init;
    case SCREEN_BROWSER_MAIN:
      return &ui_browserScreen_screen_init;
    default:
      LV_LOG_USER("Screen not defined");
      while (1);
  }
}
