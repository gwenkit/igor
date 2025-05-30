#include <stdio.h>


#define NUMBERS_COUNT 10 // config


void selection_sort(int *, const int);
void swap(int *, int *);
void scan_numbers(int *, const int);
void print_numbers(const int *, const int);

int comp_count, swap_count;


int main(void) {
    int arr[NUMBERS_COUNT] = {0,};


    printf("START;\t\t\tarr: %p, cnt: %d\n", arr, NUMBERS_COUNT);

    scan_numbers(arr, NUMBERS_COUNT);
    print_numbers(arr, NUMBERS_COUNT);

    selection_sort(arr, NUMBERS_COUNT);
    print_numbers(arr, NUMBERS_COUNT);

    printf("\nFINISH;\t\t\tcomp_count: %d, swap_count: %d\n", comp_count, swap_count);


    return 0;
}

void selection_sort(int * arr, const int cnt) {
    printf("\n[selection_sort]\tarr: %p, cnt: %d\n", arr, cnt);

    int i, j, i_start = 0, selected = 0;
    for (j=0; j<cnt-1; j++) {
        selected = j;
        i_start = selected + 1;
        for (i=i_start; i<cnt; i++) {
            // if (arr[selected] < arr[i]) { // 내림차순
            if (arr[selected] > arr[i]) { // 오름차순
                selected = i;
            }

            comp_count++;
        } // for i
        if (j != selected) {
            swap(&arr[j], &arr[selected]);
        } else {
            printf("// SKIP;\t\tswap [selected: %d]\n", selected);
        }

        printf("---\n");
    } // for j

    printf("[selection_sort]\tCOMPLETE\n");
}

void swap(int * pnum1, int * pnum2) {
    int tmp = *pnum1;
    *pnum1 = *pnum2;
    *pnum2 = tmp;


    printf("// swap(%d, %d)\n", *pnum1, *pnum2);

    swap_count++;
}

void scan_numbers(int * arr, const int cnt) {
    printf("\n[scan_numbers]\t\tarr: %p, cnt: %d\n", arr, cnt);

    printf("input %d int: ", cnt);
    int i = 0;
    for (; i<cnt; i++) {
        scanf(" %d", &arr[i]); // !!!
    }

    printf("[scan_numbers]\t\tCOMPLETE\n");
}

void print_numbers(const int * arr, const int cnt) {
    printf("\n[print_numbers]\t\tarr: %p, cnt: %d\n", arr, cnt);

    int i = 0;
    for (; i<cnt; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("[print_numbers]\t\tCOMPLETE\n");
}


