#include <iostream>
#include <cstring>

using namespace std;

double getAvrg (const int a[], const int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return (double)sum / n;
}

int main (void) {
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int n, m, a[1000], total = 0;
        cin >> n >> m;
        for (int j = 0; j < n; j++) {
            cin >> a[j];
            total += a[j];
        }
        if (total >= m) cout << m << '\n';
        else cout << total << '\n';
    }
    return 0;
}