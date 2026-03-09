#include <Arduino.h>

#include "LGFX_Config.hpp"

namespace {
constexpr int PIN_LCD_EN = 42;
LGFX lcd;
}  // namespace

void setup() {
  pinMode(PIN_LCD_EN, OUTPUT);
  digitalWrite(PIN_LCD_EN, HIGH);
  delay(20);

  lcd.init();
  lcd.setRotation(0);
  lcd.fillScreen(TFT_BLACK);
  lcd.setTextColor(TFT_WHITE, TFT_BLACK);
  lcd.setTextDatum(middle_center);
  lcd.setTextSize(2);
  lcd.drawString("Hello AMOLED", lcd.width() / 2, lcd.height() / 2);
}

void loop() {
  delay(1000);
}
