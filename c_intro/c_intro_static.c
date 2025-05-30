#include <stdio.h>


void test_static();


int main(void) {
    int i;
    for (i=0; i<3; i++) {
        test_static();
    }


    return 0;
}

void test_static() {
    static int num_static = 0;
           int num_local  = 0;

    num_static++;
    num_local++;
    
    printf("num_static: %d, num_local: %d\n", num_static, num_local);
}


