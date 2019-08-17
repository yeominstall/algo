#include <iostream>

int main (void) {
    int T, N, res, min, max;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        res = 0, min = 10001, max = -1;
        for (int i = 0; i < 10; i++) {
            std::cin >> N;
            res += N;
            min = (min > N) ? N : min;
            max = (max < N) ? N : max;
        }
        res = ((double)(res - min - max) / 8) + 0.5;
        std::cout << "#" << tc << " " << res << "\n";
    }
    return 0;
}