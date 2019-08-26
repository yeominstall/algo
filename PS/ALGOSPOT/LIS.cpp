#include <iostream>

using namespace std;

int q[500];
int r = -1;

int main (void) {
    int T, tc, n, former, curr, cnt_max = 0;
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        cnt_max = 0;
        r = -1;
        cin >> n;
        if (n > 0) {
            cnt_max = 1;
            cin >> former;
            q[++r] = former;
        }
        while (--n > 0) {
            cin >> curr;
            if (former < curr) {
                q[++r] = curr;
            } else {
                for ( ; r > -1; r--) {
                    if (q[r] < curr) break;
                }
                q[++r] = curr;
            }
            cnt_max = max(r+1, cnt_max);
            former = curr;
        }
        cout << cnt_max << "\n";
    }
    return 0;
}