#include <iostream>
#include <list>

using namespace std;

void josephus (int n, int k) {
    int i;
    list<int> survivors;
    list<int>::iterator kill;
    for (i = 1; i <= n; ++i) survivors.push_back(i);
    kill = survivors.begin();
    while (n > 2) {
        #ifdef PPRINT
        for (list<int>::iterator it = survivors.begin(); it != survivors.end(); it++) {
            cout << *it << " ";
        }
        cout << "\n";
        #endif
        kill = survivors.erase(kill);
        if (kill == survivors.end()) kill = survivors.begin();
        --n;
        for (i = 0; i < k-1; i++) {
            ++kill;
            if (kill == survivors.end()) kill = survivors.begin();            
        }
    }
    cout << survivors.front() << " " << survivors.back() << "\n";
}

int main (void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T, tc, N, K;
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        cin >> N >> K;
        josephus(N, K);
    }
    return 0;
}