#include <stdio.h>

float log2(float n);

int main(void) {
    printf("El logaritmo de %f es %f\n", 8.00, log2(8.00));
    return 0;
}

float log2(float n) {
    if (n<=1) {
        return 0;
    }
    return 1+log2(n/2);
}