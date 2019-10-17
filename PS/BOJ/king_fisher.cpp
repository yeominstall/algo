/**
 * boj 17143
 */

#include <iostream>
#include <cstring>
#include <vector>
#define __OOB__(x,y)    (x < 0 || x >= C || y < 0 || y >= R)

using namespace std;

int R, C;
int dir[5][2] = {0, 0, -1, 0, 1, 0, 0, 1, 0, -1};

class shark {
public:
    int y;
    int x;
    int d;
    int v;
    const int size;

    shark (int _r, int _c, int _d, int _v, int _z) 
    : y(_r), x(_c), d(_d), v(_v), size(_z) 
    {}

    shark (int n) : y(0), x(0), d(0), v(0), size(-1)
    {
        // This is empty
    }

    void turn (void) {
        if (d == 1) d = 2;
        else if (d == 2) d = 1;
        else if (d == 3) d = 4;
        else if (d == 4) d = 3;
    }

    int newCoords (int curr, int next, int width) {
        int rem;
        if (next < 0) {
            next = (next + curr) * (-1);
            rem = next % (width - 1);
            if (((next-1)/width) % 2 == 1) {
                turn();
                return (width - rem);
            } else {
                return rem;
            }
        } else if (next >= width) {
            next -= curr;
            rem = next % (width - 1);
            if (((next-1)/width) % 2 == 1) {
                turn();
                return (width - rem);
            } else {
                return rem;
            }
        } else {
            return next;
        }
    }

    void moving (void) {
        int ny = y + (dir[d][0] * v);
        int nx = x + (dir[d][1] * v);
        y = newCoords(y, ny, R);
        x = newCoords(x, nx, C);
    }
};

vector<shark> sharks;
int sea[100][100];

void remap (void) {
    memset(sea, 0, sizeof(sea));
    vector<shark>::iterator it;
    for (it = sharks.begin(); it != sharks.end(); ) {
        if (sea[(*it).y][(*it).x] > (*it).size) {
            it = sharks.erase(it);
        } else {
            sea[(*it).y][(*it).x] = (*it).size;
            it++;
        }
    }
    for (it = sharks.begin(); it != sharks.end(); ) {
        if (sea[(*it).y][(*it).x] != (*it).size) {
            it = sharks.erase(it);
        } else { it++; }
    }
}

void printmap (void) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << sea[i][j] << " ";
        }
        cout << "\n";
    }
}

int fishing (int target) {
    int s;
    for (int i = 0; i < R; i++) {
        if (sea[i][target] != 0) {
            for (vector<shark>::iterator it = sharks.begin(); it != sharks.end(); it++) {
                if ((*it).y == i && (*it).x == target) {
                    s = (*it).size;
                    it = sharks.erase(it);
                    return s;
                }
            }
        }
    }
    return 0;
}

int main (void) {
    int M, rr, cc, d, v, z;
    int score, total = 0;
    cin >> R >> C >> M;
    for (int i = 0; i < M; i++) {
        cin >> rr >> cc >> d >> v >> z;
        sharks.push_back(shark(rr-1, cc-1, d, v, z));
    }
    for (int i = 0; i < C; i++) {
#ifdef PPRINT
printmap();
#endif
        if (sharks.size() < 1) break;
        score = fishing(i);
        for (vector<shark>::iterator it = sharks.begin(); it != sharks.end(); it++) {
            (*it).moving();
        }
#ifdef PPRINT
cout << "score : " << score << "\n";
#endif
        remap();
        total += score;
    }
    cout << total << "\n";
    return 0;
}