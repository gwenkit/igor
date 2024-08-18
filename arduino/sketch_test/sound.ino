// watch: sound
void watch_sound() {
  if (HAS_SOUNDR) {
    // TODO: 주기적으로 측정
    // TEST: delay(1000 * 3);
    float input = analogRead(PIN_SOUNDR); // ADC; 0..1023 (10bit)
    print_debug_log(NAME_SOUNDR, false); Serial.print(F(" [10bit; ADC]: ")); Serial.println(input);
    float voltage = input * VCC / 1023.0; // math
    float r = (BGR * voltage) / (VCC - voltage); // math // TODO: check
    print_debug_log(NAME_SOUNDR, false); Serial.print(F(" [voltage]: ")); Serial.println(voltage);
    print_debug_log(NAME_SOUNDR, false); Serial.print(F(" [R]: ")); Serial.println(r);
    // e.g. analog_alarm(d);
    // e.g. rgb_alarm(d);
  } // if (HAS_SOUNDR)
  else
  {
    // TODO: 주기적으로 안내
    //print_info(NAME_SOUNDR, false); Serial.print(F(" ")); Serial.println(MARK_NOT_EXIST);
  }
}

