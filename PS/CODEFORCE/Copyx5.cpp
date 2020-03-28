#include <iostream>
#include <algorithm>

using namespace std;

int main (void) {
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int n, a[100000];
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a+n);
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i-1]) cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}