#include <bits/stdc++.h>

int N, M;

bool isRange (int x, int y) {
    return !(x < 0 || x >= M || y < 0 || y >= M);
}

int main (void) {
    N = 3, M = 3;
    int x, y;
    std::cin >> x >> y;
    if (isRange(x, y)) {
        std::cout << "You are in range\n";
    } else {
        std::cout << "Out of Bound!\n";
    }
    return 0;
}