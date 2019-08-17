/**
 * swea 1859
 */

#include <iostream>

int pred[1000000];

long long int getPay (int from, int payday) {
    long long int invest = 0;
    for (int i = from; i < payday; i++) {
        invest += pred[i];
    }
    return (pred[payday] * (payday - from)) - invest;
}

void clearPred (void) {
    for (int i = 0; i < 1000000; i++) {
        pred[i] = 0;
    }
}

int main (void) {
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, m, max = -1; 
        long long int payday, profit = 0;
        clearPred();
        std::cin >> N;
        for (int i = 0; i < N; i++) {
            std::cin >> m;
            pred[i] = m;
        }
        
        int today = 0;
        while (today < N) {
            for (int i = today; i < N; i++) {
                if (max < pred[i]) {
                    max = pred[i];
                    payday = i;
                }
            }
            profit += getPay(today, payday);
            today = payday + 1;
            max = -1;
        }
        std::cout << "#" << tc << " " << profit << "\n";
    }
    
    return 0;
}