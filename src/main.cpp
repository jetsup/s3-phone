#include <Main.hpp>

void setup() {
  if (DEBUG) {
    Serial.begin(115200);
  }
  analogReadResolution(S3_PHONE_ANALOG_RESOLUTION);
  analogWriteResolution(S3_PHONE_ANALOG_RESOLUTION);

  gsm.init();
  fileSystem.init();
  //================Initialize all variables from settings data=================
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

      bool blcEnabled=fileSystem.readSetting(FS_VAR_SETTINGS_CONNECTIVITY_BLC).toInt();
      bool bleEnabled=fileSystem.readSetting(FS_VAR_SETTINGS_CONNECTIVITY_BLE).toInt();
      lv_utils_setBluetooth(blcEnabled, bleEnabled);
  //=============================================================================
  display.init();
  display.setRotation(2);
  display.fillScreen(TFT_BLACK);
  uint16_t calibrationData[8] = CALIBRATION_DATA;
  display.setTouchCalibrate(calibrationData);

  lv_init();
  lv_tick_set_cb((lv_tick_get_cb_t)millis);

  lv_display = lv_display_create(TFT_WIDTH, TFT_HEIGHT);

  if (lv_display == NULL) {
    DEBUG_PRINTLN("Failed to create display");
    while (1);
  }

  lv_display_set_color_format(lv_display, LV_COLOR_FORMAT_RGB565);

  lv_display_set_flush_cb(lv_display, lv_flush_cb);
  lv_display_set_buffers(lv_display, lvBuffer, lvBuffer2, lvBufferSize * 2,
                         LV_DISPLAY_RENDER_MODE_PARTIAL);

  drawBuffer =
      heap_caps_malloc(TFT_DRAW_BUF_SIZE, MALLOC_CAP_DMA | MALLOC_CAP_INTERNAL);

  if (drawBuffer == NULL) {
    DEBUG_PRINTLN("Failed to allocate draw buffer");
    while (1);
  }

  // Initialize the input device driver
  lv_indev_t *indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, my_touchpad_read);

  for (int i = 0; i < 4; i++) {
    DEBUG_PRINTF(">> %s %s\n", names[i], numbers[i]);
  }

  contactsCount = 4;

  for (int i = 0; i < 4; i++) {
    cNames[i] = (char *)names[i].c_str();
    cNumbers[i] = (char *)numbers[i].c_str();

    DEBUG_PRINTF("%s::%s\n", cNames[i], cNumbers[i]);
    cCount++;
  }

  // set the current date so that it can be used to initialize the calendar
  sprintf(lvCurrentDate, "%s/%s/%s %s", s3Time.getTime("%d"),
          s3Time.getTime("%m"), s3Time.getTime("%Y"), s3Time.getTime("%a"));

  ui_init();
  DEBUG_PRINTLN("UI initialized");
}

void loop() {
  unsigned int tickPeriod = millis() - lastTickMillis;
  lv_tick_inc(tickPeriod);
  lastTickMillis = millis();

  lv_timer_handler();
  s3Time.loop();
  if (s3Time.isTimeUpdated()) {
    // set lvCurrentTime and lvCurrentDate eg (MM/DD/YYYY Tue)
    // https://cplusplus.com/reference/ctime/strftime/
    sprintf(lvCurrentTime, "%s", s3Time.getTime("%H:%M"));
    sprintf(lvCurrentDate, "%s/%s/%s %s", s3Time.getTime("%d"),
            s3Time.getTime("%m"), s3Time.getTime("%Y"), s3Time.getTime("%a"));

    ui_utils_updateTimeDate();
  }

  if (dateChanged) {
    s3Time.setTime(s3Time.getSecond(), s3Time.getMinute(), s3Time.getHour(),
                   newDay, newMonth, newYear, s3Time.getMicros());
    DEBUG_PRINTF("New Time: %s", s3Time.getTime());
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

  if ((millis() - previousScreenTouch) / 1000 /*seconds*/ >= screenTimeout &&
      screenTimeout != TIMEOUT_NEVER) {
    display.sleep();
    screenInteractive = false;
  }

  if (themeChanged) {
    themeChanged = false;
    fileSystem.editSetting(FS_VAR_SETTINGS_THEMES_THEME_DARK,
                           String(darkThemeSelected).c_str());
    lv_utils_applyTheme();
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
    fileSystem.editSetting(FS_VAR_SETTINGS_CONNECTIVITY_BLC,
                           String(bluetoothClassicEnabled).c_str());
    fileSystem.editSetting(FS_VAR_SETTINGS_CONNECTIVITY_BLE,
                           String(bluetoothLEEnabled).c_str());
  }
}
// ----------------------------------------------------------
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
