#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> tbl(m + 1, 1);
    tbl[1] = 0;
    for (int i = 2; i <= m; ++i)
    {
        if (tbl[i] == 1)
        {
            int j = 2;
            while (i * j <= m)
            {
                --tbl[i * j];
                ++j;
            }
        }
    }

    for (int i = n; i <= m; ++i)
    {
        if (tbl[i] == 1)
            cout << i << '\n';
    }
    
    return 0;
}