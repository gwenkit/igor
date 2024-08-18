// handle: command
// TODO: 명령어 스펙은 도움말(함수: print_help)에 정확히 적어두어야 합니다.
void handle_command(char c) {
  if (!is_command_ready) {
    if (   (c == COMMAND_FIN_CHAR_NULL) \
        || (c == COMMAND_FIN_CHAR_RETURN) \
        || (c == COMMAND_FIN_CHAR_NEWLINE) \
        || (c == COMMAND_FIN_CHAR_OPTIONAL)   ) {
      debug_buffer(F("before(normalize)"));
      // normalize(trim): global buffer
      buffer.trim();
      // normalize(case): global buffer
      buffer.toLowerCase();
      debug_buffer(F("after(normalize)"));
      // 명령어 완료 확인 처리: global is_command_ready
      if (String(buffer).length() > 0) {
        is_command_ready = true;
      } // if (String(buffer).length() > 0)
      else
      {
        print_debug_log(F("garbage(empty)"), true);
      }
    } // if( c IN (COMMAND_FIN_CHAR_*) )
    else
    {
      // 공백 문자는 버퍼에 넣지 않습니다.
      if ( (String(c).length() > 0) && !(isWhitespace(c)) ) {
        buffer = String(buffer) + c;
      } // if ( (String(c).length() > 0) && !(isWhitespace(c)) )
      debug_buffer(F("continue(parse)..."));
    } // if( c NOT IN (COMMAND_FIN_CHAR_*) )
  } // if (!is_command_ready)

  if (is_command_ready) {
    run_command();
  } // if (is_command_ready)
}


// run command
void run_command() {
  print_debug_log(F(">>>>>>>>>>>> START: run_command"), true);
  debug_buffer(F("run_command"));
  validate_command();
  debug_command_token_list();
  if (command_token_list[0].equals(COMMAND_IS_VAILD)) {
    // TODO: 명령어 분석
    //// * 수행 목적: command_token_list[1]
    //// * 수행 목표: command_token_list[2], command_token_list[3]
    // e.g. int signal = String(command_token_list[3]).toInt();
    // e.g. float signal = String(command_token_list[3]).toFloat();
    // TODO: 분기: 각 조건에 맞는 명령어 수행
    // e.g. echo('아두이노 → 시리얼 모니터'); Serial.println(buffer);
    // e.g. simple_alarm(HIGH);
    // e.g. analog_alarm(signal);
    // e.g. rgb_alarm(signal);
  }
  else
  {
    print_info(F("처리할 수 없는 명령어입니다. \""), false); Serial.print(buffer); Serial.println(F("\""));
    print_help();
  }
  clear_buffer();
  print_debug_log(F("complete: clear global buffer @ run_command"), true);
  print_debug_log(F(">>>>>>>>>>>> FINISH: run_command"), true);
}


// validate command
void validate_command() {
  command_token_list[0] = "TODO";
  command_token_list[1] = "TODO";
  command_token_list[2] = "TODO";
  command_token_list[3] = "TODO";
}

