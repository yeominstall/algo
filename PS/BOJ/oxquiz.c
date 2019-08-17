/**
 * boj 8958
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void) {
	int TC;
	char *s;
	//int *point;
	int i, j, accum, total;

	scanf("%d", &TC);
	s = (char*)malloc(sizeof(char)*TC*80);
//	point = (int*)malloc(sizeof(int)*TC);

	for (i = 0; i < TC; i++) {
		scanf("%s", &s[80*i]);
	}
	for (i = 0; i < TC; i++) {
		accum = 0;
		total = 0;
		for (j = 0; j < 80 && s[80*i+j] != '\0'; j++) {
			if (s[80*i+j] == 'O') {
				// O일경우, 누적
				total += ++accum;
			} else {
				accum = 0;
			}
		}
		printf("%d\n", total);
	}

	free (s);
	//free (point);

	return 0;
}
