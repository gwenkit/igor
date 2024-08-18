// watch: pull-up switch
void watch_pullup_switch() {
  if (HAS_PULLUP_SWITCH) {
    int input = digitalRead(PIN_PULLUP_SWITCH);
    if (input == HIGH) {
      // e.g. simple_alarm(LOW);
      // TODO: 주기적으로 안내
      //print_info(NAME_PULLUP_SWITCH, false); Serial.print(F(" ")); Serial.println(MARK_OFF);
    } else {
      // e.g. simple_alarm(HIGH);
      print_info(NAME_PULLUP_SWITCH, false); Serial.print(F(" ")); Serial.println(MARK_ON);
    }
  } // if (HAS_PULLUP_SWITCH)
  else
  {
    // TODO: 주기적으로 안내
    //print_info(NAME_PULLUP_SWITCH, false); Serial.print(F(" ")); Serial.println(MARK_NOT_EXIST);
  }
}


// watch: pull-down switch
void watch_pulldown_switch() {
  if (HAS_PULLDOWN_SWITCH) {
    int input = digitalRead(PIN_PULLDOWN_SWITCH);
    if (input == HIGH) {
      // e.g. simple_alarm(HIGH);
      print_info(NAME_PULLDOWN_SWITCH, false); Serial.print(F(" ")); Serial.println(MARK_ON);
    } else {
      // e.g. simple_alarm(LOW);
      // TODO: 주기적으로 안내
      //print_info(NAME_PULLDOWN_SWITCH, false); Serial.print(F(" ")); Serial.println(MARK_OFF);
    }
  } // if (HAS_PULLDOWN_SWITCH)
  else
  {
    // TODO: 주기적으로 안내
    //print_info(NAME_PULLDOWN_SWITCH, false); Serial.print(F(" ")); Serial.println(MARK_NOT_EXIST);
  }
}


// watch: reed switch
void watch_reed_switch() {
  if (HAS_REED_SWITCH) {
    float input = digitalRead(PIN_REED_SWITCH);
    if (input) {
      // e.g. simple_alarm(LOW);
      // TODO: 주기적으로 안내
      //print_info(NAME_REED_SWITCH, false); Serial.print(F(" ")); Serial.println(MARK_OFF);
    } else {
      // e.g. simple_alarm(HIGH);
      print_info(NAME_REED_SWITCH, false); Serial.print(F(" ")); Serial.println(MARK_ON);
    }
  } // if (HAS_REED_SWITCH)
  else
  {
    // TODO: 주기적으로 안내
    //print_info(NAME_REED_SWITCH, false); Serial.print(F(" ")); Serial.println(MARK_NOT_EXIST);
  }
}

