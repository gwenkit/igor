#include <stdio.h>


int main(void) {
    printf("sizeof(char):\t\t%lu bytes <-- $\n",   sizeof(char)        );
    printf("sizeof(short):\t\t%lu bytes \n",       sizeof(short)       );
    printf("sizeof(int):\t\t%lu bytes <-- $\n",    sizeof(int)         );
    printf("sizeof(long):\t\t%lu bytes \n",        sizeof(long)        );
    printf("sizeof(long long):\t%lu bytes \n",     sizeof(long long)   );
    printf("sizeof(float):\t\t%lu bytes \n",       sizeof(float)       );
    printf("sizeof(double):\t\t%lu bytes <-- $\n", sizeof(double)      );
    printf("sizeof(long double):\t%lu bytes \n",   sizeof(long double) );

    printf("\n");

    unsigned char uc = 0xFF;
    printf("unsigned char 0xFF is %d\n", uc);

    short s = 32767;
    short x = s + 1;
    printf("short %d + 1 is %d; overflow\n", s, x);

    printf("\n");

    // ASCII

    char A = 'A';
    char a = 'a';
    printf("%c is %d\n", A, A);
    printf("%c is %d\n", a, a);

    char xx = 'A'-'a';
    printf("('A'-'a') is %d\n", xx);
    char Aa = A  - xx;
    char aA = Aa + xx;
    printf("%c -> %c -> %c\n", A, Aa, aA);

    printf("\n");

    // casting

    int i129 =  129;
    char cxx = i129;
    printf("int %d becomes char %d\n", i129, cxx);

    int num3 = 3, num4 = 4;
    double poor_3div4 = num3 / num4;
    printf("(X) %f\n", poor_3div4);
    double good_3div4 = (double)num3 / num4;
    printf("(O) %f\n", good_3div4);

    printf("\n");

    // printf

    double d = -123.123;
    printf("use('f'): %f\n", d); // -123.123000
    printf("use('e'): %e\n", d); // -1.231230e+02
    printf("use('g'): %g\n", d); // -123.123

    char str[] = "ARCANE";
    int sizeof_str = sizeof(str);
    int last_position = sizeof_str - 1;
    char last_char = str[last_position];
    printf("sizeof(%s): %d\n", str, sizeof_str);
    printf("check null char: '%c'(%d) at position %d\n", last_char, last_char, last_position);

    printf("\n");

    return 0;
}

