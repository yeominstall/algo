#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    vector<set<string>> words;
    cin >> n;
    words.resize(20000);
    for (int i = 0; i < n; ++i)
    {
        string ip;
        cin >> ip;
        words[ip.size()].insert(ip);
    }

    for (auto& line : words)
    {
        for (auto& w : line)
            cout << w << '\n';
    }

    return 0;
}