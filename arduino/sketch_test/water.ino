// watch: water height
void watch_water_height() {
  if (HAS_WHR) {
    // TODO: 주기적으로 측정
    // TEST: delay(1000 * 3);
    float input = analogRead(PIN_WHR); // ADC; 0..1023 (10bit)
    print_debug_log(NAME_WHR, false); Serial.print(F(" [10bit; ADC]: ")); Serial.println(input);
    float voltage = input * VCC / 1023.0; // math
    float r = (BGR * voltage) / (VCC - voltage); // math // TODO: check
    print_debug_log(NAME_WHR, false); Serial.print(F(" [voltage]: ")); Serial.println(voltage);
    print_debug_log(NAME_WHR, false); Serial.print(F(" [R]: ")); Serial.println(r);
    // e.g. analog_alarm(d);
    // e.g. rgb_alarm(d);
  } // if (HAS_WHR)
  else
  {
    // TODO: 주기적으로 안내
    //print_info(NAME_WHR, false); Serial.print(F(" ")); Serial.println(MARK_NOT_EXIST);
  }
}

