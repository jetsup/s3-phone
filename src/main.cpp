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

  bool bleEnabledMain =
      fileSystem.readSetting(FS_VAR_SETTINGS_CONNECTIVITY_BLE).toInt();
  lv_utils_setBluetooth(bleEnabledMain);

  bool wifiEnabledMain =
      fileSystem.readSetting(FS_VAR_SETTINGS_NETWORKING_WIFI_STATE).toInt();
  lv_utils_setWiFi(wifiEnabledMain);
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
  xTaskCreatePinnedToCore(s3looperTask, "S3Looper", 4096, NULL, 1, NULL, 1);
}

void loop() {
  //   unsigned int tickPeriod = millis() - lastTickMillis;
  //   lv_tick_inc(tickPeriod);
  //   lastTickMillis = millis();

  lv_timer_handler();
  s3UILooper();
}
