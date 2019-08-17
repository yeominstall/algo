#include <iostream>

char flag[50][50];
int counter[50][3];     // W B R

void initFlag (void) {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            flag[i][j] = '\0';
        }
    }
}

void initCounter (void) {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 3; j++) {
            counter[i][j] = 0;
        }
    }
}

int main (void) {
    int T, N, M, reverse, rev_tmp, rev_min;
    char color;
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        initCounter();
        initFlag();
        std::cin >> N >> M;
        for (int h = 0; h < N; h++) {
            for (int w = 0; w < M; w++) {
                std::cin >> color;
                flag[h][w] = color;
                // making counter
                if (color == 'W') {
                    counter[h][0]++;
                } else if (color == 'B') {
                    counter[h][1]++;
                } else if (color == 'R') {
                    counter[h][2]++;
                }
            }
        }
        reverse = (M * 2) - counter[0][0] - counter[N-1][2];
        rev_min = 2500;
        for (int b_vol = N-2; b_vol >= 1; b_vol--) {
            for (int starting = 1; starting+b_vol <= N-1; starting++) {
                rev_tmp = 0;
                for (int p = 1; p < N-1; p++) {
                    // W range
                    if (p < starting) {
                        rev_tmp += M - counter[p][0];
                    }
                    // B range
                    else if (p >= starting && p < starting+b_vol) {
                        rev_tmp += M - counter[p][1];
                    }
                    // R range
                    else {
                        rev_tmp += M - counter[p][2];
                    }
                }
                if (rev_tmp < rev_min) rev_min = rev_tmp;
            }
        }
        reverse += rev_min;

        std::cout << "#" << tc << " " << reverse << "\n";
    }
    return 0;
}