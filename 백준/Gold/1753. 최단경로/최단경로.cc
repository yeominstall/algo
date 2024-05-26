#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct p
{
    int to;
    int cost;

    friend bool operator<(const p& lhs, const p& rhs)
    {
        return rhs.cost < lhs.cost;
    }
};

constexpr int INF = 0x7fffffff;
vector<vector<p>> path;

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int v, e, start;
    cin >> v >> e >> start;
    path.resize(v + 1, vector<p>());
    int i, j, from, to, cost;
    for (i = 0; i < e; ++i)
    {
        cin >> from >> to >> cost;
        path[from].push_back({ to, cost });
    }
    vector<int> shortest(v + 1, INF);
    shortest[start] = 0;
    auto cmp = [](p& larg, p& rarg) {return larg.cost < rarg.cost; };
    //priority_queue<p, vector<p>, decltype(cmp)> pq;
    priority_queue<p> pq;
    pq.push({ start, 0 });

    while (pq.size() > 0)
    {
        auto curr = pq.top();
        pq.pop();
        if (curr.cost == shortest[curr.to])
        {
            // curr 에서 갈 수 있는 노드
            for (i = 0; i < path[curr.to].size(); ++i)
            {
                auto& next_to = path[curr.to][i].to;
                auto& next_cost = path[curr.to][i].cost;
                if (next_cost + curr.cost < shortest[next_to])
                {
                    shortest[next_to] = next_cost + curr.cost;
                    pq.push({ next_to, next_cost + curr.cost });
                }
            }
        }
    }
    for (i = 1; i <= v; ++i)
    {
        if (shortest[i] == INF)
            cout << "INF\n";
        else
            cout << shortest[i] << '\n';
    }
    
    return 0;
}