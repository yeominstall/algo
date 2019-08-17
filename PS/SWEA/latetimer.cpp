/** 
 * swea 7732
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

std::vector<std::string> split (std::string& str, char delimeter) {
    std::istringstream ip(str);
    std::vector<std::string> items;
    std::string s;
    while (std::getline(ip, s, delimeter)) {
        items.push_back(s);
    }
    return items;
}

int timeToInt (std::string s) {
    for (std::string::iterator it = s.begin(); it != s.end(); it++) {
        *it -= '0';
    }
    return (((s[0]*10+s[1])*60 + s[2]*10+s[3])*60 + s[4]*10+s[5]);
}

std::string intToTime (int t) {
    std::stringstream ss;
    int timeval = 0, div = 3600;
    while (div != 0) {
        timeval = t / div;
        t %= div;
        div /= 60;
        ss << std::setw(2) << std::setfill('0') << timeval;
    }

    return ss.str();
}

std::string timeDiff (std::string s, std::string e) {
    int diff;
    diff = timeToInt (e) - timeToInt (s);
    if (diff < 0) {
        diff += timeToInt("240000");
    }
    return intToTime (diff);
}

int main (void) {
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        std::string start, end, diff;
        std::vector<std::string> st, et;
        std::cin >> start >> end;
        start.erase(2, 1); start.erase(4, 1);
        end.erase(2, 1); end.erase(4, 1);
        diff = timeDiff(start, end);
        std::cout << "#" << tc << " ";
        for (int i = 0; i < diff.size(); i++) {
            std::cout << diff.at(i);
            if (i == 1 || i == 3) std::cout << ":";
        }
        std::cout << "\n";
    }
    return 0;
}