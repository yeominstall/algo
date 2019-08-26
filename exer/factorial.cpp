#include <iostream>

using namespace std;

int fac (int N) {
    int i;
    if (N == 0) return 1;
    for (i = N - 1; i > 0; i--) {
        N *= i;
    }
    return N;
}

int main (void) {
    int N, M;
    cin >> N;
    M = fac (N);
    cout << M << "\n";
    return 0;
}