/**
 * boj 2309
 */
#include <stdio.h>

void mergeSort (int *arr, int low, int high);
void merge (int *arr, int low, int mid, int high);
void printArr (int *arr, int len);

int main (void) {
	int h[9] = {0, };
	int real[7] = {0, };
	int total = 0;
	int diff;
	int r;
	int is_fin = 0;

	for (int i = 0; i < 9; i++) {
		scanf ("%d", &h[i]);
		total += h[i];
	}

	// 9C7 = 9!/(7!*2!) = (9*8)/2 = 36
	// 빠지는 두 명을 뽑는걸로(투입 시간 줄이기 위함)
	// 같은 키는 전제조건상 없음
	// 근데 그냥 다더해보는게 연산이 빠를듯
	diff = total - 100;
	for (int i = 0; (i < 9) && (is_fin == 0); i++) {
		for (int j = 0; (j < 9) && (is_fin == 0); j++) {
			if (i == j) continue;
			if ((h[i] + h[j]) == diff) {
				h[i] = -1;
				h[j] = -1;
				is_fin = 1;
			}
		}
	}

	for (int i = 0, r = 0; i < 9; i++) {
		if (h[i] == -1) continue;
		else {
			real[r] = h[i];
			r++;
		}
	}

	// sort
	mergeSort (real, 0, 6);

	printArr (real, 7);

	return 0;
}

void mergeSort (int *arr, int low, int high) {
	int mid;

	mid = (low + high) / 2;		// 항상 low에서 많이 가져감
	if (low == high) return;
	else {
		mergeSort(arr, low, mid);
		mergeSort(arr, mid+1, high);
		merge(arr, low, mid, high);
	}	
}

void merge (int *arr, int low, int mid, int high) {
	int buf[10] = {0, };
	int key = low;
	int i = low;
	int j = mid + 1;

	while (i <= mid && j <= high) {
		if (arr[i] < arr[j]) {
			buf[key++] = arr[i++];
		} else {
			buf[key++] = arr[j++];
		}
	}

	while (i <= mid)
		buf[key++] = arr[i++];
	while (j <= high)
		buf[key++] = arr[j++];

	for (i = low; i <= high; i++) {
		arr[i] = buf[i];
	}
}

void printArr (int *arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d\n", arr[i]);
	}
}
