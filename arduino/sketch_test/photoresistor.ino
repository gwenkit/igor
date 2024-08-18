// watch: photoresistor
void watch_light() {
  if (HAS_LDR) {
    // TODO: 주기적으로 측정
    // TEST: delay(1000 * 3);
    int input = analogRead(PIN_LDR); //     ADC; 0..1023 (10bit)
    int d = map(input, 0, 1023, 0, 255); // PWM; 0..255   (8bit)
    print_debug_log(NAME_LDR, false); Serial.print(F(" [10bit; ADC]: ")); Serial.println(input);
    print_debug_log(NAME_LDR, false); Serial.print(F(" [ 8bit; PWM]: ")); Serial.println(d);
    float voltage = input * VCC / 1023.0; // math
    float r = (BDR * VCC / voltage) - BDR; // math: 전압 분배 반영 // TODO: check
    print_debug_log(NAME_LDR, false); Serial.print(F(" [voltage]: ")); Serial.println(voltage);
    print_debug_log(NAME_LDR, false); Serial.print(F(" [R]: ")); Serial.println(r);
    // e.g. analog_alarm(d);
    // e.g. rgb_alarm(d);
  } // if (HAS_LDR)
  else
  {
    // TODO: 주기적으로 안내
    //print_info(NAME_LDR, false); Serial.print(F(" ")); Serial.println(MARK_NOT_EXIST);
  }
}

