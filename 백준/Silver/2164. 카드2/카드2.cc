#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    queue<int> cards;
    for (int i = 1; i <= n; ++i)
        cards.push(i);

    while (cards.size() != 1)
    {
        cards.pop();
        int tmp = cards.front();
        cards.pop();
        cards.push(tmp);
    }
    cout << cards.front() << '\n';
    return 0;
}