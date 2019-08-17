#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int index;
	int w;
	int h;
	int rank;
} volume;

void mergeSort (volume *arr, int low, int high);
void merge (volume *arr, int low, int mid, int high);
void printVols (volume *v, int len);
void swapVols (volume *a, volume *b);

int main (void) {
	int N;
	volume *v, *ranking;
	scanf ("%d", &N);
	v = (volume*)malloc(sizeof(volume) * N);
	ranking = (volume*)malloc(sizeof(volume) * N);

	for (int i = 0; i < N; i++) {
		scanf ("%d %d", &v[i].w, &v[i].h);
		v[i].index = i;
		ranking[i].index = v[i].index;
		ranking[i].w = v[i].w;
		ranking[i].h = v[i].h;
	}

	// weight 기준 정렬
	mergeSort (ranking, 0, N-1);
	printVols (ranking, N);

	free(v);
	free(ranking);

	return 0;
}

void mergeSort (volume *arr, int low, int high) {
	int mid;
	mid = (low + high) / 2;
	if (low == high) return;
	else {
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}

void merge (volume *arr, int low, int mid, int high) {
	volume *buf[51];
	int i, j, key;
	i = low;
	j = mid + 1;
	key = low;

	while (i <= mid && j <= high) {
		if (arr[i].w < arr[j].w) {
			swapVols (buf[key], &arr[i]);
			key++; i++;
		} else {
			swapVols (buf[key], &arr[j]);
			key++; j++;
		}
	}

	while (i <= mid) {
		swapVols (buf[key], &arr[i]);
		key++; i++;
	}
	while (j <= high) {
		swapVols (buf[key], &arr[j]);
		key++; j++;
	}

	for (i = low; i <= high; i++) {
		swapVols (buf[key], &arr[i]);
	}
}

void printVols (volume *v, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d %d\n", v[i].w, v[i].h);
	}
}

void swapVols (volume *a, volume *b) {
	volume *t;

	t->index = a->index;
	t->w = a->w;
	t->h = a->h;
	t->rank = a->rank;
	a->index = b->index;
	a->w = b->w;
	a->h = b->h;
	a->rank = b->rank;
	b->index = a->index;
	b->w = a->w;
	b->h = a->h;
	b->rank = a->rank;
}
