#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct candy
{
    unsigned int cal;
    double cost;
};

vector<vector<unsigned int>> table;

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    string budget;
    vector<candy> stock;
    
    while (cin >> n >> budget)
    {
        if (n == 0 && budget == "0.00")
            break;

        stock.resize(n + 1);

        double balance = strtod(budget.c_str(), nullptr) * 100;
        for (int i = 1; i <= n; ++i)
        {
            cin >> stock[i].cal >> stock[i].cost;
            stock[i].cost *= 100;
        }

        sort(stock.begin(), stock.end(), [](const candy& lst, const candy& rst)
            {
                return lst.cost < rst.cost;
            });

        table.clear();
        table.resize(n + 1);
        table[0].resize(balance + 1, 0);
        // i를 마지막으로 뽑을 때의 최대값을 table에 저장
        for (int i = 1; i <= n; ++i)
        {
            auto& cost = stock[i].cost;
            auto& cal = stock[i].cal;
            table[i].resize(balance + 1);
            for (int v = 1; v <= balance; ++v)
            {
                int diff = v - cost;
                if (diff < 0)
                {
                    table[i][v] = table[i - 1][v];
                    continue;
                }

                table[i][v] = max(table[i - 1][v], cal + table[i][diff]);
            }
        }
        unsigned int maxcal = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (maxcal < table[i][balance])
                maxcal = table[i][balance];
        }
        cout << maxcal << '\n';
    }

    return 0;
}