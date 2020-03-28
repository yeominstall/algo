#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main (void) {
    int T;
    cin >> T;
    unsigned long layer[100001];
    for (int i = 0; i < 100001; i++) {
        layer[i] = ((unsigned long)i * (i + 1))/2;
    }
    for (int tc = 0; tc < T; tc++) {
        int n, k;
        cin >> n >> k;
        int one = 0, another = 0;
        for (int i = 1; i <= n; i++) {
            if (layer[i] >= k) {
                one = n - i - 1;
                another = one + (layer[i] - k + 1);
                break;
            }
        }
        #ifdef DBG
        cout << one << ' ' << another << '\n';
        #endif
        for (int i = 0; i < n; i++) {
            if (i == one || i == another) {
                cout << 'b';
            } else {
                cout << 'a';
            }
        }
        cout << '\n';
    }
    return 0;
}