const int ledPins[5] = {2, 3, 4, 5, 6};
const int btn1 = 7;
const int btn2 = 8;

int lastBtn1 = HIGH;
int lastBtn2 = HIGH;

unsigned long prevMillis = 0;
unsigned long pauseStart = 0;

bool pauseMode = false;   // đang tắt chờ nút?
bool running = true;      // đang chạy hiệu ứng?

int stage = 0;            // 0=mode1,1=mode2,2=mode3
int stepEffect = 0;

void setup() {
  for (int i = 0; i < 5; i++) pinMode(ledPins[i], OUTPUT);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
}

void loop() {
  unsigned long now = millis();

  int r1 = digitalRead(btn1);
  int r2 = digitalRead(btn2);

  // ======================
  //    XỬ LÝ NÚT 1
  // ======================
  if (r1 == LOW && lastBtn1 == HIGH) {
    running = true;      // chạy lại hiệu ứng
    pauseMode = false;   // thoát pause
    stage = 0;
    stepEffect = 0;
    allOff();
  }
  lastBtn1 = r1;

  // ======================
  //    XỬ LÝ NÚT 2
  // ======================
  if (r2 == LOW && lastBtn2 == HIGH) {
    // bật 5 giây
    pauseMode = true;
    running = false;
    pauseStart = now;
    allOn();
  }
  lastBtn2 = r2;

  // ======================
  //   ĐANG PAUSE 5 GIÂY
  // ======================
  if (pauseMode) {
    // đã sáng đủ 5 giây → tắt và giữ nguyên
    if (now - pauseStart >= 5000) {
      allOff();
      // tiếp tục giữ trạng thái "đứng yên"
      // chỉ khi ấn nút 1 hoặc 2 mới chuyển tiếp
    }
    return; // không chạy hiệu ứng
  }

  // ======================
  //    CHẠY HIỆU ỨNG
  // ======================
  if (running) {
    run3Modes(now);
  }
}

void allOn() {
  for (int i = 0; i < 5; i++) digitalWrite(ledPins[i], HIGH);
}

void allOff() {
  for (int i = 0; i < 5; i++) digitalWrite(ledPins[i], LOW);
}

// ===============================
//   3 CHẾ ĐỘ LIÊN TỤC (non-blocking)
// ===============================
void run3Modes(unsigned long now) {

  // MODE 1: nhấp nháy
  if (stage == 0) {
    if (now - prevMillis >= 300) {
      prevMillis = now;
      stepEffect++;
      (stepEffect % 2 == 0) ? allOn() : allOff();

      if (stepEffect >= 12) {
        stage = 1;
        stepEffect = 0;
        allOff();
      }
    }
  }

  // MODE 2: chạy đèn trái sang phải
  else if (stage == 1) {
    if (now - prevMillis >= 150) {
      prevMillis = now;
      allOff();

      if (stepEffect < 5)
        digitalWrite(ledPins[stepEffect], HIGH);

      stepEffect++;

      if (stepEffect >= 15) {
        stage = 2;
        stepEffect = 0;
        allOff();
      }
    }
  }

  // MODE 3: sáng xen kẽ
  else if (stage == 2) {
    if (now - prevMillis >= 300) {
      prevMillis = now;

      for (int i = 0; i < 5; i++)
        digitalWrite(ledPins[i], (stepEffect % 2 == 0) ? (i % 2) : !(i % 2));

      stepEffect++;

      if (stepEffect >= 12) {
        stage = 0;
        stepEffect = 0;
        allOff();
      }
    }
  }
}
