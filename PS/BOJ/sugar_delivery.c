/**
 * from BOJ sugar delivery(2839)
 * there is 3kg/5kg packs of sugar
 * input	: total weight of sugar (3 <= N <= 5000)
 * output	: the min. number of sugar pack
 * exception	: print -1
 */

#include <stdio.h>

int get_min_pack_recur(int n);

int main (void) {

	int w;		// total weight
	int min_pack = -1;
	scanf ("%d", &w);

	/** methods
	 * 1. brute-force(compare all of the case)
	 * 2. n % 3 or n % 5 or n % 8
	 */
	min_pack = get_min_pack_recur(w);

	printf("%d\n", min_pack);

	return 0;

}

int get_min_pack_recur(int w) {
	int min = 5000;
	int big = w / 5;
	int little = w / 3;

	for (int i = 0; i <= little; i++) {
		for (int j = 0; j <= big; j++) {
			if ((((i * 3) + (j * 5)) == w) && (min > (i + j))) {
				min = i + j;
			}
		}
	}
	if (min == 5000) min = -1;

	return min;
}
