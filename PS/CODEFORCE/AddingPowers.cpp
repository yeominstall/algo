#include <iostream>
#include <cstring>

using namespace std;

int n, k;
unsigned long a[30];

bool isAllZero(void) {
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            return false;
        }
    }
    return true;
}

void printA (void) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

int main (void) {
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        bool ans = true, one = false;
        cin >> n >> k;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % k != 0) {
                if ((a[i] == 1 || (a[i] - 1) % k == 0) && !one) {
                    one = true;
                    a[i] = 0;
                } else {
                    #ifdef DBG
                    cout << "invalid element\n";
                    #endif
                    ans = false;
                }
            }
        }
        unsigned long div = k;
        while (ans && !isAllZero()) {
            bool dup = false;
            #ifdef DBG
            cout << "current div: " << div << '\n';
            #endif
            for (int i = 0; i < n; i++) {
                if (a[i] == 0) continue;
                if (a[i] % div != 0) {
                    ans = false;
                    break;
                }
                unsigned long quot = a[i] / div;
                if (quot % k != 0) {
                    if (!dup) {
                        a[i] -= div;
                        dup = true;
                    } else {
                    #ifdef DBG
                        cout << "duplicated\n";
                    #endif
                        ans = false;
                        break;
                    }
                } else if (a[i] < div) {          // maybe this condition doesn't need to be
                #ifdef DBG
                    cout << a[i] << ' ' << div << " possible?\n";
                #endif
                    ans = false;
                    break;
                }
            }
            #ifdef DBG
            printA();
            #endif
            div *= k;
        }
        if (!ans) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}