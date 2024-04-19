#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct good
{
    unsigned int weight;
    unsigned int value;
};

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<good> goods(n + 1);
    vector<vector<unsigned int>> values(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> goods[i].weight >> goods[i].value;

    // i: 물품 idx, w: 가방의 무게
    values[0].resize(k + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        values[i].resize(k + 1);
        auto& this_w = goods[i].weight;
        auto& this_v = goods[i].value;
        for (int w = 1; w <= k; ++w)
        {
            if (this_w > w)
                values[i][w] = values[i - 1][w];
            else
                values[i][w] = max(values[i - 1][w], this_v + values[i - 1][w - this_w]);
        }
    }

    cout << values[n][k] << '\n';

    return 0;
}