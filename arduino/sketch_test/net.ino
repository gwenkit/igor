// request
void request_https() {
  if (HAS_SPI_ETH && is_eth_ready) {
    // TODO: request 구현
  } // if (HAS_SPI_ETH)
  else
  {
    print_info(NAME_SPI_ETH, false); Serial.print(F(" ")); Serial.println(MARK_NOT_EXIST);
  }
}


// setup: eth
void setup_eth() {
  is_eth_ready = false;

  if (HAS_SPI_ETH) {
    print_info(F("init Ethernet with DHCP..."), true);
    if (Ethernet.begin(mac) == 0) {
      print_error(F("DHCP 문제 발생"), true);
      // 이더넷 장치가 없으면 아무것도 하지 않습니다.
      if (Ethernet.hardwareStatus() == EthernetNoHardware) {
        print_error(F("\""), false); Serial.print(NAME_SPI_ETH); Serial.print(F("\" ")); Serial.println(F("장치가 없습니다."));
        // do nothing
        while (true) {
          delay(1);
        }
      }
      // 이더넷 연결 라인이 없으면 에러 메시지를 보여줍니다.
      if (Ethernet.linkStatus() == LinkOFF) {
        print_error(F("\""), false); Serial.print(NAME_SPI_ETH); Serial.print(F("\" ")); Serial.println(F("케이블이 오프라인 상태입니다."));
      }
      // try to congifure using IP address instead of DHCP:
      // e.g. Ethernet.begin(mac, my_ip, my_dns);
    } else {
      print_info(F("DHCP assigned IP "), false); Serial.print(Ethernet.localIP()); Serial.println();
      is_eth_ready = true;
    }

    if (is_eth_ready) {
      // give the Ethernet shield a second to initialize:
      delay(1000);
      print_info(F("test: connecting to "), false); Serial.print(DataServer); Serial.print(F(":")); Serial.print(DATA_SERVER_PORT); Serial.print(F(" ..."));
    }
    else
    {
      print_error(F("\""), false); Serial.print(NAME_SPI_ETH); Serial.print(F("\" ")); Serial.println(F("연결이 없습니다. 다른 방법으로 인터넷에 접속해야 합니다."));
    }
  } // if (HAS_SPI_ETH)
  else
  {
    print_info(NAME_SPI_ETH, false); Serial.print(F(" ")); Serial.println(MARK_NOT_EXIST);
  }
}

