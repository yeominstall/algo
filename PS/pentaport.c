#include <stdio.h>
#include <stdlib.h>

int get_distance (short x1, short y1, short x2, short y2);
int is_happy (int dist);

int main (void) {
	int tc;
	int conv_num;
	short *location;
	int dist;
	int tmp;

	freopen ("input.txt", r, stdin);

	scanf ("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf ("%d", &conv_num);
		location = (short*)malloc(sizeof(short) * (conv_num + 2) * 2);
		for (int j = 0; j < conv_num + 2; j++) {
			scanf("%hd %hd", (location+j*2), (location+j*2+1));
		}
		dist = get_distance (*(location), *(location+1), *(location+(conv_num+1)*2), *(location+(conv_num+1)*2+1));

		if (dist <= 1000) {
			printf ("happy\n");
			continue;
		}
			
		}
	}

	free (location);

	return 0;
}

int get_distance (short x1, short y1, short x2, short y2) {
	int x_d, y_d; 
	x_d = (int)(x2 - x1);
	y_d = (int)(y2 - y1);
	if (x_d < 0) x_d *= -1;
	if (y_d < 0) y_d *= -1;
	return x_d + y_d;
}

int is_happy (int dist) {
	if (dist <= 1000) {
		return 1;
	} else {
		return 0;
	}
}
