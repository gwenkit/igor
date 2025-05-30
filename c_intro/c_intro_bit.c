#include <stdio.h>


const int BIT_POSITION_READ = 1;
const int BIT_POSITION_SET = 2;
const int BIT_POSITION_CLEAR = 3;
const int BIT_POSITION_TOGGLE = 4;

void debug_bit(const int);


int main(void) {

    // XOR

    int num1 =  15;          // 00000000 00000000 00000000 00001111
    int num2 =  20;          // 00000000 00000000 00000000 00010100
    printf("0x%x; %d;\t\t\t\t", num1, num1); debug_bit(num1);
    printf("0x%x; %d;\t\t\t\t", num2, num2); debug_bit(num2);
    int xor12 = num1 ^ num2; // 00000000 00000000 00000000 00011011
    printf("0x%x ^ 0x%x = 0x%x; %d;\t\t\t", num1, num2, xor12, xor12); debug_bit(xor12);

    printf("\n");


    // shift

    int num3 = -10;          // 11111111 11111111 11111111 11110110
    printf("0x%x; %d;\t\t\t", num3, num3); debug_bit(num3);
    int rshift3 = num3 >> 1; // 11111111 11111111 11111111 11111011
    printf("0x%x >> 1 = 0x%x; %d;\t", num3, rshift3, rshift3); debug_bit(rshift3);

    printf("\n");


    // -, ~, !

    int num4 = 10;
    printf("0x%x; %d;\t\t\t\t", num4, num4); debug_bit(num4);
    printf("-0x%x = 0x%x; %d;\t\t\t", num4, -num4, -num4); debug_bit(-num4);
    printf("~0x%x = 0x%x; %d;\t\t\t", num4, ~num4, ~num4); debug_bit(~num4);
    printf("!0x%x = 0x%x; %d;\t\t\t\t", num4, !num4, !num4); debug_bit(!num4);

    printf("\n");


    // read

    int num51 = 10;                                          // 00000000 00000000 00000000 00001010
    printf("0x%x; %d;\t\t\t\t", num51, num51); debug_bit(num51);
    int filter_read = 1 << BIT_POSITION_READ;                // 00000000 00000000 00000000 00000010
    printf("filter: 0x%x; %d;\t\t\t\t", filter_read, filter_read); debug_bit(filter_read);
    int read51 = (num51 & filter_read) >> BIT_POSITION_READ; //                                   1
    printf("read(bit_position=%d)? %d; use(&, >>)\n", BIT_POSITION_READ, read51);

    printf("\n");


    // set

    int num52 = 10;                         // 00000000 00000000 00000000 00001010
    printf("0x%x; %d;\t\t\t\t", num52, num52); debug_bit(num52);
    int filter_set = 1 << BIT_POSITION_SET; // 00000000 00000000 00000000 00000100
    printf("filter: 0x%x; %d;\t\t\t\t", filter_set, filter_set); debug_bit(filter_set);
    num52 |= filter_set;                    // 00000000 00000000 00000000 00001110
    printf("set(bit_position=%d)? %d; use(|=)\t", BIT_POSITION_SET, num52); debug_bit(num52);

    printf("\n");


    // clear

    int num53 = 10;                                // 00000000 00000000 00000000 00001010
    printf("0x%x; %d;\t\t\t\t", num53, num53); debug_bit(num53);
    int filter_clear = ~(1 << BIT_POSITION_CLEAR); // 11111111 11111111 11111111 11110111
    printf("filter: 0x%x; %d;\t\t\t", filter_clear, filter_clear); debug_bit(filter_clear);
    num53 &= filter_clear;                         // 00000000 00000000 00000000 00000010
    printf("clear(bit_position=%d)? %d; use(~, &=)\t", BIT_POSITION_CLEAR, num53); debug_bit(num53);

    printf("\n");


    // toggle

    int num54 = 10;                               // 00000000 00000000 00000000 00001010
    printf("0x%x; %d;\t\t\t\t", num54, num54); debug_bit(num54);
    int filter_toggle = 1 << BIT_POSITION_TOGGLE; // 00000000 00000000 00000000 00010000
    printf("filter: 0x%x; %d;\t\t\t", filter_toggle, filter_toggle); debug_bit(filter_toggle);
    num54 ^= filter_toggle;                       // 00000000 00000000 00000000 00011010
    printf("toggle(bit_position=%d)? %d; use(^=)\t", BIT_POSITION_TOGGLE, num54); debug_bit(num54);

    printf("\n");


    return 0;
}

void debug_bit(const int num) {
    printf("[");
    int max = sizeof(int)*8;
    int i = max - 1;
    int j = 0;
    int f, m;
    for (; i>=0; i--) {
        f = 0x01 << i;
        m = num & f;
        
        if (m != 0) printf("1");
        else printf("0");

        ++j;
        if (j == 8 && i > 0) {
            printf(" ");
            j = 0;
        }
    }
    printf("]\n");
}


