# 🚧 IR Obstacle Detection with OLED & Buzzer Alarm (Arduino)

Dự án phát hiện vật cản khoảng cách gần sử dụng **cảm biến hồng ngoại (IR Obstacle Avoidance Sensor)**, màn hình **OLED SSD1306 (I2C)**, còi **Buzzer** và đèn **LED** cảnh báo trên vi điều khiển Arduino[cite: 13].

---

## 📌 Tính năng chính

* **Phát hiện vật cản IR:** Đọc tín hiệu số (Digital Input) từ chân DO của module cảm biến hồng ngoại qua chân `D7`[cite: 13].
* **Cảnh báo tức thời:** Tự động kích hoạt đồng thời còi báo động Buzzer (`D12`) và đèn LED (`D13`) ngay khi phát hiện vật cản (mức logic `LOW`)[cite: 13].
* **Giao diện hiển thị trực quan:** Cập nhật liên tục trạng thái `"CO VAT CAN"` hoặc `"BINH THUONG"` lên màn hình OLED 0.96 inch[cite: 13].
* **Giao tiếp I2C tiết kiệm chân:** Sử dụng chuẩn I2C truyền dữ liệu lên màn hình OLED chỉ với 2 chân SDA/SCL[cite: 13].

---

## 🛠 Sơ đồ kết nối phần cứng (Pinout)

| Linh kiện / Peripherals | Chân Arduino | Ghi chú |
| :--- | :--- | :--- |
| **Cảm biến vật cản IR (OUT)** | `D7` | Tín hiệu Digital Input (Mức LOW = Có vật cản)[cite: 13] |
| **Còi báo động (Buzzer)** | `D12` | Kích hoạt báo động khi phát hiện vật cản[cite: 13] |
| **Đèn LED báo hiệu** | `D13` | Bật sáng khi phát hiện vật cản[cite: 13] |
| **Màn hình OLED (SDA)** | `A4` (SDA) | Giao tiếp I2C (`0x3C`)[cite: 13] |
| **Màn hình OLED (SCL)** | `A5` (SCL) | Giao tiếp I2C (`0x3C`)[cite: 13] |
| **Nguồn cấp VCC / GND** | `5V` / `GND` | Cấp nguồn cho module IR, OLED và Buzzer[cite: 13] |

---

## 📦 Thư viện yêu cầu

Cài đặt các thư viện sau trong **Arduino IDE** (*Tools -> Manage Libraries...*):

* `Adafruit SSD1306`[cite: 13]
* `Adafruit GFX Library`[cite: 13]
* `Wire` (Tích hợp sẵn trong Arduino Core)[cite: 13]

---

