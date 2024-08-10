#pragma once

#include <Arduino.h>
#include <lvgl.h>

#include <Display.hpp>
#include <FileSystem.hpp>
#include <GSM.hpp>
#include <Helpers.hpp>
#include <Network.hpp>

#include "ui.h"
#include "ui_contacts.h"

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
        lv_utils_refreshWiFiList();
      }

      if (!s3WiFi->isConnected() && isWiFiConnected) {
        isWiFiConnected = false;
        lv_utils_refreshWiFiList();
      }

      if (!s3WiFi->credentialsSaved() && s3WiFi->isConnected()) {
        fileSystem.saveCredentials(CREDENTIALS_WIFI, s3WiFi->getSSID().c_str(),
                                   s3WiFi->getPassword().c_str());
        s3WiFi->setCredentialsSaved(true);
      }
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
    s3Time.setTime(s3Time.getSecond(), s3Time.getMinute(), s3Time.getHour(),
                   newDay, newMonth, newYear, s3Time.getMicros());
    DEBUG_PRINTF("New Time: %s\n", s3Time.getTime());
    dateChanged = false;
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
    sprintf(lvCurrentTime, "%s", s3Time.getTime("%H:%M"));
    sprintf(lvCurrentDate, "%s/%s/%s %s", s3Time.getTime("%d"),
            s3Time.getTime("%m"), s3Time.getTime("%Y"), s3Time.getTime("%a"));
    if (homeScreenVisible) {
      ui_utils_updateTimeDate();
    }
  }

  if (wifiScreenVisible && wifiEnabled && wifiReady) {
    if (s3WiFi->shouldRefreshUI()) {
      lv_utils_refreshWiFiList();
      s3WiFi->setRefreshUI(false);
    }
  }
}
