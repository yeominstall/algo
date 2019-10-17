/**
 * boj 17281
 */

#include <iostream>
#include <algorithm>

using namespace std;

int r[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int runner[50][9];
int N;

int mux (int k) {
    return ((k < 3) ? k : k-1);
}

int run (void) {
    int curr, score = 0, j = 0, out = 0;
    short bases = 0, mask = 0xF0, home;
    for (int inn = 0; inn < N; inn++) {
        for ( ; ; j++) {
            j %= 9;
            curr = (j == 3) ? runner[inn][0] : runner[inn][r[mux(j)]];
            if (curr == 0) {
                out = (out+1) % 3;
                if (out == 0) {
                    j++;
                    break;
                }
            } else {
                ++bases;
                bases <<= curr;
                home = bases & mask;
                bases &= 0xF;
                home >>= 4;
                while (home != 0) {
                    if (home & 1) score++;
                    home >>= 1;
                }
            }
        }
        bases = 0;
    }
    return score;
}

int main (void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int score, max_score = -1;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> runner[i][j];
        }
    }
    do {
        score = run();
        max_score = max(max_score, score);
    } while (next_permutation(r, r+8));
    cout << max_score << "\n";
    return 0;
}