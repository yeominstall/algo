/**
 * boj 2629
 */
#include <stdio.h>
#include <stdlib.h>

void printTable(int* table, int row, int col);

int main (void) {
	int n;
	int *weight;
	int weight_total;
	int m;
	int *g;
	int weight_table[30][15001] = {0, };
	int new;

	scanf ("%d", &n);
	weight = (int*)malloc(sizeof(int) * n);
	weight_total = 0;
	for(int i = 0; i < n; i++) {
		scanf ("%d", &weight[i]);
		weight_total += weight[i];
	}

	weight_table[0][0] = 1;
	weight_table[0][weight[0]] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = -1; j <= 1; j++) {
			for (int l = -1; l <= 1; l++) {
				for (int k = 0; k <= weight_total; k++) {
					if (weight_table[i-1][k] == 1) {
						new = weight[i] * j + k * l;
						if (new >= 0) {
							weight_table[i][new] = 1;
							//						printf("i = %d, j = %d, k = %d, new = %d\n", i, j, k, new);
						}
					}
				}
			}
		}
	}
//	printTable(weight_table, n, weight_total+1);

	scanf ("%d", &m);
	g = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++) {
		scanf ("%d", &g[i]);
	}

	for (int i = 0; i < m; i++) {
//		printf("search weight_table[%d][%d]..\n", n-1, g[i]);
		if (g[i] > weight_total) {
			printf("N ");
			break;
		}
		if (weight_table[n-1][g[i]] == 1) {
			printf("Y ");
		} else {
			printf("N ");
		}
	}
	printf("\n");

	free(weight);
	free(g);

	return 0;
}

void printTable(int* table, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d ", *(table+(i*15001)+j));
		}
		printf("\n");
	}
}
