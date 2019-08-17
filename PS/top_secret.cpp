#include <iostream>
#include <string>

int main (void) {
    std::string str;
    while (std::getline(std::cin, str)) {
        if (str.compare("END") == 0) {
            break;
        }
        for (std::string::reverse_iterator rit = str.rbegin(); rit != str.rend(); rit++) {
            std::cout << *rit;
        }
        std::cout << "\n";
    }
    
    return 0;
}