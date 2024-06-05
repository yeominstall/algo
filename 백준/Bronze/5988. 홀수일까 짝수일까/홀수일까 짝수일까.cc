#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, m;
    string s;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        m = s[s.size() - 1] - '0';
        if (m % 2 == 0) cout << "even\n";
        else cout << "odd\n";
    }
    return 0;
}