#include <Arduino.h>
#include "sr04.h"
#include "ssd1306_128x64_i2c.h"

extern char current_status;           /// Trạng thái của thiết bị thay đổi tuần tự

void setup_sr04()
{
    /// Thiết lập cấu hình kết nối với SR-04
    pinMode(PIN_ECHO, INPUT);
    /// Nút bấm đầu vào tích cực mức cao
    pinMode(PIN_TRIG, OUTPUT);
    // Hiện thị thông báo
    //Hiển thị trên oled
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(2);
    display.setCursor(0, 0);
    display.print("SR-04 s.am");
    display.setTextSize(4);
    display.setCursor(6, 18);
    display.display();
    delay(200);    
}

/**
 * @brief Lấy khoảng cách từ cảm biến SR-04
 */
int GetDistance() {
  digitalWrite(PIN_TRIG, LOW);  // Set chan Trig xuong muc thap 2uS
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);  //Gui mot xung 10uS muc cao vao chan Trig
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);                      // Gui lai muc thap vao chan Trig
  unsigned int distance = pulseIn(PIN_ECHO, HIGH);  // Doc thoi gian tra ve. Hay dung kieu unsign. Da ghi nhan co so am tra ve roi
  return distance / 58;                             // Tinh toan khoang cach
}

void loop_sr04()
{
    static int dis;
    // Xóa thông tin cũ bằng cách ghi đè thông tin cũ với màu đen
    display.setCursor(6, 18);
    display.setTextColor(SSD1306_BLACK);
    display.print(dis);

    //Lấy khoảng cách mới
    dis = GetDistance();  

    //Hiện thị về serial
    Serial.println(dis);  
    
    //Hiển thị trên oled
    display.setCursor(6, 18);
    display.setTextColor(SSD1306_WHITE);
    display.print(dis);
    display.display();
    delay(200);    
}