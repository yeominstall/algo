#include <iostream>
#include <queue>

using namespace std;
typedef unsigned int uint;
uint cnt = 0;

void recursive(int n, const uint pr, const uint pc, const uint& r, const uint& c)
{
    if (n < 1) return;
    uint x = 0, y = 0;
    uint piece = 1 << (n - 1);
    if (pr + piece <= r && r < pr + (piece << 1))
        y++;
    if (pc + piece <= c && c < pc + (piece << 1))
        x++;

    cnt += ((y * 2 + x) * piece * piece);

    recursive(n - 1, pr + (y * piece), pc + (x * piece), r, c);
}

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    uint n, r, c;
    cin >> n >> r >> c;

    recursive(n, 0, 0, r, c);
    cout << cnt << '\n';

    return 0;
}