/**
 * boj 14501
 */
#include <bits/stdc++.h>

using namespace std;

int N;
int T[15], P[15];
int cmb[15] = {0};

void setCmb (int day) {
    for (int i = 0; i < N; i++) {
        if (i >= (N - day)) {cmb[i] = 1;}
        else {cmb[i] = 0;}
    }
}

bool isAvail (void) {
    int d = 0;
    bool schedule[15] = {0,};
    for (d = 0; d < N; d++) {
        if (cmb[d] == 1) {
            if (schedule[d]) return false;
            else {
                if (d+T[d] > N) return false;
                for (int it = 0; it < T[d]; it++) {
                    schedule[d+it] = true;
                }
            }
        }
    }
    return true;
}

int earnMoney (void) {
    int money = 0;
    for (int i = 0; i < N; i++) {
        if (cmb[i] == 1) {
            money += P[i];
        }
    }
    return money;
}

void printCmb (void) {
    for (int i = 0; i < N; i++) {
        cout << cmb[i] << " ";
    }
    cout << "\n";
}

int main (void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t, p, i, j, reward, max_reward = 0;
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> T[i] >> P[i];
    }
    for (i = 1; i <= N; i++) {
        setCmb(i);
        do {
            if (!isAvail()) continue;
            reward = earnMoney();
            max_reward = (max_reward < reward) ? reward : max_reward;
        } while (next_permutation(cmb, cmb+N));
    }
    cout << max_reward << "\n";
}