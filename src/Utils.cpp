#include <Utils.hpp>

void localizeTime(String currentTime, String currentDate, String timeZone,
                    char *adjustedDateTime) {
  int currentHour = currentTime.substring(0, currentTime.indexOf(':')).toInt();
  int currentMinute =
      currentTime.substring(currentTime.indexOf(':') + 1).toInt();

  int year = currentDate.substring(0, 4).toInt();
  int month = currentDate.substring(5, 7).toInt();
  int day = currentDate.substring(8, 10).toInt();

  int tzHour = timeZone.substring(0, timeZone.indexOf(':')).toInt();
  int tzMinute = timeZone.substring(timeZone.indexOf(':') + 1).toInt();

  if (timeZone.charAt(0) == '-') {
    tzMinute = -tzMinute;
    if (tzHour > 0) {
      tzHour = -tzHour;
    }

  } else if (timeZone.charAt(0) == '+') {
    if (tzHour < 0) {
      tzHour = -tzHour;
    }
  }

  // offset in minutes
  int tzOffsetMinutes = tzHour * 60 + tzMinute;

  // Calculate the adjusted time
  int adjustedMinutes = currentMinute + tzOffsetMinutes;
  int adjustedHours = currentHour;

  // Handle minute overflow/underflow
  if (adjustedMinutes >= 60) {
    adjustedHours += adjustedMinutes / 60;
    adjustedMinutes %= 60;
  } else if (adjustedMinutes < 0) {
    adjustedHours += (adjustedMinutes - 59) / 60;
    adjustedMinutes = (adjustedMinutes % 60) + 60;
  }

  // Handle hour overflow/underflow
  adjustedHours = adjustedHours % 24;
  if (adjustedHours < 0) {
    adjustedHours += 24;
    day--;  // previous day
    if (day < 1) {
      // TODO: account for different month lengths and leap years
      month--;
      if (month < 1) {
        month = 12;
        year--;
      }
      // the last day of the previous month
      int daysInMonth = 31;  // most common case.
      if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
      } else if (month == 2) {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
          daysInMonth = 29;
        } else {
          daysInMonth = 28;
        }
      }
      day = daysInMonth;
    }
  } else if (adjustedHours >= 24) {
    day++;  // next day
    // TODO: account for different month lengths and leap years.
    int daysInMonth = 31;  // most common case.
    if (month == 4 || month == 6 || month == 9 || month == 11) {
      daysInMonth = 30;
    } else if (month == 2) {
      if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        daysInMonth = 29;
      } else {
        daysInMonth = 28;
      }
    }
    if (day > daysInMonth) {
      day = 1;
      month++;
      if (month > 12) {
        month = 1;
        year++;
      }
    }
  }

  DEBUG_PRINTF("DATE::Y: '%d' m:'%d' d:'%d' TIME: '%02d:%02d'\n", year, month,
               day, adjustedHours, adjustedMinutes);
  
  sprintf(adjustedDateTime, "%d-%02d-%02d %02d:%02d", year, month, day,
          adjustedHours, adjustedMinutes);

  DEBUG_PRINTF("Adjusted Date: '%s'\n", adjustedDateTime);
}
