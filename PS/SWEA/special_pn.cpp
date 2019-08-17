/**
 * swea 4698
 */
#include <bits/stdc++.h>

#define range   1000001
using namespace std;

bool pn[range];

void makePns (void) {
    int i, j;
    for (i = 0; i < range; i++) {
        pn[i] = false;
    }
    pn[0] = true; pn[1] = true;
    for (i = 2; i < 1001; i++) {
        if (!pn[i]) {
            for (j = i+i; j < range; j += i) {
                pn[j] = true;
            }
        }
    }
}

int specialPns (char D, int from, int to) {
    int i, j, cnt = 0;
    string num;
    for (i = from; i <= to; i++) {
        if (!pn[i]) {
            num = to_string(i);
            for (j = 0; j < num.size(); j++) {
                if (num.at(j) == D) {
                    cnt++;
                    break;
                }
            }
        }
    }
    return cnt;
}

int main (void) {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    makePns();
    int T, tc, A, B;
    char D;
    cin >> T;
    for (tc = 1; tc <= T; ++tc) {
        cin >> D >> A >> B;
        cout << "#" << tc << " " << specialPns(D, A, B) << "\n";
    }
    return 0;
}