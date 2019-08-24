#include <iostream>
#include <cstring>

using namespace std;

int main (void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T, tc, i, j, tsize, ip, a, b;
    int cache[2][100];
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        memset(cache, 0, sizeof(cache));
        cin >> tsize >> cache[0][0];
        for (i = 1; i < tsize; i++) {
            for (j = 0; j <= i; j++) {
                a = -1;
                cin >> ip;
                if (j-1 >= 0) {
                    a = cache[(i-1)%2][j-1] + ip;
                }
                b = cache[(i-1)%2][j] + ip;
                cache[i%2][j] = max(a, b);
                #ifdef PPRINT
                cout << cache[i%2][j] << " ";
                #endif
            }
            #ifdef PPRINT
            cout << "\n";
            #endif
        }
        a = -1;
        b = (tsize - 1) % 2;
        for (i = 0; i < tsize; i++) {
            a = max(a, cache[b][i]);
        }
        cout << a << "\n";
    }
    return 0;
}