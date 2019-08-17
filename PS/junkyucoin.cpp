#include <iostream>
#include <vector>

int main (void) {
    int N, K, input, count = 0, loop = 0;
    std::vector<int> coin_value;
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    // input
    std::cin >> N >> K;
    while (std::cin >> input) {
        coin_value.push_back(input);
        loop++;
        if (loop == N) break;
    }

    // calc
    for (auto it = coin_value.rbegin(); it != coin_value.rend() || K != 0; it++) {
        if (K >= (*it)) {
            count += K / (*it);
            K = K % (*it);
        }
    }

    // print
    std::cout << count << "\n";

    return 0;
}