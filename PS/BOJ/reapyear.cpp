/**
 * boj 2753
 */

#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int year;
    cin >> year;
    std::cout << (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) ? 1 : 0;;
    return 0;
}