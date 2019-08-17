#include <iostream>
#include <stack>
int w = -1, h = -1;
int world[50][50] = {0, };
std::stack<std::pair<int, int>> visited;
int px[8] = {-1, 0, 1, -1, 1, -1, 0, 1};    // pointer_x
int py[8] = {-1, -1, -1, 0, 0, 1, 1, 1};    // pointer_y

void clearWorld (void) {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            world[i][j] = 0;
        }
    }
}

void dfs (int pos_x, int pos_y) {
    for (int s = 0; s < 8; s++) {
        int sx = pos_x+px[s];
        int sy = pos_y+py[s];
        if (sy >= 0 && sy < h && sx >= 0 && sx < w && world[sy][sx] == 1) {
            visited.push({sx, sy});
            world[sy][sx] = 0;
            return;
        }
    }
    visited.pop();
}

int main (void) {
    int tmp, count = 0;
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    while (std::cin >> w >> h && (w != 0 || h != 0)) {
        clearWorld();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                std::cin >> tmp;
                world[i][j] = tmp;
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (world[i][j] == 1) {
                    visited.push({j, i});
                    world[i][j] = 0;
                    while (!visited.empty()) {
                        dfs(visited.top().first, visited.top().second);
                    }
                    count++;
                }
            }
        }
        std::cout << count << "\n";
        count = 0;
    }
    return 0;
}