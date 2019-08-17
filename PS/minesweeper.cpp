#include <iostream>
#include <stack>

char panel[300][300];
int visited[300][300];
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int N;

void clearPanel (void) {
    for (int i = 0; i < 300; i++) {
        for (int j = 0; j < 300; j++) {
            panel[i][j] = '-';
            visited[i][j] = 0;
        }
    }
}

void printPanel (int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << panel[i][j];
        }
        std::cout << "\n";
    }
}

bool inBound (int x, int y) {
    return (x < N && x >= 0 && y < N && y >= 0) ? true : false;
}

char sweeping (int x, int y) {
    int mine = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (inBound (x+dx[j], y+dy[i]) && panel[y+dy[i]][x+dx[j]] == '*') {
                mine++;
            }
        }
    }
    return mine + '0';
}

void dfs (int x, int y) {
    std::stack<std::pair<int, int>> tmp;
    tmp.push({x, y});
    while (!tmp.empty()) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (inBound (tmp.top().first+dx[j], tmp.top().second+dy[i]) 
                    && (panel[tmp.top().second+dy[i]][tmp.top().first+dx[j]] != '*' && panel[tmp.top().second+dy[i]][tmp.top().first+dx[j]] != '-')) {
                    
                }
            }
        }
    }
}

int main (void) {
    std::cin.tie(0); std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, cnt = 0;
        char ip;
        std::cin >> N;
        clearPanel();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cin >> ip;
                panel[i][j] = ip;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (panel[i][j] != '*') {
                    panel[i][j] = sweeping (j, i);
                    cnt++;
                }
            }
        }
        std::cout << "#" << tc << " " << cnt << "\n";
        
    }

    return 0;
}