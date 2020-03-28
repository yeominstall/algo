#include <iostream>
#include <cstring>

using namespace std;

int main (void) {
    int n, ip;
    int p[2][100], sum[2];
    cin >> n;
    for (int i = 0; i < 2; i++) {
        sum[i] = 0;
        for (int j = 0; j < n; j++) {
            cin >> ip;
            if (i == 1 && (p[0][j] == ip)) {
                sum[0] -= p[0][j];
                p[0][j] = 0;
                p[1][j] = 0;
                continue;
            }
            sum[i] += ip;
            p[i][j] = ip;
        }
    }
    if (sum[0] == 0) {
        cout << -1 << '\n';
    } else {
        ip = ((sum[1] + 1) / sum[0]);
        if (((sum[1] + 1) % sum[0]) != 0) ++ip;
        cout << ip << '\n';
    }
    return 0;
}