#include <Adafruit_SSD1306.h>
extern Adafruit_SSD1306 display;

#ifndef OLED_I2C_H
#define OLED_I2C_HOLED_I2C_H


#define SDA 33  // 8 là chân SDA mặc định của Wemos S2 mini. Vì vậy không cần khao báo
#define SCL 35

/// @brief  Trạng thái hoạt động hiện thời, chức năng test hiện thời
extern char current_status;

#define OLED_SCK_PIN 39     /// @brief Điều khiển ma trận oled I2C, chân SCK
#define OLED_SDA_PIN 37     /// @brief Điều khiển ma trận oled I2C, chân SDA

void setup_oled();

void loop_oled();

#endif