/**
 * boj 1003
 */
#include <stdio.h>
#include <stdlib.h>

int count_fibo (int N, int *zero, int *one);

int main(void) {
	int T;
	int *Narr;
	int z = 0;
	int o = 0;

	scanf("%d", &T);
	Narr = (int*)malloc(sizeof(int) * T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &Narr[i]);
	}

	for (int i = 0; i < T; i++) {
		count_fibo(Narr[i], &z, &o);
		printf("%d %d\n", z, o);
		z = 0;
		o = 0;
	}

	free(Narr);
	return 0;
}

int count_fibo (int N, int *zero, int *one) {
	if (N == 0) {
		(*zero)++;
		return 0;
	} else if (N == 1) {
		(*one)++;
		return 1;
	} else {
		return count_fibo(N-1, zero, one) + count_fibo(N-2, zero, one);
	}
}
