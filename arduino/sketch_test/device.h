// remote
#define DATA_SERVER_IP 0,0,0,0
#define DATA_SERVER_PORT 8000


// 기준 전압(V)
#define VCC 5
// 기본 저항(K)
#define BGR 10
// 분배 저항(K)
#define BDR 10


// use(SPI); "이더넷"
#define HAS_SPI_ETH true
#define NAME_SPI_ETH "이더넷"
#define MAC { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF }


// use(PIN: Rx<-0, Tx->1); "하드웨어 시리얼"
#define HAS_SERIAL_RT false
#define NAME_SERIAL_RT "하드웨어 시리얼"
#define PIN_SERIAL_RT_RX 0
#define PIN_SERIAL_RT_TX 1

// use(PIN: 2, ~3); "소프트웨어 시리얼(Bluetooth)"
#define HAS_SERIAL_BT false
#define NAME_SERIAL_BT "소프트웨어 시리얼(Bluetooth)"
#define PIN_SERIAL_BT_RX 2
#define PIN_SERIAL_BT_TX 3

// use(PIN: ~3); "아날로그 LED"
#define HAS_ANALOG_LED false
#define NAME_ANALOG_LED "아날로그 LED"
#define PIN_ANALOG_LED 3

// use(PIN: 4, ~5, ~6, 7, 8); "BLANK"
#define PIN_BLANK_4 4
#define PIN_BLANK_5 5
#define PIN_BLANK_6 6
#define PIN_BLANK_7 7
#define PIN_BLANK_8 8

// use(PIN: ~9, ~10, ~11); "RGB LED"
#define HAS_RGB_LED false
#define NAME_RGB_LED "RGB LED"
#define PIN_RGB_LED_0 9
#define PIN_RGB_LED_1 10
#define PIN_RGB_LED_2 11

// use(PIN: 12); "풀업 스위치 버튼"
#define HAS_PULLUP_SWITCH false
#define NAME_PULLUP_SWITCH "풀업 스위치 버튼"
#define PIN_PULLUP_SWITCH 12

// use(PIN: 12); "풀다운 스위치 버튼"
#define HAS_PULLDOWN_SWITCH false
#define NAME_PULLDOWN_SWITCH "풀다운 스위치 버튼"
#define PIN_PULLDOWN_SWITCH 12

// use(PIN: 12); "리드 스위치"
#define HAS_REED_SWITCH false
#define NAME_REED_SWITCH "리드 스위치"
#define PIN_REED_SWITCH 12

// use(PIN: 13); "알람 LED"
#define HAS_ALARM_LED false
#define NAME_ALARM_LED "알람 LED"
#define PIN_ALARM_LED 13


// use(PIN: A5); "가변 저항 (potentiometer)"
#define HAS_VR false
#define NAME_VR "가변 저항 (potentiometer)"
#define PIN_VR A5

// use(PIN: A5); "조도 센서 (photoresistor)"
#define HAS_LDR false
#define NAME_LDR "조도 센서 (photoresistor)"
#define PIN_LDR A5

// use(PIN: A4); "소리 센서"
#define HAS_SOUNDR false
#define NAME_SOUNDR "소리 센서"
#define PIN_SOUNDR A4

// use(PIN: A4); "물 높이 센서"
#define HAS_WHR false
#define NAME_WHR "물 높이 센서"
#define PIN_WHR A4

// use(PIN: A3, A2, A1, A0); "BLANK"
#define PIN_BLANK_A3 A3
#define PIN_BLANK_A2 A2
#define PIN_BLANK_A1 A1
#define PIN_BLANK_A0 A0

