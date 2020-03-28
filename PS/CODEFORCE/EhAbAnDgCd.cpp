#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (a == 0) return b;  
    return gcd(b % a, a);
}

int lcm(int a, int b, int g) {
    return ((a * b) / g);
}

int main (void) {
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int x;
        cin >> x;
        for (int i = 1; i <= x/2; i++) {
            int g = gcd(i, x-i);
            int l = lcm(i, x-i, g);
            if (g+l == x) {
                cout << g << ' ' << l << '\n';
                break;
            }
        }
    }
    return 0;
}