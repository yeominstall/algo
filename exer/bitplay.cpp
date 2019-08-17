#include <limits>
#include <iostream>

int main (void) {
    int i = (1 << 31);
    long ll = (long)0x80000000 -1;
    std::cout << (long)i-1 << "\n";
    std::cout << ll << "\n";
    return 0;
}