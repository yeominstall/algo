#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> parties;

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    const string result[2] = { "Stay here", "Enjoy other party"};
    cin >> n >> m;
    parties.resize(n + 1, vector<int>(n + 1));
    int i, j, k;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            cin >> parties[i][j];

    for (k = 1; k <= n; ++k)
    {
        for (i = 1; i <= n; ++i)
        {
            if (i == k) continue;
            for (j = 1; j <= n; ++j)
            {
                if (j == k || i == j) continue;
                int alter = parties[i][k] + parties[k][j];
                if (alter < parties[i][j])
                    parties[i][j] = alter;
            }
        }
    }
    int from, to, remain;
    for (i = 0; i < m; ++i)
    {
        cin >> from >> to >> remain;
        if (parties[from][to] <= remain)
            cout << result[1] << '\n';
        else
            cout << result[0] << '\n';
    }

    return 0;
}