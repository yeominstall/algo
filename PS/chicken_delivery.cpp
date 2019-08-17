#include <bits/stdc++.h>
#define __OOB__(x,y)    (x < 0 || x >= N || y < 0 || y >= N)

using namespace std;

class coord {
public:
    int x;
    int y;

    coord (int _x, int _y) : x(_x), y(_y) {}

    int getDist (coord &Dest) {
        return (abs(x - Dest.x) + abs(y - Dest.y));
    }

    bool operator== (coord &Rhs) {
        return (x == Rhs.x && y == Rhs.y);
    }
};

vector<coord> houses;

class chicken {
public:
    coord cpos;
    int ci;

    chicken (coord _pos) : cpos(_pos), ci(0) {}

    bool operator== (chicken &Rhs) {
        return (ci == Rhs.ci);
    }

    bool operator> (chicken &Rhs) {
        if (this == Rhs) {
            return (cpos.x > Rhs.cpos.x);
        } else {
            return (ci > Rhs.ci);
        }
    }

    int getCI (void) {
        ci = 0;
        for(vector<house>::iterator it != houses.begin(); it != houses.end(); it++) {
            ci += (*it).pos.getDist(cpos);
        }
        return ci;
    }
};

int N, M;
vector<chicken> chickens;
vector<chicken>::iterator chit;

int getTownIndicator (void) {
    int TCI = 0;
    for (vector<house>::iterator it = houses.begin(); it != houses.end(); it++) {
        TCI += (*it).ck_dist;
    }
    return TCI;
}

int main (void) {
    int i, j, val, idx;
    cin >> N >> M;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cin >> val;
            if (val == 1) {
                houses.push_back(coord(j, i));
            } else if (val == 2) {
                chickens.push_back(chicken(coord(j, i)));
            }
        }
    }
    for (chit = chickens.begin(); chit != chickens.end(); chit++) {
        (*it).getCI();
    }
    sort(chickens.begin(), chickens.end());
    idx = chickens.at(M+1).ci;
    for (chit = chickens.rbegin(); chit != chickens.rend(); chit++) {

    }
}