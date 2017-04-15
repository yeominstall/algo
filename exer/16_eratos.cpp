/*
 * algorithm problem solving strategy - p.587
 */

#include <stdio.h>

#define MAX_N	1000

int n;
unsigned char sieve[(MAX_N + 7) / 8];

inline bool isPrime (int k) {
	return sieve[k >> 3] & (1 << (k & 7));
}

inline void setComposite(int k) {
	sieve[k >> 3] &= ~(1 << (k & 7));
}

void eratosthenes() {
	memset (sieve, 255, sizeof(sieve));
	setComposite (0);
	setComposite (1);
	int sqrtn = int(sqrt(n));

	for (int i = 2; i <= sqrtn; ++i) {
		if (isPrime(i))
			for (int j = i*i; j <= n; j +=i)
				setComposite(j);
	}
}
