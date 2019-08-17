#include <iostream>
#include <random>
using namespace std;

int main (void) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> cnt(0, 1);
    string tmp = cnt(gen) == 0 ? "Korea" : "Yonsei";
    cout << tmp << "\n";
}