#ifndef CONFIG_HPP_
#define CONFIG_HPP_

// GSM
#define GSM_RX 4
#define GSM_TX 5
#define GSM_BAUD 9600

// Display (ILI9341) - Touch (XPT2046)
#define TFT_CS 15
#define TFT_RST 16
#define TFT_DC 17
#define TFT_MISO 9
#define TFT_MOSI 18
#define TFT_CLK 8
#define TFT_LED 3
#define TOUCH_CLK TFT_CLK
#define TOUCH_CS 10
#define TOUCH_DIN TFT_MOSI
#define TOUCH_DO TFT_MISO

#define CALIBRATION_DATA \
  { 282, 433, 252, 3865, 3815, 438, 3833, 3878 }

#define TFT_WIDTH 240
#define TFT_HEIGHT 320
#define TFT_DRAW_BUF_SIZE (TFT_WIDTH * TFT_HEIGHT / 10 * (LV_COLOR_DEPTH / 8))

#endif  // CONFIG_HPP_