/**
 * swea 1860
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b)	a > b ? a : b

int main (void) {
	int tc;
	int N, M, K;
	int arrive;
	int queue[11112] = {0, };
	int current;
	int t_max = 11112;

	freopen ("input.txt", "r", stdin);

	scanf ("%d", &tc);
	for (int i = 1, t_max = 0; i <= tc; i++) {
		scanf ("%d %d %d", &N, &M, &K);
		for (int j = 0; j < N; j++) {
			scanf ("%d", &arrive);
			queue[arrive]++;
			t_max = MAX (t_max, arrive);
		}
		current = 0;
		for (int j = 0; j <= t_max && current >= 0; j++) {
			if (j > 0 && j % M == 0) {
				current += K;
			}
			current -= queue[j];
		}
		for (int j = 0; j <= t_max; j++) {
			queue[j] = 0;
		}
		if (current < 0) {
			printf ("#%d Impossible\n", i);
		} else {
			printf ("#%d Possible\n", i);
		}
	}

	return 0;
}
