#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> balls;

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    const int base = 0xff;
    cin >> n >> m;
    balls.resize(n + 1, vector<int>(n + 1, base));
    int i, j, k;
    int heavy, light;
    for (i = 1; i <= n; ++i)
        balls[i][i] = 0;
    for (i = 0; i < m; ++i)
    {
        cin >> heavy >> light;
        balls[heavy][light] = 1;
    }
    for (k = 1; k <= n; ++k)
    {
        for (i = 1; i <= n; ++i)
        {
            if (i == k) continue;
            for (j = 1; j <= n; ++j)
            {
                if (j == k || i == j) continue;
                if (balls[i][j] == 1 || balls[i][k] == base || balls[k][j] == base) continue;
                balls[i][j] = 1;
            }
        }
    }
    for (i = 1; i <= n; ++i)
    {
        int unknown = 0;
        for (j = 1; j <= n; ++j)
        {
            if (balls[i][j] == base && balls[j][i] == base) ++unknown;
        }
        cout << unknown << '\n';
    }

    return 0;
}