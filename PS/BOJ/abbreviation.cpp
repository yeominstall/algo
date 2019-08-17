/**
 * boj 2902
 */

#include <iostream>
#include <string>

int main (void) {
    std::string str;
    std::cin >> str;
    for (std::string::iterator it = str.begin(); it != str.end(); it++) {
        if (*it >= 65 && *it <= 90) {
            std::cout << (*it);
        }
    }
    std::cout << "\n";
    
    return 0;
}