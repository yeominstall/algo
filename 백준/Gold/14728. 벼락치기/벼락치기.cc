#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct chapter
{
    unsigned int cost;
    unsigned int point;
};

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, time;
    cin >> n >> time;
    vector<chapter> prob(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> prob[i].cost >> prob[i].point;

    vector<vector<unsigned int>> timetable(n + 1);
    timetable[0].resize(time + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        timetable[i].resize(time + 1);
        auto& cost = prob[i].cost;
        auto& point = prob[i].point;
        for (int t = 1; t <= time; ++t)
        {
            if (t < cost)
                timetable[i][t] = timetable[i - 1][t];
            else
                timetable[i][t] = max(timetable[i - 1][t], point + timetable[i - 1][t - cost]);
        }
    }

    unsigned int maxval = 0;
    for (int i = 1; i <= n; ++i)
        maxval = max(maxval, timetable[i][time]);

    cout << maxval << '\n';
    return 0;
}