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

    printf("[DEBUG] n: %d, &n: %p, *pn: %d, pn: %p\n", n, &n, *pn, pn);
    *pn = 8;
    printf("[DEBUG] n: %d, &n: %p, *pn: %d, pn: %p\n", n, &n, *pn, pn);

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

    int arr[3] = {1, 2, 3};
    int * parr = arr;
    printf("%p vs. %p vs. %p\n", arr, &arr[0], parr);
    printf("   arr[2]: %d\n",    arr[2]);
    printf("*(parr+2): %d\n", *(parr+2));

    printf("\n");

    int d1 = 1, d2 = 2, d3 = 3;
    int   arr31[3] = {  d1,  d2,  d3 }; // 값을 복사해서 만든 배열
    int * arr32[3] = { &d1, &d2, &d3 }; // 변수의 주소를 참조해서 만든 배열
    printf("//////     arr31: %p,     arr32: %p\n",  arr31,     arr32);
    printf("////// &arr31[0]: %p, &arr32[0]: %p\n", &arr31[0], &arr32[0]);
    int i = 0;
    printf("////// 3-1. 값을 복사해서 만든 배열\n");
    for (i=0; i<3; i++) {
        printf("//// DEBUG 3-1 arr31[%d]\n", i);
        printf("// &arr31[%d] == %p\t: 배열 원소의 주소\n",        i, &arr31[i]);
        printf("//  arr31[%d] == %d\t\t: 복사된 값 (!!)\n",        i,  arr31[i]);
        printf("// *arr31[%d] == 사용할 수 없음\t: 컴파일 안됨\n", i);
    }
    printf("////// 3-2. 변수의 주소를 참조해서 만든 배열\n");
    for (i=0; i<3; i++) {
        printf("//// DEBUG 3-2 arr32[%d]\n", i);
        printf("// &arr32[%d] == %p\t: 배열 원소의 주소\n",   i, &arr32[i]);
        printf("//  arr32[%d] == %p\t: 참조된 변수의 주소\n", i,  arr32[i]);
        printf("// *arr32[%d] == %d\t\t: 참조된 변수의 값\n", i, *arr32[i]);
    }
    printf("////// check: (&d1: %p), (&d2: %p), (&d3: %p)\n", &d1, &d2, &d3);

    printf("\n");

    return 0;
}

int add(int n1, int n2) {
    return n1 + n2;
}

