#include <Arduino.h>
#include <lvgl.h>

#include <Display.hpp>
#include <GSM.hpp>
#include <Helpers.hpp>

#include "ui.h"

GSM gsm(GSM_RX, GSM_TX, GSM_BAUD);
static Display display(TFT_CLK, TFT_MOSI, TFT_MISO, TFT_CS, TFT_DC, TFT_RST,
                       TFT_LED, TOUCH_CS, TOUCH_CLK, TOUCH_DIN, TOUCH_DO);

S3Time s3Time("2024-07-08 09:40:56", 3);

unsigned int lastTickMillis = 0;

void *drawBuffer;
const unsigned int lvBufferSize = TFT_DRAW_BUF_SIZE;
uint8_t lvBuffer[lvBufferSize];

/* Display flushing*/
void lv_flush_cb(lv_display_t *disp, const lv_area_t *area,
                 unsigned char *data);

/* Read the touchpad*/
void my_touchpad_read(lv_indev_t *indev_driver, lv_indev_data_t *data);

void setup() {
  if (DEBUG) {
    Serial.begin(115200);
  }
  gsm.init();
  display.init();
  display.setRotation(2);
  display.setBrightness(255);
  display.fillScreen(TFT_BLUE);
  uint16_t calibrationData[8] = CALIBRATION_DATA;
  display.setTouchCalibrate(calibrationData);
  DEBUG_PRINTLN("Calibration done");

  lv_init();
  DEBUG_PRINTLN("LVGL initialized");
  lv_tick_set_cb((lv_tick_get_cb_t)millis);

  static auto *lv_display = lv_display_create(TFT_WIDTH, TFT_HEIGHT);

  if (lv_display == NULL) {
    DEBUG_PRINTLN("Failed to create display");
    while (1);
  }

  lv_display_set_color_format(lv_display, LV_COLOR_FORMAT_RGB565);

  lv_display_set_flush_cb(
      lv_display,
      [](lv_display_t *l_display, const lv_area_t *area, unsigned char *data) {
        uint32_t w = lv_area_get_width(area);
        uint32_t h = lv_area_get_height(area);
        lv_draw_sw_rgb565_swap(data, w * h);
        display.pushImage(area->x1, area->y1, w, h, (uint16_t *)data);
        lv_display_flush_ready(l_display);
      });
  DEBUG_PRINTLN("Display flush callback set");
  lv_display_set_buffers(lv_display, lvBuffer, nullptr, lvBufferSize,
                         LV_DISPLAY_RENDER_MODE_PARTIAL);
  DEBUG_PRINTLN("Display buffers set");

  // lv_display_set_flush_cb(lv_display, lv_flush_cb);

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

  ui_init();
}

void loop() {
  unsigned int tickPeriod = millis() - lastTickMillis;
  lv_tick_inc(tickPeriod);
  lastTickMillis = millis();

  lv_timer_handler();
}

// ----------------------------------------------------------
void lv_flush_cb(lv_display_t *disp, const lv_area_t *area,
                 unsigned char *data) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  display.startWrite();
  display.setAddrWindow(area->x1, area->y1, w, h);
  // display.pushColors((uint16_t *)color_p, w * h, true);
  display.writePixels((uint16_t *)data, w * h);
  display.endWrite();

  lv_disp_flush_ready(disp);
}

/* Read the touchpad*/
void my_touchpad_read(lv_indev_t *indev_driver, lv_indev_data_t *data) {
  uint16_t touchX, touchY;

  bool touched = display.getTouch(&touchX, &touchY);

  if (!touched) {
    data->state = LV_INDEV_STATE_REL;
  } else {
    data->state = LV_INDEV_STATE_PR;

    /*Set the coordinates*/
    data->point.x = touchX;
    data->point.y = touchY;

    DEBUG_PRINTF("Touch: %d, %d\n", data->point.x, data->point.y);
  }
}