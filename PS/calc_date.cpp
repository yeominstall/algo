#include <iostream>

int date[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main (void) {
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int m1, d1, m2, d2;
        std::cin >> m1 >> d1 >> m2 >> d2;
        for (int i = 0; i < 12; i++) {
            if (i+1 < m1) {
                d1 += date[i];
            }
            if (i+1 < m2) {
                d2 += date[i];
            }
            if (m1 <= i+1 && m2 <= i+1) {
                break;
            }
        }
        std::cout << "#" << tc << " " << d2 - d1 + 1 << "\n";
    }
}