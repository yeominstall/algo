#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int T, n, i, j;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc)
    {
        cin >> n;
        vector<int> a(n), b(n);
        for (i = 0; i < n; ++i)
            cin >> a[i];
        for (i = 0; i < n; ++i)
            cin >> b[i];

        int min_prod = 0;
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        for (i = 0; i < n; ++i)
            min_prod += (a[i] * b[i]);

        cout << "Case #" << tc << ": " << min_prod << '\n';
    }
    return 0;
}