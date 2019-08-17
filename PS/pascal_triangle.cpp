/**
 * swea 2005
 */

#include <iostream>
#include <list>
#include <numeric>

std::list<int> pascal_queue;

void pascal_triangle (int l) {
    int tmp = 0, pc;
    if (pascal_queue.empty()) {
        pascal_queue.push_back(1);
    } else {
        for (int i = 0; i < l; i++) {
            pc = pascal_queue.front();
            pascal_queue.push_back(tmp + pc);
            tmp = pc;
            pascal_queue.pop_front();
        }
        pascal_queue.push_back(1);
    }
    for (std::list<int>::iterator it = pascal_queue.begin(); it != pascal_queue.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

int main (void) {
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N;
        std::cin >> N;
        std::cout << "#" << tc << "\n";
        for (int i = 0; i < N; i++) {
            pascal_triangle (i);
        }
        pascal_queue.clear();
    }
    
    return 0;
}