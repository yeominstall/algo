/**
 * swea 2001
 */

#include <iostream>

int area[15][15];

void clearArea (void) {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            area[i][j] = 0;
        }
    }
}

int hitChecker (int M, int px, int py) {
    int sum = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            sum += area[py-i][px-j];
        }
    }
    return sum;
}

int main (void) {
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, M, flies, max_hit = -1, hc = 0;
        std::cin >> N >> M;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cin >> flies;
                area[i][j] = flies;
                if (i > (M-2) && j > (M-2)) {
                    hc = hitChecker(M, j, i);
                    max_hit = (max_hit < hc) ? hc : max_hit;
                }
            }
        }

        std::cout << "#" << tc << " " << max_hit << "\n";
        max_hit = -1;
    }
    
    return 0;
}