#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> heights;

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    heights.resize(n + 1, vector<int>(n + 1, -1));
    int i, j, k;
    for (i = 1; i <= n; ++i)
        heights[i][i] = 0;
    int s, l;
    for (i = 0; i < m; ++i)
    {
        cin >> s >> l;
        heights[s][l] = 1;
    }
    for (k = 1; k <= n; ++k)
    {
        for (i = 1; i <= n; ++i)
        {
            if (i == k) continue;
            for (j = 1; j <= n; ++j)
            {
                if (j == k || i == j) continue;
                if (heights[i][k] == -1 || heights[k][j] == -1) continue;
                heights[i][j] = 1;
            }
        }
    }

    int clr = 0;
    for (i = 1; i <= n; ++i)
    {
        ++clr;
        for (j = 1; j <= n; ++j)
        {
            if (i == j) continue;
            if (heights[i][j] == -1 && heights[j][i] == -1)
            {
                --clr;
                break;
            }
        }
    }
    cout << clr << '\n';

    return 0;
}