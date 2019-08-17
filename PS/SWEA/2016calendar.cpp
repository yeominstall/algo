/**
 * swea 5515
 */

#include <iostream>

int days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main (void) {
    int T, m, d;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int wd = 4;
        std::cin >> m >> d;
        for (int i = 0; i < m-1; i++) {
            wd += days[i];
        }
        std::cout << "#" << tc << " " << (wd + d) % 7 << "\n";
    }
    return 0;
}