#include <iostream>
#include <string>
#define MAX(a,b)    (a > b) ? a : b;

using namespace std;

int cnt[26];

int main (void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
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
    for (i = 0; i < 26; i++) {
        if (mcnt == cnt[i] && i != m) {
            cout << "?\n";
            return 0;
        }
    }
    cout << (char)(m+'A') << "\n";
    return 0;
}