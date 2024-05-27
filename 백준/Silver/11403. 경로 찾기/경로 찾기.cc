#include <iostream>
#include <vector>

using namespace std;


int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> path(n, vector<int>(n));
    int i, j, k;
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            cin >> path[i][j];

    for (k = 0; k < n; ++k)
    {
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                if (path[i][k] > 0 && path[k][j] > 0)
                    path[i][j] = 1;
            }
        }
    }

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            cout << path[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}