#include <stdio.h>
#include <stdlib.h>


#define NUMBERS_COUNT 10 // config


int compare(const void *, const void *);
void scan_numbers(int *, const int);
void print_numbers(const int *, const int);

int comp_count;


int main(void) {
    int arr[NUMBERS_COUNT] = {0,};
    int item_size = sizeof(int); // 또는 sizeof(arr[0])
    int array_length = sizeof(arr) / item_size;
    comp_count = 0;


    printf("START;\t\tarr: %p, cnt: %d\n", arr, array_length);

    scan_numbers(arr, array_length);
    print_numbers(arr, array_length);

    qsort(arr, array_length, item_size, compare);
    print_numbers(arr, array_length);

    printf("\nFINISH;\t\tcomp_count: %d\n", comp_count);


    return 0;
}

int compare(const void * pn1, const void * pn2) {
    comp_count++;

    // return *( (int *)pn1 ) - *( (int *)pn2 ); // 오름차순
    return *( (int *)pn2 ) - *( (int *)pn1 ); // 내림차순
}

void scan_numbers(int * arr, const int cnt) {
    printf("\n[scan_numbers]\tarr: %p, cnt: %d\n", arr, cnt);

    printf("input %d int: ", cnt);
    int i = 0;
    for (; i<cnt; i++) {
        scanf(" %d", &arr[i]); // !!!
    }

    printf("[scan_numbers]\tCOMPLETE\n");
}

void print_numbers(const int * arr, const int cnt) {
    printf("\n[print_numbers]\tarr: %p, cnt: %d\n", arr, cnt);

    int i = 0;
    for (; i<cnt; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("[print_numbers]\tCOMPLETE\n");
}


