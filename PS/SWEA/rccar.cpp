/** 
 * swea 1940
 */

#include <iostream>
 
int main (void) {
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, dist = 0, comm, sp, csp = 0;
        std::cin >> N;
        for (int c = 0; c < N; c++) {
            std::cin >> comm;
            if (comm != 0) {
                std::cin >> sp;
            }
            if (comm == 1) csp += sp;
            else if (comm == 2) {
                csp -= sp;
                if (csp < 0) csp = 0;
            }
            dist += csp;
        }
        std::cout << "#" << tc << " " << dist << "\n";
    }
}