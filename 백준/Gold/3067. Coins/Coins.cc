#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T;
    int n, k;
    vector<unsigned int> kind;
    vector<unsigned int> table;
    cin >> T;
    for (int tc = 0; tc < T; ++tc)
    {
        cin >> n;
        kind.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> kind[i];

        sort(kind.begin(), kind.end());

        cin >> k;
        table.clear();
        table.resize(k + 1, 0);
        table[0] = 1;
        for (int i = 0; i < n; ++i)
        {
            for (int v = 1; v <= k; ++v)
            {
                // kind[i] 를 마지막으로 넣어서 v가 되는 경우
                int diff = v - kind[i];
                if (diff >= 0)
                {
                    table[v] += table[diff];
                }
            }
        }
        cout << table[k] << '\n';
    }
    return 0;
}