/**
 * swea 2007
 */

#include <iostream>

int main (void) {
    int T, count;
    std::string str;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        count = 0;
        std::cin >> str;
        for (int i = 10; i > 1; i--) {
            for (int j = 0; j < i; j++) {
                if (str[j] != str[j+i]) {
                    break;
                }
                if (j == i-1) {
                    count = i;
                    break;
                }
            }
        }

        std::cout << "#" << tc << " " << count << "\n";
    }
    
    return 0;
}