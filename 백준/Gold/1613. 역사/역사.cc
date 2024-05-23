#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> history;

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m, s, former, later, i, j, k;
    const int base = 10000001;
    cin >> n >> m;
    history.resize(n + 1, vector<int>(n + 1, base));
    for (i = 1; i <= n; ++i)
        history[i][i] = 0;

    for (i = 0; i < m; ++i)
    {
        cin >> former >> later;
        history[former][later] = 1;
    }

    for (k = 1; k <= n; ++k)
    {
        for (i = 1; i <= n; ++i)
        {
            if (i == k) continue;
            for (j = 1; j <= n; ++j)
            {
                if (j == k || i == j) continue;
                if (history[i][k] == base || history[k][j] == base) continue;
                int alter = history[i][k] + history[k][j];
                if (alter < history[i][j])
                    history[i][j] = alter;
            }
        }
    }
    cin >> s;
    for (i = 0; i < s; ++i)
    {
        cin >> former >> later;
        if (history[former][later] != base)
            cout << "-1\n";
        else if (history[later][former] != base)
            cout << "1\n";
        else
            cout << "0\n";
    }

    return 0;
}