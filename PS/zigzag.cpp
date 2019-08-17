#include <iostream>

int main (void) {
    int T, N, res;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        std::cin >> N;
        res = (N % 2 == 0) ? N/2*(-1) : N/2;
        std::cout << "#" << tc << " " << res << ;
    }
    return 0;
}