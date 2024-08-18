// setup: PIN
void setup_pin() {
  pinMode(LED_BUILTIN, OUTPUT);
  //digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(LED_BUILTIN, LOW);

  // INPUT
  if (HAS_PULLUP_SWITCH) {
    pinMode(PIN_PULLUP_SWITCH, INPUT_PULLUP);
    // 버튼 상승 에지(RISING)에서 함수(handle_interrupt)가 호출되도록 인터럽트 처리 루틴 등록
    attachInterrupt(digitalPinToInterrupt(PIN_PULLUP_SWITCH), handle_pullup_interrupt, RISING);
  }
  if (HAS_PULLDOWN_SWITCH) {
    pinMode(PIN_PULLDOWN_SWITCH, INPUT);
  }
  if (HAS_REED_SWITCH) {
    pinMode(PIN_REED_SWITCH, INPUT_PULLUP);
  }

  // OUTPUT
  if (HAS_ANALOG_LED) {
    pinMode(PIN_ANALOG_LED, OUTPUT);
  }
  if (HAS_RGB_LED) {
    pinMode(PIN_RGB_LED_0, OUTPUT);
    pinMode(PIN_RGB_LED_1, OUTPUT);
    pinMode(PIN_RGB_LED_2, OUTPUT);
  }
  if (HAS_ALARM_LED) {
    pinMode(PIN_ALARM_LED, OUTPUT);
  }
}

