/**
 * boj 1157
 */

#include <iostream>
#include <string>

using namespace std;

int cnt[26];

void printChecker (void) {
    for (int i = 0; i < 26; i++) {
        cout << cnt[i] << " ";
    }
    cout << "\n";
}

int main (void) {
    freopen("input.txt", "r", stdin);
    int i, mcnt = -1, m, n;
    string str;
    cin >> str;
    for (i = 0; i < str.size(); i++) {
        if (str[i] >= 'a') n = str[i] - 'a';
        else if (str[i] >= 'A') n = str[i] - 'A';
        ++cnt[n];
        if (cnt[n] > mcnt) {
            mcnt = cnt[n];
            m = n;
        }
    }
    printChecker();
    for (i = 0; i < 26; i++) {
        if (mcnt == cnt[i] && i != m) {
            cout << "?\n";
            return 0;
        }
    }
    cout << (char)(m+'A') << "\n";
    return 0;
}
