#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> kitchen;

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    kitchen.resize(n + 1, vector<int>(n + 1, 101));
    int i, j, k;
    for (i = 1; i <= n; ++i)
        kitchen[i][i] = 0;

    int a, b;
    for (i = 0; i < m; ++i)
    {
        cin >> a >> b;
        kitchen[a][b] = 1;
        kitchen[b][a] = 1;
    }

    for (k = 1; k <= n; ++k)
    {
        for (i = 1; i <= n; ++i)
        {
            if (i == k) continue;
            for (j = 1; j <= n; ++j)
            {
                if (i == j || j == k)
                    continue;
                int alter = kitchen[i][k] + kitchen[k][j];
                if (alter < kitchen[i][j])
                {
                    kitchen[i][j] = alter;
                    kitchen[j][i] = alter;
                }
            }
        }
    }

    int total = 0;
    int shortest = 0x7fffffff, idx1, idx2;
    for (i = 1; i < n; ++i)
    {
        for (j = i + 1; j <= n; ++j)
        {
            for (k = 1; k <= n; ++k)
            {
                total += min(kitchen[k][i], kitchen[k][j]);
            }
            if (total < shortest)
            {
                shortest = total;
                idx1 = i;
                idx2 = j;
            }
        }
    }
    cout << idx1 << ' ' << idx2 << ' ' << shortest * 2 << '\n';

    return 0;
}