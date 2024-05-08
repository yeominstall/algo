#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, m;
vector<vector<int>> cities;

void printroute(void)
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (cities[i][j] > 10000000)
                cout << "0 ";
            else
                cout << cities[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int from, to, cost;
    int i, j, k;
    cin >> n >> m;
    cities.resize(n + 1);
    for (i = 1; i <= n; ++i)
    {
        cities[i].resize(n + 1, 10000001);
        cities[i][i] = 0;
    }

    for (i = 0; i < m; ++i)
    {
        cin >> from >> to >> cost;
        if (cost < cities[from][to])
            cities[from][to] = cost;
    }

    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            if (j == i)
                continue;
            for (k = 1; k <= n; ++k)
            {
                if (j == k || k == i)
                    continue;
                int alter = cities[j][i] + cities[i][k];
                if (cities[j][k] > alter)
                    cities[j][k] = alter;
            }
        }
    }
    printroute();

    return 0;
}