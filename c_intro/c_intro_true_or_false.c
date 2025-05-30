#include <stdio.h>


int main(void)
{
    int n, m;
    n = 10;
    m = 100;

    printf("?( %d == %d ): %d\n", n, m, (n == m));
    printf("?( %d <= %d ): %d\n", n, m, (n <= m));
    printf("?(      !%d ): %d\n", m,    (    !m));


    return 0;
}


