#include <iostream>
#include <vector>

using namespace std;

struct test
{
    unsigned int priority;
    unsigned int time;
};

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int time_limit, n;
    cin >> time_limit >> n;
    vector<test> subjects(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> subjects[i].priority >> subjects[i].time;

    vector<vector<unsigned int>> best_practice(n + 1);
    best_practice[0].resize(time_limit + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        best_practice[i].resize(time_limit + 1);
        auto& prior = subjects[i].priority;
        auto& time = subjects[i].time;
        for (int t = 1; t <= time_limit; ++t)
        {
            if (t < time)
                best_practice[i][t] = best_practice[i - 1][t];
            else
                best_practice[i][t] = max(best_practice[i - 1][t], prior + best_practice[i - 1][t - time]);
        }
    }

    cout << best_practice[n][time_limit] << '\n';

    return 0;
}