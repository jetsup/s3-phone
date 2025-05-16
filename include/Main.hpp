#pragma once

#include <Arduino.h>
#include <lvgl.h>

#include <Display.hpp>
#include <Helpers.hpp>
#include <functionality/communication/GSM.hpp>
#include <functionality/communication/Network.hpp>
#include <functionality/storage/FileSystem.hpp>

#include "Utils.hpp"
#include "enums/ETimezones.hpp"
#include "ui/helpers/ui_contacts.h"
#include "ui/ui.h"

int contactsCount = 0;
String names[] = {"George Ngigi", "John", "Joe", "Brandon"};
String numbers[] = {"0714430347", "0788965432", "0709765432", "0787653434"};
char *cStrNames[] = {};
char *cStrNumbers[] = {};

char *cNames[] = {};
char *cNumbers[] = {};
int cCount = 0;

GSM gsm(GSM_RX, GSM_TX, GSM_BAUD);
static Display display(TFT_CLK, TFT_MOSI, TFT_MISO, TFT_CS, TFT_DC, TFT_RST,
                       TFT_LED, TOUCH_CS, TOUCH_CLK, TOUCH_DIN, TOUCH_DO);
S3Time s3Time("2024-11-01 14:40:56", 3);
FileSystem fileSystem(LittleFS);
Network *s3WiFi;
bool wifiNameUtilsUpdated = false;

unsigned int lastTickMillis = 0;

void *drawBuffer;
const unsigned int lvBufferSize = TFT_DRAW_BUF_SIZE;
uint8_t lvBuffer[lvBufferSize * 2];
uint8_t lvBuffer2[lvBufferSize * 2];

// ----------------------------------------------------------
/* Display flushing*/
void lv_flush_cb(lv_display_t *disp, const lv_area_t *area,
                 unsigned char *data) {
  uint32_t w = lv_area_get_width(area);
  uint32_t h = lv_area_get_height(area);
  display.startWrite();
  display.setAddrWindow(area->x1, area->y1, w, h);
  lv_draw_sw_rgb565_swap(data, w * h);
  display.pushImage(area->x1, area->y1, w, h, (uint16_t *)data);
  display.writePixels((uint16_t *)data, w * h);
  display.endWrite();

  lv_display_flush_ready(disp);
}

/* Read the touchpad*/
void my_touchpad_read(lv_indev_t *indev_driver, lv_indev_data_t *data) {
  uint16_t touchX, touchY;

  bool touched = display.getTouch(&touchX, &touchY);

  if (!touched) {
    data->state = LV_INDEV_STATE_REL;
  } else {
    if (!screenInteractive) {
      display.wake();
      screenInteractive = true;
    } else {
      data->state = LV_INDEV_STATE_PR;

      /*Set the coordinates*/
      data->point.x = touchX;
      data->point.y = touchY;
    }

    previousScreenTouch = millis();
  }
}

/**
 * @brief Load configurations from file system and apply them. Called during
 * system boot
 */
void loadSystemConfigurations() {
  lv_utils_setBrightness(
      fileSystem.readSetting(FS_VAR_SETTINGS_DISPLAY_BRIGHTNESS).toInt());

  lv_utils_setScreenTimeout(
      fileSystem.readSetting(FS_VAR_SETTINGS_DISPLAY_TIMEOUT).toInt());

  lv_utils_setTheme(
      fileSystem.readSetting(FS_VAR_SETTINGS_THEMES_THEME_DARK).toInt());

  uint8_t fontSmall =
      fileSystem.readSetting(FS_VAR_SETTINGS_THEMES_FONT_SMALL).toInt();
  uint8_t fontMedium =
      fileSystem.readSetting(FS_VAR_SETTINGS_THEMES_FONT_MEDIUM).toInt();
  uint8_t fontLarge =
      fileSystem.readSetting(FS_VAR_SETTINGS_THEMES_FONT_LARGE).toInt();

  lv_utils_setFonts(fontSmall, fontMedium, fontLarge);

  lv_utils_setWallpaper(
      fileSystem.readSetting(FS_VAR_SETTINGS_THEMES_WALLPAPER).toInt(), false);

  bool bleEnabledMain =
      fileSystem.readSetting(FS_VAR_SETTINGS_CONNECTIVITY_BLE).toInt();
  lv_utils_setBluetooth(bleEnabledMain);

  bool wifiEnabledMain =
      fileSystem.readSetting(FS_VAR_SETTINGS_NETWORKING_WIFI_STATE).toInt();
  lv_utils_setWiFi(wifiEnabledMain);

  // load date and time
  // YYYY-MM-DD
  // HH:MM:SS
  String date = fileSystem.readSetting(FS_VAR_SETTINGS_DATE_TIME_DATE);
  String time = fileSystem.readSetting(FS_VAR_SETTINGS_DATE_TIME_TIME);
  currentTimezoneIndex =
      fileSystem.readSetting(FS_VAR_SETTINGS_DATE_TIME_TIMEZONE).toInt();
  // TODO: update the time based on the timezone
  String timezoneSTR = /*"+03:00"*/ getTimezoneString(
      static_cast<ETimezones>(currentTimezoneIndex));
  char offsetSign = timezoneSTR.charAt(0);
  bool isOffsetPositive;
  if (offsetSign == '+') {
    isOffsetPositive = true;
  } else {  // for negative and 00:00
    isOffsetPositive = false;
  }
  int hourOffset = timezoneSTR.substring(1, 3).toInt();
  int minuteOffset = timezoneSTR.substring(4).toInt();

  s3Time.setTimeZone(hourOffset + minuteOffset / 60);

  int year = date.substring(0, 4).toInt();
  int month = date.substring(5, 7).toInt();
  int day = date.substring(8, 10).toInt();
  int hour = time.substring(0, 2).toInt();
  int minute = time.substring(3, 5).toInt();
  int second = time.substring(6, 8).toInt();

  s3Time.setTime(second, minute, hour, day, month, year, 0);
  currentTimeHour = hour;
  currentTimeMinute = minute;
  currentTimeSecond = second;

  sprintf(lvCurrentDate, "%s/%s/%s %s", s3Time.getTime("%d"),
          s3Time.getTime("%m"), s3Time.getTime("%Y"), s3Time.getTime("%a"));

  sprintf(lvCurrentTime, "%02d:%02d", currentTimeHour, currentTimeMinute);
  if (homeScreenVisible) {
    ui_utils_updateTimeDate();
  }

  int syncTime = fileSystem.readSetting(FS_VAR_SETTINGS_DATE_TIME_SYNC).toInt();
  syncTimeAutomatically = syncTime;
};

/**
 * @brief Contains all the background functions and operations that do not
 * update the UI directly
 */
void s3looperTask(void *params) {
  while (true) {
    if (wifiStatusChanged) {
      wifiStatusChanged = false;
      fileSystem.editSetting(FS_VAR_SETTINGS_NETWORKING_WIFI_STATE,
                             String(wifiEnabled).c_str());

      if (wifiEnabled) {
        s3WiFi = new Network(S3PHONE_MODEL_NAME);
        wifiReady = true;
      } else {
        if (s3WiFi != nullptr) {
          delete s3WiFi;
          s3WiFi = nullptr;
          wifiReady = false;
        }
      }
    }

    if (wifiEnabled && wifiReady) {
      s3WiFi->loop();

      if (utilsConnectToWiFi) {
        wifiNameUtilsUpdated = false;
        DEBUG_PRINTF("Connecting to '%s'::'%s'\n", wifiName, wifiPassword);
        s3WiFi->connect(String(wifiName), String(wifiPassword));
        utilsConnectToWiFi = false;
      }

      if (s3WiFi->isConnected() && !wifiNameUtilsUpdated) {
        isWiFiConnected = true;
        wifiNameUtilsUpdated = true;
        strcpy(connectedWiFiSSID, s3WiFi->getSSID().c_str());
        // so that the connected WIFI name can be highlighted
        // FIXME: This is not working. Not updating the UI
        DEBUG_PRINTLN("Refreshing WiFi List after connection");
        // lv_utils_refreshWiFiList();
      }

      if (!s3WiFi->isConnected() && isWiFiConnected) {
        // refresh the list so that the connected WIFI name can be unhighlighted
        isWiFiConnected = false;
        lv_utils_refreshWiFiList();
      }

      if (!s3WiFi->credentialsSaved() && s3WiFi->isConnected()) {
        fileSystem.saveCredentials(CREDENTIALS_WIFI, s3WiFi->getSSID().c_str(),
                                   s3WiFi->getPassword().c_str());
        s3WiFi->setCredentialsSaved(true);
      }
    }

    if (syncTimeAutomatically && !s3Time.isNtpTimeUpdated()) {
      syncTimeAutomatically = false;
      s3Time.updateS3Time(true, 60 * 60);
      DEBUG_PRINTLN("Syncing time from NTP server");
    }
  }
}

/**
 * @brief This function is the same as `s3looperTask` but have `lvgl` functions
 * that should only run on `main loop` thread.
 */
void s3UILooper() {
  s3Time.loop();

  if (dateChanged) {
    dateChanged = false;
    s3Time.setTime(s3Time.getSecond(), s3Time.getMinute(), s3Time.getHour(),
                   newDay, newMonth, newYear, s3Time.getMicros());

    fileSystem.editSetting(
        FS_VAR_SETTINGS_DATE_TIME_DATE,
        String(String(newYear) + "-" + (newMonth < 10 ? "0" : "") +
               String(newMonth) + "-" + (newDay < 10 ? "0" : "") +
               String(newDay))
            .c_str());
  }

  if (brightnessChanged) {
    brightnessChanged = false;
    display.updateBrightness(screenBrightnessLevel);
    fileSystem.editSetting(FS_VAR_SETTINGS_DISPLAY_BRIGHTNESS,
                           String(screenBrightnessLevel).c_str());
  }

  if (timeoutChanged) {
    timeoutChanged = false;
    fileSystem.editSetting(FS_VAR_SETTINGS_DISPLAY_TIMEOUT,
                           String(screenTimeout).c_str());
  }

  if (timezoneChanged) {
    timezoneChanged = false;
    fileSystem.editSetting(FS_VAR_SETTINGS_DATE_TIME_TIMEZONE,
                           String(currentTimezoneIndex).c_str());
    String cTime = s3Time.getTime("%H:%M");
    String cDate = s3Time.getTime("%Y-%m-%d");
    String selectedTimezoneStr =
        getTimezoneString(static_cast<ETimezones>(currentTimezoneIndex));
    DEBUG_PRINTF("Date: '%s' Time: '%s' Timezone: '%s'\n", cDate.c_str(),
                 cTime.c_str(), selectedTimezoneStr.c_str());

    char *localizedDateTime = (char *)malloc(17);  // "2025-03-01 12:56\0"
    localizeTime(cTime, cDate, selectedTimezoneStr, localizedDateTime);

    DEBUG_PRINTF("Localized Time: '%s'\n", localizedDateTime);

    int localizedYear, localizedMonth, localizedDay, localizedHour,
        localizedMinute;

    String localizedSTR = String(localizedDateTime);
    localizedYear = localizedSTR.substring(0, 4).toInt();
    localizedMonth = localizedSTR.substring(5, 7).toInt();
    localizedDay = localizedSTR.substring(8, 10).toInt();
    localizedHour = localizedSTR.substring(11, 13).toInt();
    localizedMinute = localizedSTR.substring(14).toInt();

    s3Time.setTime(s3Time.getSecond(), localizedMinute, localizedHour,
                   localizedDay, localizedMonth, localizedYear);

    lv_utils_setTime(localizedHour, localizedMinute, s3Time.getSecond());
    lv_utils_setDate(localizedYear, localizedMonth, localizedDay);

    free(localizedDateTime);
  }

  if ((millis() - previousScreenTouch) / 1000 >= screenTimeout &&
      screenTimeout != TIMEOUT_NEVER && screenInteractive) {
    display.sleep();
    screenInteractive = false;
  }

  if (wallpaperChanged) {
    wallpaperChanged = false;
    fileSystem.editSetting(FS_VAR_SETTINGS_THEMES_WALLPAPER,
                           String(screenWallpaperID).c_str());
  }

  if (fontChanged) {
    fontChanged = false;
    fileSystem.editSetting(FS_VAR_SETTINGS_THEMES_FONT_SMALL,
                           String(sFont).c_str());
    fileSystem.editSetting(FS_VAR_SETTINGS_THEMES_FONT_MEDIUM,
                           String(mFont).c_str());
    fileSystem.editSetting(FS_VAR_SETTINGS_THEMES_FONT_LARGE,
                           String(lFont).c_str());
  }

  if (bluetoothStatusChanged) {
    bluetoothStatusChanged = false;
    fileSystem.editSetting(FS_VAR_SETTINGS_CONNECTIVITY_BLE,
                           String(bluetoothLEEnabled).c_str());
  }

  if (themeChanged) {
    themeChanged = false;
    fileSystem.editSetting(FS_VAR_SETTINGS_THEMES_THEME_DARK,
                           String(darkThemeSelected).c_str());
    lv_utils_applyTheme();
  }

  if (s3Time.isTimeUpdated()) {
    // set lvCurrentTime and lvCurrentDate eg (MM/DD/YYYY Tue)
    // https://cplusplus.com/reference/ctime/strftime/
    currentTimeHour = s3Time.getHour();
    currentTimeMinute = s3Time.getMinute();
    currentTimeSecond = s3Time.getSecond();
    sprintf(lvCurrentTime, "%02d:%02d", currentTimeHour, currentTimeMinute);
    sprintf(lvCurrentDate, "%s/%s/%s %s", s3Time.getTime("%d"),
            s3Time.getTime("%m"), s3Time.getTime("%Y"), s3Time.getTime("%a"));
    if (homeScreenVisible) {
      ui_utils_updateTimeDate();
    }
  }

  if (updateTimeSet) {
    updateTimeSet = false;
    s3Time.setTime(currentTimeSecond, currentTimeMinute, currentTimeHour,
                   s3Time.getDay(), s3Time.getMonth(), s3Time.getYear(),
                   s3Time.getMicros());
    fileSystem.editSetting(
        FS_VAR_SETTINGS_DATE_TIME_TIME,
        String((s3Time.getHour() < 10 ? "0" : "") + String(s3Time.getHour()) +
               ":" + (s3Time.getMinute() < 10 ? "0" : "") +
               String(s3Time.getMinute()) + ":" +
               (s3Time.getSecond() < 10 ? "0" : "") +
               String(s3Time.getSecond()))
            .c_str());
  }

  if (syncTimeAutomaticallyChanged) {
    syncTimeAutomaticallyChanged = false;
    fileSystem.editSetting(FS_VAR_SETTINGS_DATE_TIME_SYNC,
                           String(syncTimeAutomatically).c_str());
  }

  if (wifiScreenVisible && wifiEnabled && wifiReady) {
    if (s3WiFi->shouldRefreshUI()) {
      lv_utils_refreshWiFiList();
      s3WiFi->setRefreshUI(false);
    }
  }
}
