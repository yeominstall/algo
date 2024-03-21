#include <iostream>
#include <queue>

using namespace std;

int game[101];
int route[101];

struct path
{
    int idx;
    int cost;
};

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int lad, snak;
    cin >> lad >> snak;
    for (int i = 0; i < (lad + snak); i++)
    {
        int start, end;
        cin >> start >> end;
        game[start] = end;
    }

    for (int i = 2; i <= 100; i++)
        route[i] = i - 1;

    int fastest = 1000;
    queue<path> routing;
    routing.push({ 1, 0 });
    while (routing.size() != 0)
    {
        path curr = routing.front();
        routing.pop();
        for (int i = 1; i <= 6; i++)
        {
            int next = curr.idx + i;
            int next_cost = curr.cost + 1;
            if (next > 100) continue;
            if (game[next] == 0)
            {
                if (next_cost < route[next])
                {
                    route[next] = next_cost;
                    routing.push({ next, curr.cost + 1 });
                }
            }
            else
            {
                if (next_cost < route[game[next]])
                {
                    route[game[next]] = next_cost;
                    routing.push({ game[next], next_cost });
                }
            }
            if (next == 100)
                fastest = min(fastest, next_cost);
        }
    }
    cout << fastest << '\n';

    return 0;
}