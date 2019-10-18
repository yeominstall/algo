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

    int newPos (int curr, int next, int width) {
        int rem;
        if (curr == next) return curr;
        if (next < 0 || next >= width) {
            
        }
        if (width == 2) {
            if (next < 0 || next >= width) {
                next = abs(next);
                if (next % 2 == 1) return 1;
                else return 0;
            } else {
                return next;
            }
        }
        if (next < 0) {
            next = -next;
            rem = (next - 1) % (width - 1);
            if (((next-1)/(width-1)) % 2 == 0) {
                turn();
                return (rem + 1);
            } else {
                return (width - 2 - rem);
            }
        } else if (next >= width) {
            rem = next % (width - 1);
            if ((next-1)/(width-1) % 2 == 1) {
                turn();
                return (width - 1 - rem);
            } else {
                return rem;
            }
        } else {
            return next;
        }
    }

    void moving (void) {
        int ny = p.y + (dir[d][0] * v);
        int nx = p.x + (dir[d][1] * v);
        p.y = newPos(p.y, ny, R);
        p.x = newPos(p.x, nx, C);
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