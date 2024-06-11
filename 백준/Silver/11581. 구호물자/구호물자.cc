#include <iostream>
#include <vector>

using namespace std;

int n, m, o;
vector<vector<int>> junction;

int main(void)
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    junction.resize(n + 1, vector<int>(n + 1, 0));
    int i, j, k;
    for (i = 1; i < n; ++i)
    {
        cin >> m;
        for (j = 0; j < m; ++j)
        {
            cin >> o;
            junction[i][o] = 1;
        }
    }

    for (k = 1; k < n; ++k)
    {
        for (i = 1; i < n; ++i)
        {
            for (j = 1; j <= n; ++j)
            {
                if (junction[i][k] == 0 || junction[k][j] == 0)
                    continue;
                junction[i][j] = 1;
            }
        }
    }

    bool flag = false;
    for (i = 1; i <= n; ++i)
    {
        if (junction[1][i] == 1 && junction[i][i] == 1)
        {
            flag = true;
            break;
        }
    }
    if (flag)
        cout << "CYCLE\n";
    else
        cout << "NO CYCLE\n";
    return 0;
}