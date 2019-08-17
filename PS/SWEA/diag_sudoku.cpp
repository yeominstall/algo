/**
 * swea 1974
 */

#include <iostream>

int checker[10];
int game[9][9];

void setGame (void) {
    for (int i = 0; i < 81; i++) {
        game[i/9][i%9] = 0;
    }
}

void setChecker(void) {
    for (int i = 1; i < 10; i++) {
        checker[i] = 0;
    }
}

void printChecker(void) {
    for (int i = 1; i < 10; i++) {
        std::cout << checker[i] << " ";
    }
    std::cout << "\n";
}

int main (void) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    int T, n, res, c, r;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        res = 1;
        setGame();
        setChecker();
        for (int i = 0; i < 81; i++) {
            std::cin >> n;
            game[i/9][i%9] = n;
            if (checker[n] != 0) {
                res = 0;
                break;
            } else {
                checker[n] = 1;
            }
            if (i % 9 == 8) {
                setChecker();
            }
        }
        for (int i = 0; i < 9; i++) {
            if (res == 0) break;
            setChecker();
            for (int j = 0; j < 9; j++) {
                if (res == 0) break;
                if (checker[game[j][i]] != 0) {
                    res = 0;
                    break;
                } else {
                    checker[game[j][i]] = 1;
                }
            }
        }
        for (int k = 0; k < 9; k++) {
            if (res == 0) break;
            c = k / 3; r = k % 3;
            setChecker();
            for (int i = 0; i < 3; i++) {
                if (res == 0) break;
                for (int j = 0; j < 3; j++) {
                    if (res == 0) break;
                    if (checker[game[(c*3)+i][(r*3)+j]] != 0) {
                        res = 0;
                        std::cout << "box! -- " << game[(c*3)+i][(r*3)+j] << " " << (c*3)+i << " " << (r*3)+j << "\n";
                        printChecker();
                        break;
                    } else {
                        checker[game[(c*3)+i][(r*3)+j]] = 1;
                    }
                }
            }
        }
        std::cout << "#" << tc << " " << res << "\n";
    }
}