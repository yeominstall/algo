#include <stdio.h>

int main (void) {
	int x, y, n, wd;
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char *weekdays[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

	scanf ("%d %d", &x, &y);

	n = y - 1;		// 1월 1일이 0번째
	for (int m = (x - 1); m > 0; m--) {
		n += days[m - 1];
	}
	wd = n % 7;
	printf("%s\n", weekdays[wd]);

	return 0;
}
