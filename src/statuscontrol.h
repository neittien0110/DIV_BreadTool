/**
 * @file statuscontrol.h
 * @author Nguyen Duc Tien
 * @brief Kiếm soát các đối tượng đầu vào nhằm thiết lập trạng thái hoạt động của board
 * @version 0.1
 * @date 2024-09-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */
 
#ifndef STATUS_CONTROL_H
#define STATUS_CONTROL_H

#define PIN_LEFT_BUTTON 12     /// @brief Nút bấm chuyển trạng thái, tích cực mức cao
#define PIN_RIGHT_BUTTON 13    /// @brief Nút bấm chuyển trạng thái, tích cực mức cao

#define NUM_OF_STATUS   3      /// Số lượng tối đa các trạng thái hoạt động và kiểm tra

void setup_statuscontrol();

void loop_statuscontrol();

#endif