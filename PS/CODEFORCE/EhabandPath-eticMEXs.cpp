#include <iostream>

using namespace std;

int main (void) {
    unsigned long int u, v;
    cin >> u >> v;
    if (u == v) {
        cout << 2 << '\n' << "0 " << v << '\n';
        return 0;
    } else if (u > v) {
        cout << -1 << '\n';
    }
    int w = u;

    return 0;
}