#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void)
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, tc = 1;
    while (cin >> n)
    {
        if (n == 0) break;
        vector<string> lists(n + 1);
        unordered_map<int, int> earrings;
        cin.ignore();
        for (int i = 1; i <= n; ++i)
        {
            string name;
            getline(cin, name);
            lists[i] = name;
        }
        int m;
        char a;
        for (int i = 0; i < (2 * n - 1); ++i)
        {
            cin >> m >> a;
            ++earrings[m];
        }
        for (auto& e : earrings)
        {
            if (e.second == 1)
                cout << tc++ << ' ' << lists[e.first] << '\n';
        }
    }
    return 0;
}