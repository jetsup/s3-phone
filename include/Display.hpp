#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include <Arduino.h>

#include <Config.hpp>
#include <LovyanGFX.hpp>

#include "ui_utils.h"

class Display : public lgfx::LGFX_Device {
  lgfx::Panel_ILI9341 _panel_instance;
  lgfx::Bus_SPI _bus_instance;
  lgfx::Light_PWM _light_instance;
  lgfx::Touch_XPT2046 _touch_instance;

 private:
  uint8_t _backlightPin;

 public:
  Display() = delete;

  /**
   * @brief Construct a new Display object
   */
  Display(uint8_t tftCLK, uint8_t tftMOSI, uint8_t tftMISO, uint8_t tftCS,
          uint8_t tftDC, uint8_t tftRST, uint8_t tftLED, uint8_t touchCS,
          uint8_t touchCLK, uint8_t touchDIN, uint8_t touchDO);

  /**
   * @brief Change screen brightness
   * @param brightness The new screen brightness
   */
  void updateBrightness(int brightness);

  /**
   * @brief Turn off the backlight
   */
  void sleep();

  /**
   * @brief Turn on the backlight
   */
  void wake();
};

#endif  // DISPLAY_HPP_
