#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> relationship;

int find_root(int node)
{
    if (node == relationship[node])
        return node;

    return relationship[node] = find_root(relationship[node]);
}

void connect(int larg, int rarg)
{
    larg = find_root(larg);
    rarg = find_root(rarg);

    if (larg < rarg)
        relationship[rarg] = larg;
    else if (larg > rarg)
        relationship[larg] = rarg;
}

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t, tc;
    cin >> t;
    int users, rel, a, b, m;

    for (tc = 0; tc < t; ++tc)
    {
        cin >> users >> rel;
        relationship.resize(users);
        for (int i = 0; i < users; ++i)
            relationship[i] = i;

        for (int i = 0; i < rel; ++i)
        {
            cin >> a >> b;
            connect(a, b);
        }
        cin >> m;
        cout << "Scenario " << tc + 1 << ":\n";
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b;
            if (find_root(a) == find_root(b))
                cout << "1\n";
            else
                cout << "0\n";
        }
        cout << '\n';
    }

    return 0;
}