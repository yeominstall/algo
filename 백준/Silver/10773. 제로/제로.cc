#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int k, n = 0, input;
    cin >> k;
    vector<int> arr(k);
    for (int i = 0; i < k; ++i)
    {
        cin >> input;
        if (input == 0)
            --n;
        else
            arr[n++] = input;
    }
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += arr[i];

    cout << sum << '\n';

    return 0;
}