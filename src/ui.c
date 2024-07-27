#include "ui.h"

#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////

// SCREEN: ui_homeScreen
void ui_homeScreen_screen_init(void);
lv_obj_t* ui_homeScreen;
lv_obj_t* ui_panelMain;
lv_obj_t* ui_homeContainerTopBar;
lv_obj_t* ui_lblHomeBatteryLevel;
lv_obj_t* ui_lblHomeSignalLevel;
lv_obj_t* ui_homeContainerDateISP;
lv_obj_t* ui_lblHomeTime;
lv_obj_t* ui_lblHomeDate;
lv_obj_t* ui_lblHomeISP;
lv_obj_t* ui_homeContainerStart;
lv_obj_t* ui_imbHomePhone;
lv_obj_t* ui_imbHomeMessages;
lv_obj_t* ui_imbHomeApps;
lv_obj_t* ui_imbHomeBrowser;
lv_obj_t* ui_imbHomeContacts;

// SCREEN: ui_mainMenuScreen
void ui_mainMenuScreen_screen_init(void);
lv_obj_t* ui_mainMenuScreen;
lv_obj_t* ui_panelMainMenu;
lv_obj_t* ui_menuMainContainer;
lv_obj_t* ui_menuPhoneContainer;
lv_obj_t* ui_imbPhone;
lv_obj_t* ui_lblMenuPhone;
lv_obj_t* ui_menuMessagesContainer;
lv_obj_t* ui_imbMessages;
lv_obj_t* ui_lblMenuMessages;
lv_obj_t* ui_menuMultimediaContainer;
lv_obj_t* ui_imbMultimedia;
lv_obj_t* ui_lblMenuMultimedia;
lv_obj_t* ui_menuExtraContainer;
lv_obj_t* ui_imbExtra;
lv_obj_t* ui_lblMenuExtra;
lv_obj_t* ui_menuGamesContainer;
lv_obj_t* ui_imbGames;
lv_obj_t* ui_lblMenuGames;
lv_obj_t* ui_menuMyZoneContainer;
lv_obj_t* ui_imbMyZone;
lv_obj_t* ui_lblMenuMyZone;
lv_obj_t* ui_menuAboutContainer;
lv_obj_t* ui_imbAbout;
lv_obj_t* ui_lblMenuAbout;
lv_obj_t* ui_menuToolsContainer;
lv_obj_t* ui_imbTools;
lv_obj_t* ui_lblMenuTools;
lv_obj_t* ui_menuSettingsContainer;
lv_obj_t* ui_imbSettings;
lv_obj_t* ui_lblMenuSettings;
lv_obj_t* ui_menuClockContainer;
lv_obj_t* ui_imbClock;
lv_obj_t* ui_lblMenuSettings1;
lv_obj_t* ui_menuCalculatorContainer;
lv_obj_t* ui_imbCalculator;
lv_obj_t* ui_lblMenuCalculator;
lv_obj_t* ui_menuCalendarContainer;
lv_obj_t* ui_imbCalendar;
lv_obj_t* ui_lblMenuCalendar;
lv_obj_t* ui_menuFilesContainer;
lv_obj_t* ui_imbFiles;
lv_obj_t* ui_lblMenuFiles;
lv_obj_t* ui_menuTodoContainer;
lv_obj_t* ui_imbTodo;
lv_obj_t* ui_lblMenuTodo;
lv_obj_t* ui_menuSTKContainer;
lv_obj_t* ui_imbSTK;
lv_obj_t* ui_lblMenuSTK;
lv_obj_t* ui_menuContactsContainer;
lv_obj_t* ui_imbMenuContacts;
lv_obj_t* ui_lblMenuContacts;
lv_obj_t* ui_menuGalleryContainer;
lv_obj_t* ui_imbGallery;
lv_obj_t* ui_lblMenuGallery;
lv_obj_t* ui_menuMusicContainer;
lv_obj_t* ui_imbMusic;
lv_obj_t* ui_lblMenuMusic;
lv_obj_t* ui_menuRadioContainer;
lv_obj_t* ui_imbRadio;
lv_obj_t* ui_lblMenuRadio;
lv_obj_t* ui_menuVideosContainer;
lv_obj_t* ui_imbVideos;
lv_obj_t* ui_lblMenuVideos;
lv_obj_t* ui_bottomBar;
lv_obj_t* ui_lblBottombarTasks;
lv_obj_t* ui_lblBottombarHome;
lv_obj_t* ui_lblBottombarBack;

// SCREEN: ui_contactsScreen
void ui_contactsScreen_screen_init(void);
lv_obj_t* ui_contactsScreen;
lv_obj_t* ui_panelContactMain;
lv_obj_t* ui_lblContactTitle;
lv_obj_t* ui_listContact;
lv_obj_t* ui_lblContactBack;

// SCREEN: ui_contactOptionsScreen
void ui_contactOptionsScreen_screen_init(void);
lv_obj_t* ui_contactOptionsScreen;
lv_obj_t* ui_panelContactDetails;
lv_obj_t* ui_lblContactDetailsTitle;
lv_obj_t* ui_listContactDetailsOptions;
lv_obj_t* ui_lblContactDetailsBack;

// SCREEN: ui_simPinScreen
void ui_simPinScreen_screen_init(void);
lv_obj_t* ui_simPinScreen;
lv_obj_t* ui_txtPinPinScreen;
lv_obj_t* ui_btnOkPinPinScreen;
lv_obj_t* ui_lblOkPinPinScreen;
lv_obj_t* ui_lblUnlockPhonePinScreen;
lv_obj_t* ui_btnMatrixNumPinScreen;

// SCREEN: ui_alarmMainScreen
void ui_alarmMainScreen_screen_init(void);
lv_obj_t* ui_alarmMainScreen;
lv_obj_t* ui____initial_actions0;

// SCREEN: ui_splashScreen
void ui_splashScreen_screen_init(void);
lv_obj_t* ui_splashScreen;
// SCREEN: ui_contactAddScreen
void ui_contactAddScreen_screen_init(void);
lv_obj_t* ui_contactAddScreen;
lv_obj_t* ui_panelContactAdd;
lv_obj_t* ui_lblContactAddName;
lv_obj_t* ui_txtContactAddName;
lv_obj_t* ui_lblContactAddNumber;
lv_obj_t* ui_txtContactAddNumber;
lv_obj_t* ui_lblContactAddSaveTo;
lv_obj_t* ui_dropDownContactAddSaveTo;
lv_obj_t* ui_lblContactAddSave;
lv_obj_t* ui_lblContactAddDiscard;
lv_obj_t* ui_lblContactAddBack;

// SCREEN: ui_settingsMainScreen
void ui_settingsMainScreen_screen_init(void);
lv_obj_t* ui_settingsMainScreen;
lv_obj_t* ui_panelSettingsMain;
lv_obj_t* listSettingsOptions;

// SCREEN: ui_settingsDisplayScreen
void ui_settingsDisplayScreen_screen_init(void);
lv_obj_t* ui_settingsDisplayScreen;
lv_obj_t* ui_panelSettingsDisplayMain;
lv_obj_t* sliderBrightness;
lv_obj_t* ui_lblBrightnessValue;
lv_obj_t* ui_dropDownSettingsScreenTimeout;

// SCREEN: ui_settingsThemesScreen
void ui_settingsThemesScreen_screen_init(void);
lv_obj_t* ui_settingsThemesScreen;
lv_obj_t* ui_panelSettingsTheme;
lv_obj_t* ui_switchTheme;

// SCREEN: ui_settingsThemeWallpaperScreen
void ui_settingsThemeWallpaperScreen_screen_init(void);
lv_obj_t* ui_settingsThemeWallpaperScreen;
lv_obj_t* ui_panelSettingsThemeWallpaper;
lv_obj_t* ui_imageViewWallpaper;

// SCREEN: ui_settingsLockSecurityScreen
void ui_settingsLockSecurityScreen_screen_init(void);
lv_obj_t* ui_settingsLockSecurityScreen;
lv_obj_t* ui_panelSettingsLockSecurity;

// SCREEN: ui_settingsNetworkInternetScreen
void ui_settingsNetworkInternetScreen_screen_init(void);
lv_obj_t* ui_settingsNetworkInternetScreen;
lv_obj_t* ui_panelSettingsNetworkInternet;

// SCREEN: ui_settingsConnectivityScreen
void ui_settingsConnectivityScreen_screen_init(void);
lv_obj_t* ui_settingsConnectivityScreen;
lv_obj_t* ui_panelSettingsConnectivity;

// SCREEN: ui_settingsConnectivityBLEScreen
void ui_settingsConnectivityBLEScreen_screen_init(void);
lv_obj_t* ui_settingsConnectivityBLEScreen;
lv_obj_t* ui_panelSettingsConnectivityBLE;
lv_obj_t *ui_listBLEFoundDevices;

// SCREEN: ui_settingsStorageScreen
void ui_settingsStorageScreen_screen_init(void);
lv_obj_t* ui_settingsStorageScreen;
lv_obj_t* ui_panelSettingsStorage;

// SCREEN: ui_settingsSoundScreen
void ui_settingsSoundScreen_screen_init(void);
lv_obj_t* ui_settingsSoundScreen;
lv_obj_t* ui_panelSettingsSound;

// SCREEN: ui_settingsSystemScreen
void ui_settingsSystemScreen_screen_init(void);
lv_obj_t* ui_settingsSystemScreen;
lv_obj_t* ui_panelSettingsSystem;

// SCREEN: ui_settingsAboutScreen
void ui_settingsAboutScreen_screen_init(void);
lv_obj_t* ui_settingsAboutScreen;
lv_obj_t* ui_panelSettingsAbout;

// SCREEN: ui_timeScreen
void ui_timeScreen_screen_init(void);
lv_obj_t* ui_timeScreen;
lv_obj_t* ui_panelTimeMain;

// SCREEN: ui_calculatorScreen
void ui_calculatorScreen_screen_init(void);
lv_obj_t* ui_calculatorScreen;
lv_obj_t* ui_panelCalculatorMain;

// SCREEN: ui_calendarScreen
void ui_calendarScreen_screen_init(void);
lv_obj_t* ui_calendarScreen;
lv_obj_t* ui_panelCalendarMain;
lv_obj_t* ui_calendar;
lv_obj_t* ui_btnCalendarApply;
lv_obj_t* ui_btnCalendarDiscard;

// SCREEN: ui_filesScreen
void ui_filesScreen_screen_init(void);
lv_obj_t* ui_filesScreen;
lv_obj_t* ui_panelFilesMain;

// SCREEN: ui_todoScreen
void ui_todoScreen_screen_init(void);
lv_obj_t* ui_todoScreen;
lv_obj_t* ui_panelTodoMain;

// SCREEN: ui_stkScreen
void ui_stkScreen_screen_init(void);
lv_obj_t* ui_stkScreen;
lv_obj_t* ui_panelSTKMain;

// SCREEN: ui_galleryScreen
void ui_galleryScreen_screen_init(void);
lv_obj_t* ui_galleryScreen;
lv_obj_t* ui_panelGalleryMain;

// SCREEN: ui_musicScreen
void ui_musicScreen_screen_init(void);
lv_obj_t* ui_musicScreen;
lv_obj_t* ui_panelMusicMain;

// SCREEN: ui_radioScreen
void ui_radioScreen_screen_init(void);
lv_obj_t* ui_radioScreen;
lv_obj_t* ui_panelRadioMain;

// SCREEN: ui_videoScreen
void ui_videoScreen_screen_init(void);
lv_obj_t* ui_videoScreen;
lv_obj_t* ui_panelVideoMain;

// SCREEN: ui_phoneScreen
void ui_phoneScreen_screen_init(void);
lv_obj_t* ui_phoneScreen;
lv_obj_t* ui_panelPhoneMain;

// SCREEN: ui_messagesScreen
void ui_messagesScreen_screen_init(void);
lv_obj_t* ui_messagesScreen;
lv_obj_t* ui_panelMessagesMain;

// SCREEN: ui_multimediaScreen
void ui_multimediaScreen_screen_init(void);
lv_obj_t* ui_multimediaScreen;
lv_obj_t* ui_panelMultimediaMain;

// SCREEN: ui_extraScreen
void ui_extraScreen_screen_init(void);
lv_obj_t* ui_extraScreen;
lv_obj_t* ui_panelExtraMain;

// SCREEN: ui_gamesScreen
void ui_gamesScreen_screen_init(void);
lv_obj_t* ui_gamesScreen;
lv_obj_t* ui_panelGamesMain;

// SCREEN: ui_myZoneScreen
void ui_myZoneScreen_screen_init(void);
lv_obj_t* ui_myZoneScreen;
lv_obj_t* ui_panelMyZoneMain;

// SCREEN: ui_aboutScreen
void ui_aboutScreen_screen_init(void);
lv_obj_t* ui_aboutScreen;
lv_obj_t* ui_panelAboutMain;

// SCREEN: ui_toolsScreen
void ui_toolsScreen_screen_init(void);
lv_obj_t* ui_toolsScreen;
lv_obj_t* ui_panelToolsMain;

// SCREEN: ui_browserScreen
void ui_browserScreen_screen_init(void);
lv_obj_t* ui_browserScreen;
lv_obj_t* ui_panelBrowserMain;

// General UI
lv_obj_t* ui_keyboard_full;
lv_obj_t* ui_keyboard_num;

lv_obj_t* ui____initial_actions0;

const lv_image_dsc_t* ui_imgset_usergroup[1] = {&ui_img_usergroup40_png};
const lv_image_dsc_t* ui_imgset_browser[1] = {&ui_img_browser40_png};
const lv_image_dsc_t* ui_imgset_callgreen[1] = {&ui_img_callgreen40_png};
const lv_image_dsc_t* ui_imgset_callred[1] = {&ui_img_callred40_png};
const lv_image_dsc_t* ui_imgset_phoneblue[1] = {&ui_img_phoneblue40_png};
const lv_image_dsc_t* ui_imgset_dropzone[1] = {&ui_img_dropzone40_png};
const lv_image_dsc_t* ui_imgset_simcard[1] = {&ui_img_simcard40_png};
const lv_image_dsc_t* ui_imgset_outdatedphone[1] = {
    &ui_img_outdatedphone40_png};
const lv_image_dsc_t* ui_imgset_about[1] = {&ui_img_about40_png};
const lv_image_dsc_t* ui_imgset_extra[1] = {&ui_img_extra40_png};
const lv_image_dsc_t* ui_imgset_messages[1] = {&ui_img_messages40_png};
const lv_image_dsc_t* ui_imgset_openphone[1] = {&ui_img_openphone40_png};
const lv_image_dsc_t* ui_imgset_multimedia[1] = {&ui_img_multimedia40_png};
const lv_image_dsc_t* ui_imgset_games[1] = {&ui_img_games40_png};
const lv_image_dsc_t* ui_imgset_phonered[1] = {&ui_img_phonered40_png};
const lv_image_dsc_t* ui_imgset_phonebluee[1] = {&ui_img_phonebluee40_png};
const lv_image_dsc_t* ui_imgset_tools[1] = {&ui_img_tools40_png};
const lv_image_dsc_t* ui_imgset_apps[1] = {&ui_img_apps40_png};
const lv_image_dsc_t* ui_imgset_bg[5] = {&ui_img_bg1_png, &ui_img_bg2_png,
                                         &ui_img_bg3_png, &ui_img_bg4_png,
                                         &ui_img_bg5_png};
const lv_image_dsc_t* ui_imgset_settings[1] = {&ui_img_settings40_png};
const lv_image_dsc_t* ui_imgset_clock[1] = {&ui_img_clock40_png};
const lv_image_dsc_t* ui_imgset_calculator[1] = {&ui_img_calculator40_png};
const lv_image_dsc_t* ui_imgset_calendar[1] = {&ui_img_calendar40_png};
const lv_image_dsc_t* ui_imgset_folder[1] = {&ui_img_folder40_png};
const lv_image_dsc_t* ui_imgset_stk[1] = {&ui_img_stk40_png};
const lv_image_dsc_t* ui_imgset_todo[1] = {&ui_img_todo40_png};
const lv_image_dsc_t* ui_imgset_gallery[1] = {&ui_img_gallery40_png};
const lv_image_dsc_t* ui_imgset_radio[1] = {&ui_img_radio40_png};
const lv_image_dsc_t* ui_imgset_music[1] = {&ui_img_music40_png};
const lv_image_dsc_t* ui_imgset_video[1] = {&ui_img_video40_png};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
#error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

// General events
///////////////////// eSCREENS ////////////////////

void ui_init(void) {
  lv_disp_t* dispp = lv_display_get_default();
  lv_theme_t* theme = lv_theme_default_init(
      dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
      false, LV_FONT_DEFAULT);
  lv_disp_set_theme(dispp, theme);

  // initialize the stack for managing screen navigation. Must be done here
  screenStackInit();

  ui_homeScreen_screen_init();
  ui____initial_actions0 = lv_obj_create(NULL);
  lv_screen_load(ui_homeScreen);
}
