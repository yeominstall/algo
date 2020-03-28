/**
 * Codeforce #624 - A. Add Odd or Subtract Even
 */
#include <iostream>

using namespace std;

int main (void) {
    int T, a, b;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> a >> b;
        int i = 0, diff;
        while (a != b) {
            ++i;
            diff = b - a;
            a += diff;
            // a is bigger
            if ((diff < 0 && -diff % 2 != 0) || (diff > 0 && diff % 2 == 0)) {
                a--;
            }
        }
        cout << i << '\n';
    }
    return 0;
}