/**
 * swea 3809
 */
#include <iostream>

using namespace std;

int main (void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T, tc, N, i;
    string s; char ip;
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        s.clear();
        cin >> N;
        for (i = 0; i < N; i++) {
            cin >> ip;
            s += ip;
        }
        for (i = 0; i < 1000; i++) {
            if (s.find(to_string(i)) == string::npos) {
                cout << "#" << tc << " " << i << "\n";
                break;
            }
        }
    }
    return 0;
}