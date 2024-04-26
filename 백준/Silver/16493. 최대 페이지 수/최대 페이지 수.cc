#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct chapter
{
    unsigned int days;
    unsigned int page;
};

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, time;
    cin >> time >> n;
    vector<chapter> prob(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> prob[i].days >> prob[i].page;

    vector<vector<unsigned int>> timetable(n + 1);
    timetable[0].resize(time + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        timetable[i].resize(time + 1);
        auto& days = prob[i].days;
        auto& page = prob[i].page;
        for (int t = 1; t <= time; ++t)
        {
            if (t < days)
                timetable[i][t] = timetable[i - 1][t];
            else
                timetable[i][t] = max(timetable[i - 1][t], page + timetable[i - 1][t - days]);
        }
    }

    unsigned int maxval = 0;
    for (int i = 1; i <= n; ++i)
        maxval = max(maxval, timetable[i][time]);

    cout << maxval << '\n';
    return 0;
}