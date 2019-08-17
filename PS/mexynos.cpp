#include <iostream>
#include <array>

int main (void) {
    int T, N, item, length, pos = 0;
    std::cin >> T;
    std::array<int, 144> panel;
    std::array<int, 12> cores;

    for (int i = 1; i <= T; i++) {
        std::cin >> N;
        for (int j = 0; j < N*N; j++) {
            std::cin >> item;
            panel.at(j) = item;
            if (item == 1) {
                cores.at(pos++) = j;
            }
        }

        // find closest way of each chips
        // empty = 0, chip = 1, line = 2
        // 1 <= core <= 12
        for (int c = 0; c < pos)


        // print
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cout << panel.at(i * N + j) << " ";
            }
            std::cout << "\n";
        }

        // print result
        std::cout << "#" << T << " " << length << "\n";
    }

    return 0;
}