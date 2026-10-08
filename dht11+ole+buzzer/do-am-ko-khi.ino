#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define BUZZER_PIN 9   // phải dùng chân PWM để thay đổi âm lượng
#define LED_PIN 13

void setup() {
  Serial.begin(9600);
  
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  dht.begin();

  // Khởi động OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Địa chỉ I2C thường là 0x3C hoặc 0x3D
    Serial.println(F("OLED không kết nối!"));
    for(;;);
  }
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println(F("Starting..."));
  display.display();
  delay(2000);
}

void loop() {
  delay(500); 

  float h = dht.readHumidity();
  float t = dht.readTemperature(); // độ C

  // Kiểm tra lỗi cảm biến
  if (isnan(h) || isnan(t)) {
    //Serial.println("Loi doc DHT11");      // hiện serial
    display.clearDisplay();
    display.setCursor(0,10);
    display.setTextSize(1);
    display.println(F("Loi cam bien DHT11!"));
    display.display();
    return;
  }
  //Serial.print("Nhiet do: ");
  //Serial.print(t);
  //Serial.print(" C | Do am: ");
  //Serial.print(h);
  //Serial.println(" %");

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print(F("Nhiet do: "));
  display.print(t, 1);
  display.print(F(" C"));

  display.setCursor(0,20);
  display.print(F("Do am: "));
  display.print(h, 1);
  display.print(F(" %"));

  // Tắt còi trước khi quyết định chế độ mới
  noTone(BUZZER_PIN);

  // 1. Nhiệt độ > 45°C và độ ẩm < 30% → còi to nhất, kêu liên tục
  if (t > 45.0 && h < 30.0) {
    //Serial.println("CANH BAO NGUY HIEM");
    display.setCursor(0,45);
    display.setTextSize(1);
    display.println(F("CANH BAO"));
    display.println(F("NGUY HIEM!"));
    
    tone(BUZZER_PIN, 1000); // tần số cao, âm lượng max (vì dùng tone) tone(chân, tần_số, thời_gian);
    digitalWrite(LED_PIN, HIGH);// LED sáng liên tục
    // lặp lại liên tục trong vòng loop
  }
  // 2. Nhiệt độ > 40°C → còi kêu nhanh + to
  else if (t > 40.0) {
    //Serial.println("Nhiet do QUA CAO");
    display.setCursor(0,45);
    display.setTextSize(1);
    display.println(F("Nhiet do QUA CAO!"));
    display.println(F("Coi keu NHANH + TO"));

    // Kêu nhanh 200ms bật - 200ms tắt
    tone(BUZZER_PIN, 1800);
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    noTone(BUZZER_PIN);
    digitalWrite(LED_PIN, LOW);
    delay(100);
  }
  // 3. Nhiệt độ  → còi kêu chậm + nhỏ
  else if (t > 30.0) {
    //Serial.println("Nhiet do cao");
    display.setCursor(0,45);
    display.setTextSize(1);
    display.println(F("Nhiet do cao"));
    display.println(F("Coi keu NHO + CHAM"));

    // Kêu chậm 200ms bật - 800ms tắt
    tone(BUZZER_PIN, 2000); // tần số thấp hơn → âm trầm hơn
    digitalWrite(LED_PIN, HIGH); 
    delay(200);
    noTone(BUZZER_PIN);
    digitalWrite(LED_PIN, LOW);
    delay(800);
  }
  // 4. Bình thường
  else {
    //Serial.println("Trang thai BINH THUONG");
    display.setCursor(0,45);
    display.println(F("Trang thai BINH THUONG"));
    noTone(BUZZER_PIN);
    digitalWrite(LED_PIN, LOW);
  }

  display.display();
}
