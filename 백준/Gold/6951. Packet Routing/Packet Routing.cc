#include <iostream>
#include <vector>

using namespace std;

int n, w, p;
vector<vector<int>> network;

int main(void)
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> w >> p;
    network.resize(n + 1, vector<int>(n + 1, 500001));
    int i, j, k, from, to, time;
    for (i = 1; i <= n; ++i)
        network[i][i] = 0;
    for (i = 0; i < w; ++i)
    {
        cin >> from >> to >> time;
        network[from][to] = time;
        network[to][from] = time;
    }

    for (k = 1; k <= n; ++k)
    {
        for (i = 1; i <= n; ++i)
        {
            if (i == k) continue;
            for (j = 1; j <= n; ++j)
            {
                if (j == k || i == j) continue;
                int alter = network[i][k] + network[k][j];
                if (alter < network[i][j])
                    network[i][j] = alter;
            }
        }
    }

    for (i = 0; i < p; ++i)
    {
        cin >> from >> to;
        cout << network[from][to] << '\n';
    }
    return 0;
}