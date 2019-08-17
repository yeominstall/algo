/**
 * boj 17144
 */
#include <bits/stdc++.h>
#define __OOB__(y, x)   (x < 0 || x >= C || y < 0 || y >= R)

using namespace std;

typedef struct cell {
    int ptc;
    int s_ptc;
} _cell;

int R, C, T;
cell room[50][50];
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void printRoom (void) {
    int i, j;
    cout << "======================\n";
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            cout << room[i][j].ptc << " ";
        }
        cout << "\n";
    }
}

void calcSPtc (void) {
    int i, j;
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            if (room[i][j].ptc == -1) continue;
            if (room[i][j].ptc != 0) {
                room[i][j].s_ptc = room[i][j].ptc/5;
            } else {
                room[i][j].s_ptc = 0;
            }
        }
    }
}

void spread (void) {
    int i, j, d, nr, nc;
    int cnt;
    calcSPtc();
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            if (room[i][j].ptc == -1) continue;
            if (room[i][j].ptc > 0) {
                cnt = 0;
                for (d = 0; d < 4; d++) {
                    nr = i + dir[d][0];
                    nc = j + dir[d][1];
                    if (__OOB__(nr, nc) || room[nr][nc].ptc == -1) continue;
                    room[nr][nc].ptc += room[i][j].s_ptc;
                    // cnt++;
                    room[i][j].ptc -= room[i][j].s_ptc;
                }
                // room[i][j].ptc -= (cnt * room[i][j].s_ptc);
            }
        }
    }
}

void run (int upper, int lower) {
    int i, j;
    for (i = upper-2; i >= 0; i--) {
        room[i+1][0].ptc = room[i][0].ptc;
    }
    // printRoom();
    for (j = 0; j < C-1; j++) {
        room[0][j].ptc = room[0][j+1].ptc;
    }
    // printRoom();
    for (i = 0; i < upper; i++) {
        room[i][C-1].ptc = room[i+1][C-1].ptc;
    }
    // printRoom();
    for (j = C-1; j >= 2; j--) {
        room[upper][j].ptc = room[upper][j-1].ptc;
    }
    // printRoom();

    for (i = lower+1; i < R-1; i++) {
        room[i][0].ptc = room[i+1][0].ptc;
    }
    for (j = 0; j < C-1; j++) {
        room[R-1][j].ptc = room[R-1][j+1].ptc;
    }
    for (i = R-1; i >= lower+1; i--) {
        room[i][C-1].ptc = room[i-1][C-1].ptc;
    }
    for (j = C-1; j >= 2; j--) {
        room[lower][j].ptc = room[lower][j-1].ptc;
    }
    room[upper][1].ptc = 0;
    room[lower][1].ptc = 0;
}

int getParticles (void) {
    int i, j, ptc = 0;
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            if (room[i][j].ptc == -1) continue;
            ptc += room[i][j].ptc;
        }
    }
    return ptc;
}

int main (void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int i, j;
    vector<int> wind;
    cin >> R >> C >> T;
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            cin >> room[i][j].ptc;
            if (room[i][j].ptc == -1) wind.push_back(i);
        }
    }
    for (i = 0; i < T; i++) {
        spread();
        printRoom();
        run(wind.at(0), wind.at(1));
        printRoom();
    }
    cout << getParticles() << "\n";
    return 0;
}