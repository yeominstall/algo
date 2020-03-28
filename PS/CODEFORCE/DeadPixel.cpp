/**
 * Codeforce #623 - A. DeadPixel
 */
#include <iostream>
#include <cstring>

using namespace std;

int main (void) {
    int T, a, b, x, y;
    int res[12];
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> a >> b >> x >> y;
        int mx = -1;
        memset(res, 0, sizeof(res));
        res[0] = x * b;
        res[1] = y * a;
        res[2] = (a - x - 1) * b;
        res[3] = (b - y - 1) * a;
        res[4] = y * (x + 1);
        res[5] = y * (a - x);
        res[6] = (b - y - 1) * (x + 1);
        res[7] = (b - y - 1) * (a - x);
        res[8] = x * (y + 1);
        res[9] = x * (b - y);
        res[10] = (a - x - 1) * (y + 1);
        res[11] = (a - x - 1) * (b - y);

        for (int i = 0; i < 12; i++) {
            mx = max(mx, res[i]);
        }
        cout << mx << '\n';
    }

    return 0;

}