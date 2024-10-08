#include "ui.h"
#include "ui_utils_calculator.h"

lv_obj_t *calculationArea;
lv_obj_t *calculationResults;
char calculationTokens[] = {'(', ')', '*', '/', '+', '-'};

static void evtComputeCalculations(lv_event_t *e);

void ui_calculatorScreen_screen_init(void) {
  ui_calculatorScreen = lv_obj_create(NULL);
  lv_obj_remove_flag(ui_calculatorScreen, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_panelCalculatorMain = lv_obj_create(ui_calculatorScreen);
  lv_obj_set_width(ui_panelCalculatorMain, 240);
  lv_obj_set_height(ui_panelCalculatorMain, 320);
  lv_obj_remove_flag(ui_panelCalculatorMain, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_image_src(ui_panelCalculatorMain, screenWallpaperImg,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_image_opa(ui_panelCalculatorMain, 100,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_panelCalculatorMain, lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_panelCalculatorMain, 0,
                              LV_PART_MAIN | LV_STATE_DEFAULT);

  static const char *kb_map[] = {"1",  "2",  "3",  LV_SYMBOL_BACKSPACE,
                                 "\n", "4",  "5",  "6",
                                 "/",  "\n", "7",  "8",
                                 "9",  "*",  "\n", ".",
                                 "0",  "C",  "+",  "\n",
                                 "(",  "=",  ")",  "-",
                                 NULL};

  static const lv_buttonmatrix_ctrl_t kb_ctrl[] = {
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 8, 2, 4};

  lv_obj_t *kb = lv_keyboard_create(ui_panelCalculatorMain);
  lv_keyboard_set_map(kb, LV_KEYBOARD_MODE_USER_1, kb_map, kb_ctrl);
  lv_keyboard_set_mode(kb, LV_KEYBOARD_MODE_USER_1);
  lv_obj_set_width(kb, 240);
  lv_obj_set_height(kb, 185);
  lv_obj_set_align(kb, LV_ALIGN_TOP_LEFT);
  lv_obj_set_y(kb, 95);
  lv_obj_set_x(kb, -15);

  calculationArea = lv_textarea_create(ui_panelCalculatorMain);
  lv_obj_set_align(calculationArea, LV_ALIGN_TOP_MID);
  lv_obj_set_width(calculationArea, 230);
  lv_obj_set_height(calculationArea, 35);
  lv_obj_set_y(calculationArea, -10);
  lv_obj_add_event_cb(calculationArea, evtComputeCalculations, LV_EVENT_ALL,
                      NULL);
  lv_textarea_set_one_line(calculationArea, true);

  calculationResults = lv_textarea_create(ui_panelCalculatorMain);
  lv_obj_set_align(calculationResults, LV_ALIGN_TOP_MID);
  lv_obj_set_width(calculationResults, 230);
  lv_obj_set_height(calculationResults, 60);
  lv_obj_set_y(calculationResults, 30);
  lv_obj_add_state(calculationResults, LV_STATE_DISABLED);
  lv_obj_remove_state(calculationResults, LV_STATE_FOCUSED);
  lv_obj_remove_flag(calculationResults, LV_OBJ_FLAG_CLICKABLE);  /// Flags

  lv_obj_add_state(calculationArea, LV_STATE_FOCUSED);

  lv_keyboard_set_textarea(kb, calculationArea);

  ui_add_bottom_bar(ui_panelCalculatorMain, 0xFFFFFF, 10);
}

static void evtComputeCalculations(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *ta = lv_event_get_target(e);
  lv_obj_t *kb = lv_event_get_user_data(e);

  if (code == LV_EVENT_FOCUSED) {
    // gained focus
  }

  if (code == LV_EVENT_DEFOCUSED) {
    // lost focus
  }

  if (code == LV_EVENT_VALUE_CHANGED) {
    const char *text = lv_textarea_get_text(calculationArea);

    if (text[strlen(text) - 1] == '=') {
      // replace the '=' with a null terminator
      char *expression = malloc(strlen(text));
      strncpy(expression, text, strlen(text) - 1);
      expression[strlen(text) - 1] = '\0';

      // compute the result
      int error = 0;
      double result = evaluate(expression, &error);

      if (!error) {
        char resultText[100];
        snprintf(resultText, sizeof(resultText), "%s%.3f", text, result);
        remove_trailing_zeros(resultText, resultText);

        lv_textarea_add_text(calculationResults, "\n");
        lv_textarea_add_text(calculationResults, resultText);

        snprintf(resultText, sizeof(resultText), "%.3f", result);
        remove_trailing_zeros(resultText, resultText);
        lv_textarea_set_text(calculationArea, resultText);
      } else {
        if (strlen(lv_textarea_get_text(calculationResults)) > 0) {
          lv_textarea_add_text(calculationResults, "\n");
        }
        lv_textarea_add_text(calculationResults, "Error");
        lv_textarea_set_text(calculationArea, expression);
      }

    } else if (text[strlen(text) - 1] == 'C') {
      // clear the text
      lv_textarea_set_text(calculationArea, "");
    }
  }
}
