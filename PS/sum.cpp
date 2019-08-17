#include <iostream>
#include <array>
#include <iterator>

std::array<std::array<int, 100>, 100> panel;

int sumOfRow(int row) {
    int result = 0;
    for (int i = 0; i < 100; i++) {
        result += panel[row][i];
    }
    return result;
}

int sumOfCol(int col) {
    int result = 0;
    for (int i = 0; i < 100; i++) {
        result += panel[i][col];
    }
    return result;
}

int sumOfSlash(void) {
    int sl = 0, revsl = 0;
    for (int i = 0; i < 100; i++) {
        sl += panel[i][i];
        revsl += panel[i][99-i];
    }
    return sl > revsl ? sl : revsl;
}

int main (void) {
    int input, max, tc = 0;
    while (tc != 10) {
        std::cin >> tc;;
        for (int dit = 0; dit < 100; dit++) {
            for (int it = 0; it < 100; it++) {
                std::cin >> panel[dit][it];
            }
        }

        max = sumOfSlash();
        for (int i = 0; i < 100; i++) {
            if (sumOfRow(i) > max) max = sumOfRow(i);
            if (sumOfCol(i) > max) max = sumOfCol(i);
        }

        std::cout << "#" << tc << " " << max << "\n";
    }
    return 0;
}