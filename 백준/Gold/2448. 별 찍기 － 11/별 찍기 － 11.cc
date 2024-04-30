#include <iostream>
#include <vector>

using namespace std;

char unit[3][5] =
{
    ' ',' ','*',' ',' ',
    ' ','*',' ','*',' ',
    '*','*','*','*','*'
};
vector<vector<char>> pic;

void fractal(int n, int px, int py)
{
    if (n == 3)
    {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 5; ++j)
                pic[py + i][px + j] = unit[i][j];
    }
    else
    {
        fractal(n / 2, px + (n / 2), py);
        fractal(n / 2, px, py + (n / 2));
        fractal(n / 2, px + n, py + (n / 2));
    }
}

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    pic.resize(n);
    // f(n) = f(n - 1) * 2 + 1
    // k = n * 2 - 1
    for (int i = 0; i < n; ++i)
        pic[i].resize(n * 2 - 1, ' ');

    fractal(n, 0, 0);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < (n * 2) - 1; ++j)
            cout << pic[i][j];
        cout << '\n';
    }

    return 0;
}