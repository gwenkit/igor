// handle: interrupt
void handle_pullup_interrupt() {
  print_info(F("interrupt(from: "), false); Serial.print(NAME_PULLUP_SWITCH); Serial.println(F(")"));
}

