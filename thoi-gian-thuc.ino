#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "RTClib.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {
  "CN", "Thu 2", "Thu 3", "Thu 4", "Thu 5", "Thu 6", "Thu 7"
};

void setup() {
  Serial.begin(9600);

  // Khởi động OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (1);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  // Khởi động RTC
  if (!rtc.begin()) {
    display.setCursor(0, 0);
    display.print("LOI RTC");
    display.display();
    while (1);
  }

  // Nếu RTC mất nguồn thì set lại thời gian
  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  DateTime now = rtc.now();

  display.clearDisplay();

  // ----- HIEN THI GIO -----
  display.setTextSize(2);
  display.setCursor(0, 0);

  if (now.hour() < 10) display.print("0");
  display.print(now.hour());
  display.print(":");

  if (now.minute() < 10) display.print("0");
  display.print(now.minute());
  display.print(":");

  if (now.second() < 10) display.print("0");
  display.print(now.second());

  // ----- HIEN THI NGAY THANG -----
  display.setTextSize(1);
  display.setCursor(0, 35);

  if (now.day() < 10) display.print("0");
  display.print(now.day());
  display.print("/");

  if (now.month() < 10) display.print("0");
  display.print(now.month());
  display.print("/");
  display.print(now.year());

  // ----- HIEN THI THU -----
  display.setCursor(0, 50);
  display.print("Thu: ");
  display.print(daysOfTheWeek[now.dayOfTheWeek()]);

  display.display();
  delay(1000);
}
