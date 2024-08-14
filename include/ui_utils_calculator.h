#ifndef UI_UTILS_CALCULATOR_H_
#define UI_UTILS_CALCULATOR_H_

#include <ctype.h>
#include <esp_log.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char CALC_LOG_TAG[11];

/**
 * @brief Calculate the result of an expression
 * @param expr The expression to evaluate
 * @param error A pointer to an integer that will be set to 1 if an error occurs
 */
double evaluate(const char *expr, int *error);

/**
 * @brief Remove trailing zeros from a number
 * @param numberIn The number to remove trailing zeros from
 * @param numberOut The number to store the result in
 */
void remove_trailing_zeros(char *numberIn, char *numberOut);

#endif  // UI_UTILS_CALCULATOR_H_
