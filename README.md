# ESP32 LED Control with OneButton

Dự án điều khiển đèn LED ngoài thông qua một nút nhấn (Push Button) sử dụng vi điều khiển ESP32 và thư viện **OneButton** trên nền tảng **PlatformIO**.

## 1. Phần cứng

| STT | Tên linh kiện | Số lượng | Ghi chú |
| :-: | :--- | :-: | :--- |
| 1 | ESP32 Devkit V1 | 01 | Mạch xử lý trung tâm |
| 2 | Đèn LED | 01 | LED ngoài nối chân GPIO 18 |
| 3 | Điện trở vạch 1K 1/4W | 01 | Mắc nối tiếp LED về chân GND |
| 4 | Nút nhấn 4 chân | 01 | Nối chân GPIO 19 về chân GND |
| 5 | Test board & Dây cắm | 01 | Dùng để cắm mạch thử nghiệm |

## 2. Yêu cầu tính năng

* **Single Click (Nhấn 1 lần):** Bật hoặc tắt đèn LED luân phiên. Nếu đang ở chế độ nhấp nháy, nhấn single click sẽ dừng nháy và tắt hẳn LED.
* **Double Click (Nhấn đúp 2 lần):** Chuyển sang chế độ đèn LED nhấp nháy liên tục (chu kỳ 300ms một lần).
* **Khử rung phím bấm:** Tự động khử rung bằng thư viện OneButton.
