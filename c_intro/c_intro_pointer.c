#include <stdio.h>


int add(int, int);


int main(void) {
    int n = 7;
    double nn = 3.14L;

    int * pn = NULL; // !! SAFE !!
    double * pnn = NULL; // !! SAFE !!

    pn = &n;
    pnn = &nn;

    int sizeof_ptr_int = sizeof(int *);
    int sizeof_pn = sizeof(pn);
    int sizeof_n = sizeof(n);
    printf("sizeof_ptr_int: %d, sizeof_pn: %d, sizeof_n(int): %d\n", sizeof_ptr_int, sizeof_pn, sizeof_n);

    int sizeof_ptr_double = sizeof(double *);
    int sizeof_pnn = sizeof(pnn);
    int sizeof_nn = sizeof(nn);
    printf("sizeof_ptr_double: %d, sizeof_pnn: %d, sizeof_nn(double): %d\n", sizeof_ptr_double, sizeof_pnn, sizeof_nn);

    printf("[DEBUG] n: %d\n", n);
    *pn = 8;
    printf("[DEBUG] n: %d\n", n);

    printf("\n");

    int num = 10;
    const int * pnum1 = &num;
    int * const pnum2 = &num;

    // *pnum1 = 20; // compile error: "read-only variable is not assignable"; see: `const int * pnum1`

    *pnum2 = 12;
    printf("num: %d, *pnum1: %d, *pnum2: %d\n", num, *pnum1, *pnum2);

    num = 20;
    printf("num: %d, *pnum1: %d, *pnum2: %d\n", num, *pnum1, *pnum2);

    printf("\n");

    int (*fptr) (int, int) = add;
    printf("%d + %d = %d; check: %d\n", 1, 2, fptr(1, 2), add(1, 2));

    printf("\n");

    return 0;
}

int add(int n1, int n2) {
    return n1 + n2;
}

