/**
 * swea 1946
 */
#include <iostream>

char nums[200];

int main (void) {
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, cnt = 0, K, p = 0;
        char C;
        std::cin >> N;
        for (int i = 0; i < N; i++) {
            std::cin >> C >> K;
            cnt += K;
            for (int j = 0; j < K; j++) {
                nums[p++] = C;
            }
        }
        std::cout << "#" << tc << "\n";
        for (int i = 0; i < cnt; i++) {
            std::cout << nums[i];
            if ((i+1) % 10 == 0 || (i+1) == cnt) std::cout << "\n";
        }
    }
    return 0;
}