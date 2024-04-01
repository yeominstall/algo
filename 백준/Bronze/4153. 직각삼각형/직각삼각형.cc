#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int a, b, c;
    while (1)
    {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;
        a *= a; b *= b; c *= c;
        if (a + b == c || a + c == b || b + c == a)
            cout << "right\n";
        else
            cout << "wrong\n";
    }
    return 0;
}