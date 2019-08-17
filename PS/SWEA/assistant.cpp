/** 
 * swea 1983
 */

#include <iostream>
#include <map>

int main (void) {
    int T;
    char* grade[10] = {"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"};
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, K;
        char* res;
        std::map<double, int, std::greater<double>> total;
        std::cin >> N >> K;
        for (int st = 1; st <= N; st++) {
            int mid, fin, hw;
            std::cin >> mid >> fin >> hw;
            total.insert(std::pair<double, int>((mid * 0.35f + fin * 0.45f + hw * 0.2f), st));
        }
        int rank = 0;
        for (std::map<double, int>::iterator it = total.begin(); it != total.end(); it++) {
            if (it->second == K) {
                res = grade[rank*10/N];
                break;
            }
            rank++;
        }
        std::cout << "#" << tc << " " << res << "\n";
    }
    
    return 0;
}