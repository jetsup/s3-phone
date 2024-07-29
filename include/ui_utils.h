#ifndef UI_UTILS_H_
#define UI_UTILS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"
#include "ui_constants.h"
#include "ui_utils_screens.h"

extern char lvCurrentTime[6];
extern char lvCurrentDate[15];

#define CONTACT_NAME_NUMBER_LENGTH 44
extern const char contactSeparationDelimeter[4];
extern char contactName[30];
extern char contactNumber[14];
extern bool dateChanged;
extern int newYear;
extern int newMonth;
extern int newDay;

#define SCREEN_STACK_SIZE 20

static lv_display_t *lv_display;

// Settings Display
#define UI_BRIGHTNESS_SLIDER_MAX 4096
#define UI_BRIGHTNESS_SLIDER_MIN 100
extern int screenBrightnessLevel;
extern bool brightnessChanged;

extern const char screenTimeoutSeparationDelimeter[2];
extern unsigned int screenTimeout;  // in seconds
extern bool timeoutChanged;
extern bool screenInteractive;  // true when baclight on
extern unsigned long previousScreenTouch;
extern uint8_t dropdownSelectedTimeout;

// Settings Theme
extern bool darkThemeSelected;
extern bool themeChanged;
extern lv_theme_t *screenTheme;

extern lv_font_t *systemFontSmall;
extern lv_font_t *systemFontMedium;
extern lv_font_t *systemFontLarge;
extern uint8_t sFont, mFont, lFont;
extern bool fontChanged;

extern char selectedWallpaper[20];  // e.g. beautiful sunset
extern int clickedWallpaperImage;
extern uint8_t screenWallpaperID;
extern lv_image_dsc_t *screenWallpaperImg;
extern bool wallpaperChanged;

// Settings Connectivity
extern bool bluetoothLEEnabled;
extern bool bluetoothStatusChanged;

// Settings Network and Internet
extern bool wifiEnabled;
extern bool wifiStatusChanged;
// So that wifi scanning can be started if need be
extern bool wifiScreenVisible;
extern char wifiName[30];
extern char wifiPassword[30];
#define MAX_WIFI_DISCOVERABLE 20
#define MAX_WIFI_NAME_LENGTH 30
extern char discoveredWiFiNames[MAX_WIFI_DISCOVERABLE][MAX_WIFI_NAME_LENGTH];
extern int discoveredWiFiRSSI[MAX_WIFI_DISCOVERABLE];
extern bool discoveredWiFiOpen[MAX_WIFI_DISCOVERABLE];
extern uint8_t discoveredWiFiCount;

//========================Screen Stack========================
/**
 * @brief Holds the data to be stored in the stack
 */
typedef struct {
  s3_screens_t screen;
  lv_obj_t *previousScreen;
  lv_screen_load_anim_t transitionAnimation;
  void (*previousScreenInit)(void);
} ScreenStackElement;

typedef struct {
  ScreenStackElement *screenStackElements;
  int top;
} ScreenStack;

extern ScreenStack screenStack;
/**
 * @brief Initializes the screen stack
 */
bool screenStackInit();

/**
 * @brief Checks if the screen stack is empty
 * @return true if the screen stack is empty
 */
bool screenStackIsEmpty();

/**
 * @brief Checks if the screen stack is full
 * @return true if the screen stack is full
 */
bool screenStackIsFull();

/**
 * @brief Pushes a screen to the screen stack
 * @param screen The screen you are transitioning from
 * @param transitionAnimation The animation used when transitioning to the
 * screen
 * @return true if the screen was pushed
 */
bool screenStackPush(s3_screens_t screen,
                     lv_screen_load_anim_t transitionAnimation);

/**
 * @brief Pops a screen from the screen stack
 * @return The screen that was popped
 */
ScreenStackElement screenStackPop();

/**
 * @brief Peeks the screen stack
 * @return The screen at the top of the stack
 */
ScreenStackElement screenStackPeek();

/**
 * @brief Clears the screen stack by continuously popping the `s3_screens_t`
 * until the stack is empty. This means that the user will be taken back to
 * the home screen.
 */
void screenStackEmpty();

/**
 * @brief Gets number of `s3_screens_t` in the screen stack
 * @return The number of `s3_screens_t` in the screen stack
 */
int screenStackSize();

//============================UI Updates============================

/**
 * @brief Updates the time and date on the screen
 */
void ui_utils_updateTimeDate();

/**
 * @brief Get the current date and store it in the buffer
 * @param buffer The buffer to store the date
 */
void lv_utils_getDate(char *buffer);

/**
 * @brief Update system date
 * @param year The year
 * @param month The month
 * @param day The day
 */
void lv_utils_setDate(int year, int month, int day);

/**
 * @brief Update the screen brightness variable monitored to change the LCD
 * brightness
 * @param brightness The brightness to set
 */
void lv_utils_setBrightness(int brightness);

/**
 * @brief Update the timeout to darken the screen
 * @param timeout Timeout in seconds
 */
void lv_utils_setScreenTimeout(unsigned int timeout);

/**
 * @brief Get the index of the selected timeout
 */
uint8_t lv_set_selected_timeout();

/**
 * @brief Set the size of the fonts
 * @param sFont font size for small font
 * @param sFont font size for medium font
 * @param sFont font size for large font
 */
void lv_utils_setFonts(uint8_t sFont, uint8_t mFont, uint8_t lFont);

/**
 * @brief Set update the system theme
 * @param themeDark Dark theme if set to `true` else light theme
 */
void lv_utils_setTheme(bool themeDark);

/**
 * @brief Apply the selected theme. This includes updating UI colors.
 */
void lv_utils_applyTheme();

/**
 * @brief Get the defined image using the `imageID`
 * @param imageID the ID of the image
 */
lv_image_dsc_t *lv_utils_getImage(s3_resource_num_t imageID);

/**
 * @brief Get the name of the resource specified with the 'resID'
 * @param resID The ID of the image
 * @param nameBuf The buffer to store the retrieved name
 */
void lv_utils_getResourceName(int resID, char *nameBuf);

/**
 * @brief Update the wallpaper
 * @param wallpaperID The ID of the image to be used
 * @param refreshUI Refresh the UI. Should only be set if the UI is already
 * loaded.
 */
void lv_utils_setWallpaper(uint8_t wallpaperID, bool refreshUI);

/**
 * @brief Update the status of bluetooth for the dependent UI components
 * @param bleEnabled Set the status of bluetooth LE to active
 */
void lv_utils_setBluetooth(bool bleEnabled);

/**
 * @brief Update the status of `WIFI` for the dependent UI components
 * @param bleEnabled Set the status of WIFI
 */
void lv_utils_setWiFi(bool wifiState);

/**
 * @brief Add options to a list object
 * @param list The list object to be populated
 * @param listOptions The strings array containing the options for the list
 * @param optionsCount The number of options to be populated, `size of the
 * array`
 * @param evt Event callback
 * @param evtFilter ORed event type to respond to e.g.`LV_EVENT_CLICKED`
 * @param callbackData The data to be passed to the callback
 */
void lv_utils_populate_list_options(lv_obj_t *list, const char **listOptions,
                                    int optionsCount, lv_event_t *evt,
                                    lv_event_code_t eventFilter,
                                    const char *callbackData);

/**
 * @brief Reset the screen visibility variables. This should be called inside
 * the screen transition function
 */
void lv_utils_resetScreenVisibility();

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
