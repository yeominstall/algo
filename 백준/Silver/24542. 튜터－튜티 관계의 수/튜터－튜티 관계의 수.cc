#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> unite;

int find_root(int node)
{
    if (node == unite[node])
        return node;

    return unite[node] = find_root(unite[node]);
}

void connect(int larg, int rarg)
{
    larg = find_root(larg);
    rarg = find_root(rarg);

    if (larg < rarg)
        unite[rarg] = larg;
    else if (larg > rarg)
        unite[larg] = rarg;
}

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m, a, b;
    cin >> n >> m;
    unite.resize(n + 1);
    int i, j;
    for (i = 1; i <= n; ++i)
        unite[i] = i;

    for (i = 0; i < m; ++i)
    {
        cin >> a >> b;
        connect(a, b);
    }
    for (i = 1; i <= n; ++i)
        unite[i] = find_root(i);

    unordered_map<int, int> roots;
    for (i = 1; i <= n; ++i)
        roots[unite[i]]++;
    
    unsigned long long cases = 1;
    for (auto& group : roots)
    {
        cases *= (group.second % 1000000007ULL);
        cases %= 1000000007ULL;
    }
    cout << cases << '\n';

    return 0;
}