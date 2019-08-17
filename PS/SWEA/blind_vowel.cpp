/**
 * swea 4406
 */
#include <bits/stdc++.h>

using namespace std;

void printConso (string str) {
    int i;
    for (i = 0; i < str.size(); i++) {
        if (!(str.at(i) == 'a' || str.at(i) == 'e' || str.at(i) == 'i' || str.at(i) == 'o' || str.at(i) == 'u')) {
            cout << str.at(i);
        }
    }
    cout << "\n";
}

int main (void) {
    int T, tc;
    cin >> T;
    string origin;
    for (tc = 1; tc <= T; tc++) {
        cin >> origin;
        cout << "#" << tc << " ";
        printConso (origin);
    }
    return 0;
}