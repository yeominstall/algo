#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n,m;
    string name;
    unordered_map<string, int> pokedex;
    vector<string> seq;
    seq.push_back("null");
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> name;
        pokedex[name] = i;
        seq.push_back(name);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> name;
        if (pokedex[name] != 0)
            cout << pokedex[name] << '\n';
        else
        {
            int n = atoi(name.c_str());
            cout << seq[n] << '\n';
        }
    }

    return 0;
}