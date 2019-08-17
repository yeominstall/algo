/** 
 * boj 2941
 */

#include <iostream>

int main (void) {
    std::string str, tmp;
    int count = 0;
    std::cin >> str;
    tmp.clear();
    for (int i = str.size()-1; i > -1 ; i--) {
        if (tmp == "*") {
            tmp.clear();
            if (str.at(i) == 'd') {
                continue;
            }
        }
        if (tmp.empty()) {
            if (str.at(i) == '=' || str.at(i) == '-' || str.at(i) == 'j') {
                tmp = str.at(i);
            } else {
                count++;
            }

        } else { 
            tmp = str.at(i) + tmp;
            if (tmp == "c=" || tmp == "c-" || tmp == "z=" || tmp == "d-" || tmp == "lj" || tmp == "nj" || tmp == "s=") {
                count++;
                if (tmp != "z=") { tmp.clear(); }
                else { tmp = "*"; }
            } else {
                tmp = str.at(i);
                count++;
            }
        }
    }
    if (!tmp.empty()) {
        count++;
    }
    std::cout << count << "\n";

    return 0;
}