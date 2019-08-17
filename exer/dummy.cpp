#include <iostream>

int main (void) {
    int T, a, b;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        std::cin >> a >> b;
        std::cout << "#" << tc << " " << a / b << a % b << "\n";
    }
    return 0;
}