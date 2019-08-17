/**
 * swea 4371
 */
#include <bits/stdc++.h>

int hp[5000];

int main (void) {
    
    int T, tc, N, ship_cnt, i, j, ip;
    std::cin >> T;
    for (tc = 1; tc <= T; ++tc) {
        ship_cnt = 0;
        std::cin >> N;
        for (i = 0; i < N; i++) {
            std::cin >> hp[i];
            --hp[i];
        }
        for (i = 1; i < N; i++) {
            if (hp[i] == 0) continue;
            ship_cnt++;
            for (j = i+1; j < N; j++) {
                if (hp[j] % hp[i] == 0) {
                    hp[j] = 0;
                }
            }
        }
        std::cout << "#" << tc << " " << ship_cnt << "\n";
    }
}