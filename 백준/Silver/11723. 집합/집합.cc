#include <iostream>
#include <string>

using namespace std;

bool set[21];

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        string ops;
        cin >> ops;
        if (ops == "all")
            for (int i = 0; i < 21; i++) set[i] = true;
        else if (ops == "empty")
            for (int i = 0; i < 21; i++) set[i] = false;
        else
        {
            cin >> x;
            if (ops == "add")
                set[x] = true;
            else if (ops == "remove")
                set[x] = false;
            else if (ops == "check")
                cout << set[x] << '\n';
            else if (ops == "toggle")
                set[x] = !set[x];
        }
    }

    return 0;
}