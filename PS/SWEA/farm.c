/**
 * swea 2805
 */

#include <stdio.h>
#include <stdlib.h>

void print_table (int* table,  int size);

int main (void) {
	int tc;
	int N, income, center, line, line_idx;
	int *val;
	char *val_tmp;

	//	freopen ("input.txt", "r", stdin);

	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++) {
		scanf ("%d", &N);
		val = (int*)malloc(sizeof(int) * N * N);
		val_tmp = (char*)malloc(sizeof(char) * N);
		for (int j = 0; j < N; j++) {
			scanf ("%s", val_tmp);
			for (int k = N - 1; k >= 0; k--) {
				*(val+N*j+k) = atoi (&val_tmp[k]);
				val_tmp[k] = '\0';
			}
		}

		income = 0;
		center = N / 2;
		line = 1;
		line_idx = center;
		for (int j = 0; j <= center; j++) {
			for (int k = 0; k < line; k++) {
				income += *(val+N*j+(line_idx+k));
			}
			line += 2;
			line_idx--;	
		}
		//		for (int j = 0; j < N; j++) {
		//			income += *(val+N*center+j);
		//		}
		//		line = N - 2;
		line_idx = 1;
		for (int j = center + 1; j < N; j++) {
			for (int k = 0; k < line; k++) {
				income += *(val+N*j+(line_idx+k));
			}
			line -= 2;
			line_idx++;	
		}

		printf ("#%d %d\n", i, income);
	}

	free (val);
	free (val_tmp);

	return 0;
}

void print_table (int* table, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d ", *(table+size*i+j));
		}
		printf("\n");
	}
}
