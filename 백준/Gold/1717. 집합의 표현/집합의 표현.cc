#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> subsets;
int find_root(int& x)
{
    if (subsets[x] == x)
        return x;

    return subsets[x] = find_root(subsets[x]);
}

void union_set(int& larg, int& rarg)
{
    larg = find_root(larg);
    rarg = find_root(rarg);
    if (larg < rarg)
        subsets[rarg] = larg;
    else if (larg > rarg)
        subsets[larg] = rarg;
}

bool check(int& larg, int& rarg)
{
    if (find_root(larg) == find_root(rarg))
        return true;
    return false;
}

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    int i, j;
    cin >> n >> m;
    subsets.resize(n + 1);
    for (i = 0; i <= n; ++i)
        subsets[i] = i;

    // 연산 입력
    int ops, larg, rarg;
    for (i = 0; i < m; ++i)
    {
        cin >> ops >> larg >> rarg;
        if (ops == 0)
            union_set(larg, rarg);
        else if (ops == 1)
        {
            if (check(larg, rarg))
                printf("YES\n");
            else
                printf("NO\n");

        }
    }

    return 0;
}