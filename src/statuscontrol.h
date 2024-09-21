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
 
/// @brief  Trạng thái hoạt động hiện thời, chức năng test hiện thời
extern char current_status;
/// @brief  Cờ báo hiệu mới chuyển trạng thái, cần khởi tạo 
extern bool must_setup;


#ifndef STATUS_CONTROL_H
#define STATUS_CONTROL_H

#define PIN_LEFT_BUTTON  33     /// @brief Nút bấm chuyển trạng thái, tích cực mức cao
#define PIN_RIGHT_BUTTON 35    /// @brief Nút bấm chuyển trạng thái, tích cực mức cao

#define NUM_OF_STATUS   3      /// Số lượng tối đa các trạng thái hoạt động và kiểm tra

void setup_statuscontrol();

void loop_statuscontrol();

#endif