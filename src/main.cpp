#include <Arduino.h>
#include <OneButton.h>

#define LED_PIN 18      // LED ngoài nối GPIO 18
#define BUTTON_PIN 19   // Nút bấm ngoài nối GPIO 19

OneButton btn(BUTTON_PIN, true, true);

bool ledState = false;
bool isBlinking = false;
unsigned long lastBlinkTime = 0;
const unsigned long blinkInterval = 300; // Chu kỳ nháy 300ms

void handleClick() {
  if (isBlinking) {
    isBlinking = false;
    ledState = false; // Thoát nháy thì tắt hẳn LED
  } else {
    ledState = !ledState;
  }
  digitalWrite(LED_PIN, ledState ? HIGH : LOW);
}

void handleDoubleClick() {
  isBlinking = !isBlinking;
  if (isBlinking) {
    lastBlinkTime = millis();
    digitalWrite(LED_PIN, HIGH); // Bật sáng ngay khi kích hoạt nháy
  } else {
    ledState = false;
    digitalWrite(LED_PIN, LOW);
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  btn.attachClick(handleClick);
  btn.attachDoubleClick(handleDoubleClick);
}

void loop() {
  btn.tick();

  if (isBlinking && (millis() - lastBlinkTime >= blinkInterval)) {
    lastBlinkTime = millis();
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  }
}