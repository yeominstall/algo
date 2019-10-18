/**
 * boj 17143
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int R, C, M;
int dir[5][2] = {0, 0, -1, 0, 1, 0, 0, 1, 0, -1};
int arr[200];
int dd[200];

class coord {
public:
    int x;
    int y;

    coord (int _x, int _y) : x(_x), y(_y) {}

    bool operator== (const coord &rhs) const {
        return (x == rhs.x && y == rhs.y);
    }

    bool operator< (const coord &rhs) const {
        if (x == rhs.x && y == rhs.y) return true;

        if (x == rhs.x) {
            return (y < rhs.y);
        } else {
            return (x < rhs.x);
        }
    }
};

class shark {
public:
    coord p;
    int v;
    int d;
    int size;

    shark (coord _p, int _v, int _d, int _z) : p(_p), v(_v), d(_d), size(_z) {}

    bool operator< (const shark &rhs) const {
        if (p == rhs.p) {
            return (size > rhs.size);
        } else {
            return (p < rhs.p);
        }
    }

    void turn (void) {
        if (d == 1) d = 2;
        else if (d == 2) d = 1;
        else if (d == 3) d = 4;
        else if (d == 4) d = 3;
    }

    int newPos (int curr, int dd, int width) {
        if (dd == 0) return curr;
        int rem = v % (2 * (width - 1));
        for (int i = 0; i < rem; i++) {
            if ((curr == 0 && dd == -1) || (curr == (width - 1) && dd == 1)) {
                dd *= -1;
                turn();
            }
            curr += dd;
        }
        return curr;
    }

    void moving (void) {
        p.y = newPos(p.y, dir[d][0], R);
        p.x = newPos(p.x, dir[d][1], C);
    }
};

vector<shark> sharks;

void printSea (void) {
    int sea[100][100];
    memset(sea, 0, sizeof(sea));
    for (vector<shark>::iterator it = sharks.begin(); it != sharks.end(); it++) {
        coord p = (*it).p;
        sea[p.y][p.x] = (*it).size;
    }
    cout << "===================\n";
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << sea[i][j] << " ";
        }
        cout << "\n";
    }
}

int fishing (int src) {
    int score = 0;
    vector<shark>::iterator it;
    for (it = sharks.begin(); it != sharks.end(); it++) {
        if ((*it).p.x == src) {
            score = (*it).size;
            it = sharks.erase(it);
            break;
        }
    }
    return score;
}

void setPos (void) {
    vector<shark>::iterator it;
    sort(sharks.begin(), sharks.end());
    coord former = sharks.front().p;
    for (it = sharks.begin()+1; it != sharks.end(); ) {
        if ((*it).p == former) {
            it = sharks.erase(it);
        } else {
            former = (*it).p;
            it++;
        }
    }
}

int main (void) {
    int rr, cc, v, d, z, score, total = 0;
    cin >> R >> C >> M;
    for (int i = 0; i < M; i++) {
        cin >> rr >> cc >> v >> d >> z;
        sharks.push_back(shark(coord(cc-1, rr-1), v, d, z));
    }
    sort(sharks.begin(), sharks.end());
    for (int i = 0; i < C; i++) {
#ifdef PPRINT
    printSea();
#endif
        score = fishing(i);
#ifdef PPRINT
        cout << "score: " << score << "\n";
#endif
        total += score;
        if (sharks.size() < 1) break;
        for (vector<shark>::iterator it = sharks.begin(); it != sharks.end(); it++) {
            (*it).moving();
        }
        setPos();
    }
    cout << total << "\n";
    return 0;
}