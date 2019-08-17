/**
 * boj 14499
 */
#include <bits/stdc++.h>

#define __OOB__(x, y)   (x < 0 || x >= M || y < 0 || y >= N)

using namespace std;

int dmap[20][20];
int dice[6] = {0};
int dir[5][2] = {0, 0, 1, 0, -1, 0, 0, -1, 0, 1};

int N, M, px, py;

void rollDice (int comm) {
    int i, tmp;
    if (comm == 1) {
        tmp = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[4];
        dice[4] = tmp;
    } else if (comm == 2) {
        tmp = dice[3];
        dice[3] = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[5];
        dice[5] = tmp;
    } else if (comm == 3) {
        tmp = dice[0];
        dice[0] = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[3];
        dice[3] = tmp;
    } else if (comm == 4) {
        tmp = dice[3];
        dice[3] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[0];
        dice[0] = tmp;
    }
}

void moveDice (int comm) {
    int dx, dy;
    dx = px + dir[comm][0];
    dy = py + dir[comm][1];
    if (__OOB__(dx, dy)) return;
    rollDice(comm);
    if (dmap[dy][dx] == 0) {
        dmap[dy][dx] = dice[3];
    } else {
        dice[3] = dmap[dy][dx];
        dmap[dy][dx] = 0;
    }
    cout << dice[1] << "\n";
    px = dx; py = dy;
}

void printDice (void) {
    for (int i = 0; i < 6; i++) {
        cout << dice[i] << " ";
    }
    cout << "\n";
}

int main (void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int K, comm, i, j;
    cin >> N >> M >> py >> px >> K;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            cin >> dmap[i][j];
        }
    }
    for (j = 0; j < K; j++) {
        cin >> comm;
        moveDice(comm);
    }
    return 0;
}