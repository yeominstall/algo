/**
 * swea 7728
 */

#include <iostream>

int checker[10];

void resetChecker (void) {
    for (int i = 0; i < 10; i++) {
        checker[i] = 0;
    }
}

int sumOfChecker (void) {
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += checker[i];
    }
    return sum;
}

void printChecker (void) {
    for (int i = 0; i < 10; i++) {
        std::cout << checker[i] << " ";
    }
    std::cout << "\n";
}

int main (void) {
    std::cin.tie(0); std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        std::string N;
        std::cin >> N;
        resetChecker();
        for (int i = 0; i < N.size(); i++) {
            checker[N.at(i)-'0'] = 1;
            printChecker();
            if (i > 9 && sumOfChecker() == 10) {
                break;
            }
        }
        std::cout << "#" << tc << " " << sumOfChecker() << "\n";
    }

}