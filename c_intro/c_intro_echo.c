#include <stdio.h>


int main(void) {
    int ch;

    printf("EOF is %d\n", EOF);
    printf("^C to call EOF\n");

    while (1) {
        ch = getchar();
        if (ch == EOF) break;
        putchar(ch);
    }


    return 0;
}


