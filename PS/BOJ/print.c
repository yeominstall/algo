/**
 * boj 11719
 */
#include <stdio.h>

int main(void){
	char sentence[101];

	while (fgets(sentence, sizeof(sentence), stdin) != NULL){
		fputs(sentence, stdout);
	}

	return 0;
}
