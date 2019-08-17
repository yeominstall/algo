/**
 * swea 4466
 */
#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int T, tc, N, K, i, ip;
    vector<int> p;
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        int res = 0;
        cin >> N >> K;
        for (i = 0; i < N; i++) {
            cin >> ip;
            p.push_back(ip);
        }
        sort(p.rbegin(), p.rend());
        for (i = 0; i < K; i++) {
            res += p.at(i);
        }
        std::cout << "#" << tc << " " << res << "\n";
        p.clear();
    }
    return 0;
}