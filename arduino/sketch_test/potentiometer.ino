// watch: potentiometer
void watch_vr() {
  if (HAS_VR) {
    // TODO: 주기적으로 측정
    // TEST: delay(1000 * 3);
    int input = analogRead(PIN_VR); // ADC; 0..1023 (10bit)
    int d = input >> 2; // PWM; duty cycle; 0..255   (8bit)
    print_debug_log(NAME_VR, false); Serial.print(F(" [10bit; ADC]: ")); Serial.println(input);
    print_debug_log(NAME_VR, false); Serial.print(F(" [ 8bit; PWM]: ")); Serial.println(d);
    float voltage = input * VCC / 1023.0; // math
    float r = (BGR * voltage) / (VCC - voltage); // math // TODO: check
    print_debug_log(NAME_VR, false); Serial.print(F(" [voltage]: ")); Serial.println(voltage);
    print_debug_log(NAME_VR, false); Serial.print(F(" [R]: ")); Serial.println(r);
    // e.g. analog_alarm(d);
    // e.g. rgb_alarm(d);
    // e.g. float temperature = voltage * 100; // spec(LM35D)
    // e.g. float temperature = voltage * 100 - 50; // spec(TMP36)
    // e.g. int led_count = map(input, 0, 1023, 0, pin_led_arr_length);
  } // if (HAS_VR)
  else
  {
    // TODO: 주기적으로 안내
    //print_info(NAME_VR, false); Serial.print(F(" ")); Serial.println(MARK_NOT_EXIST);
  }
}

