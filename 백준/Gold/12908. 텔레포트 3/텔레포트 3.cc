#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct pos
{
    ll x;
    ll y;
};

#define GetDist(a, b)   (abs(a.x - b.x) + abs(a.y - b.y))

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    constexpr int n = 8;
    pos v[n];   // 정점이 8개인 그래프
    int i, j, k;
    for (i = 0; i < n; ++i)
        cin >> v[i].x >> v[i].y;

    vector<vector<ll>> path(n, vector<ll>(n, 0));
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            path[i][j] = GetDist(v[i], v[j]);
            path[j][i] = path[i][j];
        }
    }

    // 텔포 vs 점프 계산
    for (i = 2; i < n; i += 2)
    {
        if (10 < path[i][i + 1])
        {
            path[i][i + 1] = 10;
            path[i + 1][i] = 10;
        }
    }

    for (k = 0; k < n; ++k)
    {
        for (i = 0; i < n; ++i)
        {
            if (i == k) continue;
            for (j = 0; j < n; ++j)
            {
                if (j == k || i == j) continue;
                ll alter = path[i][k] + path[k][j];
                if (alter < path[i][j])
                    path[i][j] = alter;
            }
        }
    }

    cout << path[0][1] << '\n';

    return 0;
}