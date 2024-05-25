#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> members;

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, a, b, i, j, k;
    const int base = 100000;
    cin >> n;
    members.resize(n + 1, vector<int>(n + 1, base));
    for (i = 1; i <= n; ++i)
        members[i][i] = 0;
    while (cin >> a >> b)
    {
        if (a == -1)
            break;
        members[a][b] = 1;
        members[b][a] = 1;
    }
    for (k = 1; k <= n; ++k)
    {
        for (i = 1; i <= n; ++i)
        {
            if (i == k) continue;
            for (j = 1; j <= n; ++j)
            {
                if (j == k || i == j || members[i][k] == base || members[k][j] == base) continue;
                int alter = members[i][k] + members[k][j];
                if (alter < members[i][j])
                    members[i][j] = alter;
            }
        }
    }
    int minimum = 0x7fffffff;
    for (i = 1; i <= n; ++i)
    {
        members[i][0] = 0;
        for (j = 1; j <= n; ++j)
        {
            if (members[i][0] < members[i][j])
                members[i][0] = members[i][j];
        }
        if (members[i][0] < minimum)
            minimum = members[i][0];
    }
    vector<int> cands;
    for (i = 1; i <= n; ++i)
        if (members[i][0] == minimum)
            cands.push_back(i);

    cout << minimum << ' ' << cands.size() << '\n';
    for (auto& i : cands)
        cout << i << ' ';
    cout << '\n';

    return 0;
}