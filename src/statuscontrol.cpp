#include <Arduino.h>
#include "statuscontrol.h"

char current_status;           /// Trạng thái của thiết bị thay đổi tuần tự

void setup_statuscontrol()
{
    /// Nút bấm đầu vào tích cực mức cao
    pinMode(PIN_LEFT_BUTTON, PULLDOWN);
    /// Nút bấm đầu vào tích cực mức cao
    pinMode(PIN_RIGHT_BUTTON, PULLDOWN);
    /// Trạng thái hoạt động đầu tiên
    current_status = 0;
}

void loop_statuscontrol()
{
    if (digitalRead(PIN_LEFT_BUTTON) == 1) {
        current_status = (current_status ==0)?(NUM_OF_STATUS -1):current_status-1;
    } else if (digitalRead(PIN_RIGHT_BUTTON) == 1) {
        current_status = (current_status == NUM_OF_STATUS)?0:current_status+1;
    }    
}