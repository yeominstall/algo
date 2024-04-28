#include <iostream>
#include <vector>

using namespace std;

struct person
{
    unsigned int hp;
    unsigned int pleasure;
};

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<person> people(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> people[i].hp;
    for (int i = 1; i <= n; ++i)
        cin >> people[i].pleasure;

    vector<vector<unsigned int>> table(n + 1);
    table[0].resize(101, 0);
    for (int i = 1; i <= n; ++i)
    {
        table[i].resize(101);
        auto& hp = people[i].hp;
        auto& pleasure = people[i].pleasure;
        for (int j = 1; j <= 100; ++j)
        {
            if (j <= hp)
                table[i][j] = table[i - 1][j];
            else
                table[i][j] = max(table[i - 1][j], pleasure + table[i - 1][j - hp]);
        }
    }
    cout << table[n][100] << '\n';

    return 0;
}