// https://arduinojson.org/
#include <ArduinoJson.h>
#include <ArduinoJson.hpp>

// https://docs.arduino.cc/learn/built-in-libraries/software-serial/
#include <SoftwareSerial.h>

// https://docs.arduino.cc/learn/communication/spi/
#include <SPI.h>
#include <Ethernet.h>


// config(device)
#include "device.h"


// config(console)
//// DEBUG 0: console level INFO (production mode)
//// DEBUG 1: console level DEBUG (development mode)
//// 아래 TEST 1 설정되면 DEBUG 설정은 무시합니다.
#define DEBUG 0
//// TEST 0: 테스트를 실행하지 않습니다.
//// TEST 1: 테스트를 실행하며 모든 DEBUG 메시지를 출력합니다.
#define TEST 1
//// 메시지 시작 문자열
#define TEST_MESSAGE_STARTER "[TEST] "
#define DEBUG_MESSAGE_STARTER "[DEBUG] "
#define INFO_MESSAGE_STARTER "[INFO] "
#define ERROR_MESSAGE_STARTER "[ERROR] "
//// ON, OFF 표시
#define MARK_ON "ON"
#define MARK_OFF "OFF"
//// 없음 표시
#define MARK_NOT_EXIST "없음"
#define MARK_NOT_FOUND "찾을 수 없음"


// global variables
//// 다목적 버퍼; 주로 USB-UART 통신으로 입력되는 명령어를 처리하기 위해 사용합니다.
String buffer;
//// 명령어 완료 확인 문자
#define COMMAND_FIN_CHAR_NULL '\0'
#define COMMAND_FIN_CHAR_RETURN '\r'
#define COMMAND_FIN_CHAR_NEWLINE '\n'
#define COMMAND_FIN_CHAR_OPTIONAL ';'
//// 명령어 준비 완료 여부
boolean is_command_ready;
//// 명령어 조각 개수
#define COMMAND_TOKEN_COUNT 4
//// 명령어 구조: 각각 역할이 있는 String 배열
////// * command_token_list[0]: is_valid
////// * command_token_list[1]: function (수행 목적; 함수 식별)
////// * command_token_list[2]: target (수행 목표; 목표 식별)
////// * command_token_list[3]: parameter (수행 목표; 목표값)
String command_token_list[COMMAND_TOKEN_COUNT];
//// 명령어 유효성 검사 결과
#define COMMAND_IS_VAILD "valid"
#define COMMAND_IS_INVAILD "invalid"
//// eth
byte mac[] = MAC;
EthernetClient EthClient;
boolean is_eth_ready;
////// cubebrio data server
IPAddress DataServer(DATA_SERVER_IP);
//// 소프트웨어 시리얼(Bluetooth) 연결
////// * 아두이노 Rx <- 블루투스 Tx
////// * 아두이노 Tx -> 블루투스 Rx
SoftwareSerial BTSerial(PIN_SERIAL_BT_RX, PIN_SERIAL_BT_TX);


// clear global buffer
void clear_buffer() {
  buffer = "";
  command_token_list[0] = COMMAND_IS_INVAILD;
  command_token_list[1] = "";
  command_token_list[2] = "";
  command_token_list[3] = "";
  is_command_ready = false;
}

