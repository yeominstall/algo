#include <iostream>
#include <list>
#include <iterator>

int powForTwo(int n) {
    int result = 1;
    for (int i = 0; i < n; i++) {
        result *= 2;
    }
    return result;
}

int main (void) {
    int N, S, ip, on, off, pool_size, count = 0, rt;
    std::list<int> input;
    std::list<int> numbers;
    std::list<int>::iterator it;
    std::list<int>::iterator num_it;

    std::cin >> N >> S;
    for (int i = 0; i < N; i++) {
        std::cin >> ip;
        input.push_back(ip);
    }
    for (it = input.begin(); it != input.end(); it++) {
        on = *it;
        off = 0;
        if (numbers.empty()) {
            numbers.push_back(on);
            numbers.push_back(off);
        } else {
            pool_size = numbers.size();
            for (int i = 0; i < pool_size; i++) {
                rt = numbers.front();
                numbers.push_back(rt + on);
                numbers.push_back(rt + off);
                numbers.pop_front();
            }
        }
    }
    // remove empty set
    numbers.pop_back();
    for (num_it = numbers.begin(); num_it != numbers.end(); num_it++) {
        if (*num_it == S) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}