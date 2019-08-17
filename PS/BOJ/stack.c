/**
 * boj 10828
 */
#include <stdio.h>
#include <string.h>

void spush (int n);
int spop ();
int ssize ();
int isempty ();
int stop ();

int top = -1;
int stack[10000];
int size = 0;

int main (void) {
	int tc, X;
	char inst[5];
	enum instructions {push, pop, size, empty, top};

	// input
	scanf ("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf ("%s", inst);
		if (strcmp(inst, "push") == 0) {
			scanf ("%d", &X);
			spush (X);
		}
		// calc
		if (strcmp (inst, "pop") == 0) {
			printf("%d\n", spop());
		}
		if (strcmp (inst, "size") == 0) {
			printf("%d\n", ssize());
		}
		if (strcmp (inst, "empty") == 0) {
			printf("%d\n", isempty());
		}
		if (strcmp (inst, "top") == 0) {
			printf("%d\n", stop());
		}
	}

	return 0;
}

void spush (int n) {
	if (top >= 10000) {
		return;
	} else {
		top += 1;
		stack[top] = n;
	}
}

int spop (void) {
	int n;
	if (isempty() == 1) {
		return -1;
	} else {
		n = stack[top];
		stack[top] = '\0';
		top -= 1;
		return n;
	}
}

int ssize (void) {
	return top+1;
}

int isempty (void) {
	if (top == -1) {
		return 1;
	} else {
		return 0;
	}
}

int stop (void) {
	if (isempty() == 1) {
		return -1;
	} else {
		return stack[top];
	}
}
