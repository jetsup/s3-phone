#ifndef UTILS_HPP_
#define UTILS_HPP_

#define DEBUG 1

#if DEBUG
#include <Arduino.h>
#endif

#if DEBUG
static unsigned long DEBUG_TIMER_1 = 0;
static unsigned long DEBUG_TIMER_2 = 0;
#endif

#define DEBUG_PRINT(x) \
  if (DEBUG) {         \
    Serial.print(x);   \
  }

#define DEBUG_PRINTLN(x) \
  if (DEBUG) {           \
    Serial.println(x);   \
  }

#define DEBUG_PRINTF(x, ...)       \
  if (DEBUG) {                     \
    Serial.printf(x, __VA_ARGS__); \
  }

#endif  // UTILS_HPP_