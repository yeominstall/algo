#include <iostream>

using namespace std;

int main (void) {
    cout.tie(0); ios_base::sync_with_stdio(0);
    int N, i, j, core, a;
    cin >> N;
    core = N * 2 - 1;
    for (i = 1-N; i < N; i++) {
        a = N-1 - abs(i);
        for (j = 0; j < core-a; j++) {
            if (j < a) cout << " ";
            else cout << "*";
        }
        cout << "\n";
    }
    return 0;
}