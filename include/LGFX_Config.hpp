#pragma once

#include <LovyanGFX.hpp>

class LGFX : public lgfx::LGFX_Device {
 private:
  // NOTE:
  // LovyanGFX v1.2.x used by PlatformIO does not expose Panel_SH8601,
  // so we use a supported panel class with custom timing/geometry.
  lgfx::Panel_ST7796 _panel_instance;
  lgfx::Bus_SPI _bus_instance;

 public:
  LGFX() {
    {
      auto cfg = _bus_instance.config();
      cfg.spi_host = SPI2_HOST;
      cfg.spi_mode = 0;
      cfg.freq_write = 80000000;
      cfg.freq_read = 20000000;

      // This board wiring does not expose a dedicated DC pin.
      // Use 3-wire command mode and D0 as data line.
      cfg.spi_3wire = true;
      cfg.use_lock = true;
      cfg.dma_channel = SPI_DMA_CH_AUTO;

      cfg.pin_sclk = 10;
      cfg.pin_mosi = 11;  // D0
      cfg.pin_miso = -1;
      cfg.pin_dc = -1;

      _bus_instance.config(cfg);
      _panel_instance.setBus(&_bus_instance);
    }

    {
      auto cfg = _panel_instance.config();
      cfg.pin_cs = 9;
      cfg.pin_rst = 21;
      cfg.pin_busy = -1;

      cfg.memory_width = 466;
      cfg.memory_height = 466;
      cfg.panel_width = 466;
      cfg.panel_height = 466;
      cfg.offset_x = 0;
      cfg.offset_y = 0;
      cfg.offset_rotation = 0;
      cfg.dummy_read_pixel = 8;
      cfg.dummy_read_bits = 1;
      cfg.readable = false;
      cfg.invert = false;
      cfg.rgb_order = false;
      cfg.dlen_16bit = false;
      cfg.bus_shared = false;

      _panel_instance.config(cfg);
    }

    setPanel(&_panel_instance);
  }
};
