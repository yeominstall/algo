#include <bits/stdc++.h>
#define __OOB__(x,y)    (x < 0 || x >= M || y < 0 || y >= N)
#define MAX(a,b)        (a > b) ? a : b

using namespace std;

int N, M;
int lab[8][8];
int cmb[64];
bool visited[8][8];
int dir[4][2] = {0, -1, 0, 1, -1, 0, 1, 0};
int empt;

class coord {
public:
    int x;
    int y;

    coord (int _x, int _y) : x(_x), y(_y) {}

    coord (int key) {
        x = key % M;
        y = key / M;
    }

    bool operator== (coord &rhs) {
        return (x == rhs.x && y == rhs.y);
    }
};

vector<coord> nwall;
vector<coord> virus;

bool isWall (coord p) {
    if (lab[p.y][p.x] == 1) return true;
    else {
        for (vector<coord>::iterator it = nwall.begin(); it != nwall.end(); it++) {
            if ((*it) == p) return true;
        }
        return false;
    }
}

bool isSpace (coord p) {
    if (lab[p.y][p.x] == 0) return true;
    else return false;
}

bool isSetWall (void) {
    int i;
    nwall.clear();
    for (i = 0; nwall.size() < 3; i++) {
        if (i > empt || (cmb[i] == 1 && !isSpace(coord(i)))) return false;
        else if (cmb[i] == 1 && isSpace(coord(i))) {
            nwall.push_back(coord(i));
        }
    }
    return true;
}

void resetVisited (void) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            visited[i][j] = false;
        }
    }
}

void spreading (void) {
    int d, cx, cy, dx, dy;
    queue<coord> vst;
    resetVisited();
    for (vector<coord>::iterator it = virus.begin(); it != virus.end(); it++) {
        cx = (*it).x;
        cy = (*it).y;
        if (!visited[cy][cx]) {
            visited[cy][cx] = true;
            vst.push((*it));
        }
        while (!vst.empty()) {
            for (d = 0; d < 4; d++) {
                dx = dir[d][0] + cx;
                dy = dir[d][1] + cy;
                if (__OOB__(dx, dy) || visited[dy][dx] || isWall(coord(dx, dy))) continue;
                else {
                    visited[dy][dx] = true;
                    vst.push(coord(dx, dy));
                }
            }
            vst.pop();
        }
    }
}

int getSafeArea (void) {
    int cnt = 0, i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (!visited[i][j] && !isWall(coord(j, i))) cnt++;
        }
    }
    return cnt;
}

void printVisited (void) {
    int i, j;
    cout << "==================\n";
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}

void setCmb (int empt) {
    int i;
    for (i = 0; i < empt; i++) {
        if (i < empt-3) cmb[i] = 0;
        else cmb[i] = 1;
    }
}

int main (void) {
    int i, j;
    int saf, max_saf = -1;
    cin >> N >> M;
    empt = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 0) empt++;
            else if (lab[i][j] == 2) virus.push_back(coord(j, i));
        }
    }
#ifdef PPRINT
    cout << "--EMPTY AREA\n" << empt << "\n";
    cout << "--VIRUSES\n";
    for (vector<coord>::iterator vit = virus.begin(); vit != virus.end(); vit++) {
        cout << (*vit).x << "," << (*vit).y << " | ";
    }
    cout << "\n";
#endif
    setCmb(empt);
    do {
        if (!isSetWall()) continue;
        spreading();
        saf = getSafeArea();
#ifdef PPRINT
        if (saf > max_saf) {
            cout << "==================\n";
            for (vector<coord>::iterator it = nwall.begin(); it != nwall.end(); it++) {
                cout << (*it).x << "," << (*it).y << "\n";
            }
            printVisited();
        }
#endif
        max_saf = MAX(saf, max_saf);
        if (max_saf == empt-3) break;
    } while (next_permutation(cmb, cmb+empt));
    cout << max_saf << "\n";
}