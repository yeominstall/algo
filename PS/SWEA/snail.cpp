/**
 * swea 1954
 */

#include <iostream>

int shell[10][10];

void resizeShell (int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            shell[i][j] = 0;
        }
    }
}

void carvingShell (int N) {
    int p = 1, msb = 1, cnt;
    int pi = 0, pj = 0;
    for (int i = 1; i <= N; i++) {
        shell[pi][pj] = i;
        pj++;
    }
    p = N + 1; cnt = N - 1;
    pj = N - 1;
    while (p <= N * N) {
        for (int i = 0; i < cnt; i++) {
            pi += msb;
            shell[pi][pj] = p;
            p++;
        }
        msb *= -1;
        for (int j = 0; j < cnt; j++) {
            pj += msb;
            shell[pi][pj] = p;
            p++;
        }
        cnt--;
    }
}

void printShell (int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << shell[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main (void) {
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N;
        std::cin >> N;
        resizeShell(N);
        carvingShell(N);
        std::cout << "#" << tc << "\n";
        printShell(N);
    }
    return 0;
}