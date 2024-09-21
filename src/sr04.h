/**
 * @file statuscontrol.h
 * @author Nguyen Duc Tien
 * @brief Kiếm soát chức năng đo khoảng cách từ SR04 và hiện ra màn hình oled
 * @version 0.1
 * @date 2024-09-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */
 
#ifndef SR04_H
#define SR04_H

#define PIN_ECHO 13    /// @brief SR04.Echo
#define PIN_TRIG 12    /// @brief SR04.Trig

void setup_sr04();

void loop_sr04();

#endif