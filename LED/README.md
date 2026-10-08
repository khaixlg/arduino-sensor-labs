# 💡 Arduino 5-LED Multi-Effect Controller with Dual Buttons

Dự án sử dụng vi điều khiển **Arduino** điều khiển dãy 5 đèn LED chạy các hiệu ứng ánh sáng liên tục không sử dụng hàm `delay()` (non-blocking), kết hợp với 2 nút bấm điều khiển trạng thái thực thi.

---

## 📌 Tính năng chính

* **3 Chế độ hiệu ứng ánh sáng (Chạy nối tiếp):**
  * **Mode 1 (Blink):** Nhấp nháy toàn bộ 5 LED (chu kỳ 300ms).
  * **Mode 2 (Chaser):** Đèn chạy đuổi từ trái sang phải (chu kỳ 150ms).
  * **Mode 3 (Alternate):** Chớp nháy chẵn/lẻ xen kẽ (chu kỳ 300ms).
* **Điều khiển chuyển trạng thái qua 2 Nút bấm:**
  * **Nút 1 (Reset / Start):** Khởi tạo lại hệ thống, quay về chạy hiệu ứng từ Mode 1.
  * **Nút 2 (Pause / Override):** Kích hoạt chế độ tạm dừng, bật sáng tất cả 5 LED trong 5 giây, sau đó tắt toàn bộ và chờ lệnh mới.
* **Lập trình Non-blocking (`millis()`):** Xử lý hiệu ứng và đọc nút bấm phản hồi tức thời mà không làm gián đoạn chương trình.

---

## 🛠 Sơ đồ kết nối phần cứng (Pinout)

| Linh kiện / Peripherals | Chân Arduino | Ghi chú |
| :--- | :--- | :--- |
| **LED 1 - LED 5** | `D2, D3, D4, D5, D6` | Nối nối tiếp trở $220\Omega$ xuống GND |
| **Nút bấm 1 (Start/Reset)** | `D7` | Chế độ `INPUT_PULLUP` (Nối xuống GND khi nhấn) |
| **Nút bấm 2 (Hold 5s)** | `D8` | Chế độ `INPUT_PULLUP` (Nối xuống GND khi nhấn) |
| **Nguồn cấp** | `5V` / `GND` | Cấp nguồn cho vi điều khiển & LED |

---

## 🚀 Hướng dẫn sử dụng

1. Kết nối LED và nút bấm theo bảng **Pinout** ở trên.
2. Mở file mã nguồn `.ino` bằng **Arduino IDE**.
3. Chọn đúng loại Bo mạch (ví dụ: *Arduino Uno* hoặc *Arduino Nano*) và Cổng COM tương ứng.
4. Bấm **Upload** để nạp chương trình.
5. Nhấn **Nút 1** để bắt đầu hoặc làm mới chuỗi hiệu ứng. Nhấn **Nút 2** để kích hoạt chế độ sáng toàn bộ 5 giây.

---
