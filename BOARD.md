# ESP32-S3 Touch AMOLED 1.43 (Waveshare)

MCU: ESP32-S3  
Flash: 16MB  
PSRAM: 8MB  

Display:
AMOLED 1.43"
Resolution: 466x466
Driver: SH8601 / CO5300
Interface: QSPI

Touch:
Controller: FT3168 / FT6146
Interface: I2C

Important pins:

Display QSPI
GPIO9  - CS
GPIO10 - CLK
GPIO11 - D0
GPIO12 - D1
GPIO13 - D2
GPIO14 - D3
GPIO21 - RST
GPIO42 - EN

Touch
GPIO47 - SDA
GPIO48 - SCL

IMU
GPIO8 - INT
I2C: 47 / 48