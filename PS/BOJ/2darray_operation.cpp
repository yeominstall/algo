/**
 * boj 17140
 */
#include <iostream>
#include <map>
#define MAX(a,b)    (a > b) ? a : b

using namespace std;

int R_bound = 3, C_bound = 3;
int arr[2][100][100];
int flipper = 0; // @TODO: replace flipper to tick and remove flipper(or change type to bool)
int tmp[101];
int frb;

class num {
public:
    int number;
    int cnt;

    num(int _n, int _cnt) : number(_n), cnt(_cnt) {}

    bool operator< (const num &right) const {
        if (cnt == right.cnt) {
            return number < right.number;
        } else {
            return cnt < right.cnt;
        }
    }

    bool operator== (const num &right) const {
        return (!(cnt < right.cnt) && !(cnt > right.cnt) && !(number < right.number) && !(number > right.number));
    }
};

map<num, int> nset;

void resetTmp (void) {
    int i;
    for (i = 0; i < 101; i++) tmp[i] = 0;
}
int csort (int c_idx) {
    int i, j, k;
    resetTmp();
    for (i = 0; i < frb; i++) {
        tmp[arr[flipper][i][c_idx]]++;
    }
    j = 0;
    for (k = 1; k < 101; k++) {
        for (i = 1; i < 101; i++) {
            if (tmp[i] == k) {
                arr[flipper][j++][c_idx] = i;
                arr[flipper][j++][c_idx] = tmp[i];
            }
        }
    }
    return j;
}

void operR (void) {
#ifdef PVAR
    cout << "-- start operR --\n";
#endif
    int i, j, fcb, cnt, curr;
    for (i = 0; i < R_bound; i++) {
        sort(arr[flipper][i], arr[flipper][i]+C_bound);
    }
    fcb = C_bound;
    C_bound = 0;
    for (i = 0; i < R_bound; i++) {
        nset.clear();
        curr = arr[flipper][i][0];
        cnt = 1;
        for (j = 0; j < fcb-1; j++) {
            if (curr == arr[flipper][i][j+1]) {
                cnt++;
            } else {
                nset.insert(pair<num, int>(num(curr, cnt), curr));
                curr = arr[flipper][i][j+1];
                cnt = 1;
            }
        }
        nset.insert(pair<num, int>(num(curr, cnt), curr));
        j = -1;
        for (map<num, int>::iterator it = nset.begin(); it != nset.end(); ) {
            if (j == 99) break;
            if ((*it).first.number == 0) {
                it = nset.erase(it);
                continue;
            } else {
                arr[flipper][i][++j] = (*it).first.number;
                arr[flipper][i][++j] = (*it).first.cnt;
                it++;
            }
        }
        C_bound = MAX(j+1, C_bound);
        for (++j ; j < 100; j++) {
            arr[flipper][i][j] = 0;
        }
    }
}

void operC (void) {
#ifdef PVAR
    cout << "-- start operC --\n";
#endif
    int i, j, rb;
    frb = R_bound;
    R_bound = 0;
    for (j = 0; j < C_bound; j++) {
        rb = csort(j);
        R_bound = MAX(rb, R_bound);
        for (i = rb ; i < 100; i++) {
            arr[flipper][i][j] = 0;
        }
    }
}

void printArr (void) {
    int i, j;
    cout << "==============\n";
    for (i = 0; i < R_bound; i++) {
        for (j = 0; j < C_bound; j++) {
            cout << arr[flipper][i][j] << " ";
        }
        cout << "\n";
    }
}

int main (void) {
    int r, c, k, i, j, tick;
    cin >> r >> c >> k;
    --r; --c;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cin >> arr[flipper][i][j];
        }
    }
    for (tick = 0; tick <= 100; tick++) {
#ifdef PVAR
        printArr();
#endif
        if (arr[flipper][r][c] == k) {
            cout << tick << "\n";
            return 0;
        }
        // if (arr[flipper][r][c] > 100) {
        //     cout << "-1\n"; 
        //     return 0;
        // }
        if (R_bound < C_bound) operC();
        else operR();
#ifdef PVAR
        cout << "[" << tick << "] C_bound: " << C_bound << " R_bound: " << R_bound << "\n";
#endif
    }
    cout << "-1\n";
    return 0;
}