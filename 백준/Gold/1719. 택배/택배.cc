#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> hubs;
vector<vector<int>> nxt;

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m, a, b, c, fr, pos, i, j, k;
    const int base = 10000001;
    cin >> n >> m;
    hubs.resize(n + 1, vector<int>(n + 1, base));
    nxt.resize(n + 1, vector<int>(n + 1, 0));
    for (i = 1; i <= n; ++i)
        hubs[i][i] = 0;

    for (i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        // 집하장 간 경로가 여러 개 있다면 여기에 조건 추가
        hubs[a][b] = c;
        hubs[b][a] = c;
        nxt[a][b] = b;
        nxt[b][a] = a;
    }

    for (k = 1; k <= n; ++k)
    {
        for (i = 1; i <= n; ++i)
        {
            if (i == k) continue;
            for (j = 1; j <= n; ++j)
            {
                if (j == k || i == j) continue;
                int alter = hubs[i][k] + hubs[k][j];
                if (alter < hubs[i][j])
                {
                    hubs[i][j] = alter;
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            if (i == j)
                cout << "- ";
            else
                cout << nxt[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}