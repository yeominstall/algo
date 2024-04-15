#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    vector<int> LIS;
    LIS.push_back(arr[0]);
    for (int i = 1; i < n; ++i)
    {
        if (LIS.back() < arr[i])
            LIS.push_back(arr[i]);
        else
        {
            auto lower = lower_bound(LIS.begin(), LIS.begin() + LIS.size(), arr[i]) - LIS.begin();
            LIS[lower] = arr[i];
        }
    }

    cout << LIS.size() << '\n';

    return 0;
}