/**
 * swea 5162
 */
#include <bits/stdc++.h>

using namespace std;

int main (void) {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T, tc, a, b, c;
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        cin >> a >> b >> c;
        cout << "#" << tc << " " << ((a < b) ? (c / a) : (c / b)) << "\n";
    }
    return 0;
}