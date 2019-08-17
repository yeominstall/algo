/**
 * swea 1284
 */

#include <iostream>
 
int P, Q, R, S;
 
int calcA (int W) {
    return W * P;
}
 
int calcB (int W) {
    int ch = Q;
    if (W > R) {
        ch += (W - R) * S;
    }
    return ch;
}
 
int main (void) {
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int W, charge, a, b;
        std::cin >> P >> Q >> R >> S >> W;
        a = calcA (W);
        b = calcB (W);
        charge = (a > b) ? b : a;
        std::cout << "#" << tc << " " << charge << "\n";
    }
}