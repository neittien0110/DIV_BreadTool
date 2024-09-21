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
#include "sr04.h"

void setup() {
  Serial.begin(115200);
  setup_oled();
  setup_statuscontrol();
}

void loop() {
  // Cập nhật trạng thái hoạt động mới thông qua các nút điều khiển. Sử dụng ngắt rồi
  if (must_setup) {
    Serial.print("Chuyen trang thai TRUOC ==> ");
    Serial.println(current_status);        
  }
  // Chạy chức năng kiểm tra
  switch (current_status) {
    case 0: { 
              if (must_setup) setup_oled();
              must_setup = false;
              loop_oled(); 
              break; 
            }
    case 1: { 
              if (must_setup) setup_sr04();
              must_setup = false;
              loop_sr04(); 
              break; 
            }
    case 2: Serial.println("FEATURE YEAH"); delay(1000);break;
  }
}

