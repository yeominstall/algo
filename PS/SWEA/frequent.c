/**
 * swea 1204
 */
#include <stdio.h>
#include <stdlib.h>

int main (void) {
	int tc = 10;
	int point[10][1000];
	int list[101];
	int tmp, freq_max, freq_num;

	for (int i = 0; i < 10; i++) {
		scanf ("%d", &tmp);
		for (int j = 0; j < 1000; j++) {
			scanf("%d", &point[i][j]);
		}
	}
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 101; j++) {
			list[j] = 0;
		}
		freq_max = 0;
		for (int j = 0; j < 1000; j++) {
			list[point[i][j]]++;
		}
		for (int j = 0; j < 101; j++) {
			if (freq_max <= list[j]) {
				freq_max = list[j];
				freq_num = j;
			}
		}
		printf ("#%d %d\n", i+1, freq_num);
	}
	return 0;
}
