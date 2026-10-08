# 🎙️ Analog Sound Detector with OLED Display (Arduino)

Dự án sử dụng vi điều khiển **Arduino** kết hợp với **cảm biến âm thanh (Analog Output)** và màn hình **OLED SSD1306 (I2C)** để phát hiện tiếng động trong môi trường và hiển thị trạng thái trực quan.

---

## 📌 Tính năng chính

* **Giám sát âm thanh theo thời gian thực:** Đọc tín hiệu Analog từ cảm biến âm thanh qua chân `A0`.
* **Đánh giá ngưỡng tự động:** So sánh giá trị âm thanh thu được với ngưỡng cài đặt (`threshold = 200`) để xác định trạng thái.
* **Hiển thị giao diện OLED:** Cập nhật trạng thái `"PHÁT HIỆN TIẾNG ĐỘNG"` hoặc `"IM LẶNG"` lên màn hình OLED 0.96 inch.
* **Cảnh báo qua đèn LED:** Tự động bật đèn LED (chân `D13`) khi phát hiện tiếng động vượt ngưỡng.

---

## 🛠 Sơ đồ kết nối phần cứng (Pinout)

| Linh kiện / Peripherals | Chân Arduino | Ghi chú |
| :--- | :--- | :--- |
| **Cảm biến âm thanh (AO)** | `A0` | Chân đọc tín hiệu Analog |
| **Màn hình OLED (SDA)** | `A4` (SDA) | Giao tiếp I2C (`0x3C`) |
| **Màn hình OLED (SCL)** | `A5` (SCL) | Giao tiếp I2C (`0x3C`) |
| **Đèn LED báo hiệu** | `D13` | Bật khi phát hiện tiếng động |
| **Nguồn VCC / GND** | `5V` / `GND` | Cấp nguồn cho cảm biến & OLED |

---

## 📦 Thư viện yêu cầu

Để biên dịch và nạp code, bạn cần cài đặt các thư viện sau trong **Arduino IDE** (*Tools -> Manage Libraries...*):

* `Adafruit SSD1306`
* `Adafruit GFX Library`
* `Wire` (Tích hợp sẵn trong Arduino Core)

---

## 🚀 Hướng dẫn sử dụng

1. Kết nối phần cứng theo bảng **Pinout** ở trên.
2. Mở file `.ino` bằng **Arduino IDE**.
3. Chọn đúng loại Bo mạch (ví dụ: *Arduino Uno* hoặc *Arduino Nano*) và Cổng COM.
4. Bấm **Upload** để nạp chương trình.
5. Mở **Serial Monitor** với tốc độ baud `9600` để theo dõi giá trị cảm biến đọc về.

---

## 📄 Giấy phép (License)

Dự án được phân phối dưới giấy phép **MIT License**.
