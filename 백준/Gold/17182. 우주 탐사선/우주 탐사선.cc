#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> systems;

int shortest = 100001, sum = 0, cnt = 1;
vector<bool> checker;
void making(int from)
{
    if (cnt == n && sum < shortest)
    {
        shortest = sum;
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (checker[i]) continue;
        checker[i] = true;
        sum += systems[from][i];
        ++cnt;
        making(i);
        --cnt;
        sum -= systems[from][i];
        checker[i] = false;
    }
}

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int i, j, k;
    const int base = 10000001;
    cin >> n >> m;
    systems.resize(n, vector<int>(n, base));
    checker.resize(n, false);
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            cin >> systems[i][j];

    for (k = 0; k < n; ++k)
    {
        for (i = 0; i < n; ++i)
        {
            if (i == k) continue;
            for (j = 0; j < n; ++j)
            {
                if (j == k || i == j) continue;
                int alter = systems[i][k] + systems[k][j];
                if (alter < systems[i][j])
                    systems[i][j] = alter;
            }
        }
    }
    checker[m] = true;
    making(m);
    cout << shortest << '\n';

    return 0;
}