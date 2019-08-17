#include <iostream>
#include <vector>
#include <array>

#define RANGE   10000

int main (void) {
    std::array<int, RANGE> counter;
    int quotient, remains;
    // fill numbers in container
    counter.fill(0);

    for (int i = 1; i <= RANGE; i++) {
        quotient = i;
        remains = i; 
        // split i into each numbers & add numbers(make d(n))
        for (int j = RANGE; j >= 1; j = j / 10) {
            quotient += remains / j;
            remains = remains % j;
        }

        // if remains is in RANGE, count it
        if (quotient <= RANGE) {
            // std::cout << quotient << " is not a self-number. (cause " << i << ")\n";
            counter.at(quotient-1) += 1;
        }
    }
    // print remaining self-numbers
    for (int i = 1; i <= RANGE; i++) {
        if (counter.at(i-1) == 0) {
            std::cout << i << "\n";
        }
    }
    return 0;
}