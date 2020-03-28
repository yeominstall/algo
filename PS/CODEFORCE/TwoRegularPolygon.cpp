#include <iostream>

using namespace std;

int main (void) {
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int n, m;
        cin >> n >> m;
        if (n % m == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}