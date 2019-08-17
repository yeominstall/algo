/**
 * boj 2193
 */
#include <iostream>

using namespace std;

int main (void) {
    long N;
    cin >> N;
    long zero_end = 0, one_end = 1, former_zero_end, total = 0;
    for (int i = 1; i < N; i++) {
        former_zero_end = zero_end;
        zero_end += one_end;
        one_end = former_zero_end;
    }
    total = zero_end + one_end;
    cout << total << "\n";
    return 0;
}