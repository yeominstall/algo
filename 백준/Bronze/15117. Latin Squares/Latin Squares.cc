#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> latin(n, vector<int>(n));
    int i, j;
    string str;
    for (i = 0; i < n; ++i)
    {
        cin >> str;
        for (j = 0; j < n; ++j)
        {
            if (str[j] > '9')
                latin[i][j] = str[j] - 'A' + 10;
            else
                latin[i][j] = str[j] - '0';
        }
    }

    bool is_reduced = true;
    vector<bool> row(n, false);
    vector<bool> col(n, false);
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (row[latin[i][j]])
                goto NO;
            if (col[latin[j][i]])
                goto NO;
            row[latin[i][j]] = true;
            col[latin[j][i]] = true;
        }
        fill(row.begin(), row.end(), false);
        fill(col.begin(), col.end(), false);
    }

    for (i = 0; i < n; ++i)
    {
        if (latin[i][0] != i || latin[0][i] != i)
        {
            is_reduced = false;
            break;
        }
    }
    if (is_reduced)
        cout << "Reduced\n";
    else
        cout << "Not Reduced\n";
    return 0;

NO:
    cout << "No\n";
    return 0;
}