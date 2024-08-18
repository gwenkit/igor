/* igor/arduino */


// global settings
#include "global.h"


// put your setup code here, to run once:
void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);

  delay(1000 * 4);
  print_greetings();

  test_init();

  setup_pin();
  setup_eth();
  clear_buffer();
  print_debug_log(F("complete: clear global buffer @ setup"), true);

  print_help();
}


// put your main code here, to run repeatedly:
void loop() {
  // serial(bluetooth)
  watch_software_serial();
  // switch
  watch_pullup_switch();
  watch_pulldown_switch();
  watch_reed_switch();
  // potentiometer
  watch_vr();
  // photoresistor
  watch_light();
  // sound
  watch_sound();
  // water
  watch_water_height();
}


// serial event loop:
void serialEvent() {
  watch_hardware_serial();
}

