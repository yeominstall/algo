/**
 * boj 1065
 */

#include <iostream>

int main (void) {
    int input, result;
    char buf[5];

    std::cin >> input;

    if (input < 100) {
        result = input;
    } else {
        result = 99;
        for (int i = 100; i <= input; i++) {
            sprintf(buf, "%d", i);
            if (buf[0] - buf[1] == buf[1] - buf[2]) {
                result++;
            }
        }
    }

    std::cout << result << "\n";
    return 0;
}