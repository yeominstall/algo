#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    vector<int> ordered;
    set<int> val;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ip;
        cin >> ip;
        ordered.push_back(ip);
        val.insert(ip);
    }
    
    unordered_map<int, uint32_t> ranktable;
    int rank = 0;
    for (auto& n : val)
        ranktable[n] = rank++;

    for (auto& r : ordered)
        cout << ranktable[r] << ' ';

    return 0;
}