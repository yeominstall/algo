#include <stdio.h>
#include <string.h>

int main (void) {
	char sent[50] = "kim sang hyung 1970 6.29";
	char *str;

	str = strtok(sent, " ");
	if (str) printf("%s\n", str);
	puts("aa");

	while (str!=NULL) {
		str = strtok(NULL, " ");
		if (str) printf("%s\n", str);
	}
	return 0;
}
