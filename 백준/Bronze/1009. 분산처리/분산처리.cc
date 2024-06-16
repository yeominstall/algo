#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int T, a, b;
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        cin >> a >> b;
        b = b % 4;
        if (b == 0) b = 4;
        int ret = 1;
        for (int i = 0; i < b; ++i)
        {
            ret *= a;
            ret = ret % 10;
            if (ret == 0) ret = 10;
        }
        cout << ret << '\n';
    }
    return 0;
}