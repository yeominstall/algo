/**
 * swea 1928
 */

#include <iostream>

int dcdToInt (char c) {
    if (c >= 'A' && c <= 'Z') {
        return (c - 'A');
    } else if (c >= 'a' && c <= 'z') {
        return (c - 'a' + 26);
    } else if (c >= '0' && c <= '9') {
        return (c - '0' + 52);
    } else if (c == '+') {
        return 62;
    } else if (c == '/') {
        return 63;
    }
}

int main (void) {
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        std::string dcd;
        int store = 0;
        std::cin >> dcd;
        std::cout << "#" << tc << " ";
        for (int i = 0; i < dcd.size(); i++) {
            store |= 63&dcdToInt(dcd.at(i));
            if (i%4 != 3) {
                store <<= 6;
            } else {
                std::cout << (char)((store&0xFF0000)>>16) << (char)((store&0xFF00)>>8) << (char)(store&0xFF);
                store = 0;
            }
        }
        std::cout << "\n";
    }
    return 0;
}