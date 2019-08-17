#include <iostream>

int game[16][16];

void resetGame(void) {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            game[i][j] = -1;
        }
    }
}

int findNRow (int n, int k) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int r = 0;
        for (int j = 0; j < n; j++) {
            if (game[i][j] == 1) {
                r++;
            } else {
                r = 0;
            }
            if (r == k && game[i][j+1] != 1) {
                cnt++;
            }
        }
    }
    return cnt;
}

int findNCol (int n, int k) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int r = 0;
        for (int j = 0; j < n; j++) {
            if (game[j][i] == 1) {
                r++;
            } else {
                r = 0;
            }
            if (r == k && game[j+1][i] != 1) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main (void) {
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, K, res, data;
        std::cin >> N >> K;
        resetGame();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cin >> data;
                game[i][j] = data;
            }
        }
        res = findNCol(N, K) + findNRow (N, K);
        std::cout << "#" << tc << " " << res << "\n";
    }
    
    return 0;
}