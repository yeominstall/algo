#include <bits/stdc++.h>

bool regexChecker (std::string pat, std::string str) {
    std::string::iterator pit, it;
    bool isWildcard = false;
    it = str.begin();
    for (pit = pat.begin(); pit != pat.end(); pit++) {
        if (*pit == '*') {
            isWildcard = true;
            continue;
        }
        for ( ; it != str.end(); ) {
#ifdef PPRINT
            std::cout << *pit << " " << *it << "\n";
#endif
            if (isWildcard) {
                it = std::find(it, str.end(), *pit);
                if (it == str.end()) return false;
                isWildcard = false;
                it++;
            } else {
                if (*pit != *it && *pit != '?') return false;
                it++;
            }
            break;
        }
    }
    return true;
}

int main (void) {
    int tc, T, n, i;
    std::string pattern, str;
    std::cin >> T;
    for (tc = 1; tc <= T; tc++) {
        std::cin >> pattern >> n;
        for (i = 0; i < n; i++) {
            std::cin >> str;
            if (regexChecker(pattern, str)) {
                std::cout << str << "\n";
            }
        }
    }
    return 0;
}