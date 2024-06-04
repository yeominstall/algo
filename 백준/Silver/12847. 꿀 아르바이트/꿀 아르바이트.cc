#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, m;
    int i, j;
    cin >> n >> m;
    vector<int> payroll(n);
    for (i = 0; i < n; ++i)
        cin >> payroll[i];

    long long max_pay = 0;
    for (i = 0; i < m; ++i)
        max_pay += payroll[i];
    long long curr = max_pay;
    for (i = 1; i <= n - m; ++i)
    {
        curr = curr - payroll[i - 1] + payroll[i + m - 1];
        max_pay = max(max_pay, curr);
    }

    cout << max_pay << '\n';
    return 0;
}