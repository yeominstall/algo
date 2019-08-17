#include <bits/stdc++.h>

int main (void) {
    int arr[5] = {0};
    for (int i = 0; i < 2; i++) {
        arr[4-i] = 1;
    }
    do {
        for (int i = 0; i < 5; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    } while (std::next_permutation(arr, arr+5));
    return 0;
}