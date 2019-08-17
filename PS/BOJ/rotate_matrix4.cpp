/**
 * boj 17406
 */
#include <iostream>
#include <algorithm>
#define __OOB__(x,y)    (x < 0 || x >= M || y < 0 || y >= N)
#define MIN(x,y)        (x < y) ? x : y

using namespace std;

int N, M, K;
int origin[50][50];
int field[50][50];
int twist[6][3];
int do_twist[6] = {0, 1, 2, 3, 4, 5};

void printField (void) {
    int i, j;
    cout << "===================\n";
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            cout << field[i][j] << " ";
        }
        cout << "\n";
    }
}

void initTwirl (void) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            field[i][j] = origin[i][j];
        }
    }
}

int getShortest (void) {
    int i, j, sum, res = 5001;
    for (i = 0; i < N; i++) {
        sum = 0;
        for (j = 0; j < M; j++) {
            sum += field[i][j];
        }
        res = MIN(sum, res);
    }
    return res;
}

void run (int r, int c, int s) {
    int i, j, k, tmp, shortest;
    for (k = 1; k <= s; k++) {
        tmp = field[r-k][c-k];
        for (i = r-k; i < r+k; i++) {
            field[i][c-k] = field[i+1][c-k];
        }
        for (j = c-k; j < c+k; j++) {
            field[r+k][j] = field[r+k][j+1];
        }
        for (i = r+k; i > r-k; i--) {
            field[i][c+k] = field[i-1][c+k];
        }
        for (j = c+k; j > c-k; j--) {
            field[r-k][j] = field[r-k][j-1];
        }
        field[r-k][c-k+1] = tmp;
#ifdef PPRINT
        printField();
#endif
    }
}

void twirl (void) {
    int tw;
    int r, c, s;
    for (tw = 0; tw < K; tw++) {
        r = twist[do_twist[tw]][0];
        c = twist[do_twist[tw]][1];
        s = twist[do_twist[tw]][2];
        run(r, c, s);
    }
}

int main (void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int power, min_power = 10000;
    int i, j;
    cin >> N >> M >> K;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            cin >> origin[i][j];
        }
    }
    for (i = 0; i < K; i++) {
        cin >> twist[i][0] >> twist[i][1] >> twist[i][2];
        --twist[i][0];
        --twist[i][1];
    }
    do {
        initTwirl();
        twirl();
        power = getShortest();
        min_power = MIN(power, min_power);
        if (min_power == M) break;
    } while (next_permutation(do_twist, do_twist+K));
    cout << min_power << "\n";
    return 0;
}