#include <Arduino.h>
#include "statuscontrol.h"

char current_status;           // Trạng thái của thiết bị thay đổi tuần tự
bool must_setup;               // Cờ báo hiệu mới chuyển trạng thái, cần khởi tạo 

long pre_press_time;           // Thời điểm của lượt bấm trước, sử dụng để chống nhảy phím
long cur_press_time;           // Thời điểm của lượt bấm hiện tại, sử dụng để chống nhảy phím

#define LED_BUILTIN 15

void LeftButon_Click()
{
    // Chống nhảy phím 
    cur_press_time = millis();
    if (cur_press_time - pre_press_time < 300) return;
    pre_press_time = cur_press_time;
    
    // Chương trình con ngắt chính
    current_status = (current_status ==0)?(NUM_OF_STATUS -1):current_status-1;
    must_setup = true;      
    
}

void RightButon_Click()
{
    // Chống nhảy phím 
    cur_press_time = millis();    
    if (cur_press_time - pre_press_time < 300) return;
    pre_press_time = cur_press_time;
    
    // Chương trình con ngắt chính
    current_status = (current_status == NUM_OF_STATUS-1)?0:current_status+1;
    must_setup = true;      
}

void setup_statuscontrol()
{
    /// Nút bấm đầu vào tích cực mức cao
    pinMode(PIN_LEFT_BUTTON, INPUT_PULLDOWN);
    /// Nút bấm đầu vào tích cực mức cao
    pinMode(PIN_RIGHT_BUTTON, INPUT_PULLDOWN);
    /// Trạng thái hoạt động đầu tiên
    current_status = 0;
    // Phải setup chức năng đầu tiên
    must_setup = true;
    //
    attachInterrupt(PIN_LEFT_BUTTON, LeftButon_Click, RISING); 
    attachInterrupt(PIN_RIGHT_BUTTON, RightButon_Click, RISING); 
}