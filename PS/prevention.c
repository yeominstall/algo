#include <stdio.h>
#include <stdlib.h>

#define MAX(A, B)	A > B ? A : B

int main (void) {
	int tc;
	int N, M;
	int *city;
	int serv_max = 0;

	// input
	scanf ("%d", &tc);
	for (int i = 1; i <= tc; i++) {
		scanf ("%d %d", &N, &M);
		city = (int*)malloc (sizeof (int) * N * N);
		for (int j = 0; j < N * N; j++) {
			scanf ("%d", (city+j));
		}

		// calc
		for (int j = 0; j < XXXXX; j++) {
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < N; l++) {
					benefit = *(city+N*k+l) * M - cost;
					if (benefit >= 0) {
						serv_max = MAX(serv_max, )
					}
				}
			}
		}

		// output
		printf ("#%d %d\n", i, benefit);
	}

	free (city);
	return 0;
}
