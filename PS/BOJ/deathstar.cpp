/** 
 * boj 11811
 */

#include <iostream>

int nums[1000];

int main (void) {
    int N, ip;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> ip;
            nums[i] |= ip;
            nums[j] |= ip;
        }
    }
    for (int i = 0; i < N; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << "\n";
    return 0;
}