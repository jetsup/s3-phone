#ifndef _S3_PHONE_UI_H
#define _S3_PHONE_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

#include <CustomSymbols.hpp>

#include "ui_constants.h"
#include "ui_events.h"
#include "ui_helpers.h"
#include "ui_utils.h"

// SCREEN: ui_homeScreen
void ui_homeScreen_screen_init(void);
extern lv_obj_t* ui_homeScreen;
extern lv_obj_t* ui_panelMain;
extern lv_obj_t* ui_homeContainerTopBar;
extern lv_obj_t* ui_lblHomeBatteryLevel;
extern lv_obj_t* ui_lblHomeSignalLevel;
extern lv_obj_t* ui_homeContainerDateISP;
extern lv_obj_t* ui_lblHomeTime;
extern lv_obj_t* ui_lblHomeDate;
extern lv_obj_t* ui_lblHomeISP;
extern lv_obj_t* ui_homeContainerStart;
extern lv_obj_t* ui_imbHomePhone;
extern lv_obj_t* ui_imbHomeMessages;
extern lv_obj_t* ui_imbHomeApps;
extern lv_obj_t* ui_imbHomeBrowser;
extern lv_obj_t* ui_imbHomeContacts;
// SCREEN: ui_mainMenuScreen
void ui_mainMenuScreen_screen_init(void);
extern lv_obj_t* ui_mainMenuScreen;
extern lv_obj_t* ui_panelMainMenu;
extern lv_obj_t* ui_menuMainContainer;
extern lv_obj_t* ui_menuPhoneContainer;
extern lv_obj_t* ui_imbPhone;
extern lv_obj_t* ui_lblMenuPhone;
extern lv_obj_t* ui_menuMessagesContainer;
extern lv_obj_t* ui_imbMessages;
extern lv_obj_t* ui_lblMenuMessages;
extern lv_obj_t* ui_menuMultimediaContainer;
extern lv_obj_t* ui_imbMultimedia;
extern lv_obj_t* ui_lblMenuMultimedia;
extern lv_obj_t* ui_menuExtraContainer;
extern lv_obj_t* ui_imbExtra;
extern lv_obj_t* ui_lblMenuExtra;
extern lv_obj_t* ui_menuGamesContainer;
extern lv_obj_t* ui_imbGames;
extern lv_obj_t* ui_lblMenuGames;
extern lv_obj_t* ui_menuMyZoneContainer;
extern lv_obj_t* ui_imbMyZone;
extern lv_obj_t* ui_lblMenuMyZone;
extern lv_obj_t* ui_menuAboutContainer;
extern lv_obj_t* ui_imbAbout;
extern lv_obj_t* ui_lblMenuAbout;
extern lv_obj_t* ui_menuToolsContainer;
extern lv_obj_t* ui_imbTools;
extern lv_obj_t* ui_lblMenuTools;
extern lv_obj_t* ui_menuSettingsContainer;
extern lv_obj_t* ui_imbSettings;
extern lv_obj_t* ui_lblMenuSettings;
extern lv_obj_t* ui_menuClockContainer;
extern lv_obj_t* ui_imbClock;
extern lv_obj_t* ui_lblMenuSettings1;
extern lv_obj_t* ui_menuCalculatorContainer;
extern lv_obj_t* ui_imbCalculator;
extern lv_obj_t* ui_lblMenuCalculator;
extern lv_obj_t* ui_menuCalendarContainer;
extern lv_obj_t* ui_imbCalendar;
extern lv_obj_t* ui_lblMenuCalendar;
extern lv_obj_t* ui_menuFilesContainer;
extern lv_obj_t* ui_imbFiles;
extern lv_obj_t* ui_lblMenuFiles;
extern lv_obj_t* ui_menuTodoContainer;
extern lv_obj_t* ui_imbTodo;
extern lv_obj_t* ui_lblMenuTodo;
extern lv_obj_t* ui_menuSTKContainer;
extern lv_obj_t* ui_imbSTK;
extern lv_obj_t* ui_lblMenuSTK;
extern lv_obj_t* ui_menuContactsContainer;
extern lv_obj_t* ui_imbMenuContacts;
extern lv_obj_t* ui_lblMenuContacts;
extern lv_obj_t* ui_menuGalleryContainer;
extern lv_obj_t* ui_imbGallery;
extern lv_obj_t* ui_lblMenuGallery;
extern lv_obj_t* ui_menuMusicContainer;
extern lv_obj_t* ui_imbMusic;
extern lv_obj_t* ui_lblMenuMusic;
extern lv_obj_t* ui_menuRadioContainer;
extern lv_obj_t* ui_imbRadio;
extern lv_obj_t* ui_lblMenuRadio;
extern lv_obj_t* ui_menuVideosContainer;
extern lv_obj_t* ui_imbVideos;
extern lv_obj_t* ui_lblMenuVideos;
extern lv_obj_t* ui_bottomBar;
extern lv_obj_t* ui_lblBottombarTasks;
extern lv_obj_t* ui_lblBottombarHome;
extern lv_obj_t* ui_lblBottombarBack;

// SCREEN: ui_contactsScreen
void ui_contactsScreen_screen_init(void);
extern lv_obj_t* ui_contactsScreen;
extern lv_obj_t* ui_panelContactMain;
extern lv_obj_t* ui_lblContactTitle;
extern lv_obj_t* ui_listContact;
extern lv_obj_t* ui_lblContactBack;
// SCREEN: ui_contactOptionsScreen
void ui_contactOptionsScreen_screen_init(void);
extern lv_obj_t* ui_contactOptionsScreen;
extern lv_obj_t* ui_panelContactDetails;
extern lv_obj_t* ui_lblContactDetailsTitle;
extern lv_obj_t* ui_listContactDetailsOptions;
extern lv_obj_t* ui_lblContactDetailsBack;
extern lv_obj_t* ui_lblContactBack;
// SCREEN: ui_simPinScreen
void ui_simPinScreen_screen_init(void);
extern lv_obj_t* ui_simPinScreen;
extern lv_obj_t* ui_txtPinPinScreen;
extern lv_obj_t* ui_btnOkPinPinScreen;
extern lv_obj_t* ui_lblOkPinPinScreen;
extern lv_obj_t* ui_lblUnlockPhonePinScreen;
extern lv_obj_t* ui_btnMatrixNumPinScreen;

// SCREEN: ui_alarmMainScreen
void ui_alarmMainScreen_screen_init(void);
extern lv_obj_t* ui_alarmMainScreen;
// SCREEN: ui_splashScreen
void ui_splashScreen_screen_init(void);
extern lv_obj_t* ui_splashScreen;
// SCREEN: ui_contactAddScreen
void ui_contactAddScreen_screen_init(void);
extern lv_obj_t* ui_contactAddScreen;
extern lv_obj_t* ui_panelContactAdd;
extern lv_obj_t* ui_lblContactAddName;
extern lv_obj_t* ui_txtContactAddName;
extern lv_obj_t* ui_lblContactAddNumber;
extern lv_obj_t* ui_txtContactAddNumber;
extern lv_obj_t* ui_lblContactAddSaveTo;
extern lv_obj_t* ui_dropDownContactAddSaveTo;
extern lv_obj_t* ui_lblContactAddSave;
extern lv_obj_t* ui_lblContactAddDiscard;
extern lv_obj_t* ui_lblContactAddBack;
// SCREEN: ui_settingsMainScreen
void ui_settingsMainScreen_screen_init(void);
extern lv_obj_t* ui_settingsMainScreen;
extern lv_obj_t* ui_panelSettingsMain;
extern lv_obj_t* listSettingsOptions;
// SCREEN: ui_settingsDisplayScreen
void ui_settingsDisplayScreen_screen_init(void);
extern lv_obj_t* ui_settingsDisplayScreen;
extern lv_obj_t* ui_panelSettingsDisplayMain;
extern lv_obj_t* sliderBrightness;
extern lv_obj_t* ui_lblBrightnessValue;
extern lv_obj_t* ui_dropDownSettingsScreenTimeout;
// SCREEN: ui_settingsThemesScreen
void ui_settingsThemesScreen_screen_init(void);
extern lv_obj_t* ui_settingsThemesScreen;
extern lv_obj_t* ui_panelSettingsTheme;
extern lv_obj_t* ui_switchTheme;
// SCREEN: ui_settingsThemeWallpaperScreen
void ui_settingsThemeWallpaperScreen_screen_init(void);
extern lv_obj_t* ui_settingsThemeWallpaperScreen;
extern lv_obj_t* ui_panelSettingsThemeWallpaper;
extern lv_obj_t* ui_imageViewWallpaper;
// SCREEN: ui_settingsLockSecurityScreen
void ui_settingsLockSecurityScreen_screen_init(void);
extern lv_obj_t* ui_settingsLockSecurityScreen;
extern lv_obj_t* ui_panelSettingsLockSecurity;
// SCREEN: ui_settingsNetworkInternetScreen
void ui_settingsNetworkInternetScreen_screen_init(void);
extern lv_obj_t* ui_settingsNetworkInternetScreen;
extern lv_obj_t* ui_panelSettingsNetworkInternet;
// SCREEN: ui_settingsNetworkInternetWiFiScreen
void ui_settingsNetworkInternetWiFiScreen_screen_init(void);
extern lv_obj_t* ui_settingsNetworkInternetWiFiScreen;
extern lv_obj_t* ui_panelSettingsNetworkInternetWiFi;
extern lv_obj_t* ui_lblWiFiScanning;
extern lv_obj_t* ui_spinnerWiFiScanning;
extern lv_obj_t* ui_listWiFiFoundDevices;
// SCREEN: ui_settingsNetworkWiFiPasswordScreen
void ui_settingsNetworkWiFiPasswordScreen_screen_init(void);
extern lv_obj_t* ui_settingsNetworkWiFiPasswordScreen;
extern lv_obj_t* ui_panelSettingsNetworkWiFiPassword;
extern lv_obj_t *ui_txtWiFiPassword;
// SCREEN: ui_settingsNetworkInternetGPRSScreen
void ui_settingsNetworkInternetGPRSScreen_screen_init(void);
extern lv_obj_t* ui_settingsNetworkInternetGPRSScreen;
extern lv_obj_t* ui_panelSettingsNetworkInternetGPRS;
// SCREEN: ui_settingsConnectivityScreen
void ui_settingsConnectivityScreen_screen_init(void);
extern lv_obj_t* ui_settingsConnectivityScreen;
extern lv_obj_t* ui_panelSettingsConnectivity;
// SCREEN: ui_settingsConnectivityBLEScreen
void ui_settingsConnectivityBLEScreen_screen_init(void);
extern lv_obj_t* ui_settingsConnectivityBLEScreen;
extern lv_obj_t* ui_panelSettingsConnectivityBLE;
extern lv_obj_t* ui_lblBtScanning;
extern lv_obj_t* ui_spinnerBtScanning;
extern lv_obj_t* ui_listBLEFoundDevices;
// SCREEN: ui_settingsStorageScreen
void ui_settingsStorageScreen_screen_init(void);
extern lv_obj_t* ui_settingsStorageScreen;
extern lv_obj_t* ui_panelSettingsStorage;
// SCREEN: ui_settingsSoundScreen
void ui_settingsSoundScreen_screen_init(void);
extern lv_obj_t* ui_settingsSoundScreen;
extern lv_obj_t* ui_panelSettingsSound;
// SCREEN: ui_settingsSystemScreen
void ui_settingsSystemScreen_screen_init(void);
extern lv_obj_t* ui_settingsSystemScreen;
extern lv_obj_t* ui_panelSettingsSystem;
// SCREEN: ui_settingsAboutScreen
void ui_settingsAboutScreen_screen_init(void);
extern lv_obj_t* ui_settingsAboutScreen;
extern lv_obj_t* ui_panelSettingsAbout;
// SCREEN: ui_timeScreen
void ui_timeScreen_screen_init(void);
extern lv_obj_t* ui_timeScreen;
extern lv_obj_t* ui_panelTimeMain;
// SCREEN: ui_calculatorScreen
void ui_calculatorScreen_screen_init(void);
extern lv_obj_t* ui_calculatorScreen;
extern lv_obj_t* ui_panelCalculatorMain;
// SCREEN: ui_calendarScreen
void ui_calendarScreen_screen_init(void);
extern lv_obj_t* ui_calendarScreen;
extern lv_obj_t* ui_panelCalendarMain;
extern lv_obj_t* ui_calendar;
extern lv_obj_t* ui_btnCalendarApply;
extern lv_obj_t* ui_btnCalendarDiscard;
// SCREEN: ui_filesScreen
void ui_filesScreen_screen_init(void);
extern lv_obj_t* ui_filesScreen;
extern lv_obj_t* ui_panelFilesMain;
// SCREEN: ui_todoScreen
void ui_todoScreen_screen_init(void);
extern lv_obj_t* ui_todoScreen;
extern lv_obj_t* ui_panelTodoMain;
// SCREEN: ui_stkScreen
void ui_stkScreen_screen_init(void);
extern lv_obj_t* ui_stkScreen;
extern lv_obj_t* ui_panelSTKMain;
// SCREEN: ui_galleryScreen
void ui_galleryScreen_screen_init(void);
extern lv_obj_t* ui_galleryScreen;
extern lv_obj_t* ui_panelGalleryMain;
// SCREEN: ui_musicScreen
void ui_musicScreen_screen_init(void);
extern lv_obj_t* ui_musicScreen;
extern lv_obj_t* ui_panelMusicMain;
// SCREEN: ui_radioScreen
void ui_radioScreen_screen_init(void);
extern lv_obj_t* ui_radioScreen;
extern lv_obj_t* ui_panelRadioMain;
// SCREEN: ui_videoScreen
void ui_videoScreen_screen_init(void);
extern lv_obj_t* ui_videoScreen;
extern lv_obj_t* ui_panelVideoMain;
// SCREEN: ui_phoneScreen
void ui_phoneScreen_screen_init(void);
extern lv_obj_t* ui_phoneScreen;
extern lv_obj_t* ui_panelPhoneMain;
// SCREEN: ui_messagesScreen
void ui_messagesScreen_screen_init(void);
extern lv_obj_t* ui_messagesScreen;
extern lv_obj_t* ui_panelMessagesMain;
// SCREEN: ui_multimediaScreen
void ui_multimediaScreen_screen_init(void);
extern lv_obj_t* ui_multimediaScreen;
extern lv_obj_t* ui_panelMultimediaMain;
// SCREEN: ui_extraScreen
void ui_extraScreen_screen_init(void);
extern lv_obj_t* ui_extraScreen;
extern lv_obj_t* ui_panelExtraMain;
// SCREEN: ui_gamesScreen
void ui_gamesScreen_screen_init(void);
extern lv_obj_t* ui_gamesScreen;
extern lv_obj_t* ui_panelGamesMain;
// SCREEN: ui_myZoneScreen
void ui_myZoneScreen_screen_init(void);
extern lv_obj_t* ui_myZoneScreen;
extern lv_obj_t* ui_panelMyZoneMain;
// SCREEN: ui_toolsScreen
void ui_toolsScreen_screen_init(void);
extern lv_obj_t* ui_toolsScreen;
extern lv_obj_t* ui_panelToolsMain;
// SCREEN: ui_browserScreen
void ui_browserScreen_screen_init(void);
extern lv_obj_t* ui_browserScreen;
extern lv_obj_t* ui_panelBrowserMain;

// General UI events
extern lv_obj_t* ui_keyboard_full;
extern lv_obj_t* ui_keyboard_num;

// Events handlers
void ui_event_textarea_cb(lv_event_t* e);
void ui_event_keyboard_cb(lv_event_t* e);
void ui_event_fab_cb(lv_event_t* e);
void ui_event_evtBottombar(lv_event_t* e);
void ui_event_imagebutton_cb(lv_event_t* e);
void ui_event_uiComponentsChangeEvent(lv_event_t* e);
void ui_event_slider_cb(lv_event_t* e);
void ui_event_dropdown_cb(lv_event_t* e);
void ui_event_label_cb(lv_event_t* e);
void ui_event_button_cb(lv_event_t* e);
void ui_event_list_button_cb(lv_event_t* e);
void ui_event_list_wifi_cb(lv_event_t* e);

extern lv_obj_t* ui____initial_actions0;

LV_IMG_DECLARE(ui_lottie_load_circular);       // binary lottie file
LV_IMG_DECLARE(ui_lottie_load_circular_lines)  // binary lottie file
LV_IMG_DECLARE(ui_img_bg1_png);                // assets/bg1.png
LV_IMG_DECLARE(ui_img_bg2_png);                // assets/bg2.png
LV_IMG_DECLARE(ui_img_bg3_png);                // assets/bg3.png
LV_IMG_DECLARE(ui_img_bg4_png);                // assets/bg4.png
LV_IMG_DECLARE(ui_img_bg5_png);                // assets/bg5.png
LV_IMG_DECLARE(ui_img_openphone40_png);        // assets/openphone40.png
LV_IMG_DECLARE(ui_img_messages40_png);         // assets/messages40.png
LV_IMG_DECLARE(ui_img_apps40_png);             // assets/apps40.png
LV_IMG_DECLARE(ui_img_browser40_png);          // assets/browser40.png
LV_IMG_DECLARE(ui_img_usergroup40_png);        // assets/usergroup40.png
LV_IMG_DECLARE(ui_img_multimedia40_png);       // assets/multimedia40.png
LV_IMG_DECLARE(ui_img_extra40_png);            // assets/extra40.png
LV_IMG_DECLARE(ui_img_games40_png);            // assets/games40.png
LV_IMG_DECLARE(ui_img_dropzone40_png);         // assets/dropzone40.png
LV_IMG_DECLARE(ui_img_about40_png);            // assets/about40.png
LV_IMG_DECLARE(ui_img_tools40_png);            // assets/tools40.png
LV_IMG_DECLARE(ui_img_settings40_png);         // assets/settings40.png
LV_IMG_DECLARE(ui_img_callgreen40_png);        // assets/callgreen40.png
LV_IMG_DECLARE(ui_img_callred40_png);          // assets/callred40.png
LV_IMG_DECLARE(ui_img_phoneblue40_png);        // assets/phoneblue40.png
LV_IMG_DECLARE(ui_img_simcard40_png);          // assets/simcard40.png
LV_IMG_DECLARE(ui_img_outdatedphone40_png);    // assets/outdatedphone40.png
LV_IMG_DECLARE(ui_img_phonered40_png);         // assets/phonered40.png
LV_IMG_DECLARE(ui_img_phonebluee40_png);       // assets/phonebluee40.png
LV_IMG_DECLARE(ui_img_clock40_png);            // assets/clock40.png
LV_IMG_DECLARE(ui_img_calculator40_png);       // assets/calculator40.png
LV_IMG_DECLARE(ui_img_calendar40_png);         // assets/calendar40.png
LV_IMG_DECLARE(ui_img_folder40_png);           // assets/folder40.png
LV_IMG_DECLARE(ui_img_todo40_png);             // assets/todo40.png
LV_IMG_DECLARE(ui_img_stk40_png);              // assets/stk40.png
LV_IMG_DECLARE(ui_img_gallery40_png);          // assets/gallery40.png
LV_IMG_DECLARE(ui_img_music40_png);            // assets/music40.png
LV_IMG_DECLARE(ui_img_radio40_png);            // assets/radio40.png
LV_IMG_DECLARE(ui_img_video40_png);            // assets/video40.png
void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
