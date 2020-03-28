/**
 * Codeforce #624 - B. WeirdSort
 */
#include <iostream>
#include <cstring>

using namespace std;

int a[100], b[100], p[100];
int n, m;

void printA (void) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

bool isSorted () {
    int prev = a[0];
    for (int i = 1; i < n; i++) {
        if (prev > a[i]) return false;
        prev = a[i];
    }
    return true;
}

bool isSame () {
    for (int i = 0; i < n; i++) {
        if(a[i] != b[i]) return false;
    }
    return true;
}

bool doSort () {
    while (!isSorted()) {
        // printA();
        memcpy(b, a, sizeof(a));
        for (int i = 0; i < m; i++) {
            int src = p[i] - 1;
            int dest = p[i];
            if (a[src] > a[dest]) {
                int tmp = a[src];
                a[src] = a[dest];
                a[dest] = tmp;
            }
        }
        if (isSame()) return false;
    }
    return true;
}

int main (void) {
    int T;
    bool res;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> n >> m;
        memset(a, 0, sizeof(a));
        memset(p, 0, sizeof(p));
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int j = 0; j < m; j++) {
            cin >> p[j];
        }
        res = doSort();
        if (res) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}