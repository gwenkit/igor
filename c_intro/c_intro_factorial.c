#include <stdio.h>


long long f(const int x);


int main(void) {
    int num;
    printf("number(0 ~ 20): ");
    scanf(" %d", &num);
    printf("%d! = %lld\n", num, f(num));

    return 0;
}

long long f(const int x) {
    long long r = 1;
    int i;
    for (i=r; i<=x; i++) {
        r *= i;
    }
    // max: 20! = 2432902008176640000
    return r;
}

