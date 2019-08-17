/**
 * swea 1945
 */

#include <iostream>

int s[5];

void clr (void) { for (int i = 0; i < 5; i++) s[i] = 0; }

int main (void) {
    int T;
    int nums[5] = {2, 3, 5, 7, 11};
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N;
        clr();
        std::cin >> N;
        int i = 0;
        while (i != 5) {
            if (N % nums[i] == 0) {
                s[i]++;
                N /= nums[i];
            } else {
                i++;
            }
        }
        std::cout << "#" << tc << " ";
        for (int i = 0; i < 5; i++) { std::cout << s[i] << " "; }
        std::cout << "\n";
    }
    return 0;
}