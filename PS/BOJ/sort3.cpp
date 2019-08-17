/**
 * boj 2752
 */

#include <iostream>

int main (void) {
    int a[3], min = 0, tmp = -1;
    for (int i = 0; i < 3; i++) {
        std::cin >> a[i];
        if (a[i] < a[min]) min = i;
    }
    std::cout << a[min] << " ";
    for (int i = 0; i < 3; i++) {
        if (i != min) {
            if (tmp == -1) {
                tmp = i;
            } else {
                if (a[tmp] < a[i]) {
                    std::cout << a[tmp] << " " << a[i] << "\n";
                } else {
                    std::cout << a[i] << " " << a[tmp] << "\n";
                }
            }
        }
    }
    return 0;
}