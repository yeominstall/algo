/**
 * swea 1288
 */

#include <iostream>
 
int checker[10];
 
void clearChecker (void) {
    for (int i = 0; i < 10; i++) {
        checker[i] = 0;
    }
}
 
int supervise (void) {
    for (int i = 0; i < 10; i++) {
        if (checker[i] != 1) return 0;
    }
    return 1;
}
 
int main (void) {
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, store, cnt = 1;
        std::cin >> N;
        clearChecker();
        while (1) {
            store = N * cnt;
            while (store != 0) {
                checker[store%10] = 1;
                store /= 10;
            }
            if (supervise() == 1) break;
            cnt++;
        }
        std::cout << "#" << tc << " " << cnt * N << "\n";
    }
    return 0;
}