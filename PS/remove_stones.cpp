#include <iostream>

int main (void) {
    // n is size of field, k is number of stones
    int n, k;
    int stones_pos[][2] = {0, };
    std::cin.tie(NULL);
    std::cin >> n >> k;
    for (int i = 0; i < k; i++) {
        std::cin >> stones_pos[i][0] >> stones_pos[i][1];
    }

    // GG
    return 0;
}