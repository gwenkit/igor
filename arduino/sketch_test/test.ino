// test(init)
void test_init() {
  test_cpp();
  test_UNO();
}


// 테스트 제목 구분 표시
#define TEST_TITLE_STARTER "//////////// "
// 테스트 제목 출력
void print_test_title(String title) {
  Serial.print(TEST_TITLE_STARTER);
  Serial.println(title);
}


// test(cpp)
void test_cpp() {
  if (TEST) {
    Serial.println(F("\n======================== START  : test(lang: 'C++') ========================\n"));

    print_test_title(F("test('대소문자 변환')"));
    char ch_upper = 'E';
    char ch_lower = ch_upper + ('a' - 'A');
    char ch_upper_again = ch_lower - ('a' - 'A');
    Serial.print(F("("));
    Serial.print(ch_lower);
    Serial.print(F(", "));
    Serial.print(ch_upper_again);
    Serial.print(F(")"));
    Serial.println();
    Serial.println((char)(ch_upper + 1));
    Serial.println();

    print_test_title(F("test('16진수와 2진수')"));
    byte b = 0xAA;
    byte c = b | (0x01 << 2);
    debug_byte(c);
    Serial.println();

    print_test_title(F("test('비트 연산')"));
    byte n = 0xAA, f = 0xF0, m;
    Serial.print(F("n:\t\t\t")); debug_byte(n);
    Serial.print(F("f:\t\t\t")); debug_byte(f);
    print_test_log(F("n & f 연산:\t"), false);   m = n & f;  debug_byte(m);
    print_test_log(F("n | f 연산:\t"), false);   m = n | f;  debug_byte(m);
    print_test_log(F("n ^ f 연산:\t"), false);   m = n ^ f;  debug_byte(m);
    print_test_log(F("~n 연산:\t\t"), false);    m = ~n;     debug_byte(m);
    print_test_log(F("n << 1 연산:\t"), false);  m = n << 1; debug_byte(m);
    print_test_log(F("n >> 1 연산:\t"), false);  m = n >> 1; debug_byte(m);
    Serial.println();

    print_test_title(F("test('배열 초기화')"));
    int arr_size = 10;
    int arr[arr_size] = { 0, };
    print_test_log(F("arr["), false); Serial.print(arr_size); Serial.print(F("] = { 0, };\t"));
    print_debug_log(F("{"), false);
    for (int i=0; i<arr_size; i++) {
      Serial.print(F(" "));
      Serial.print(arr[i]);
      if (i < (arr_size - 1)) Serial.print(F(","));
    }
    Serial.println(F(" }"));
    Serial.println();

    print_test_title(F("test('sin 함수')"));
    float d = 30;
    float r = sin(d * 3.14 / 180.0);
    print_test_log(F("sin("), false); Serial.print(d); Serial.print(F(" * 3.14 / 180.0);\t"));
    print_debug_log(String(r), true);
    Serial.println();

    Serial.println(F("\n======================== FINISH : test(lang: 'C++') ========================\n"));
  } // if (TEST)
  else
  {
    print_info(F("skip: test(lang: 'C++')"), true);
  }
}


// 바이트 단위 표시
#define MARK_BYTES " byte(s)"
// 바이트 출력
void print_bytes_with_mark(size_t bytes) {
  Serial.print(bytes);
  Serial.println(MARK_BYTES);
}


// test(UNO)
void test_UNO() {
  if (TEST) {
    Serial.println(F("\n======================== START  : test(core: 'UNO') ========================\n"));

    print_test_title(F("test('언더플로, 오버플로')"));
    int x;
    // 언더플로
    x = -32768;
    x = x - 1;
    Serial.print(F("-32768 - 1 = "));
    Serial.println(x);
    // 오버플로
    x = 32767;
    x = x + 1;
    Serial.print(F("+32767 + 1 = "));
    Serial.println(x);
    Serial.println();

    print_test_title("test('sizeof(...)')");
    Serial.print(F("bool\t\t\t: "));         print_bytes_with_mark(sizeof(bool));
    Serial.print(F("boolean\t\t\t: "));      print_bytes_with_mark(sizeof(boolean));
    Serial.print(F("char\t\t\t: "));         print_bytes_with_mark(sizeof(char));
    Serial.print(F("byte\t\t\t: "));         print_bytes_with_mark(sizeof(byte));
    Serial.print(F("int\t\t\t: "));          print_bytes_with_mark(sizeof(int));
    Serial.print(F("word\t\t\t: "));         print_bytes_with_mark(sizeof(word));
    Serial.print(F("short\t\t\t: "));        print_bytes_with_mark(sizeof(short));
    Serial.print(F("long\t\t\t: "));         print_bytes_with_mark(sizeof(long));
    Serial.print(F("size_t\t\t\t: "));       print_bytes_with_mark(sizeof(size_t));
    Serial.print(F("uint8_t\t\t\t: "));      print_bytes_with_mark(sizeof(uint8_t));
    Serial.print(F("uint16_t\t\t: "));       print_bytes_with_mark(sizeof(uint16_t));
    Serial.print(F("uint32_t\t\t: "));       print_bytes_with_mark(sizeof(uint32_t));
    Serial.print(F("float\t\t\t: "));        print_bytes_with_mark(sizeof(float));
    Serial.print(F("double\t\t\t: "));       print_bytes_with_mark(sizeof(double));
    Serial.print(F("char pointer\t\t: "));   print_bytes_with_mark(sizeof(char*));
    Serial.print(F("int pointer\t\t: "));    print_bytes_with_mark(sizeof(int*));
    Serial.print(F("double pointer\t\t: ")); print_bytes_with_mark(sizeof(double*));
    char str[] = "우리말";
    Serial.print(F("char [] \"우리말\"\t: "));
    Serial.print(sizeof(str));
    Serial.print(F(" (= 3 + 3 + 3 + 1)"));
    Serial.println(MARK_BYTES);
    String sstr = String(str);
    Serial.print(F("String(...)\t\t: "));
    print_bytes_with_mark(sizeof(sstr));
    Serial.println();

    print_test_title(F("test('연산 부정확')"));
    Serial.println(3.14, 8);       // 3.14000010
    Serial.println(3.141, 8);      // 3.14100003
    Serial.println(3.1415, 8);     // 3.14149999
    Serial.println(3.14159, 8);    // 3.14159011
    Serial.println(3.141592, 8);   // 3.14159202
    Serial.println(3.1415926, 8);  // 3.14159250
    Serial.println(3.14159265, 8); // 3.14159274

    Serial.println(F("\n======================== FINISH : test(core: 'UNO') ========================\n"));
  } // if (TEST)
  else
  {
    print_info(F("skip: test(core: 'UNO')"), true);
  }
}

