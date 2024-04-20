#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    vector<unsigned short> counts(11);
    counts[1] = 1;
    counts[2] = 2;
    counts[3] = 4;
    for (int i = 4; i <= 10; ++i)
        counts[i] = counts[i - 1] + counts[i - 2] + counts[i - 3];

    int tc, n;
    cin >> tc;
    for (int T = 0; T < tc; ++T)
    {
        cin >> n;
        cout << counts[n] << '\n';
    }

    return 0;
}