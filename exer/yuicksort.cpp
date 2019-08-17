#include <iostream>
#include <array>

std::array<int, 10> numbers = {6, 2, 9, 8, 3, 4, 7, 5};

int main (void) {
    int pivot, i, j, tmp, input;
    j = 0;
    pivot = 0;
    for (i = j + 1; i < numbers.size(); i++) {
        if (numbers.at(pivot) > numbers.at(i)) {
            ++j;
            std::swap(numbers.at(i), numbers.at(j));
        }
    }
    std::swap(numbers.at(j), numbers.at(pivot));

    // print
    for (auto it = 0; it != numbers.size(); it++) {
        std::cout << numbers.at(it) << " ";
    }
    std::cout << "\n";

    return 0;
}