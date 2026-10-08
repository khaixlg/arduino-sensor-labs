# 📏 Ultrasonic Distance Meter with OLED & Multi-Stage Frequency Alarm

Dự án đo khoảng cách chính xác bằng cảm biến siêu âm **HC-SR04**, hiển thị thông số căn giữa màn hình **OLED SSD1306 (I2C)** và phát cảnh báo còi **Buzzer (`tone()`)** kết hợp **LED** theo từng khoảng tần số âm thanh khác nhau trên Arduino.

---

## 📌 Tính năng chính

* **Đo khoảng cách chính xác:** Sử dụng cảm biến HC-SR04 đo khoảng cách thực tế (giới hạn timeout 30ms ~ 5m).
* **Hiển thị OLED chuyên nghiệp:**
  * Màn hình khởi động chào mừng "HC-SR04 READY".
  * Tự động tính toán căn giữa văn bản (Center alignment) giá trị khoảng cách trên màn hình.
  * Báo trạng thái lỗi `"LOI"` khi không có phản hồi xung (Echo timeout) hoặc vượt ngưỡng `>4m`.
* **Cảnh báo âm thanh & ánh sáng đa tầng (Multi-stage Alarm Logic):**
  * **$\le$ 10 cm:** Trạng thái bình thường, tắt còi và LED.
  * **10 cm - 20 cm:** Cảnh báo nhịp chậm (Tần số $1000\text{ Hz}$, chớp tắt chu kỳ $200\text{ms} / 600\text{ms}$).
  * **20 cm - 30 cm:** Cảnh báo dồn dập (Tần số $2000\text{ Hz}$, chớp tắt chu kỳ $150\text{ms} / 150\text{ms}$).
  * **> 30 cm:** Báo động tần số cao liên tục ($3000\text{ Hz}$, LED sáng liên tục).

---

## 🛠 Sơ đồ kết nối phần cứng (Pinout)

| Linh kiện / Peripherals | Chân Arduino | Ghi chú |
| :--- | :--- | :--- |
| **HC-SR04 (Trig)** | `D9` | Phát xung siêu âm |
| **HC-SR04 (Echo)** | `D10` | Nhận xung phản hồi |
| **Còi báo động (Buzzer)** | `D6` | Phát tần số bằng hàm `tone()` |
| **Đèn LED báo hiệu** | `D7` | Bật/tắt/chớp nháy theo khoảng cách |
| **Màn hình OLED (SDA)** | `A4` (SDA) | Giao tiếp I2C (`0x3C`) |
| **Màn hình OLED (SCL)** | `A5` (SCL) | Giao tiếp I2C (`0x3C`) |
| **Nguồn cấp VCC / GND** | `5V` / `GND` | Cấp nguồn cho vi điều khiển & linh kiện |

---

## 📦 Thư viện yêu cầu

Cài đặt các thư viện sau trong **Arduino IDE** (*Tools -> Manage Libraries...*):

* `Adafruit SSD1306`
* `Adafruit GFX Library`
* `Wire` (Tích hợp sẵn trong Arduino Core)

---

## 🚀 Hướng dẫn sử dụng

1. Kết nối linh kiện theo bảng **Pinout** ở trên.
2. Mở file mã nguồn `.ino` bằng **Arduino IDE**.
3. Chọn đúng loại Bo mạch (ví dụ: *Arduino Uno* hoặc *Arduino Nano*) và Cổng COM tương ứng.
4. Bấm **Upload** để nạp chương trình.
5. Mở **Serial Monitor** với tốc độ baud `9600` để theo dõi khoảng cách chi tiết thu được.

---
