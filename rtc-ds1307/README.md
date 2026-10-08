# ⏰ Real-Time Clock (RTC DS3231) Digital Clock with OLED Display (Arduino)

Dự án đồng hồ thời gian thực sử dụng module **RTC DS3231**, màn hình **OLED SSD1306 (I2C)** để hiển thị giờ, phút, giây, ngày, tháng, năm và thứ trong tuần trên vi điều khiển Arduino.

---

## 📌 Tính năng chính

* **Giám sát thời gian thực chính xác cao:** Đọc dữ liệu thời gian từ module RTC DS3231 với sai số cực thấp nhờ thạch anh tích hợp bên trong chip.
* **Tự động đồng bộ thời gian:** Tự động kiểm tra trạng thái nguồn (`lostPower()`) và cập nhật thời gian theo giờ máy tính khi nạp code (`F(__DATE__)`, `F(__TIME__)`).
* **Hiển thị thông số đầy đủ trên OLED:**
  * **Dòng 1 (Size 2):** Giờ:Phút:Giây (Định dạng $24\text{h}$ có chèn số `0` phía trước).
  * **Dòng 2 (Size 1):** Ngày/Tháng/Năm.
  * **Dòng 3 (Size 1):** Thứ trong tuần dạng tiếng Việt (`CN`, `Thu 2` $\rightarrow$ `Thu 7`).
* **Chuẩn hóa chuỗi hiển thị:** Tự động căn chỉnh format chữ số $0$ cho các giá trị nhỏ hơn $10$ (ví dụ: `09:05:02`).

---

## 🛠 Sơ đồ kết nối phần cứng (Pinout)

| Linh kiện / Peripherals | Chân Arduino | Ghi chú |
| :--- | :--- | :--- |
| **Module RTC DS3231 (SDA)** | `A4` (SDA) | Giao tiếp I2C chung bus với OLED |
| **Module RTC DS3231 (SCL)** | `A5` (SCL) | Giao tiếp I2C chung bus với OLED |
| **Màn hình OLED (SDA)** | `A4` (SDA) | Giao tiếp I2C (`0x3C`) |
| **Màn hình OLED (SCL)** | `A5` (SCL) | Giao tiếp I2C (`0x3C`) |
| **Nguồn cấp VCC / GND** | `5V` / `GND` | Cấp nguồn cho RTC DS3231 và OLED |

---

## 📦 Thư viện yêu cầu

Cài đặt các thư viện sau trong **Arduino IDE** (*Tools -> Manage Libraries...*):

* `RTClib` by Adafruit
* `Adafruit SSD1306`
* `Adafruit GFX Library`
* `Wire` (Tích hợp sẵn trong Arduino Core)

---
