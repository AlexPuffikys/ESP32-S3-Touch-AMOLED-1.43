# Project AI Instructions

This project uses:

- PlatformIO
- Arduino framework
- ESP32-S3
- LovyanGFX for display
- LVGL for UI (planned)

Target board:
ESP32-S3 Touch AMOLED 1.43 (Waveshare)

Hardware configuration:

Flash: 16MB
PSRAM: 8MB

Display:
AMOLED 1.43"
Resolution: 466x466
Driver: SH8601
Interface: QSPI

Display pins:

CS   GPIO9
CLK  GPIO10
D0   GPIO11
D1   GPIO12
D2   GPIO13
D3   GPIO14
RST  GPIO21
EN   GPIO42

Touch controller:
FT3168 (I2C)

SDA GPIO47
SCL GPIO48

IMU:
connected via I2C
INT GPIO8

Coding rules:

- Always generate PlatformIO compatible code
- Do NOT generate Arduino IDE sketches
- Use LovyanGFX for display driver
- Use separate configuration class for display
- Prefer modular architecture

Expected structure:

src/
main.cpp

lib/
display/
touch/
imu/

include/
board_config.h