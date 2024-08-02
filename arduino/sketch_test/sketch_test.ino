/* Hello, world! */

// https://docs.arduino.cc/learn/built-in-libraries/software-serial/
#include <SoftwareSerial.h>

// https://arduinojson.org/
#include <ArduinoJson.h>
#include <ArduinoJson.hpp>

#define DEBUG 0

// global variables
String buffer;

// put your setup code here, to run once:
void setup() {
  Serial.begin(9600);

  delay(1000 * 4);
  Serial.println("Hello, world!");

  print_help();
  clear_buffer();
}

// put your main code here, to run repeatedly:
void loop() {
}

// print HELP messages
void print_help() {
}

// print DEBUG messages
void debug_buffer() {
  if (DEBUG) {
    Serial.println(String("[DEBUG] buffer[") + buffer + "]");
  }
}

// clear buffer
void clear_buffer() {
  buffer = "";
}
