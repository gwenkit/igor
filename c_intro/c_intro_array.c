#include <stdio.h>


int main(void) {
    int arr1[9] = {100, 101};
    int arr2[ ] = {1000, 1001, 1002, 1003, 1004};

    int sizeof_arr1 = sizeof(arr1);
    int sizeof_arr2 = sizeof(arr2);
    printf("sizeof(arr1): %d\n", sizeof_arr1);
    printf("sizeof(arr2): %d\n", sizeof_arr2);

    int len_arr1 = sizeof_arr1 / sizeof(int);
    int len_arr2 = sizeof_arr2 / sizeof(int);
    printf("len(arr1): %d\n", len_arr1);
    printf("len(arr2): %d\n", len_arr2);

    printf("\n");

    int i = 0;
    for (i=0; i<len_arr1; i++) {
        printf("arr1[%d]: %d\n", i, arr1[i]);
    }
    printf("\n");
    for (i=0; i<len_arr2; i++) {
        printf("arr2[%d]: %d\n", i, arr2[i]);
    }
    printf("\n");

    return 0;
}

