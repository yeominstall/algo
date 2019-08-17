/**
 * swea 5356
 */
#include <iostream>
#define LEN 16

using namespace std;

char strs[5][LEN];

void clearText (void) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < LEN; j++) {
            strs[i][j] = '\0';
        }
    }
}

int main (void) {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    cin.ignore(2, '\n');
    for (int tc = 1; tc <= T; tc++) {
        int maxlength = -1;
        clearText();
        for (int i = 0; i < 5; i++) {
            cin.getline (strs[i], LEN);
            int len = 0;
            for (int j = 0; j < LEN; j++) {
                if (strs[i][j] == '\0') {
                    break;
                }
                len++;
            }
            maxlength = (maxlength < len) ? len : maxlength;
        }

        cout << "#" << tc << " ";
        for (int i = 0; i < maxlength; i++) {
            for (int j = 0; j < 5; j++) {
                if (strs[j][i] != '\0') {
                    cout << strs[j][i];
                }
            }
        }
        cout << "\n";
    }
    return 0;
}