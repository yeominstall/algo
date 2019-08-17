/**
 * swea 4676
 */
#include <bits/stdc++.h>

using namespace std;

int p[21];

void initP (void) {
    int i;
    for (i = 0; i < 21; i++) p[i] = 0;
}

int main (void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T, tc, H, i, j, pc;
    string ip;
    cin >> T;
    for (tc = 1; tc <= T; ++tc) {
        cin >> ip >> H;
        initP();
        for (i = 0; i < H; i++) {
            cin >> pc;
            p[pc]++;
        }
        cout << "#" << tc << " ";
        for (i = 0; i <= ip.size(); i++) {
            for (j = 0; j < p[i]; j++) {
                cout << "-";
            }
            if (i == ip.size()) break;
            cout << ip.at(i);
        }
        cout << "\n";
    }
    return 0;
}