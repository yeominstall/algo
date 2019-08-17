#include <iostream>
#include <array>

int main (void) {
    std::string S;
    std::array<int, 26> count;
    count.fill(0);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> S;

    for (int i = 0; i < S.size(); i++) {
        count[S[i] - 97]++;
    }
    for (int i = 0; i < 26; i++) {
        std::cout << count[i];
        if (i != 25) {
            std::cout << " ";
        }
    }
    return 0;
}