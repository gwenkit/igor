// watch: USB-UART
void watch_hardware_serial() {
  // 시리얼 모니터 → 아두이노
  if(Serial.available()) {
    char c = Serial.read();
    handle_command(c);
  } // if(Serial.available())
}


// watch: BLE-UART
void watch_software_serial() {
  if (HAS_SERIAL_BT) {
    // 블루투스 모듈 → 아두이노
    if (BTSerial.available()) {
      char c = BTSerial.read();
      handle_command(c);
    } // if (BTSerial.available())
  } // if (HAS_SERIAL_BT)
  else
  {
    // TODO: 주기적으로 안내
    //print_info(NAME_SERIAL_BT, false); Serial.print(F(" ")); Serial.println(MARK_NOT_EXIST);
  }
}

