#include <iostream>
#include <string>

using namespace std;

void reverseStr (string &s, int start, int k) {
    for (int i = 0; i < k/2; i++) {
        const char tmp = s[start+i];
        s[start+i] = s[start+k-1-i];
        s[start+k-1-i] = tmp; 
    }
}

int main (void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int n, smallk;
        string s, _s, smallest;
        cin >> n >> s;
        smallest = s;
        smallk = 1;
        for (int k = 1; k <= n; k++) {
            _s = s;
            for (int i = 0; i < (n - k + 1); i++) {
                // cout << "k: " << k << " rev: " << i << '\n';
                reverseStr(_s, i, k);
            }
            cout << _s << '\n';
            if (_s < smallest) {
                smallk = k;
                smallest = _s;
            }
        }
        cout << smallest << '\n' << smallk << '\n';
    }
    return 0;
}