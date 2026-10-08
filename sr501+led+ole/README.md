# 🚨 PIR Motion Detector with OLED & Buzzer Alarm (Arduino)

Dự án phát hiện chuyển động thân nhiệt sử dụng cảm biến **PIR (HC-SR501)**, màn hình **OLED SSD1306 (I2C)**, còi báo động **Buzzer** và đèn **LED** cảnh báo trên vi điều khiển Arduino.

---

## 📌 Tính năng chính

* **Phát hiện chuyển động thân nhiệt:** Đọc tín hiệu số (Digital Input) từ cảm biến PIR HC-SR501 qua chân `D2`.
* **Cảnh báo đa phương thức:** Kích hoạt đồng thời còi báo động Buzzer (`D8`) và đèn LED (`D13`) ngay khi có chuyển động.
* **Giao diện hiển thị trực quan:** Cập nhật trạng thái `"CO CHUYEN DONG"` hoặc `"KHONG CHUYEN DONG"` lên màn hình OLED 0.96 inch.
* **Tối ưu phản hồi (State Tracking):** Sử dụng biến theo dõi trạng thái (`state`) giúp hệ thống chỉ cập nhật màn hình và Serial khi có sự thay đổi mức tín hiệu, tránh hiện tượng nhấp nháy màn hình liên tục.

---

## 🛠 Sơ đồ kết nối phần cứng (Pinout)

| Linh kiện / Peripherals | Chân Arduino | Ghi chú |
| :--- | :--- | :--- |
| **Cảm biến PIR HC-SR501 (OUT)** | `D2` | Tín hiệu Digital Input |
| **Còi báo động (Buzzer)** | `D8` | Kích hoạt khi có chuyển động |
| **Đèn LED báo hiệu** | `D13` | Bật khi phát hiện chuyển động |
| **Màn hình OLED (SDA)** | `A4` (SDA) | Giao tiếp I2C (`0x3C`) |
| **Màn hình OLED (SCL)** | `A5` (SCL) | Giao tiếp I2C (`0x3C`) |
| **Nguồn cấp VCC / GND** | `5V` / `GND` | Cấp nguồn cho PIR, OLED, Buzzer |

---

## 📦 Thư viện yêu cầu

Cài đặt các thư viện sau trong **Arduino IDE** (*Tools -> Manage Libraries...*):

* `Adafruit SSD1306`
* `Adafruit GFX Library`
* `Wire` (Tích hợp sẵn trong Arduino Core)

---

## 🚀 Hướng dẫn sử dụng

1. Kết nối linh kiện theo bảng **Pinout** ở trên.
2. Mở file `.ino` bằng **Arduino IDE**.
3. Chọn đúng loại Bo mạch (ví dụ: *Arduino Uno* hoặc *Arduino Nano*) và Cổng COM tương ứng.
4. Bấm **Upload** để nạp chương trình.
5. Mở **Serial Monitor** với tốc độ baud `9600` để theo dõi nhật ký hoạt động.

---
