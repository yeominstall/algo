#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int tc;
    cin >> tc;
    vector<vector<int>> sudoku(10, vector<int>(9));
    vector<bool> col(10);
    vector<bool> row(10);
    int i, j;
    for (int T = 1; T <= tc; ++T)
    {
        for (i = 0; i < 9; ++i)
            for (j = 0; j < 9; ++j)
                cin >> sudoku[i][j];
        // col row
        for (i = 0; i < 9; ++i)
        {
            fill(col.begin(), col.end(), false);
            fill(row.begin(), row.end(), false);
            for (j = 0; j < 9; ++j)
            {

                if (col[sudoku[j][i]] || row[sudoku[i][j]])
                    goto INCORRECT;
                col[sudoku[j][i]] = true;
                row[sudoku[i][j]] = true;
            }
        }
        // box
        for (int a = 0; a < 9; a += 3)
        {
            for (int b = 0; b < 9; b += 3)
            {
                fill(col.begin(), col.end(), false);
                for (i = 0; i < 3; ++i)
                {
                    for (j = 0; j < 3; ++j)
                    {
                        if (col[sudoku[a + i][b + j]])
                            goto INCORRECT;
                        col[sudoku[a + i][b + j]] = true;
                    }
                }
            }
        }

        cout << "Case " << T << ": CORRECT\n";
        continue;
    INCORRECT:
        cout << "Case " << T << ": INCORRECT\n";
    }

    return 0;
}