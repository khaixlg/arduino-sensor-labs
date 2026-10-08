#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int irPin  = 7;    // DO cảm biến vật cản IR
int buzzerPin = 12;
int ledPin = 13;   // LED báo

void setup() {
  pinMode(irPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);                 // chữ bình thường
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("KHOI DONG...");
  display.display();
}

void loop() {
  int irValue = digitalRead(irPin);

  display.clearDisplay();
  display.setCursor(0, 0);

  if (irValue == LOW) {     // đa số IR: LOW = có vật cản
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    display.print("CO VAT CAN");
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW); 
    display.print("BINH THUONG");
  }

  display.display();
  delay(100);
}
