#include <Display.hpp>

Display::Display(uint8_t tftCLK, uint8_t tftMOSI, uint8_t tftMISO,
                 uint8_t tftCS, uint8_t tftDC, uint8_t tftRST, uint8_t tftLED,
                 uint8_t touchCS, uint8_t touchCLK, uint8_t touchDIN,
                 uint8_t touchDO) {
  {
    auto cfg = _bus_instance.config();
    cfg.spi_host = SPI3_HOST;
    cfg.spi_mode = 0;
    cfg.freq_write = 40000000;
    cfg.freq_read = 16000000;
    cfg.spi_3wire = false;
    cfg.use_lock = true;
    cfg.dma_channel = SPI_DMA_CH_AUTO;

    cfg.pin_sclk = tftCLK;
    cfg.pin_mosi = tftMOSI;
    cfg.pin_miso = tftMISO;
    cfg.pin_dc = tftDC;

    _bus_instance.config(cfg);
    _panel_instance.setBus(&_bus_instance);
  }

  {
    auto cfg = _panel_instance.config();

    cfg.pin_cs = 15;
    cfg.pin_rst = 16;
    cfg.pin_busy = -1;

    cfg.panel_width = 240;
    cfg.panel_height = 320;
    cfg.offset_x = 0;
    cfg.offset_y = 0;
    cfg.offset_rotation = 0;
    cfg.dummy_read_pixel = 8;
    cfg.dummy_read_bits = 1;
    cfg.readable = true;
    cfg.invert = false;
    cfg.rgb_order = false;
    cfg.dlen_16bit = false;

    cfg.bus_shared = true;
    cfg.memory_width = 240;
    cfg.memory_height = 320;

    _panel_instance.config(cfg);
  }

  {
    auto cfg = _light_instance.config();

    cfg.pin_bl = 3;
    cfg.invert = false;
    cfg.freq = 44100;
    cfg.pwm_channel = 7;

    _light_instance.config(cfg);
    _panel_instance.setLight(&_light_instance);
  }
  {
    auto cfg = _touch_instance.config();

    cfg.x_min = 0;
    cfg.x_max = 239;
    cfg.y_min = 0;
    cfg.y_max = 319;
    cfg.pin_int = -1;
    cfg.bus_shared = true;
    cfg.offset_rotation = 0;

    cfg.spi_host = SPI3_HOST;
    cfg.freq = 1000000;
    cfg.pin_sclk = 8;
    cfg.pin_mosi = 18;
    cfg.pin_miso = 9;
    cfg.pin_cs = 10;

    _touch_instance.config(cfg);
    _panel_instance.setTouch(&_touch_instance);
  }
  setPanel(&_panel_instance);
}

