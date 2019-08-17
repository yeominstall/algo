/**
 * swea 2056
 */

#include <stdio.h>
#include <stdlib.h>

int main (void) {
	int TC;
	int *str, *res;
	int yy, mm, dd;
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	scanf ("%d", &TC);
	str = (int*)malloc(sizeof(int) * TC);
	res = (int*)malloc(sizeof(int) * TC);

	for (int i = 0; i < TC; i++) {
		scanf ("%d", &str[i]);
	}

	for (int i = 0; i < TC; i++) {
		dd = str[i] % 100;
		str[i] = str[i] / 100;
		mm = str[i] % 100;
		str[i] = str[i] / 100;
		yy = str[i];
		

		if (yy == 0 || mm == 0 || dd == 0) {
			printf("#%d %d\n", i+1, -1);
			continue;
		} 
		if (dd > days[mm-1]) {
			printf("#%d %d\n", i+1, -1);
			continue;
		}
		if (mm < 1 || mm > 12) {
			printf("#%d %d\n", i+1, -1);
			continue;
		}
		printf("#%d %.4d/%.2d/%.2d\n", i+1, yy, mm, dd);
	}
	free(str);
	free(res);

	return 0;
}
