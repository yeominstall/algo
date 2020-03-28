#include <iostream>

using namespace std;

int main (void) {
    int T, n, a[100], highest;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> n;
        highest = -1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            highest = max(highest, a[i]);
        }
        bool res = true;
        for (int i = 0; i < n; i++) {
            if ((highest - a[i]) % 2 != 0) {
                res = false;
                break;
            }
        }
        if (res) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}