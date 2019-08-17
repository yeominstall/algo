/**
 * swea 1285
 */

#include <iostream>
 
int main (void) {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, closer = 100001, winner = 0, ip;
        std::cin >> N;
        for (int p = 0; p < N; p++) {
            std::cin >> ip;
            if (ip < 0) ip *= -1;
            if (closer == ip) {
                winner++;
            } else if (closer > ip) {
                winner = 1;
                closer = ip;
            }
        }
        std::cout << "#" << tc << " " << closer << " " << winner << "\n";
    }
}