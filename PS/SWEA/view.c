/**
 * swea 1206
 */
#include <stdio.h>
#include <stdlib.h>

int main (void) {
	int tc = 10;
	int res;
	int n, h_max;
	int *h, *scene;

	freopen ("input.txt", "r", stdin);

	for (int i = 1; i <= tc; i++) {
		scanf ("%d", &n);
		h = (int*)malloc(sizeof(int) * n);
		h_max = 0;
		for (int j = 0; j < n; j++) {
			scanf ("%d", h+j);
			if (h_max < *(h+j)) {
				h_max = *(h+j);
			}
		}
		scene = (int*)malloc(sizeof(int) * n * h_max);
		res = 0;

		for (int j = 0; j < h_max; j++) {
			for (int k = 0; k < n; k++) {
				if (h[k] <= j) {
					*(scene+j*n+k) = -1;
				} else {
					if (j > 0 && (*(scene+(j-1)*n+k) == 1 || *(scene+(j-1)*n+k) == -1)) {
						*(scene+j*n+k) = *(scene+(j-1)*n+k);
					} else {
						if (*(scene+j*n+(k-2)) == -1 && *(scene+j*n+(k-1)) == -1 && h[k+1] <= j && h[k+2] <= j) {
							*(scene+j*n+k) = 1;
						} else {
							*(scene+j*n+k) = 0;
						}
					}
				}
			}
		}
		for (int j = 0; j < h_max * n; j++) {
			if (*(scene+j) == 1) {
				res++;
			}
		}

		printf ("#%d %d\n", i, res);
	}

	free (h);
	free (scene);

	return 0;
}
