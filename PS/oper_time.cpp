#include <iostream>

int main (void) {
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int h, m, h1, h2, m1, m2;
        std::cin >> h1 >> m1 >> h2 >> m2;
        m = (m1 + m2) % 60;
        h = (h1 + h2 + ((m1 + m2) / 60)) % 12;
        if (h == 0) h = 12;

        std::cout << "#" << tc << " " << h << " " << m << "\n";
    }
}