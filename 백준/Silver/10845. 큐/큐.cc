#include <iostream>

using namespace std;

int queue[10001];
int front = 0, back = -1;

void qpush (int x) {
    queue[++back] = x;
}

int qpop (void) {
    if (front-1 == back) return -1;
    return queue[front++];
}

int qsize (void) {
    return (back+1 - front);
}

bool qempty (void) {
    return ((front-1 == back) ? 1 : 0);
}

int qfront (void) {
    if (qempty()) return -1;
    return queue[front];
}

int qback (void) {
    if (qempty()) return -1;
    return queue[back];
}

int main (void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int N, arg, i;
    string comm;
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> comm;
        if (comm == "push") {
            cin >> arg;
            qpush(arg);
        } else if (comm == "pop") {
            cout << qpop() << "\n";
        } else if (comm == "size") {
            cout << qsize() << "\n";
        } else if (comm == "empty") {
            cout << qempty() << "\n";
        } else if (comm == "front") {
            cout << qfront() << "\n";
        } else if (comm == "back") {
            cout << qback() << "\n";
        }
    }
    return 0;
}