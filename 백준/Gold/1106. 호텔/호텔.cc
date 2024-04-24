#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct city
{
    int cost;
    int user;
};

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    // 목표 고객 수, 도시의 수
    int goal, n;
    cin >> goal >> n;
    vector<city> cities(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> cities[i].cost >> cities[i].user;

    // 비용이 큰 순서로 정렬
    sort(cities.begin() + 1, cities.end(), [](const city& lst, const city& rst) { return lst.cost > rst.cost; });

    // table[i] = j: i 명의 고객을 확보하기 위해 필요한 최소 비용 j
    vector<int> min_cost(goal + 1, INT_MAX);
    min_cost[0] = 0;
    for (int v = 1; v <= n; ++v)
    {
        auto& cost = cities[v].cost;
        auto& user = cities[v].user;
        for (int u = 1; u <= goal; ++u)
        {
            int prev = 0;
            if (u - user >= 0)
                prev = min_cost[u - user];

            min_cost[u] = min(min_cost[u], cost + prev);
        }
    }

    cout << min_cost[goal] << '\n';

    return 0;
}