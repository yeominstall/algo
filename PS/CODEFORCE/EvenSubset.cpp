#include <iostream>

using namespace std;

int main (void) {
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int n, k = 0, a[100];
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) {
                k = i + 1;
            }
        }
        if (k == 0) {
            if (n > 1) {
                cout << 2 << '\n' << "1 2\n";
            } else {
                cout << -1 << '\n';
            }
        } else {
            cout << 1 << '\n' << k << '\n';
        }
    }
    return 0;
}