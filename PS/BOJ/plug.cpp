/**
 * boj 2010
 */

#include <iostream>

int main (void) {
  freopen("input.txt", "r", stdin);
    int N, i, tab, conn = 0;
    std::cin >> N;
    for (i = 0; i < N; i++) {
        std::cin >> tab;
        conn += tab;
    }
    conn -= (N-1);
    std::cout << conn << "\n";
    return 0;
}
