/**
 * swea 7675
 */

#include <iostream>
#include <vector>

bool upper (char c) {
    return (c >= 'A' && c <= 'Z') ? true : false;
}

int main (void) {
    std::cin.tie(0); std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);

    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, names = 0, tmp;
        char es[3] = {'.', '?', '!'};
        std::string s;
        std::cin >> N;
        std::cin.ignore(2, '\n');
        std::getline(std::cin, s);

        std::cout << "#" << tc << " ";
        bool isName = false;
        for (int i = 0; i < s.size(); i++) {
            if (isName && s.at(i) == ' ') {
                ++names; 
                isName = false;
            } else if (isName^upper(s.at(i)) && !(s.at(i) >= '0' && s.at(i) <= '9')) {
                isName = true;
            } else {
                isName = false;
            }
            if (s.at(i) == es[0] || s.at(i) == es[1] || s.at(i) == es[2]) {
                if (isName) ++names;
                std::cout << names << " ";
                names = 0;
                isName = false;
            }
        }
        std::cout << "\n";
    }
    return 0;
}