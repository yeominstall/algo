#include <iostream>
#define coef    1000000000

long long int store[101][10] = {0, };

long long int dp (int n, int m) {
    long long int val;
    if (n == 1 && m != 0) {
        val = 1;
    } else if (n > 1) {
        val = 0;
        if (m - 1 >= 0) {
            val += store[n-1][m-1] % coef;
        }
        if (m + 1 < 10) {
            val += store[n-1][m+1] % coef;
        }
    }

    return val;
}

int main (void) {
    int num;
    long long int sum = 0;
    std::cin >> num;

    for (int i = 1; i <= num; i++) {
        for (int j = 0; j < 10; j++) {
            store[i][j] = dp (i, j);
        }
    }

    for (int i = 0; i < 10; i++) {
        sum += store[num][i] % coef;
    }

    std::cout << sum % coef << "\n";

    return 0;
}