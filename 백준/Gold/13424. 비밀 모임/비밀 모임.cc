#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> rooms;
vector<int> positions;

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int tc, n, m, a, b, c, fr, pos, i, j, k;
    const int base = 100000;
    cin >> tc;
    for (int T = 0; T < tc; ++T)
    {
        cin >> n >> m;
        rooms.clear();
        rooms.resize(n + 1);
        for (i = 1; i <= n; ++i)
        {
            rooms[i].resize(n + 1, base);
            rooms[i][i] = 0;
        }
        for (i = 0; i < m; ++i)
        {
            cin >> a >> b >> c;
            rooms[a][b] = c;
            rooms[b][a] = c;
        }
        for (k = 1; k <= n; ++k)
        {
            for (i = 1; i <= n; ++i)
            {
                if (i == k) continue;
                for (j = 1; j <= n; ++j)
                {
                    if (j == k || i == j) continue;
                    int alter = rooms[i][k] + rooms[k][j];
                    if (alter < rooms[i][j])
                    {
                        rooms[i][j] = alter;
                        rooms[j][i] = alter;
                    }
                }
            }
        }
        cin >> fr;
        positions.resize(fr, 0);
        for (i = 0; i < fr; ++i)
            cin >> positions[i];
        int sum, shortest = base, roomno = 0;
        for (i = 1; i <= n; ++i)
        {
            sum = 0;
            for (j = 0; j < fr; ++j)
                sum += rooms[i][positions[j]];
            if (sum < shortest)
            {
                shortest = sum;
                roomno = i;
            }
        }
        cout << roomno << '\n';
    }

    return 0;
}