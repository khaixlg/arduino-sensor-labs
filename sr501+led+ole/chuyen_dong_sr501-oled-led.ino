#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int ledPin = 13;     
int pirPin = 2;      
int buzzerPin = 8;   // COI

int state = LOW;    
int val = 0;        

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("KHOI DONG...");
  display.display();
}

void loop() {
  val = digitalRead(pirPin);

  // ----- CÓ CHUYỂN ĐỘNG -----
  if (val == HIGH && state == LOW) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    state = HIGH;

    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("CO CHUYEN DONG");
    display.display();

    Serial.println("Motion detected!");
  }

  // ----- KHÔNG CHUYỂN ĐỘNG -----
  if (val == LOW && state == HIGH) {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    state = LOW;

    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("KHONG CHUYEN DONG");
    display.display();

    Serial.println("Motion stopped!");
  }
}
