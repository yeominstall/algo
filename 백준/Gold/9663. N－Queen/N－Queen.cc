#include <iostream>
#include <vector>

using namespace std;

struct pos
{
    int x;
    int y;
};

int n, cases;
vector<pos> conquered;

bool check(int x, int y)
{
    for (auto& p : conquered)
    {
        if (x == p.x || y == p.y || abs(x - p.x) == abs(y - p.y))
            return false;
    }
    return true;
}

void dfs(const int& row)
{
    if (row == n)
    {
        ++cases;
        return;
    }
    
    for (int col = 1; col <= n; ++col)
    {
        if (check(col, row + 1))
        {

            conquered.push_back({ col, row + 1 });
            dfs(row + 1);
            conquered.pop_back();
        }
    }
}

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    cin >> n;
    dfs(0);
    cout << cases << '\n';

    return 0;
}