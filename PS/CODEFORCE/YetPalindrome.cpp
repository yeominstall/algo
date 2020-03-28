#include <iostream>
#include <cstring>

using namespace std;

int main (void) {
    int T, n, a[5000];
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> n;
        bool former[5000];
        memset(former, 0, sizeof(former));
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool res = false;
        for (int i = 0; (i < n-2 && !res); i++) {
            former[a[i]] = true;
            if (former[a[i+2]]) {
                res = true;
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