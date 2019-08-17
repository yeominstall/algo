/**
 * swea 3975
 */
#include <bits/stdc++.h>
using namespace std;

int main (void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T, tc, b, d;
    float a, c;
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        cin >> a >> b >> c >> d;
        a = a/b; c = c/d;
        cout << "#" << tc << " ";
        if (a == c) {
            cout << "DRAW";
        } else {
            cout << ((a > c) ? "ALICE" : "BOB");
        }
        cout << "\n";
    }
    return 0;
}