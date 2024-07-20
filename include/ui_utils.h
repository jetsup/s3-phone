#ifndef UI_UTILS_H_
#define UI_UTILS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"
#include "ui_constants.h"

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

//========================Screen Stack========================
typedef struct {
  enum SCREENS screen;
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
bool screenStackPush(enum SCREENS screen, lv_obj_t *previousScreen,
                     void (*previousScreenInit)(void),
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
 * @brief Clears the screen stack by continuously popping the screens
 * until the stack is empty. This means that the user will be taken back to
 * the home screen.
 */
void screenStackEmpty();

/**
 * @brief Gets number of screens in the screen stack
 * @return The number of screens in the screen stack
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
