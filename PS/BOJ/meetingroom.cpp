/**
 * boj 1931
 */
#include <iostream>
#include <map>

class meeting {
public:
    int start_time;
    int end_time;

    meeting(int x, int y) : start_time(x), end_time(y) {}

    bool operator<(const meeting &right) const {
        if (end_time == right.end_time) {
            return start_time < right.start_time;
        } else {
            return end_time < right.end_time;
        }
    }

    bool operator==(const meeting &right) const {
        return (!(start_time < right.start_time) && !(start_time > right.start_time)) && (!(end_time < right.end_time) && !(end_time > right.end_time));
    }
};

int main (void) {
    int n, st, et, count = 0, pc = -1;
    std::multimap<meeting, int, std::less<meeting>> req;
    std::multimap<meeting, int, std::less<meeting>>::iterator it;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> st >> et;
        req.insert({meeting(st, et), et-st});

    }

    //start from pc
    for (it = req.begin(); it != req.end(); it++) {
        if ((*it).first.start_time >= pc) {
            pc = (*it).first.end_time;
            count++;
        }
    }

    std::cout << count << "\n";
    
    return 0;
}