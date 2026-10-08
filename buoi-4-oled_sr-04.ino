#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ---------- OLED ----------
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ---------- HC-SR04 ----------
const int trigPin = 9;
const int echoPin = 10;
#define SPEED_OF_SOUND_CM 29.1

// ---------- BUZZER + LED ----------
const int buzzerPin = 6;
const int ledPin    = 7;

void setup() {
  Serial.begin(9600);

  // OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while (1);
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 10);
  display.println("HC-SR04");
  display.setCursor(15, 40);
  display.println("READY");
  display.display();
  delay(2000);

  // HC-SR04
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Buzzer + LED
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);

  Serial.println("System Ready");
}

void loop() {
  // ---------- Trigger ----------
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // ---------- Echo ----------
  long duration = pulseIn(echoPin, HIGH, 30000); // 30ms ~ 5m
  float cm = -1;

  if (duration > 0) {
    cm = duration / 2.0 / SPEED_OF_SOUND_CM;
  }

  // ---------- SERIAL ----------
  if (cm < 0) {
    Serial.println("No echo");
  } else {
    Serial.print("Distance: ");
    Serial.print(cm, 1);
    Serial.println(" cm");
  }

  // ---------- OLED ----------
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Khoang cach:");

  if (cm < 0) {
    display.setTextSize(2);
    display.setCursor(30, 25);
    display.println("LOI");
  } 
  else if (cm > 400) {
    display.setTextSize(2);
    display.setCursor(30, 25);
    display.println(">4m");
  } 
  else {
    display.setTextSize(3);
    String dist = String(cm, 1);
    int x = (128 - dist.length() * 18) / 2;
    display.setCursor(x, 15);
    display.print(dist);

    display.setTextSize(2);
    display.setCursor(x + dist.length() * 18 - 10, 40);
    display.println("cm");
  }

  display.display();

  // ---------- BUZZER + LED LOGIC ----------
  if (cm <= 0 || cm <= 10) {
    // Bình thường
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
  }

  // >10cm → 20cm : chậm + nhỏ
  else if (cm > 10 && cm <= 20) {
    tone(buzzerPin, 1000);
    digitalWrite(ledPin, HIGH);
    delay(200);
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
    delay(600);
  }

  // >20cm → 30cm : nhanh + to hơn
  else if (cm > 20 && cm <= 30) {
    tone(buzzerPin, 2000);
    digitalWrite(ledPin, HIGH);
    delay(150);
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
    delay(150);
  }

  // >30cm : to nhất liên tục
  else if (cm > 30) {
    tone(buzzerPin, 3000);
    digitalWrite(ledPin, HIGH);
  }
}
