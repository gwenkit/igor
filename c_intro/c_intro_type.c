#include <stdio.h>


typedef struct {
    int x;
    int y;
    char name[30];
} Position;


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


    int d1, d2, d3;
    printf("%d..%d..%d..; unexpected; trash\n", d1, d2, d3);
    printf("%d..%d..%d..; inline assignment\n", d1=1, d2=2, d3=3);

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

    char xxx = 'A'-'a';
    printf(  "('A'-'a') is %d\n", xxx  );
    char Aa = A  - xxx;
    char aA = Aa + xxx;
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

    double d = -123.456;
    printf("use('f'): %f\n",      d); // -123.456000
    printf("use('e'): %e\n",      d); // -1.234560e+02
    printf("use('g'): %g\n",      d); // -123.456
    printf(" \"%%.2f\" : %.2f\n", d); // -123.46; 반올림

    printf("8   / 3   = %d (d)\n", (8 / 3));   // 2
    // printf("8 / 3 = %f (f)\n",  (8 / 3));   // 0.000000; [-Wformat]
    printf("8.0 / 3   = %f (f)\n", (8.0 / 3)); // 2.666667
    printf("8   / 3.0 = %f (f)\n", (8 / 3.0)); // 2.666667
    printf("8   %% 3   = %d\n", 8%3);

    char str[] = "ARCANE";
    int sizeof_str = sizeof(str);
    int last_position = sizeof_str - 1;
    char last_char = str[last_position];
    printf("sizeof(%s): %d\n", str, sizeof_str);
    printf("check null char: '%c'(%d) at position %d\n", last_char, last_char, last_position);

    printf("\n");


    Position position = {
        .name="position_test",
        .x=7,
        .y=8,
    }; // 순서 자유로움
    printf("&position: %p\n", &position);
    printf("%10s %10s %13s\n", "position.x", "position.y", "position.name");
    printf("----------+----------+-------------\n");
    printf("%10d %10d %13s\n",  position.x,   position.y,   position.name );

    printf("\n");


    Position * ptr_position = &position;
    printf("ptr_position: %p\n", ptr_position);
    printf("%15s %15s %18s\n", "ptr_position->x", "ptr_position->y", "ptr_position->name");
    printf("---------------+---------------+------------------\n");
    printf("%15d %15d %18s\n",  ptr_position->x,   ptr_position->y,   ptr_position->name );

    printf("\n");


    Position position_backup = position;
    printf("&position_backup: %p\n", &position_backup);
    printf("COMPLETE: backup position\n");
    position.x = 100;
    position.y = 200;
    int len_position_name = sizeof(position.name);
    int i = 0;
    for (; i<len_position_name; i++) {
        if (position.name[i] != 0 && position.name[i] != '_') {
            printf("[%2d] '%c'", i, position.name[i]);
            position.name[i] = position.name[i] + xxx;
            printf(" ---> '%c' \n", position.name[i]);
        }
    }
    printf("CHANGED: original position\n");
    printf("%10s %10s %13s  %17s %17s %20s\n", "position.x", "position.y", "position.name", "position_backup.x", "position_backup.y", "position_backup.name");
    printf("----------+----------+-------------||-----------------+-----------------+--------------------\n");
    printf("%10d %10d %13s  %17d %17d %20s\n",  position.x,   position.y,   position.name,   position_backup.x,   position_backup.y,   position_backup.name );

    printf("\n");


    return 0;
}


