#include <iostream>

using namespace std;

int main (void) {
    int T, a, b;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> a >> b;
        if (a % b == 0) { cout << 0 << '\n'; continue; }
        cout << b - (a % b) << '\n';
    }
    return 0;
}