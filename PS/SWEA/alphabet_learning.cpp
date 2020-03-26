/**
 * SWEA 9480
 */
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int comb[15];

int getTotalCases(const int N) {
    int cs = 1;
    for (int i = 0; i < N; i++) {
        cs *= 2;
    }
    return cs - 1;
}

void makeCombSet (const int N, const int c) {
    memset(comb, 0, sizeof(comb));
    for (int i = 0; i < c; i++) {
        comb[N-i-1] = 1;
    }
}

int main (void) {
    int T, N;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N;
        const int comp = 67108863;    // 2^26 - 1
        int wordcheck[15];
        int tcs = getTotalCases(N);
        string w;
        memset(wordcheck, 0, sizeof(wordcheck));
        for (int i = 0; i < N; i++) {
            cin >> w;
            for (int j = 0; j < w.size(); j++) {
                wordcheck[i] |= (1 << (w[j] - 'a'));
            }
        }
        for (int i = 1; i <= N; i++) {
            bool keep = false;
            makeCombSet(N, i);
            do {
                int tmp = 0;
                for (int j = 0; j < N; j++) {
                    if (comb[j] != 0) {
                        tmp |= wordcheck[j];
                    }
                }
                if (tmp != comp) {
                    tcs--;
                    keep = true;
                }
            } while (next_permutation(comb, comb+N));
            if (!keep) break;
        }
        cout << "#" << tc << " " << tcs << '\n';
    }
    return 0;
}