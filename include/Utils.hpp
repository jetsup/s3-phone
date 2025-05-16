#pragma once

#include <Arduino.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * @brief Factor in the timezone offset to the current time and date
 * @param currentTime Current time in HH:MM format
 * @param currentDate Current date in YYYY-MM-DD format
 * @param timeZone Timezone offset in HH:MM format
 * @param localizedDateTime The buffer to store the localized date and time
 */
void localizeTime(const String& currentTime, const String& currentDate, const String& timeZone,
                  char *localizedDateTime);

#define DEBUG 1

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
