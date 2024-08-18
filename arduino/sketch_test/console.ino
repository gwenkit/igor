// print "Hello, world!"
void print_greetings() {
  Serial.println(F("Hello, world!"));
}


// print HELP messages
void print_help() {
}


// print DEBUG messages(byte; param)
void debug_byte(byte n) {
  if (DEBUG || TEST) {
    print_debug_log(F("byte["), false);

    // 16진수
    Serial.print(F("0x"));
    Serial.print(n, HEX);

    Serial.print(F(", "));

    // 2진수
    Serial.print(F("0b"));
    for(int i=7; i>=0; i--) {
      byte f = 0x01 << i;
      byte m = n & f;
      if(m != 0) Serial.print(F("1"));
      else Serial.print(F("0"));
    }

    Serial.println(F("]"));
  } // if (DEBUG || TEST)
}


// print DEBUG messages(buffer; global)
void debug_buffer(String label) {
  if (DEBUG || TEST) {
    print_debug_log(F("buffer @ "), false);
    Serial.print(label);
    Serial.print(F(" \""));
    Serial.print(buffer);
    Serial.print(F("\" "));
    Serial.println();
  } // if (DEBUG || TEST)
}


// print DEBUG messages(command_token_list; global)
void debug_command_token_list() {
  if (DEBUG || TEST) {
    print_debug_log(F("command_token_list[0] \""), false);
    Serial.print(command_token_list[0]);
    Serial.println(F("\""));
    print_debug_log(F("command_token_list[1] \""), false);
    Serial.print(command_token_list[1]);
    Serial.println(F("\""));
    print_debug_log(F("command_token_list[2] \""), false);
    Serial.print(command_token_list[2]);
    Serial.println(F("\""));
    print_debug_log(F("command_token_list[3] \""), false);
    Serial.print(command_token_list[3]);
    Serial.println(F("\""));
  } // if (DEBUG || TEST)
}


// print TEST messages(String; param)
void print_test_log(String s, boolean linefeed) {
  if (DEBUG || TEST) {
    Serial.print(TEST_MESSAGE_STARTER);
    Serial.print(s);
    if (linefeed) Serial.println();
  } // if (DEBUG || TEST)
}


// print DEBUG messages(String; param)
void print_debug_log(String s, boolean linefeed) {
  if (DEBUG || TEST) {
    Serial.print(DEBUG_MESSAGE_STARTER);
    Serial.print(s);
    if (linefeed) Serial.println();
  } // if (DEBUG || TEST)
}


// print INFO messages(String; param)
void print_info(String s, boolean linefeed) {
  Serial.print(INFO_MESSAGE_STARTER);
  Serial.print(s);
  if (linefeed) Serial.println();
}


// print ERROR messages(String; param)
void print_error(String s, boolean linefeed) {
  Serial.print(ERROR_MESSAGE_STARTER);
  Serial.print(s);
  if (linefeed) Serial.println();
}

