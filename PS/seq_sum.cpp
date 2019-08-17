#include <iostream>

bool ert[1000001] = {true, };

void eratos (int N) {
    ert[1] = true;
    for (int i = 2; i * i <= N; i++) {
        if (ert[i]) {
            for (int j = i * 2; j <= N; j += i) {
                ~ert[j];
            }
        }
    }
}

int main (void) {
    eratos (1000000);
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N;
        std::cin >> N;
    }
}