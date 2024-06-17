#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, i;
    cin >> n;
    vector<int> lv(5000);
    lv[0] = 0;
    for (i = 1; i <= 5000; ++i)
    {
        lv[i] = lv[i - 1] + i;
        if (n <= lv[i])
            break;
    }
    // 짝수는 역순
    int diff = lv[i] - n;
    if (i % 2 == 0)
        cout << (i - diff) << '/' << (1 + diff) << '\n';
    else
        cout << (1 + diff) << '/' << (i - diff) << '\n';

    return 0;
}