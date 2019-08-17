/**
 * swea 3750
 */
#include <stdio.h>

int dsum (long long int n) {
    int m = 0;
    while (n != 0) {
        m += (n % 10);
        n /= 10;
    }
    if (m >= 10) return dsum (m);
    else return m;
}

int main (void) {
    int T, tc;
    long long int N;
    scanf ("%d", &T);
    for (tc = 1; tc <= T; tc++) {
        scanf ("%lld", &N);
        printf ("#%d %lld\n", tc, dsum(N));
    }
    return 0;
}