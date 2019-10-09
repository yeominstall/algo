/**
 * boj 2667
 */

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define __OOB__(x,y)    (x < 0 || x >= N || y < 0 || y >= N)

using namespace std;

class coord {
public:
    int x;
    int y;

    coord (int _x, int _y) : x(_x), y(_y) {}
};

int N;
bool visited[25][25];
int dir[4][2] = {0, -1, 0, 1, -1, 0, 1, 0};
int village[25][25];

void init (void) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }
}

int bfs (coord src) {
    int cnt = 1;
    queue<coord> q;
    q.push(src);
    int pos_x, pos_y, next_x, next_y;
    while (!q.empty()) {
        pos_x = q.front().x;
        pos_y = q.front().y;
        q.pop();
        for (int i = 0; i < 4; i++) {
            next_x = pos_x + dir[i][0];
            next_y = pos_y + dir[i][1];
            if (!__OOB__(next_x, next_y) && (village[next_y][next_x] == 1) && !visited[next_y][next_x]) {
                visited[next_y][next_x] = true;
                q.push(coord(next_x, next_y));
                cnt++;
            }
        }
    }
    return cnt;
}

int main (void) {
    cin >> N;
    vector<int> vills;
    init();
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++) {
            village[i][j] = (s[j] - '0');
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (village[i][j] == 1 && !visited[i][j]) {
                visited[i][j] = true;
                int t = bfs (coord(j, i));
                vills.push_back(t);
            }
        }
    }
    sort (vills.begin(), vills.end());
    cout << vills.size() << "\n";
    auto print = [](const int &n) { cout << n << "\n"; };
    for_each (vills.begin(), vills.end(), print);
    return 0;
}