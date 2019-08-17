/**
 * boj 1436
 */

#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int i = 665, cnt = 0, N;
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    std::cin >> N;
    while (cnt != N) {
        ++i;
        string sn = to_string(i);
        if (sn.find("666") != string::npos) {
            cnt++;
        }
    }
    std::cout << i << "\n";
}