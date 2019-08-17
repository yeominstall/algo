/**
 * swea 1859
 */

#include <stdio.h>
#include <stdlib.h>

int main (void) {
	int tc;
	int *N;
	int *price;
	int max = 0;
	int max_idx, c;
	long long total;		// 총 구매금액, 재고
	long long benefit;
	int pc;

	freopen ("input.txt", "r", stdin);
	// input
	scanf("%d", &tc);
	N = (int*)malloc(sizeof(int) * tc);
	price = (int*)malloc(sizeof(int) * tc * 1000000);

	for (int i = 0; i < tc; i++) {
		scanf ("%d", &N[i]);
		for (int j = 0; j < N[i]; j++) {
			scanf ("%d", price+1000000*i+j);
		}
//		printf("@%d %d\n", i+1, *(price+1000000*(i+1)-1));
	}

	// calc
	for (int i = 0; i < tc; i++) {
		benefit = 0;
		total = 0;
		c = 0;
		max = 0;
		pc = 0;
		while (pc < N[i]) {
			for (int j = pc; j < N[i]; j++) {
				if (max <= *(price+1000000*i+j)) {
					max = *(price+1000000*i+j);
					max_idx = j;
				}
				//printf("%d ", *(price+10000*i+j));
			}
			//printf("\n");

			for (int j = pc; j < max_idx; j++) {
				total += *(price+1000000*i+j);
				c++;
			}
			benefit += (long long)max * c - total;
			max = 0;
			c = 0;
			total = 0;
			pc = max_idx + 1;
		}

	// output
		printf("#%d %lld\n", i+1, benefit);
	}


	return 0;
}
