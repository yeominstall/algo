#include <bits/stdc++.h>

#define __OOB__(x,y)    (x < 0 || x >= C || y < 0 || y >= R)
#define MAX(x,y)        (x > y) ? x : y

using namespace std;

int R, C, M;
int dir[5][2] = {0, 0, 0, -1, 0, 1, 1, 0, -1, 0};

class shark {
    int _x, _y;
    int _v;
    int _d;
    int _size;
    shark(int r, int c, int s, int d, int z) 
    : _y(r), _x(c), _v(s), _d(d), _size(z) {

    }

    void turnSharks (int nx, int ny) {
        
    }

    void moveSharks () {
        int nx, ny;
        nx = _x + dir[_d][0]*v;
        ny = _y + dir[_d][1]*v;
        if (__OOB__(nx, ny)) turnShark();
    }
};

vector<shark> sharks;
shark sea[100][100];

int main (void) {
    int r, c, s, d, z, i, j;
    cin >> R >> C >> M
    sharks.reserve(M);
    for (i = 0; i < M; i++) {
        cin >> r >> c >> s >> d >> z;
        shark fish(r, c, s, d, z);
        sharks.push_back(fish);
    }

    return 0;
}
