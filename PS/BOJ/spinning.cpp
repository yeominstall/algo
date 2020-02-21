/**
 * boj 17822
 */
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <utility>

#define __OOB__(y,x)    (x < 0 || x >= M || y < 0 || y >= N)
#define CLOCKWISE   0
#define COUNTERCW   1

using namespace std;

int N, M, T, sum;
int disk[50][50];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void printDisk (void) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            cout << disk[i][j] << ' ';
        }
        cout << '\n';
    }
}

int getRestOf (void) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            sum += disk[i][j];
        }
    }
    return sum;
}

double getAverage () {
    double sum = 0, cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (disk[i][j] != 0) {
                sum += disk[i][j];
                cnt++;
            }
        }
    }
    return sum / cnt;
}

void match (vector<pair<int, int> > &pang) {
    vector<pair<int, int> >::iterator it;
    int px, py;
    for (it = pang.begin(); it != pang.end(); it++) {
        py = it->first;
        px = it->second;
        disk[py][px] = 0;
    }
}

void retrieve (void) {
    vector<pair<int, int> > local;
    queue<pair<int, int> > q;
    bool visited[50][50];
    int i, j, base = 0;
    memset(visited, 0, sizeof(visited));

    int cx, cy, nx, ny;
    int before = getRestOf();
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (disk[i][j] != 0 && !visited[i][j]) {
                base = disk[i][j];
                visited[i][j] = true;
                local.push_back(make_pair(i, j));
                q.push(make_pair(i, j));
                while (!q.empty()) {
                    cx = q.front().second;
                    cy = q.front().first;
                    q.pop();
                    for (int d = 0; d < 4; d++) {
                        nx = (M + cx + dx[d]) % M;
                        ny = cy + dy[d];
                        if (__OOB__(ny, nx) || visited[ny][nx] || disk[ny][nx] != base) continue;
                        local.push_back(make_pair(ny, nx));
                        q.push(make_pair(ny, nx));
                        visited[ny][nx] = true;
                    }
                }
                if (local.size() > 1)
                    match(local);
                local.clear();
            }
        }
    }
    int after = getRestOf();
    if (before == after) {
        double avr = getAverage();
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                int &curr = disk[i][j];
                if (curr == 0) continue;
                if (curr > avr) --curr;
                else if (curr < avr) ++curr;
            }
        }
    }
}

void spin (int x, int d, int k) {
    int tmp[50], offset;
    if (d == CLOCKWISE) k = -k;
    for (int i = 0; i < N; i++) {
        if ((i+1) % x == 0) {
            // memset(tmp, 0, sizeof(tmp));
            for (int j = 0; j < M; j++) {
                offset = (M + k + j) % M;
                tmp[j] = disk[i][offset];
            }
            memcpy(&disk[i], tmp, sizeof(int)*M);
        }
    }
}

int main (void) {
    int res = 0, x, d, k;
    cin >> N >> M >> T;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> disk[i][j];
        }
    }

    for (int l = 0; l < T; l++) {
        cin >> x >> d >> k;
        spin(x, d, k);
        retrieve();
    }
    res = getRestOf();
    cout << res << '\n';
    // printDisk();
    return 0;
}