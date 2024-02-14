#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#define offset 10000000

int main(void)
{
	int n, m, tmp;
	int* have;
	scanf("%d", &n);
	have = (int*)malloc(sizeof(int) * (offset * 2 + 1));
	memset(have, 0, sizeof(int) * (offset * 2 + 1));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		have[tmp + offset]++;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &tmp);
		printf("%d ", have[tmp + offset]);
	}
	printf("\n");

	free(have);


	return 0;
}