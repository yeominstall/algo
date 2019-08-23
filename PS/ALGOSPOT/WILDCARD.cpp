#include <iostream>
#include <vector>
#include <algorithm>

bool regexChecker (std::string pat, std::string str) {
    std::string::iterator pit, it;
    std::string::size_type spos;
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
                // it = std::find(it, str.end(), *pit);
                spos = str.rfind(*it);
                if (spos == std::string::npos) return false;
                isWildcard = false;
                it++;
            } else {
                if (*pit != *it && *pit != '?') return false;
                it++;
            }
            break;
        }
    }
    if (!isWildcard && it != str.end()) return false;
    return true;
}

int main (void) {
    int tc, T, n, i;
    std::string pattern, str;
    std::vector<std::string> fns;
    std::vector<std::string>::iterator fit;
    std::cin >> T;
    for (tc = 1; tc <= T; tc++) {
        std::cin >> pattern >> n;
        for (i = 0; i < n; i++) {
            std::cin >> str;
            if (regexChecker(pattern, str)) {
                fns.push_back(str);
            }
        }
        std::sort (fns.begin(), fns.end());
        for (fit = fns.begin(); fit != fns.end(); fit++) {
            std::cout << *fit << "\n";
        }
        fns.clear();
    }
    return 0;
}