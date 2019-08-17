#include <stdio.h>

void get_coord (int val, int *x, int *y);
int get_val (int x, int y);

int main (void) {
	int tc;
	int p, q;
	int x, y, z, w, res;

	freopen ("input.txt", "r", stdin);

	scanf ("%d", &tc);
	for (int i = 1; i <= tc; i++) {
		scanf ("%d %d", &p, &q);
		get_coord (p, &x, &y);
		get_coord (q, &z, &w);
		res = get_val (x + z, y + w);	
		printf ("#%d %d\n", i, res);
	}
	return 0;
}

void get_coord (int val, int *x, int *y) {
	int current;
	int a, b;
	for (int i = 2; i < 10000; i++) {
		current = 1 + ((i - 1) * i) / 2;
		if (val < current) {
			b = i;
			break;
		}
	}
	// y = -x + b
	for (int i = 1; i < b; i++) {
		a = 1 + ((b-i)*(b-i-1) + i*(i-1))/2 + (b-i)*(i-1);
		if (a == val) {
			*x = i;
			*y = b - i;
			break;
		}
	}
}

int get_val (int x, int y) {
	return 1 + (y*(y-1) + x*(x-1))/2 + y*(x-1);
}
