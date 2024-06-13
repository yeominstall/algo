#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    // 0, 1, 5, 15
    // 1, 2 2, 3 4 3, 4 7 7 4
    if (n == 3) cout << "0\n";
    else if (n == 4) cout << "1\n";
    else
        cout << (n * (n - 1) * (n - 2) * (n - 3)) / 24 << '\n';

    return 0;
}