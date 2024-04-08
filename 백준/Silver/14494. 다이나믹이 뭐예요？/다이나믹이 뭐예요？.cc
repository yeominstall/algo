#include <iostream>

using namespace std;

constexpr int dval = 1000000007;
int arr[1001][1001];

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    // n: x, m: y
    // f[i][j] = f[i-1][j] + f[i][j-1] + f[i-1][j-1]
    for (int i = 1; i <= n; i++)
        arr[1][i] = 1;
    for (int i = 1; i <= m; i++)
        arr[i][1] = 1;

    for (int i = 2; i <= m; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            arr[i][j] = (((arr[i - 1][j] + arr[i][j - 1]) % dval) + arr[i - 1][j - 1]) % dval;
        }
    }
    cout << arr[m][n] << '\n';

    return 0;
}