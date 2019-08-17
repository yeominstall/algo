/**
 * boj 1107
 */
#include <iostream>

int channel[10];

int closer (int ch) {
    int cest = 10;
    for (int i = 0; i < 10; i++) {
        if (channel[i] != 1 && abs(ch - i) < cest) {
            cest = ch - i;
        }
    }
    return (ch - cest);
}

int main (void) {
    int N, M, c, min = 0, nearest = 0;
    int N_arr[6];
    std::cin >> N >> M;
    for (int ch = 0; ch < M; ch++) {
        std::cin >> c;
        channel[c] = 1;
    }
    if (M == 10) {
        min = abs(N - 100);
    } else if (N == 100) {
        min = 0;
    } else {
        int p = 0, mul = 1;
        c = N;
        while (c != 0) {
            if (channel[c % 10] == 1) {
                N_arr[p] = closer (c % 10);
            } else {
                N_arr[p] = c % 10;
            }
            c /= 10;
            nearest += (N_arr[p] * mul);
            p++; mul *= 10; min++;
        }
        min += abs (nearest - N);
    }
    std::cout << min << "\n";
}