/**
 * @file main.cpp
 * @author Nguyễn Đức Tiến
 * @brief 
 * @version 0.1
 * @date 2024-09-21
 * @see  https://neittien0110.github.io/MCU/ESP32/Lolin_S2_mini.html
 * @copyright Copyright (c) 2024
 * 
 */
#include <Arduino.h>
#include "ssd1306_128x64_i2c.h"
#include "statuscontrol.h"

/// @brief  Trạng thái hoạt động hiện thời, chức năng test hiện thời
extern char current_status;

void setup() {
  Serial.begin(115200);
  setup_oled();
  setup_statuscontrol();
}

void loop() {
  // Cập nhật trạng thái hoạt động mới thông qua các nút điều khiển
  loop_statuscontrol();
  // Chạy chức năng kiểm tra
  switch (current_status) {
    case 0: loop_oled();
    case 1: Serial.println("Trang thai 1"); delay(1000);
  }
}

