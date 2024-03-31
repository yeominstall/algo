#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    vector<int> arr;
    vector<int> length;
    cin >> n;
    arr.resize(n);
    length.resize(n, 1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int historical_high = 1;
    for (int i = 1; i < n; i++)
    {
        int longest = -1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && longest < length[j])
                longest = length[j];
        }
        if (longest == -1)
            length[i] = 1;
        else
            length[i] = longest + 1;
        if (historical_high < length[i])
            historical_high = length[i];
    }
    cout << historical_high << '\n';

    return 0;
}