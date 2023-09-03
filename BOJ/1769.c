#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int N, M, sum=0, cnt=0;
    for ( ;; cnt++ ) {
        int ch = getchar();
        if ( ch < '0' || ch >'9' ) break;
        sum += ch - '0';
    }
    cnt = cnt > 1 ? 1 : 0;
    N = sum;

    while ( N >= 10 ) {
        M = N;
        sum = 0;
        while ( M > 0 ) {
            sum = sum + (M % 10);
            M /= 10;
        }
        N = sum;
        cnt++;
    }

    if ( N % 3 != 0 )
        printf("%d\nNO", cnt);
    else
        printf("%d\nYES", cnt);

}