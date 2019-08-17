/**
 * algospot QUADTREE
 */
#include <bits/stdc++.h>

using namespace std;

string flipper (string &s, int idx) {
    int i, cnt = 0;
    for (i = idx; i < s.size; i++) {

    }
}

string decode (string s) {
    stack<char> dcd;
    int p, i, j, cnt = 0;
    for (p = 0; p < s.size(); p++) {
        if (str[p] == 'x') {
            flipper(s, p);
        }
    }
}

int main (void) {
    int T, tc;
    string str;
    for (tc = 0; tc < T; tc++) {
        cin >> str;
        decode (str);
    }
}