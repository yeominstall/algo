#include <iostream>
#include <string>

using namespace std;

int main (void) {
    int n, cost = -1;
    string s;
    cin >> n >> s;
    if (n % 2 == 0) {
        int opening = 0, closing = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                ++opening;
            } else {
                ++closing;
            }
        }
        if (opening == closing) {
            // make sentence correct
            int unfair;
            bool inside;
            if (s[0] == '(') {
                unfair = -1;
                inside = true;
                cost = 0;
            } else {
                unfair = 1;
                inside = false;
                cost = 1;
            }
            
            for (int i = 1; i < n; i++) {
                cout << unfair;
                if (unfair > 0) {
                    cost++;
                }
                if (s[i] == '(') {
                    unfair--;
                } else {
                    unfair++;
                }
            }
        }
    }
    cout << '\n' << cost << '\n';
    
    return 0;
}