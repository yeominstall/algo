#include <iostream>

using namespace std;

int N;

int tiling (int pc) {
    if (pc+1 == N) return 1;
    else if (pc+2 == N) return 2;
    else {
        // add = case and | case
        return ((tiling(pc+1) + tiling(pc+2)) % 1000000007);
    }
}

int main (void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T, tc, res;
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        cin >> N;
        res = tiling(0);
        cout << res << "\n";
    }
    return 0;
}