#include <iostream>
#include <list>
#include <string>

int main (void) {
    std::string input, command;
    int count;
    std::list<char> buffer;

    // input initial string and number of command
    std::cin >> input;
    std::cin >> count;

    // input each command
    for (int i = 0; i < count; i++) {
        std::getline(std::cin, command);
        std::cout << command << std::endl;
    }

    // print
    return 0;
}