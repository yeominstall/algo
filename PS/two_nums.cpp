#include <iostream>
#include <vector>

int compareNums (std::vector<int> little, std::vector<int> big, int offset) {
    int result = 0;
    for (int i = 0; i < little.size(); i++) {
        result += little.at(i) * big.at(i + offset);
    }
    return result;
}

int main (void) {
    int T, N, M, sum, res;
    std::vector<int> A, B;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        std::cin >> N >> M;
        for (int i = 0; i < N; i++) {
            std::cin >> res;
            A.push_back(res);
        }
        for (int i = 0; i < M; i++) {
            std::cin >> res;
            B.push_back(res);
        }
        res = -1;
        if (N < M) {
            for (int i = 0; i <= M - N; i++) {
                sum = compareNums(A, B, i);
                res = (res < sum) ? sum : res;
            }
        } else {
            for (int i = 0; i <= N - M; i++) {
                sum = compareNums(B, A, i);
                res = (res < sum) ? sum : res;
            }
        }
        std::cout << "#" << tc << " " << res << "\n";
        A.clear(); B.clear();
    }

    return 0;
}