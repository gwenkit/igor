#include <stdio.h>


int main(void) {
    int num10 =   25;
    int num8  =  025;
    int num16 = 0x25;

    printf("  %d is %d\n", num10, num10);
    printf(" 0%o is %d\n",  num8,  num8);
    printf("0x%x is %d\n", num16, num16);

    return 0;
}

