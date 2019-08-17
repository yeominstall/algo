/**
 * boj 1152
 */
#include <stdio.h>
#include <string.h>

int main (void) {
	char sentence[1000001];
	char *str;
	int wc = 0;

	fgets (sentence, sizeof(sentence), stdin);
	str = strtok (sentence, " ");

	while (str != NULL) {
		if (str) wc++;
		str = strtok (NULL, " ");
	}

	printf("%d\n", wc);

	return 0;
}
