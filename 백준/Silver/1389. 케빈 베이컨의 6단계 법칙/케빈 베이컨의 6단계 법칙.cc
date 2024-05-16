#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> kevin;

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    kevin.resize(n + 1, vector<int>(n + 1, 500000));
    int i, j, k;
    for (i = 1; i <= n; ++i)
        kevin[i][i] = 0;
    int from, to;
    for (i = 0; i < m; ++i)
    {
        cin >> from >> to;
        kevin[from][to] = 1;
        kevin[to][from] = 1;
    }
    for (k = 1; k <= n; ++k)
    {
        for (i = 1; i <= n; ++i)
        {
            if (k == i) continue;
            for (j = 1; j <= n; ++j)
            {
                if (k == j || i == j) continue;
                int alter = kevin[i][k] + kevin[k][j];
                if (alter < kevin[i][j])
                {
                    kevin[i][j] = alter;
                    kevin[j][i] = alter;
                }
            }
        }
    }

    int min_k = 1000000, sum_k, min_user = -1;
    for (i = 1; i <= n; ++i)
    {
        sum_k = 0;
        for (j = 1; j <= n; ++j)
        {
            sum_k += kevin[i][j];
        }
        if (sum_k < min_k)
        {
            min_k = sum_k;
            min_user = i;
        }
    }
    cout << min_user << '\n';

    return 0;
}