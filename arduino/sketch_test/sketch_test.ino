// Hello, world!

#define DEBUG 0

String buffer;

void setup() {
  Serial.begin(9600);
  Serial.println("Hello, world!");

  print_help();
  clear_buffer();
}

void loop() {
}

void print_help() {
}

void debug_buffer() {
  if (DEBUG) {
    Serial.println(String("[DEBUG] buffer[") + buffer + "]");
  }
}

void clear_buffer() {
  buffer = "";
}
