#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, arr[100];

bool isGood(void) {
    bool visited[200];
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
        int tmp = i - arr[i] + 101;
        if (visited[tmp]) {
            return false;
        }
        visited[tmp] = true;
    }
    return true;
}

void printGood(void) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

void fixer(void) {
    int visited[200];
    memset(visited, -1, sizeof(visited));
    for (int i = 0; i < n; i++) {
        int diff = i - arr[i] + 1;
        if (visited[diff+100] != -1) {
            int tmp = arr[visited[diff+100]];
            arr[visited[diff+100]] = arr[i];
            arr[i] = tmp;
            visited[diff+100] = -1;
        } else {
            visited[diff+100] = i;
        }
    }
}

int main (void) {
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        memset(arr, 0, sizeof(arr));
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        if (n == 1) {
            cout << arr[0] << '\n';
        } else {
            while (!isGood()) {
                fixer();
            }
            printGood();
        }
    }
    return 0;
}