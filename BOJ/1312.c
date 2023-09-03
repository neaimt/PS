#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int A, B, N, re;
    scanf("%d %d %d", &A, &B, &N);
    for ( int i = 0; i < N; i++ ) {
        A = A % B;
        A *= 10;
        re = A / B;
    }

    printf("%d", re);
}
