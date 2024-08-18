// OUTPUT: simple alarm(LED)
void simple_alarm(int signal) {
  if (HAS_ALARM_LED) {
    digitalWrite(PIN_ALARM_LED, signal);
    if (signal == HIGH) {
      print_info(NAME_ALARM_LED, false); Serial.print(F(" ")); Serial.println(MARK_ON);
    } else {
      // TODO: 주기적으로 안내
      //print_info(NAME_ALARM_LED, false); Serial.print(F(" ")); Serial.println(MARK_OFF);
    }
  } // if (HAS_ALARM_LED)
  else
  {
    // TODO: 주기적으로 안내
    //print_info(NAME_ALARM_LED, false); Serial.print(F(" ")); Serial.println(MARK_NOT_EXIST);
  }
}


// OUTPUT: analog alarm(LED)
void analog_alarm(int signal) {
  if (HAS_ANALOG_LED) {
    analogWrite(PIN_ANALOG_LED, signal);
  } // if (HAS_ANALOG_LED)
  else
  {
    // TODO: 주기적으로 안내
    //print_info(NAME_ANALOG_LED, false); Serial.print(F(" ")); Serial.println(MARK_NOT_EXIST);
  }
}


// OUTPUT: RGB alarm(LED)
void rgb_alarm(int signal) {
  if (HAS_RGB_LED) {
    if ((0 <= signal) && (signal < 100)) {
      analogWrite(PIN_RGB_LED_0, LOW);
      analogWrite(PIN_RGB_LED_1, LOW);
      analogWrite(PIN_RGB_LED_2, HIGH);
      print_debug_log(F("RGB_LED: R"), true);
    } else if ((100 <= signal) && (signal < 200)) {
      analogWrite(PIN_RGB_LED_0, LOW);
      analogWrite(PIN_RGB_LED_1, HIGH);
      analogWrite(PIN_RGB_LED_2, LOW);
      print_debug_log(F("RGB_LED: G"), true);
    } else {
      analogWrite(PIN_RGB_LED_0, HIGH);
      analogWrite(PIN_RGB_LED_1, LOW);
      analogWrite(PIN_RGB_LED_2, LOW);
      print_debug_log(F("RGB_LED: B"), true);
    }
  } // if (HAS_RGB_LED)
  else
  {
    // TODO: 주기적으로 안내
    //print_info(NAME_RGB_LED, false); Serial.print(F(" ")); Serial.println(MARK_NOT_EXIST);
  }
}

