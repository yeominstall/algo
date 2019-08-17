/**
 * swea 5431
 */

#include <bits/stdc++.h>

bool stud[101];

void clearStdPool (void) {
    for (int i = 0; i < 101; i++) {
        stud[i] = false;
    }
}

int main (void) {
    std::cin.tie(0); std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, K, ip;
        std::cin >> N >> K;
        clearStdPool();
        for (int i = 0; i < K; i++) {
            std::cin >> ip;
            stud[ip] = true;
        }
        std::cout << "#" << tc << " ";
        for (int i = 1; i <= N; i++) {
            if (!stud[i]) {
                std::cout << i << " ";
            }
        }
        std::cout << "\n";
    }
    return 0;
}