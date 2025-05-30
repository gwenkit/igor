#include <stdio.h>


#define NUMBERS_COUNT 10 // config


void bubble_sort(int *, const int);
void swap(int *, int *);
void scan_numbers(int *, const int);
void print_numbers(const int *, const int);

int comp_count, swap_count;


int main(void) {
    int arr[NUMBERS_COUNT] = {0,};


    printf("START;\t\tarr: %p, cnt: %d\n", arr, NUMBERS_COUNT);

    scan_numbers(arr, NUMBERS_COUNT);
    print_numbers(arr, NUMBERS_COUNT);

    bubble_sort(arr, NUMBERS_COUNT);
    print_numbers(arr, NUMBERS_COUNT);

    printf("\nFINISH;\t\tcomp_count: %d, swap_count: %d\n", comp_count, swap_count);


    return 0;
}

void bubble_sort(int * arr, const int cnt) {
    printf("\n[bubble_sort]\tarr: %p, cnt: %d\n", arr, cnt);

    int i, j;
    for (j=cnt-1; j>0; j--) {
        for (i=0; i<j; i++) {
            // if (arr[i] < arr[i+1]) { // 내림차순
            if (arr[i] > arr[i+1]) { // 오름차순
                swap(&arr[i], &arr[i+1]);
            } else {
                printf("// SKIP;\t{i: %d, j: %d}\n", i, j);
            }

            comp_count++;
        } // for i

        printf("---\n");
    } // for j

    printf("[bubble_sort]\tCOMPLETE\n");
}

void swap(int * pnum1, int * pnum2) {
    int tmp = *pnum1;
    *pnum1 = *pnum2;
    *pnum2 = tmp;


    printf("// swap(%d, %d)\n", *pnum1, *pnum2);

    swap_count++;
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


