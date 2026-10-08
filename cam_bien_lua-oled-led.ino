#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int flamePin  = 7;    // DO cảm biến lửa
int ledPin    = 13;   // LED
int buzzerPin = 12;   // Còi

void setup() {
  pinMode(flamePin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("KHOI DONG...");
  display.display();
}

void loop() {
  int flameValue = digitalRead(flamePin);

  display.clearDisplay();
  display.setCursor(0, 0);

  if (flameValue == LOW) {          // CÓ LỬA
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 2000);          // còi kêu
    display.print("BAO CHAY !");
  } else {                          // KHÔNG CÓ LỬA
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);              // tắt còi
    display.print("BINH THUONG");
  }

  display.display();
  delay(100);
}
