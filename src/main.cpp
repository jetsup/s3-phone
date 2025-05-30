#include <Main.hpp>

void setup() {
  if (DEBUG) {
    Serial.begin(115200);
    delay(2000);
  }
  analogReadResolution(S3_PHONE_ANALOG_RESOLUTION);
  analogWriteResolution(S3_PHONE_ANALOG_RESOLUTION);

  gsm.init();
  fileSystem.init();
  //================Initialize all variables from settings data=================
  loadSystemConfigurations();
  //=============================================================================
  display.init();
  display.setRotation(2);
  display.fillScreen(TFT_BLACK);
  uint16_t calibrationData[8] = CALIBRATION_DATA;
  display.setTouchCalibrate(calibrationData);

  lv_init();
  lv_tick_set_cb((lv_tick_get_cb_t)millis);

  lv_display = lv_display_create(TFT_WIDTH, TFT_HEIGHT);

  if (lv_display == nullptr) {
    DEBUG_PRINTLN("Failed to create display");
    while (true);
  }

  lv_display_set_color_format(lv_display, LV_COLOR_FORMAT_RGB565);

  lv_display_set_flush_cb(lv_display, lv_flush_cb);
  lv_display_set_buffers(lv_display, lvBuffer, lvBuffer2, lvBufferSize * 2,
                         LV_DISPLAY_RENDER_MODE_PARTIAL);

  drawBuffer =
      heap_caps_malloc(TFT_DRAW_BUF_SIZE, MALLOC_CAP_DMA | MALLOC_CAP_INTERNAL);

  if (drawBuffer == nullptr) {
    DEBUG_PRINTLN("Failed to allocate draw buffer");
    while (true);
  }

  // Initialize the input device driver
  lv_indev_t *indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, my_touchpad_read);

  ui_init();
  DEBUG_PRINTLN("UI initialized");
  xTaskCreatePinnedToCore(s3looperTask, "S3Looper", 4096, nullptr, 1, nullptr,
                          1);
}

void loop() {
  //   unsigned int tickPeriod = millis() - lastTickMillis;
  //   lv_tick_inc(tickPeriod);
  //   lastTickMillis = millis();

  lv_timer_handler();
  s3UILooper();
}
