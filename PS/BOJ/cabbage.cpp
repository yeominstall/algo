/**
 * boj 1012
 */

#include <iostream>
#include <stack>

int T, N, M, K;
int land[50][50];
std::stack<std::pair<int, int>> visitor;

void clearLand(void) {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            land[i][j] = 0;
        }
    }
}

void dfs (int px, int py) {
    if (py - 1 >= 0 && land[py-1][px] == 1) {
        visitor.push({px, py-1});
        land[py-1][px] = 0;
        return; 
    } else if (px + 1 < N && land[py][px+1] == 1) {
        visitor.push({px+1, py});
        land[py][px+1] = 0;        
        return;
    } else if (py + 1 < M && land[py+1][px] == 1) {
        visitor.push({px, py+1});
        land[py+1][px] = 0;        
        return;
    } else if (px - 1 >= 0 && land[py][px-1] == 1) {
        visitor.push({px-1, py});
        land[py][px-1] = 0;        
        return;
    } else {
        visitor.pop();
        return;
    }
}

int main (void) {
    int pos_x, pos_y;
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    std::cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int count = 0;
        std::cin >> N >> M >> K;
        clearLand();
        for (int c = 0; c < K; c++) {
            std::cin >> pos_x >> pos_y;
            land[pos_y][pos_x] = 1;
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (land[i][j] == 1) {
                    visitor.push({j, i});
                    land[i][j] = 0;
                    while (!visitor.empty()) {
                        dfs(visitor.top().first, visitor.top().second);
                    }
                    count++;
                }
            }
        }
        std::cout << count << "\n";
    }

    return 0;
}