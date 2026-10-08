#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int ledPin = 13;
int sensorPin = A0;
int threshold = 200;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  // Khởi động OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED lỗi"));
    while (1);
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  int soundValue = analogRead(sensorPin);
  Serial.println(soundValue);

  display.clearDisplay();
  display.setCursor(0, 20);

  if (soundValue < threshold) {
    digitalWrite(ledPin, HIGH);
    display.println("PHAT HIEN");
    display.println("TIENG DONG");
  } else {
    digitalWrite(ledPin, LOW);
    display.println("IM LANG");
  }

  display.display();
}

