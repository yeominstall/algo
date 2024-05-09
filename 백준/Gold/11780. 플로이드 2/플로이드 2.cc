#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> cities;
vector<vector<int>> nxt;

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

void printpath(void)
{
    vector<int> path;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (nxt[i][j] == 0)
                cout << "0\n";
            else
            {
                int r = i, c = j;
                path.clear();
                while (r != 0)
                {
                    path.push_back(r);
                    if (r == j)
                        break;
                    r = nxt[r][c];
                }
                cout << path.size() << ' ';
                for (auto& p : path)
                    cout << p << ' ';
                cout << '\n';
            }
        }
    }
}

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int from, to, cost;
    int i, j, k;
    cin >> n >> m;
    cities.resize(n + 1);
    nxt.resize(n + 1);
    for (i = 1; i <= n; ++i)
    {
        cities[i].resize(n + 1, 10000001);
        nxt[i].resize(n + 1, 0);
        cities[i][i] = 0;
    }

    for (i = 0; i < m; ++i)
    {
        cin >> from >> to >> cost;
        if (cost < cities[from][to])
        {
            cities[from][to] = cost;
            nxt[from][to] = to;
        }
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
                {
                    cities[j][k] = alter;
                    nxt[j][k] = nxt[j][i];
                }
            }
        }
    }
    printroute();
    printpath();

    return 0;
}