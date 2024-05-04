#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> path;

int find_root(int node)
{
    if (node == path[node])
        return node;

    return path[node] = find_root(path[node]);
}

void connect(int larg, int rarg)
{
    larg = find_root(larg);
    rarg = find_root(rarg);

    if (larg < rarg)
        path[rarg] = larg;
    else if (larg > rarg)
        path[larg] = rarg;
}

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    int i, j, ip;
    cin >> n >> m;
    path.resize(n);
    for (i = 0; i < n; ++i)
        path[i] = i;

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            cin >> ip;
            if (ip == 1)
                connect(i, j);
        }
    }

    string result = "YES";
    cin >> ip;
    int path_root = find_root(ip - 1);
    for (i = 0; i < (m - 1); ++i)
    {
        cin >> ip;
        if (find_root(ip - 1) != path_root)
        {
            result = "NO";
            break;
        }
    }
    cout << result << '\n';

    return 0;
}