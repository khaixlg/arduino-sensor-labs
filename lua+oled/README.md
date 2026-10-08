# 🔥 Flame Detection & Fire Alarm System with OLED Display (Arduino)

Dự án hệ thống cảnh báo cháy sớm sử dụng cảm biến phát hiện lửa (Flame Sensor), màn hình **OLED SSD1306 (I2C)**, còi báo động **Buzzer (`tone()`)** và đèn **LED** chỉ thị trên vi điều khiển Arduino.

---

## 📌 Tính năng chính

* **Phát hiện lửa / Tia hồng ngoại:** Đọc tín hiệu số (Digital Input) từ chân DO của cảm biến lửa qua chân `D7`.
* **Cảnh báo cháy tức thời:** Kích hoạt còi báo động Buzzer tần số $2000\text{ Hz}$ và bật đèn LED (`D13`) ngay khi phát hiện có nguồn lửa.
* **Hiển thị trạng thái trực quan:** Cập nhật ngay trạng thái `"BAO CHAY !"` hoặc `"BINH THUONG"` lên màn hình OLED 0.96 inch.
* **Tự động ngắt còi:** Tắt còi báo động (`noTone()`) và trả hệ thống về trạng thái an toàn ngay khi không còn tín hiệu lửa.

---

## 🛠 Sơ đồ kết nối phần cứng (Pinout)

| Linh kiện / Peripherals | Chân Arduino | Ghi chú |
| :--- | :--- | :--- |
| **Cảm biến lửa Flame Sensor (DO)** | `D7` | Tín hiệu Digital Input (Mức LOW = Có lửa) |
| **Còi báo động (Buzzer)** | `D12` | Kích hoạt âm thanh tần số $2000\text{ Hz}$ |
| **Đèn LED báo hiệu** | `D13` | Bật sáng khi báo cháy |
| **Màn hình OLED (SDA)** | `A4` (SDA) | Giao tiếp I2C (`0x3C`) |
| **Màn hình OLED (SCL)** | `A5` (SCL) | Giao tiếp I2C (`0x3C`) |
| **Nguồn cấp VCC / GND** | `5V` / `GND` | Cấp nguồn cho các module linh kiện |

---

## 📦 Thư viện yêu cầu

Cài đặt các thư viện sau trong **Arduino IDE** (*Tools -> Manage Libraries...*):

* `Adafruit SSD1306`
* `Adafruit GFX Library`
* `Wire` (Tích hợp sẵn trong Arduino Core)

---

## 🚀 Hướng dẫn sử dụng

1. Kết nối linh kiện theo đúng bảng **Pinout** ở trên.
2. Mở file mã nguồn `.ino` bằng **Arduino IDE**.
3. Chọn đúng loại Bo mạch (ví dụ: *Arduino Uno* hoặc *Arduino Nano*) và Cổng COM tương ứng.
4. Bấm **Upload** để nạp chương trình.
5. Dùng bật lửa hoặc nguồn phát hồng ngoại kiểm thử để quan sát phản hồi của màn hình OLED và còi báo động.

---
