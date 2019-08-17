/**
 * boj 2577
 */
#include <stdio.h>

int main (void) {
	int a, b, c, mul;
	int scattered[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	int numbers[10] = {0, };

	scanf("%d %d %d", &a, &b, &c);

	mul = a * b * c;
	printf("\nmul: %d\n", mul);

	for (int i = 0; i < 10; i++) {
		if (mul == 0) break;
		scattered[i] = mul % 10;
		mul = mul / 10;
	}
	for (int i = 0; i < 10; i++) printf("%d", scattered[i]);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (scattered[j] == i) {
				numbers[i]++;
			}
		}
		printf("%d\n", numbers[i]);
	}

	return 0;
}
