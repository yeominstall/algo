/**
 * swea 1926
 */

#include <iostream>

int main (void) {
    int ip, flag = 0;
    std::string clap;
    std::cin >> ip;
    for (int i = 1; i <= ip; i++) {
        std::string num = std::to_string(i);
        for (int j = 0; j < num.size(); j++) {
            if (num.at(j) == '3' || num.at(j) == '6' || num.at(j) == '9') {
                flag = 1;
                clap += "-";
            }
        }
        if (flag == 0) {
            std::cout << num << " ";
        } else {
            std::cout << clap << " ";
        }
        clap.clear();
        flag = 0;
    }
    
    return 0;
}