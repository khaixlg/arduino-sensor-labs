# 🌡️ Temperature & Humidity Monitor with DHT11, OLED & Multi-Stage Alarm (Arduino)

Dự án giám sát nhiệt độ và độ ẩm thời gian thực sử dụng cảm biến **DHT11**, hiển thị thông số chi tiết trên màn hình **OLED SSD1306 (I2C)** và tự động kích hoạt hệ thống cảnh báo đa tầng qua còi **Buzzer (`tone()`)** cùng đèn **LED** chỉ thị trên vi điều khiển Arduino[cite: 14].

---

## 📌 Tính năng chính

* **Giám sát môi trường thời gian thực:** Đọc chính xác thông số nhiệt độ (°C) và độ ẩm (%) từ cảm biến DHT11 qua chân `D2`[cite: 14].
* **Bắt lỗi cảm biến (Error Handling):** Tự động phát hiện trạng thái mất kết nối hoặc đọc lỗi tín hiệu (`isnan`) và hiển thị thông báo `"Loi cam bien DHT11!"` lên màn hình OLED[cite: 14].
* **Hiển thị giao diện OLED:** Cập nhật liên tục nhiệt độ, độ ẩm và trạng thái cảnh báo hệ thống lên màn hình OLED 0.96 inch[cite: 14].
* **Hệ thống cảnh báo phân cấp 4 mức độ (Multi-stage Alarm System):**
  1. **🚨 CẢNH BÁO NGUY HIỂM ($T > 45^\circ\text{C}$ & $H < 30\%$):** Phát còi báo động liên tục tần số $1000\text{ Hz}$, LED sáng liên tục[cite: 14].
  2. **🔥 Nhiệt độ quá cao ($T > 40^\circ\text{C}$):** Phát còi dồn dập tần số $1800\text{ Hz}$ kết hợp chớp nháy LED chu kỳ $100\text{ms} / 100\text{ms}$[cite: 14].
  3. **⚠️ Nhiệt độ cao ($T > 30^\circ\text{C}$):** Phát còi nhịp chậm tần số $2000\text{ Hz}$ kết hợp chớp nháy LED chu kỳ $200\text{ms} / 800\text{ms}$[cite: 14].
  4. **✅ BÌNH THƯỜNG ($T \le 30^\circ\text{C}$):** Tắt toàn bộ còi (`noTone()`) và đèn LED chỉ thị[cite: 14].

---

## 🛠 Sơ đồ kết nối phần cứng (Pinout)

| Linh kiện / Peripherals | Chân Arduino | Ghi chú |
| :--- | :--- | :--- |
| **Cảm biến DHT11 (DATA)** | `D2` | Chân đọc dữ liệu nhiệt độ & độ ẩm[cite: 14] |
| **Còi báo động (Buzzer)** | `D9` | Chân PWM kích hoạt tần số bằng `tone()`[cite: 14] |
| **Đèn LED báo hiệu** | `D13` | Bật/chớp nháy theo từng mức cảnh báo[cite: 14] |
| **Màn hình OLED (SDA)** | `A4` (SDA) | Giao tiếp I2C (`0x3C` hoặc `0x3D`)[cite: 14] |
| **Màn hình OLED (SCL)** | `A5` (SCL) | Giao tiếp I2C (`0x3C` hoặc `0x3D`)[cite: 14] |
| **Nguồn cấp VCC / GND** | `5V` / `GND` | Cấp nguồn cho DHT11, OLED và Buzzer[cite: 14] |

---

## 📦 Thư viện yêu cầu

Cài đặt các thư viện sau trong **Arduino IDE** (*Tools -> Manage Libraries...*):

* `DHT sensor library` by Adafruit[cite: 14]
* `Adafruit SSD1306`[cite: 14]
* `Adafruit GFX Library`[cite: 14]
* `Wire` (Tích hợp sẵn trong Arduino Core)[cite: 14]

---

## 🚀 Hướng dẫn sử dụng

1. Kết nối linh kiện theo đúng bảng **Pinout** ở trên[cite: 14].
2. Mở file mã nguồn `.ino` bằng **Arduino IDE**[cite: 14].
3. Chọn đúng loại Bo mạch (ví dụ: *Arduino Uno* hoặc *Arduino Nano*) và Cổng COM tương ứng.
4. Bấm **Upload** để nạp chương trình.
5. Quan sát màn hình hiển thị OLED lúc khởi động (`"Starting..."`) và theo dõi thông số đo thời gian thực[cite: 14].

---

## 📄 Giấy phép (License)

Dự án được phân phối dưới giấy phép **MIT License**.
